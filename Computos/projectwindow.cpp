#include "projectwindow.h"
#include "ui_projectwindow.h"

#include <QMenu>
#include <QMimeData>

#include "datastore.h"
#include "dlgnuevoelementoconstructivo.h"
#include <QMessageBox>
#include "htmlhelper.h"

ProjectWindow::ProjectWindow(QWidget *parent) :
    PrintableWindow(parent),
    ui(new Ui::ProjectWindow)
{
    ui->setupUi(this);
    projectName = "./Proyecto.pr";
    DataStore::getInstance()->crearProyecto(projectName, this);
}

ProjectWindow::~ProjectWindow()
{
    delete ui;
}

void ProjectWindow::LoadProyecto(QString &filename)
{
    projectName = filename;
    DataStore::getInstance()->LoadProject(projectName, this);
    LoadProyecto();
}

void ProjectWindow::LoadProyecto()
{
    if (projectName.isEmpty())
        return;
    proyecto::Proyecto *p = DataStore::getInstance()->getProject(projectName);
    ui->txtNombreProyecto->setText(p->Nombre());
    ui->txtPropietarios->setText(p->Propietarios());
    ui->txtDireccion->setText(p->Direccion());
    ui->txtTelefono->setText(p->Telefono());
    ui->txtEMail->setText(p->EMail());
    ui->txtNotas->setText(p->Notas());

    ui->treeProyecto->clear();

    setWindowTitle(projectName);

    // Aca cargo el arrchivo...
    boost::shared_ptr<QStringList> elementosProyecto = p->getAllElementoConstructivoNames();

    foreach(QString elementoProyecto, *elementosProyecto)
    {
        QTreeWidgetItem *item = new QTreeWidgetItem();
        item->setText(0, elementoProyecto);

        ui->treeProyecto->insertTopLevelItem(0, item);
        proyecto::ElementoConstructivo *el = p->getElementoConstructivo(elementoProyecto);

        if (el->getElemento() != NULL)
            item->setText(1, el->getElemento()->getName());
        else
            item->setText(1, "");


        if (el->getCantidad() != NULL)
        {
            item->setText(2, el->getCantidad()->getName());

            QPixmap pixmap(el->getCantidad()->getShape());
            QIcon icon(pixmap);
            item->setIcon(2, icon);

            item->setText(3, el->getCantidad()->getDimensions());

            item->setText(4, QString::number(el->getCantidad()->getValue()));
            item->setText(5, el->getElemento()->getMeasureUnit()->getDisplayName());
        }
        else
        {
            item->setText(2, "");
            item->setText(3, "");
            item->setText(4, "");
            item->setText(5, "");
        }
    }
    DataStore::getInstance()->getComputo(projectName)->Compute();
    LoadComputo();
    reLoadResumenMateriales();
}

void ProjectWindow::reLoadProyecto()
{
    ui->treeProyecto->clear();
    LoadProyecto();
}

void ProjectWindow::reLoadComputo()
{
    ui->treeComputoMetrico->clear();
    DataStore::getInstance()->getComputo(projectName)->Compute();
    LoadComputo();
    reLoadResumenMateriales();
}

void ProjectWindow::LoadResumenMateriales()
{
    boost::shared_ptr<QMap<QString, double> > resultado = DataStore::getInstance()->getComputo(projectName)->getResumenMateriasPrimas();
//Material,  cantidad, unidad
    foreach(QString material, (*resultado).keys())
    {
        QTreeWidgetItem *item = new QTreeWidgetItem();

        item->setText(0, material);

        ui->treeComputoMateriaPrima->insertTopLevelItem(0, item);

        item->setText(1, QString::number((*resultado)[material]));
        item->setText(2, DataStore::getInstance()->getMaterialLibrary()->getElemento(material)->getMeasureUnit()->getDisplayName());
    }
}

void ProjectWindow::reLoadResumenMateriales()
{
    ui->treeComputoMateriaPrima->clear();
    LoadResumenMateriales();
}

void ProjectWindow::populateSubtree(QTreeWidgetItem *item, computo::ElementoComputo *elemento)
{
    foreach(computo::ComponenteElementoComputo *e, *elemento->getComponentes())
    {
        QTreeWidgetItem *subitem = new QTreeWidgetItem();
        subitem->setText(0, e->getElemento()->getElemento()->getName());
        subitem->setText(1, QString::number(e->getElemento()->getCantidad()));
        subitem->setText(2, e->getElemento()->getElemento()->getMeasureUnit()->getDisplayName());
        item->addChild(subitem);
        if (e->getElemento()->esCompuesto())
        {
            populateSubtree(subitem, e->getElemento());
        }
    }
}

