#include "wndmateriales.h"
#include "ui_wndmateriales.h"
#include "datastore.h"
#include <QTreeWidgetItem>
#include <QMenu>
#include "dlgcomponente.h"
#include "htmlhelper.h"

wndMateriales::wndMateriales(QWidget *parent) :
    PrintableWindow(parent),
    ui(new Ui::wndMateriales)
{
    loadingElemento = true;
    ui->setupUi(this);
    cboLibraries = new QComboBox(this);
    ui->toolBar->addWidget(cboLibraries);
    connect(cboLibraries, SIGNAL(currentIndexChanged(QString)), this, SLOT(on_cboLibraries_currentIndexChanged(QString)));
    loadLibraries();
    //loadMateriales("");
    loadComboMeasureUnits();
    materialDirty = false;
    libraryDirty = false;
    loadingElemento = false;
    loadingLibraries = false;
    newElement = true;
    title = tr("Material Library");
    detailsTitle = tr("Details");
}

wndMateriales::~wndMateriales()
{
    delete ui;
}

void wndMateriales::loadMateriales(QString library)
{
    ui->treeMateriales->clear();

    // Aca tengo que pedir la lista de materiales e ir cargandola
    QString filter = "";
    boost::shared_ptr<QStringList> materiales = DataStore::getInstance()->getMaterialLibrary()->getAllNames(library, filter, false);

    foreach(QString material, *materiales)
    {
        materialLibrary::Elemento *elemento = DataStore::getInstance()->getMaterialLibrary()->getElemento(material);
        if (elemento != NULL)
        {
            QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeMateriales);
            item->setText(0, material);
            if (elemento->getMeasureUnit() != NULL)
                item->setText(1, elemento->getMeasureUnit()->getDisplayName());
            else
                item->setText(1, "");

            item->setText(2, elemento->getTagsString());

            if (elemento->esCompuesto())
                item->setText(3, tr("Complex"));
            else
                item->setText(3, "");

            ui->treeMateriales->insertTopLevelItem(0, item);
        }
    }
    QString status = tr("%1 materials in library.").arg(materiales->count());
    ui->statusbar->showMessage(status);
}

void wndMateriales::loadComboMeasureUnits()
{
    ui->cboMeasureUnit->clear();

    boost::shared_ptr<QStringList> nombres = DataStore::getInstance()->getUnitsLibrary()->getAllInternalNames();
    foreach(QString nombre, *nombres)
    {
        ui->cboMeasureUnit->addItem(DataStore::getInstance()->getUnitsLibrary()->getUnit(nombre)->getDisplayName(), nombre);
    }
}

void wndMateriales::on_treeMateriales_itemSelectionChanged()
{
    if (materialDirty)
        return;
    loadingElemento = true;
    QList<QTreeWidgetItem*> selected = ui->treeMateriales->selectedItems();
    foreach (QTreeWidgetItem * item, selected)
    {
        QString nombreElemento = item->text(0);
        editMaterial(nombreElemento);
    }
    loadingElemento = false;
}

void wndMateriales::editMaterial(QString materialName)
{
    materialLibrary::Elemento *e = DataStore::getInstance()->getMaterialLibrary()->getElemento(materialName);
    if (e != NULL)
    {
        newElement = false;
        ui->txtNombre->setText(e->getName());
        ui->txtDescripcion->setText(e->getDescription());
        ui->txtTags->setText(e->getTagsString());
        ui->chkUsableDirectly->setChecked(e->UsableDirectamente());
        ui->treeComponentes->clear();
        foreach(materialLibrary::ComponenteElemento* c, *e->getComponentes())
        {
            QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeComponentes);
            item->setText(0, c->getElemento()->getName());
            item->setText(1, QString::number(c->getCantidad()));
            ui->treeComponentes->insertTopLevelItem(0, item);
            item->setText(1, QString::number(c->getCantidad()));
            item->setText(2, c->getElemento()->getMeasureUnit()->getDisplayName());
            if (c->getElemento()->esCompuesto())
                item->setText(3, tr("Complex"));
            else
                item->setText(3, "");
        }
        int index = ui->cboMeasureUnit->findData(e->getMeasureUnit()->getDisplayName());
        ui->cboMeasureUnit->setCurrentIndex(index);
    }
    else
    {
        newElement = true;
        ui->txtNombre->clear();
        ui->txtDescripcion->clear();
        ui->txtTags->clear();
        ui->treeComponentes->clear();
    }
}

void wndMateriales::saveMaterial()
{
    materialLibrary::Elemento *e = DataStore::getInstance()->getMaterialLibrary()->getElemento(
                ui->txtNombre->text().simplified());
    if (e == NULL)
    {
        e = new materialLibrary::Elemento(DataStore::getInstance()->getMaterialLibrary());
        e->setName(ui->txtNombre->text().simplified());
    }

    e->setDescription(ui->txtDescripcion->toHtml());

    QStringList tags = ui->txtTags->text().split(" ", QString::SkipEmptyParts);
    foreach (QString tag, tags)
    {
        e->addTag(tag);
    }

    e->setUsableDirectamente(ui->chkUsableDirectly->isChecked());

    if (ui->treeComponentes->topLevelItemCount() > 0)
    {
        e->eliminarTodosComponentes();
        QTreeWidgetItemIterator it(ui->treeComponentes);
        while(*it)
        {
            QString componente = (*it)->text(0);
            QString aux = (*it)->text(1);
            double cantidad = aux.toDouble();
            e->AddComponente(DataStore::getInstance()->getMaterialLibrary()->getElemento(componente), cantidad);
            it++;
        }
    }
    materialDirty = false;

    e->setMeasureUnit(DataStore::getInstance()->getUnitsLibrary()->getUnit(ui->cboMeasureUnit->currentText()));

    DataStore::getInstance()->getMaterialLibrary()->addMaterial(e);
    loadMateriales(cboLibraries->currentText());
    ui->grpDetails->setTitle(detailsTitle);

}

