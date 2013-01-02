#include "wndpricelist.h"
#include "ui_wndpricelist.h"
#include "datastore.h"
#include <QMenu>
#include "dlgpriceitem.h"
#include <QMessageBox>
#include "htmlhelper.h"

wndPriceList::wndPriceList(QWidget *parent) :
    PrintableWindow(parent),
    ui(new Ui::wndPriceList)
{
    ui->setupUi(this);
    ui->lblPriceList->clear();
    ui->lblProvider->clear();
}

wndPriceList::~wndPriceList()
{
    delete ui;
}

void wndPriceList::setProvider(QString providerName)
{
    ui->lblProvider->setText(providerName);
}

void wndPriceList::setPriceList(QString priceListName)
{
    ui->lblPriceList->setText(priceListName);
    loadPricelist();
}

void wndPriceList::clearPriceList()
{
    ui->treePriceList->clear();
}

void wndPriceList::loadPricelist()
{
    clearPriceList();
    listaPrecios::Proveedor *proveedor =
            DataStore::getInstance()->getProvidersList()->getProveedor(
                ui->lblProvider->text());
    listaPrecios::ListaPrecios *lista = proveedor->getListaPrecios(ui->lblPriceList->text());
    boost::shared_ptr<QStringList> elementos = lista->getTodosElementos();
    foreach(QString elemento, *elementos)
    {
        if (elemento.size() > 0)
        {
            QTreeWidgetItem *item = new QTreeWidgetItem(ui->treePriceList);
            item->setText(0, elemento);
            ui->treePriceList->insertTopLevelItem(0, item);
            boost::shared_ptr<QList<listaPrecios::Precio *> > precios = lista->getTodosPrecios(elemento);
            foreach(listaPrecios::Precio *precio, *precios)
            {
                QTreeWidgetItem *subitem = new QTreeWidgetItem(item);
                subitem->setText(0, precio->Marca());
                subitem->setText(1, QString::number(precio->getPrecio()));
                subitem->setText(2, QString::number(precio->Relacion()));
                subitem->setText(3, DataStore::getInstance()->getMaterialLibrary()->getElemento(elemento)->getMeasureUnit()->getDisplayName());
                subitem->setText(4, precio->getUnidadVenta()->getDisplayName());
                //item->insertChild(0, subitem);
            }
        }
    }
}

void wndPriceList::on_treePriceList_customContextMenuRequested(const QPoint &pos)
{
    QMenu *menu = new QMenu(this);

    menu->addAction(ui->actionAdd_Price_Item);
    if (ui->treePriceList->selectedItems().size() > 0)
        menu->addAction(ui->actionRemove_Price_Item);

    menu->exec(ui->treePriceList->mapToGlobal(pos));
}

void wndPriceList::on_actionAdd_Price_Item_triggered()
{
    editPriceItem("", "");
}

void wndPriceList::on_actionRemove_Price_Item_triggered()
{
    if (ui->treePriceList->selectedItems().size() > 0)
    {
        if (ui->treePriceList->selectedItems().at(0)->parent() != NULL)
        {
            QString marca = ui->treePriceList->selectedItems().at(0)->text(0);
            QString elemento = ui->treePriceList->selectedItems().at(0)->parent()->text(0);
            listaPrecios::ListaPrecios *lp =
                    DataStore::getInstance()->getProvidersList()->getProveedor(
                        ui->lblProvider->text())->getListaPrecios(
                        ui->lblPriceList->text());
            if (lp != NULL)
            {
                int r = QMessageBox::question(this,
                                              tr("Delete price item"),
                                              tr("Are you sure you are going to delete"
                                                 " %1 - %2?").arg(elemento, marca),
                                              QMessageBox::Yes,
                                              QMessageBox::No | QMessageBox::Default | QMessageBox::Cancel);
                if (r == QMessageBox::Yes)
                {
                    lp->deletePriceItem(elemento, marca);
                    DataStore::getInstance()->getProvidersList()->save();
                    loadPricelist();
                }
            }
        }
    }
}

void wndPriceList::editPriceItem(QString elemento, QString marca)
{
    listaPrecios::ListaPrecios *lp =
            DataStore::getInstance()->getProvidersList()->getProveedor(
                ui->lblProvider->text())->getListaPrecios(
                ui->lblPriceList->text());

    if (lp != NULL)
    {
        dlgPriceItem dlg(this);
        dlg.setElementoYMarca(lp, elemento, marca);

        if (dlg.exec() == QDialog::Accepted)
        {
            listaPrecios::Precio *precio  = NULL;
            if (marca.size() == 0)
                precio = new listaPrecios::Precio(lp);
            else
                precio = lp->getPrecio(elemento, marca);
            precio->setMarca(dlg.getMarca());
            precio->setPrecio(dlg.getPrecio());
            precio->setNombreElemento(dlg.getElemento());
            precio->setObservaciones(dlg.getObservaciones());
            precio->setUnidadVenta(DataStore::getInstance()->getUnitsLibrary()->getUnit(dlg.getUnidadVenta()));
            precio->setRelacion(dlg.getRelacion());
            precio->setFraccionable(dlg.Divisible());
            if (marca.size() == 0)
                lp->addPrecio(precio);
            DataStore::getInstance()->getProvidersList()->save();
            loadPricelist();
        }
    }
}

void wndPriceList::on_treePriceList_doubleClicked(const QModelIndex &)
{
    if (ui->treePriceList->selectedItems().size() > 0)
    {
        QTreeWidgetItem *item = ui->treePriceList->selectedItems().at(0);
        if (item->parent() == NULL)
        {
            // this is a root element
            return;
        }
        QString marca = item->text(0);
        QString elemento = item->parent()->text(0);
        editPriceItem(elemento, marca);
    }
}

QString wndPriceList::getHtmlContents()
{
    return HtmlHelper::toHtml(tr("Price List"), ui->treePriceList, true);
}
