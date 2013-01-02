#include "dlgimportpricelist.h"
#include "ui_dlgimportpricelist.h"
#include "datastore.h"
#include <QFileDialog>
#include <QMenu>
#include "csvreader.h"
#include "proveedor.h"
#include "listaprecios.h"
#include "dlgpriceitem.h"

dlgImportPriceList::dlgImportPriceList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgImportPriceList),
    filter(new QStringList())
{
    ui->setupUi(this);
    ui->txtPriceList->clear();
    ui->txtProvider->clear();
    ui->txtRecordSeparator->setText(",");
    ui->txtStringDelimiter->setText("\"");
    ui->chkHeadersOnFirstRow->setChecked(false);
    ui->txtfilename->clear();
    ui->lblRecordCount->clear();
    newProvider = tr("<New Provider>");
    newPriceList = tr("<New Pricelist>");
    loadProviders();
    csv = NULL;

    SalesName = tr("Sales Name");
    PriceLabel = tr("Price");
    ElementLabel = tr("Element");
    SalesUnitLabel = tr("Sales Unit");
    RatioLabel = tr("Ratio");
    BrandLabel = tr("Brand");
    NotesLabel = tr("Notes");
    RemoveMappingLabel = tr("Remove mapping");
    addToFilterLabel = tr("Filter Elements like this.");
    removeFromFilter = tr("Remove this from filter");

    ui->progress->setVisible(false);
    ui->progress->setMinimum(0);
    ui->progress->setMaximum(100);
    SalesNameColumn = -1;
    columnSelected = -1;
}

dlgImportPriceList::~dlgImportPriceList()
{
    delete ui;
}

void dlgImportPriceList::loadProviders()
{
    boost::shared_ptr<QStringList> proveedores = DataStore::getInstance()->getProvidersList()->getAllProveedores();
    ui->cboProviders->clear();
    foreach(QString proveedor, *proveedores)
    {
        ui->cboProviders->addItem(proveedor);
    }
    ui->cboProviders->addItem(newProvider);
}

void dlgImportPriceList::loadPriceLists()
{
    boost::shared_ptr<QStringList> listas = DataStore::getInstance()->getProvidersList()->getProveedor(ui->cboProviders->currentText())->getActiveListaPrecios();
    ui->cboPriceLists->clear();
    foreach(QString lista, *listas)
    {
        ui->cboPriceLists->addItem(lista);
    }
    ui->cboPriceLists->addItem(newPriceList);
}

void dlgImportPriceList::on_cboProviders_currentIndexChanged(const QString &arg1)
{
    if (arg1 == newProvider)
    {
        ui->txtProvider->clear();
        ui->txtProvider->setEnabled(true);
        ui->cboPriceLists->setEnabled(false);
    }
    else
    {
        ui->txtProvider->setText(arg1);
        ui->txtProvider->setEnabled(false);
        loadPriceLists();
    }
}

void dlgImportPriceList::on_cboPriceLists_currentIndexChanged(const QString &arg1)
{
    if (arg1 == newPriceList)
    {
        ui->txtPriceList->clear();
        ui->txtPriceList->setEnabled(true);
    }
    else
    {
        ui->txtPriceList->setText(arg1);
        ui->txtPriceList->setEnabled(false);
    }
}

void dlgImportPriceList::on_btnOpenFileDialog_pressed()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Import Pricelist"), ".",
                                                    tr("Comma separated values files (*.csv)"));
    if (!filename.isEmpty())
    {
        ui->txtfilename->setText(filename);
        openFile();
    }
}

void dlgImportPriceList::openFile()
{
    csv = new CSVReader(ui->txtfilename->text(), ui->chkHeadersOnFirstRow->checkState() == Qt::Checked,
                  ui->txtRecordSeparator->text().at(0), ui->txtStringDelimiter->text().at(0), this);
    csv->readCSVFile();
    ui->lblRecordCount->setText(tr("Record count: %1. Filtered: %2").arg(csv->getRecordCount()).arg(csv->getRecordCount(filter)));
    filter->clear();
    for (int i = 0; i < csv->getFieldCount(); i++)
    {
        filter->push_back("");
    }
    fillData();
}

void dlgImportPriceList::fillData()
{
    ui->treeCSV->setColumnCount(0);
    ui->treeCSV->clear();
    int fieldCount = csv->getFieldCount();
    ui->treeCSV->setColumnCount(fieldCount);
    QStringList labels;
    for (int i = 0; i < fieldCount; i++)
    {
        boost::shared_ptr<QStringList> headers = csv->getHeaders();


        QString label = (ui->chkHeadersOnFirstRow->checkState() == Qt::Checked) ?
                    headers->at(i) : QString::number(i);

        if (fieldMapping[i] != "")
            label += "-> " + fieldMapping[i];

        labels << label;
    }
    ui->treeCSV->setHeaderLabels(labels);

    for (int i = 0; i < fieldCount; i++)
    {
        ui->treeCSV->setColumnWidth(i, ui->treeCSV->width() / fieldCount);
    }

    boost::shared_ptr<QList<QStringList> > records = csv->getRecords(filter);
    int recordCount = 0;
    foreach(QStringList record, *records)
    {
        QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeCSV);
        for (int i = 0; i < record.count(); i++)
            item->setText(i, record.at(i));
        ui->treeCSV->insertTopLevelItem(ui->treeCSV->topLevelItemCount(), item);
        recordCount++;
    }
}

void dlgImportPriceList::on_chkHeadersOnFirstRow_stateChanged(int)
{
    if (ui->txtfilename->text().size() > 0)
    {
        csv->setHeaderOnFirstRow(ui->chkHeadersOnFirstRow->checkState() == Qt::Checked);
        fillData();
        ui->lblRecordCount->setText(tr("Record count: %1. Filtered: %2").arg(csv->getRecordCount()).arg(csv->getRecordCount(filter)));
    }
}

