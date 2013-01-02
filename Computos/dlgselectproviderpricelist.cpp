#include "dlgselectproviderpricelist.h"
#include "ui_dlgselectproviderpricelist.h"
#include "datastore.h"
#include <boost/shared_ptr.hpp>

dlgSelectProviderPriceList::dlgSelectProviderPriceList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgSelectProviderPriceList)
{
    ui->setupUi(this);
    loadProviders();
}

dlgSelectProviderPriceList::~dlgSelectProviderPriceList()
{
    delete ui;
}

QString dlgSelectProviderPriceList::Provider()
{
    return ui->cboProviders->currentText();
}

QString dlgSelectProviderPriceList::PriceList()
{
    return ui->cboPriceLists->currentText();
}

void dlgSelectProviderPriceList::on_cboProviders_currentIndexChanged(const QString &arg1)
{
    loadPriceLists(arg1);
}

void dlgSelectProviderPriceList::loadProviders()
{
    ui->cboProviders->clear();
    boost::shared_ptr<QStringList> proveedores = DataStore::getInstance()->getProvidersList()->getAllProveedores();
    foreach(QString provider, *proveedores)
    {
        ui->cboProviders->addItem(provider);
    }
}

void dlgSelectProviderPriceList::loadPriceLists(QString provider)
{
    ui->cboPriceLists->clear();
    listaPrecios::Proveedor *proveedor = DataStore::getInstance()->getProvidersList()->getProveedor(provider);
    if (proveedor != NULL)
    {
        boost::shared_ptr<QStringList> listas = proveedor->getActiveListaPrecios();
        foreach(QString lista, *listas)
        {
            ui->cboPriceLists->addItem(lista);
        }
    }
}
