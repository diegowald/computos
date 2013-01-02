#include "analysiselement.h"
#include "datastore.h"

namespace computo
{
namespace analysis
{


AnalysisElement::AnalysisElement(QString nombreElemento, double cantidad, QObject *parent) :
    QObject(parent), elemento(nombreElemento), cantidadAComputar(cantidad), mejorProveedor(""),
    mejorLista(""), mejorNombrePrecio(""), mejorPrecio(1e308)

{
    boost::shared_ptr<QStringList> provs = DataStore::getInstance()->getProvidersList()->getProveedores(elemento);
    foreach (QString prov, *provs)
    {
        AnalysisProvider *provider = new AnalysisProvider(elemento, cantidad, prov, this);
        providers[prov] = provider;
    }
}

boost::shared_ptr<QStringList> AnalysisElement::getProvidersNames()
{
    boost::shared_ptr<QStringList> res(new QStringList());
    foreach (QString name, providers.keys())
    {
        res->push_back(name);
    }
    return res;
}

AnalysisProvider *AnalysisElement::getProvider(QString provider)
{
    return providers[provider];
}

void AnalysisElement::compute()
{
    foreach (AnalysisProvider *provider, providers.values())
    {
        provider->compute();
    }
}



void AnalysisElement::clearSelectedPrices()
{
    foreach (AnalysisProvider *provider, providers.values())
    {
        provider->clearSelectedPrices();
    }
}

void AnalysisElement::setSelectedPrice(QString nombreProveedor, QString nombreLista, QString nombrePrecio)
{
    providers[nombreProveedor]->setSelectedPrice(nombreLista, nombrePrecio);
}

void AnalysisElement::findBestPrice()
{
    mejorProveedor = "";
    mejorLista = "";
    mejorNombrePrecio = "";
    mejorPrecio = 1e308;

    QString Lista("");
    QString NombrePrecio("");
    double Precio = 1e308;

    foreach (QString Proveedor, providers.keys())
    {
        AnalysisProvider *provider = providers[Proveedor];
        provider->findBestPrice(Lista, NombrePrecio, Precio);
        if (Precio < mejorPrecio)
        {
            mejorProveedor = Proveedor;
            mejorLista = Lista;
            mejorNombrePrecio = NombrePrecio;
            mejorPrecio = Precio;
        }
    }

    providers[mejorProveedor]->setSelectedPrice(mejorLista, mejorNombrePrecio);
}

double AnalysisElement::getBestPrice()
{
    return mejorPrecio;
}

}}
