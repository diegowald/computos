#include "mainwindow.h"
#include "ui_projectwindow.h"

#include <QDebug>

#include "datastore.h"
#include "dlgnuevoelementoconstructivo.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    projectName = "./Proyecto.pr";
    DataStore::getInstance()->crearProyecto(projectName, this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::LoadProyecto(QString &filename)
{
    projectName = filename;
    DataStore::getInstance()->LoadProject(projectName, this);
    LoadProyecto();
}

void MainWindow::LoadProyecto()
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
    QList<QString> *elementosProyecto = p->getAllElementoConstructivoNames();

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
            item->setText(3, QString::number(el->getCantidad()->getValue()));
        }
        else
        {
            item->setText(2, "");
            item->setText(3, "");
        }
    }
    LoadComputo();
    reLoadResumenMateriales();
}

void MainWindow::reLoadProyecto()
{
    ui->treeProyecto->clear();
    LoadProyecto();
}

void MainWindow::reLoadComputo()
{
    ui->treeComputoMetrico->clear();
    DataStore::getInstance()->getComputo(projectName)->Compute();
    LoadComputo();
    reLoadResumenMateriales();
}

void MainWindow::LoadResumenMateriales()
{
    boost::shared_ptr<QMap<QString, double> > resultado = DataStore::getInstance()->getComputo(projectName)->getResumenMateriasPrimas();
//Material,  cantidad, unidad
    foreach(QString material, (*resultado).keys())
    {
        QTreeWidgetItem *item = new QTreeWidgetItem();

        item->setText(0, material);

        ui->treeComputoMateriaPrima->insertTopLevelItem(0, item);

        item->setText(1, QString::number((*resultado)[material]));
    }
}

void MainWindow::reLoadResumenMateriales()
{
    ui->treeComputoMateriaPrima->clear();
    LoadResumenMateriales();
}

void MainWindow::populateSubtree(QTreeWidgetItem *item, computo::ElementoComputo *elemento)
{
    qDebug() << elemento->getElemento()->getName();
    foreach(computo::ComponenteElementoComputo *e, *elemento->getComponentes())
    {
        QTreeWidgetItem *subitem = new QTreeWidgetItem();
        subitem->setText(0, e->getElemento()->getElemento()->getName());
        subitem->setText(1, QString::number(e->getElemento()->getCantidad()));
        subitem->setText(2, e->getElemento()->getElemento()->getMeasureUnit()->getName());
        item->addChild(subitem);
        if (e->getElemento()->esCompuesto())
        {
            populateSubtree(subitem, e->getElemento());
        }
    }
}

void MainWindow::LoadComputo()
{
    ui->treeComputoMetrico->clear();

    boost::shared_ptr<QStringList> elementosComputo = DataStore::getInstance()->getComputo(projectName)->getElementosComputoNames();

//Elemento Constructivo/material,  cantidad, unidad
    foreach(QString elementoComputo, *elementosComputo)
    {
        QTreeWidgetItem *itemConstructivo = new QTreeWidgetItem();

        itemConstructivo->setText(0, elementoComputo);

        ui->treeComputoMetrico->insertTopLevelItem(0, itemConstructivo);

        QTreeWidgetItem *item = new QTreeWidgetItem();

        computo::ElementoComputo *e = DataStore::getInstance()->getComputo(projectName)->getElementoComputo(elementoComputo);

        if (e != NULL)
        {
            item->setText(0, e->getElemento()->getName());
            item->setText(1, QString::number(e->getCantidad()));
            item->setText(2, e->getElemento()->getMeasureUnit()->getName());
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

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug() << event->mimeData()->formats().join(", ");
  /*  if (event->mimeData()->hasFormat("text/uri-list"))
        event->acceptProposedAction();
    else*/ if (event->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist"))
        event->acceptProposedAction();
}

void MainWindow::dropEvent(QDropEvent *event)
{
    qDebug() << event->mimeData()->data("application/x-qabstractitemmodeldatalist");
    QByteArray x = event->mimeData()->data("application/x-qabstractitemmodeldatalist");
    qDebug() << x.size();
    QDataStream stream(&x, QIODevice::ReadOnly);
    QString nombreMaterial = "";
    while (!stream.atEnd())
    {
        int row, col;
        QMap<int, QVariant> roleDataMap;
        stream >> row >> col >> roleDataMap;
        qDebug() << row;
        qDebug() << col;
        qDebug() << roleDataMap;
        nombreMaterial = roleDataMap[0].toString();
    }

    bool aceptar = false;
    if (nombreMaterial != "")
    {
        dlgNuevoElementoConstructivo dlg(this);
        dlg.setMaterial(nombreMaterial);
        if (dlg.exec() == QDialog::Accepted)
        {
            QString nombreElementoConstructivo = dlg.nombreElementoConstructivo();
            cantidades::Cantidad *cant = dlg.cantidad();
            proyecto::ElementoConstructivo *e = new proyecto::ElementoConstructivo(this);
            e->setName(nombreElementoConstructivo);
            e->setElemento(DataStore::getInstance()->getMaterialLibrary()->getElemento(nombreMaterial));
            e->setCantidad(cant);
            DataStore::getInstance()->getProject(projectName)->addElementoConstructivo(e);
            aceptar = true;
        }
    }

    if (aceptar)
    {
        event->accept();
        reLoadProyecto();
        reLoadComputo();
    }
}

QString MainWindow::getProjectName()
{
    return projectName;
}

void MainWindow::save()
{
    if (DataStore::getInstance()->getProject(projectName) != NULL)
        DataStore::getInstance()->getProject(projectName)->save();
}

void MainWindow::saveAs(QString newProjectName)
{
    DataStore::getInstance()->getProject(projectName)->saveAs(newProjectName);
}

void MainWindow::updateProjectInformation()
{
    proyecto::Proyecto *p = DataStore::getInstance()->getProject(projectName);
    p->setNombre(ui->txtNombreProyecto->text());
    p->setPropietarios(ui->txtPropietarios->text());
    p->setDireccion(ui->txtDireccion->text());
    p->setTelefono(ui->txtTelefono->text());
    p->setEMail(ui->txtEMail->text());
    p->setNotas(ui->txtNotas->toHtml());
}

void MainWindow::on_treeProyecto_doubleClicked(const QModelIndex &index)
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
