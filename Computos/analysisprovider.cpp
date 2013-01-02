#include "analysisprovider.h"
#include "datastore.h"
#include "proveedor.h"

namespace computo
{
namespace analysis
{

AnalysisProvider::AnalysisProvider(QString elemento, double cantidadCalculada, QString proveedor, QObject *parent) :
    QObject(parent), nombreElemento(elemento), nombreProveedor(proveedor)
{
    listaPrecios::Proveedor *p = DataStore::getInstance()->getProvidersList()->getProveedor(proveedor);
    foreach (QString listaPrecios, *p->getActiveListaPrecios())
    {
        listaPrecios::ListaPrecios *lp = p->getListaPrecios(listaPrecios);
        if (lp->provides(elemento))
        {
            AnalysisPriceList *apl = new AnalysisPriceList(elemento, cantidadCalculada, proveedor, listaPrecios, this);
            listas[listaPrecios] = apl;
        }
    }
}

boost::shared_ptr<QStringList> AnalysisProvider::getListas()
{
    boost::shared_ptr<QStringList> res(new QStringList());
    foreach (QString lista, listas.keys())
    {
        res->push_back(lista);
    }
    return res;
}

AnalysisPriceList *AnalysisProvider::getLista(QString nombreLista)
{
    return listas[nombreLista];
}

void AnalysisProvider::compute()
{
    foreach(AnalysisPriceList* lista, listas)
    {
        lista->compute();
    }
}

void AnalysisProvider::clearSelectedPrices()
{
    foreach (AnalysisPriceList *lista, listas)
    {
        lista->clearSelectedPrices();
    }
}

void AnalysisProvider::setSelectedPrice(QString nombreLista, QString nombreElemento)
{
    listas[nombreLista]->setSelectedPrice(nombreElemento);
}

void AnalysisProvider::findBestPrice(QString &Lista, QString &NombrePrecio, double &Precio)
{
    QString mejorLista("");
    QString mejorNombrePrecio("");
    double mejorPrecio = 1e308;

    QString _NombrePrecio("");
    double _Precio = 1e308;

    foreach (QString nombreLista, listas.keys())
    {
        AnalysisPriceList *lista = listas[nombreLista];
        lista->findBestPrice(_NombrePrecio, _Precio);
        if (_Precio < mejorPrecio)
        {
            mejorLista = nombreLista;
            mejorNombrePrecio = _NombrePrecio;
            mejorPrecio = _Precio;
        }
    }
    Lista = mejorLista;
    NombrePrecio = mejorNombrePrecio;
    Precio = mejorPrecio;
}

}}