void ProjectWindow::LoadComputo()
{
    ui->treeComputoMetrico->clear();

    boost::shared_ptr<QStringList> elementosComputo = DataStore::getInstance()->getComputo(projectName)->getElementosComputoNames();

//Elemento Constructivo/material,  cantidad, unidad
    foreach(QString elementoComputo, *elementosComputo)
    {
        QTreeWidgetItem *itemConstructivo = new QTreeWidgetItem();

        itemConstructivo->setText(0, elementoComputo);

        ///
        proyecto::ElementoConstructivo *el = DataStore::getInstance()->getProject(projectName)->getElementoConstructivo(elementoComputo);

        QPixmap pixmap(el->getCantidad()->getShape());
        QIcon icon(pixmap);
        itemConstructivo->setIcon(0, icon);

        if (el->getCantidad() != NULL)
        {
            // Cantidad
            itemConstructivo->setText(1, QString::number(el->getCantidad()->getValue()));
            itemConstructivo->setText(2, el->getElemento()->getMeasureUnit()->getDisplayName());
        }
        else
        {
            itemConstructivo->setText(1, "");
            itemConstructivo->setText(2, "");
        }
        ///

        ui->treeComputoMetrico->insertTopLevelItem(0, itemConstructivo);

        QTreeWidgetItem *item = new QTreeWidgetItem();

        computo::ElementoComputo *e = DataStore::getInstance()->getComputo(projectName)->getElementoComputo(elementoComputo);

        if (e != NULL)
        {
            item->setText(0, e->getElemento()->getName());
            item->setText(1, QString::number(e->getCantidad()));
            item->setText(2, e->getElemento()->getMeasureUnit()->getDisplayName());
            if (e->esCompuesto())
            {
                populateSubtree(item, e);
            }
        }
        else
        {
            item->setText(1, "");
            item->setText(2, "");
        }
        itemConstructivo->addChild(item);
    }
}