void dlgImportPriceList::addToMenu(QMenu * menu, QString text)
{
    QAction *action = new QAction(menu);
    action->setText(text);
    menu->addAction(action);
}

void dlgImportPriceList::on_treeCSV_customContextMenuRequested(const QPoint &pos)
{
    QMenu *menu = new QMenu(this);

    if (ui->txtfilename->text().size() > 0)
    {
        addToMenu(menu, SalesName);
        addToMenu(menu, PriceLabel);
        addToMenu(menu, ElementLabel);
        addToMenu(menu, SalesUnitLabel);
        addToMenu(menu, RatioLabel);
        addToMenu(menu, BrandLabel);
        addToMenu(menu, NotesLabel);
        menu->addSeparator();
        addToMenu(menu, RemoveMappingLabel);
        menu->addSeparator();
        addToMenu(menu, addToFilterLabel);
        addToMenu(menu, removeFromFilter);
        connect (menu, SIGNAL(triggered(QAction*)), this, SLOT(mapField(QAction*)));
        columnSelected = ui->treeCSV->columnAt(pos.x());
    }

    menu->exec(ui->treeCSV->mapToGlobal(pos));
    delete menu;
}

void dlgImportPriceList::mapField(QAction* action)
{
    if (action->text() == RemoveMappingLabel)
    {
        fieldMapping[columnSelected] = "";
        if (columnSelected == SalesNameColumn)
            SalesNameColumn = -1;
    }
    else if (action->text() == addToFilterLabel)
    {
        filter->removeAt(columnSelected);
        filter->insert(columnSelected, ui->treeCSV->currentItem()->text(columnSelected));
        ui->lblRecordCount->setText(tr("Record count: %1. Filtered: %2").arg(csv->getRecordCount()).arg(csv->getRecordCount(filter)));
    }
    else if (action->text() == removeFromFilter)
    {
        filter->removeAt(columnSelected);
        filter->insert(columnSelected, "");
        ui->lblRecordCount->setText(tr("Record count: %1. Filtered: %2").arg(csv->getRecordCount()).arg(csv->getRecordCount(filter)));
    }
    else // mapping
    {
        fieldMapping[columnSelected] = action->text();
        if (action->text() == SalesName)
            SalesNameColumn = columnSelected;
    }
    fillData();
}

void dlgImportPriceList::on_btnImport_pressed()
{
    listaPrecios::Proveedor *proveedor = DataStore::getInstance()->getProvidersList()->getProveedor(ui->txtProvider->text());
    listaPrecios::ListaPrecios *lista = proveedor->getListaPrecios(ui->txtPriceList->text());

    ui->progress->setVisible(true);

    ui->progress->setMaximum(csv->getRecordCount(filter));

    int i = 0;
    boost::shared_ptr<QList<QStringList> > records = csv->getRecords(filter);
    foreach (QStringList record, *records)
    {
        QString nombreEnLista = record[SalesNameColumn].simplified();
        listaPrecios::Precio *precio = lista->getPrecio(nombreEnLista);
        if ((precio == NULL) || (precio->getNombreElemento() == ""))
        {
            // Precio nuevo
            precio = new listaPrecios::Precio(lista);
            precio->setNombreEnListaPrecios(record[SalesNameColumn].simplified());
            if (getRecordValue(record, ElementLabel) != "")
                precio->setNombreElemento(getRecordValue(record, ElementLabel));
            // Aca hay que abrir un dlg para completar los campos faltantes
            actualizarPrecio(record, precio);
            if (editPriceListItem(precio))
                lista->addPrecio(precio);
        }
        else
        {
            actualizarPrecio(record, precio);
        }
        i++;
        ui->progress->setValue(i);
    }
    DataStore::getInstance()->getMaterialLibrary()->save();
    DataStore::getInstance()->getProvidersList()->save();
    accept();
}

bool dlgImportPriceList::editPriceListItem(listaPrecios::Precio *precio)
{
    bool res = false;
    dlgPriceItem dlg(this);
    dlg.setData(precio);

    if (dlg.exec() == QDialog::Accepted)
    {
        precio->setMarca(dlg.getMarca());
        precio->setPrecio(dlg.getPrecio());
        precio->setNombreElemento(dlg.getElemento());
        precio->setObservaciones(dlg.getObservaciones());
        precio->setUnidadVenta(DataStore::getInstance()->getUnitsLibrary()->getUnit(dlg.getUnidadVenta()));
        precio->setRelacion(dlg.getRelacion());
        precio->setFraccionable(dlg.Divisible());
        res = true;
    }
    return res;
}

QString dlgImportPriceList::getRecordValue(QStringList record, QString Field)
{
    QString value = "";
    foreach (int pos, fieldMapping.keys())
    {
        if (fieldMapping[pos] == Field)
        {
            value += record[pos] + " ";
        }
    }
    return value.simplified();
}


void dlgImportPriceList::actualizarPrecio(QStringList record, listaPrecios::Precio *precio)
{

    precio->setPrecio(getRecordValue(record, PriceLabel).toDouble());
    if (getRecordValue(record, ElementLabel) != "")
        precio->setNombreElemento(getRecordValue(record, ElementLabel));
    precio->setSalesUnitBrand(getRecordValue(record, SalesUnitLabel));
    precio->setRelacion(getRecordValue(record, RatioLabel).toDouble());
    precio->setMarca(getRecordValue(record, BrandLabel));
    precio->setObservaciones(getRecordValue(record, NotesLabel));
}