void wndMateriales::discardChanges()
{

}

void wndMateriales::saveLibrary()
{
    DataStore::getInstance()->getMaterialLibrary()->save();
    libraryDirty = false;
    materialDirty = false;
    setWindowTitle(title);
    ui->grpDetails->setTitle(detailsTitle);
}

void wndMateriales::on_txtNombre_textEdited(const QString &)
{
    if (loadingElemento)
        return;
    setMaterialDirty();
}

void wndMateriales::on_txtDescripcion_textChanged()
{
    if (loadingElemento)
        return;
    setMaterialDirty();
}

void wndMateriales::on_txtTags_textEdited(const QString &)
{
    if (loadingElemento)
        return;
    setMaterialDirty();
}

void wndMateriales::on_cboMeasureUnit_currentIndexChanged(const QString &)
{
    if (loadingElemento)
        return;
    setMaterialDirty();
}

void wndMateriales::on_cboLibraries_currentIndexChanged(const QString &arg1)
{
    if (loadingLibraries)
        return;
    QString filename(arg1);
    loadMateriales(filename);
}

void wndMateriales::on_actionNewMaterial_triggered()
{
    editMaterial("");
}

void wndMateriales::on_actionSaveLibrary_triggered()
{
    saveLibrary();
}

void wndMateriales::on_actionSaveMaterial_triggered()
{
    if (materialDirty)
        saveMaterial();
}

void wndMateriales::on_actionAddComponente_triggered()
{
    editComponente(-1);
}

void wndMateriales::on_actionDeleteComponente_triggered()
{
    QTreeWidgetItem *item = ui->treeComponentes->currentItem();
    if (item != NULL)
        delete item;
}

void wndMateriales::on_treeComponentes_customContextMenuRequested(const QPoint &pos)
{
    QMenu *menu = new QMenu(this);

    menu->addAction(ui->actionAddComponente);
    menu->addAction(ui->actionDeleteComponente);

    menu->exec(ui->treeComponentes->mapToGlobal(pos));
}

void wndMateriales::on_treeComponentes_doubleClicked(const QModelIndex &index)
{
    editComponente(index.row());
}

void wndMateriales::editComponente(int row)
{
    QTreeWidgetItem *item = NULL;
    dlgComponente dlg;
    dlg.setMaterial(ui->txtNombre->text());
    if (row == -1)
    {
        dlg.setComponente("");
        dlg.setCantidadComponente(0);
    }
    else
    {
        item = ui->treeComponentes->selectedItems().at(0);
        dlg.setComponente(item->text(0));
        dlg.setCantidadComponente(item->text(1).toDouble());
    }

    if (dlg.exec() == QDialog::Accepted)
    {
        materialLibrary::Elemento *e = DataStore::getInstance()->getMaterialLibrary()->getElemento(dlg.Componente());
        double cantidad = dlg.Cantidad();

        if (row == -1)
        {
            item = new QTreeWidgetItem(ui->treeComponentes);
            ui->treeComponentes->insertTopLevelItem(0, item);
        }

        item->setText(0, e->getName());
        item->setText(1, QString::number(cantidad));
        item->setText(2, e->getMeasureUnit()->getDisplayName());
        if (e->esCompuesto())
            item->setText(3, tr("Complex"));
        else
            item->setText(3, "");
        setMaterialDirty();
    }
}

void wndMateriales::setMaterialDirty()
{
    materialDirty = true;
    libraryDirty = true;
    setWindowTitle(title + "*");
    ui->grpDetails->setTitle(detailsTitle + "*");
}

void wndMateriales::on_chkUsableDirectly_stateChanged(int)
{
    if (loadingElemento)
        return;
    setMaterialDirty();
}

QString wndMateriales::getHtmlContents()
{
    return HtmlHelper::toHtml(tr("Materials"), ui->treeMateriales, true);
}

void wndMateriales::on_cmdGoogleIt_pressed()
{
    QString search("%1 %2");
    search = search.arg(tr("Building")).arg(ui->txtNombre->text().simplified());
    if (search.size() > 0)
        emit openBrowser(search);
}

void wndMateriales::loadLibraries()
{
    loadingLibraries = true;
    cboLibraries->clear();
    boost::shared_ptr<QStringList> libraries = DataStore::getInstance()->getMaterialLibrary()->getAllLibraries();

    foreach(QString library, *libraries)
    {
        cboLibraries->addItem(library, library);
    }
    loadingLibraries = false;
    on_cboLibraries_currentIndexChanged(cboLibraries->currentText());
}