void ProjectWindow::dragEnterEvent(QDragEnterEvent *event)
{
  /*  if (event->mimeData()->hasFormat("text/uri-list"))
        event->acceptProposedAction();
    else*/ if (event->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist"))
        event->acceptProposedAction();
}

void ProjectWindow::dropEvent(QDropEvent *event)
{
    QByteArray x = event->mimeData()->data("application/x-qabstractitemmodeldatalist");
    QDataStream stream(&x, QIODevice::ReadOnly);
    QString nombreMaterial = "";
    while (!stream.atEnd())
    {
        int row, col;
        QMap<int, QVariant> roleDataMap;
        stream >> row >> col >> roleDataMap;
        nombreMaterial = roleDataMap[0].toString();
    }
    if (createNewElement(nombreMaterial))
        event->accept();
}

bool ProjectWindow::createNewElement(QString material)
{
    bool aceptar = false;
    /*if (material != "")*/
    {
        dlgNuevoElementoConstructivo dlg(this);
        dlg.setMaterial(material);
        if (dlg.exec() == QDialog::Accepted)
        {
            QString nombreElementoConstructivo = dlg.nombreElementoConstructivo();
            cantidades::Cantidad *cant = dlg.cantidad();
            proyecto::ElementoConstructivo *e = new proyecto::ElementoConstructivo(this);
            e->setName(nombreElementoConstructivo);
            e->setElemento(DataStore::getInstance()->getMaterialLibrary()->getElemento(material));
            e->setCantidad(cant);
            DataStore::getInstance()->getProject(projectName)->addElementoConstructivo(e);
            aceptar = true;
        }
    }

    if (aceptar)
    {
        reLoadProyecto();
        reLoadComputo();
    }
    return aceptar;
}

void ProjectWindow::createNewElement()
{
    createNewElement("");
}

QString ProjectWindow::getProjectName()
{
    return projectName;
}

void ProjectWindow::save()
{
    if (DataStore::getInstance()->getProject(projectName) != NULL)
    {
        updateProjectInformation();
        DataStore::getInstance()->getProject(projectName)->save();
    }
}

void ProjectWindow::saveAs(QString newProjectName)
{
    if (DataStore::getInstance()->getProject(projectName) != NULL)
    {
        updateProjectInformation();
        DataStore::getInstance()->getProject(projectName)->saveAs(newProjectName);
        projectName = newProjectName;
    }
}

void ProjectWindow::updateProjectInformation()
{
    proyecto::Proyecto *p = DataStore::getInstance()->getProject(projectName);
    p->setNombre(ui->txtNombreProyecto->text());
    p->setPropietarios(ui->txtPropietarios->text());
    p->setDireccion(ui->txtDireccion->text());
    p->setTelefono(ui->txtTelefono->text());
    p->setEMail(ui->txtEMail->text());
    p->setNotas(ui->txtNotas->toPlainText());
}

void ProjectWindow::on_treeProyecto_doubleClicked(const QModelIndex &)
{
    if (ui->treeProyecto->selectedItems().size() > 0)
    {
        QTreeWidgetItem *item = ui->treeProyecto->selectedItems().at(0);
        dlgNuevoElementoConstructivo dlg(this);
        proyecto::ElementoConstructivo *el = DataStore::getInstance()->getProject(projectName)->getElementoConstructivo(item->text(0));

        dlg.setElementoConstructivo(el->getName());
        dlg.setMaterial(el->getElemento()->getName());
        dlg.setCantidad(el->getCantidad());
        dlg.setEditMode();

        if (dlg.exec() == QDialog::Accepted)
        {
            el->setCantidad(dlg.cantidad());
            reLoadProyecto();
            reLoadComputo();
        }
    }
}

void ProjectWindow::on_treeProyecto_customContextMenuRequested(const QPoint &pos)
{
    QMenu *menu = new QMenu(this);

    if (ui->treeProyecto->selectedItems().size() > 0)
    {
        menu->addAction(ui->actionRemove_Build_Part);
        menu->addAction(ui->actionClone_and_set_material);
    }

    menu->exec(ui->treeProyecto->mapToGlobal(pos));
}

void ProjectWindow::on_actionRemove_Build_Part_triggered()
{
    QString elementoConstructivo = ui->treeProyecto->selectedItems().at(0)->text(0);

    int r = QMessageBox::warning(this, tr("Remove Build Part"),
            tr("You are going to remove %1.\n"
            "Are you sure?").arg(elementoConstructivo),
            QMessageBox::Yes,
            QMessageBox::No | QMessageBox::Default | QMessageBox::Escape);

    if (r == QMessageBox::Yes)
    {
        DataStore::getInstance()->getProject(projectName)->removeElemento(elementoConstructivo);
        reLoadProyecto();
        reLoadComputo();
    }
}

void ProjectWindow::on_actionClone_and_set_material_triggered()
{
    QString elementoConstructivo = ui->treeProyecto->selectedItems().at(0)->text(0);
    QString nombreMaterial = "";
    elementoConstructivo += " (" + tr("Clone") + ")";

    dlgNuevoElementoConstructivo dlg(this);

    dlg.setMaterial("");
    dlg.setElementoConstructivo(elementoConstructivo);

    if (dlg.exec() == QDialog::Accepted)
    {
        elementoConstructivo = dlg.nombreElementoConstructivo();
        nombreMaterial = dlg.nombreMaterial();
        cantidades::Cantidad *cant = dlg.cantidad();
        proyecto::ElementoConstructivo *e = new proyecto::ElementoConstructivo(this);
        e->setName(elementoConstructivo);
        e->setElemento(DataStore::getInstance()->getMaterialLibrary()->getElemento(nombreMaterial));
        e->setCantidad(cant);
        DataStore::getInstance()->getProject(projectName)->addElementoConstructivo(e);
        reLoadProyecto();
        reLoadComputo();
    }

}

QString ProjectWindow::getHtmlContents()
{
    QString html = "";

    proyecto::Proyecto *p = DataStore::getInstance()->getProject(projectName);

    QStringList header;
    header << tr("Project Name") << tr("Owner") << tr("Address")
              << tr("Telephone") << tr("e-mail") << tr("Notes");
    QStringList aux;
    aux << p->Nombre() << p->Propietarios() << p->Direccion()
           << p->Telefono() << p->EMail() << p->Notas();
    QVector<QStringList> body;
    body.push_back(aux);
    html += HtmlHelper::toHtml(tr("Project information"), header, body);

    html += "<br>";

    html += HtmlHelper::toHtml(tr("Element definition"), ui->treeProyecto, false);

    html += "<br>";

    html += HtmlHelper::toHtml(tr("Materials estimations"), ui->treeComputoMateriaPrima, true);

    return html;
}
