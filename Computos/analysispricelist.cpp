#include "analysispricelist.h"
#include "datastore.h"
#include "proveedor.h"
#include "listaprecios.h"

namespace computo
{
namespace analysis
{

AnalysisPriceList::AnalysisPriceList(QString elemento, double cantidadCalculada, QString proveedor, QString NombrelistaPrecios, QObject *parent) :
    QObject(parent), nombreElemento(elemento), nombreListaPrecios(NombrelistaPrecios)
{
    listaPrecios::Proveedor *p = DataStore::getInstance()->getProvidersList()->getProveedor(proveedor);
    listaPrecios::ListaPrecios *lp = p->getListaPrecios(nombreListaPrecios);


    boost::shared_ptr<QList<listaPrecios::Precio *> > listaDePrecios = lp->getTodosPrecios(nombreElemento);
    foreach (listaPrecios::Precio *p, *listaDePrecios)
    {
        AnalysisPriceItem *api = new AnalysisPriceItem(p, cantidadCalculada, this);
        precios[api->getBrand()] = api;
    }
}

boost::shared_ptr<QList<AnalysisPriceItem*> > AnalysisPriceList::getPrecios()
{
    boost::shared_ptr<QList<AnalysisPriceItem*> > res(new QList<AnalysisPriceItem*>());
    foreach (AnalysisPriceItem *api, precios)
    {
        res->push_back(api);
    }
    return res;
}

AnalysisPriceItem *AnalysisPriceList::getPrecio(QString nombrePrecio)
{
    return precios[nombrePrecio];
}

void AnalysisPriceList::compute()
{
    foreach (AnalysisPriceItem *precio, precios)
    {
        precio->compute();
    }
}

void AnalysisPriceList::clearSelectedPrices()
{
    foreach (AnalysisPriceItem *precio, precios)
    {
        precio->clearSelectedPrice();
    }
}

void AnalysisPriceList::setSelectedPrice(QString nombrePrecio)
{
    precios[nombrePrecio]->selectAsBestPrice();
}

void AnalysisPriceList::findBestPrice(QString &NombrePrecio, double &Precio)
{
    QString mejorNombrePrecio("");
    double mejorPrecio = 1e308;

    foreach (QString _NombrePrecio, precios.keys())
    {
        AnalysisPriceItem *precio = precios[_NombrePrecio];
        double _precio = precio->getPrice();
        if (_precio < mejorPrecio)
        {
            mejorNombrePrecio = _NombrePrecio;
            mejorPrecio = _precio;
        }
    }
    NombrePrecio = mejorNombrePrecio;
    Precio = mejorPrecio;
}

}}
