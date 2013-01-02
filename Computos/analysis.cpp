#include "analysis.h"
#include "datastore.h"
#include <boost/shared_ptr.hpp>

namespace computo
{
namespace analysis
{

Analysis::Analysis(QString projectName, QObject *parent) :
    QObject(parent), name(projectName)
{
}

void Analysis::compute()
{
    analysisElements.clear();
    computo::ComputoMetrico *c = DataStore::getInstance()->getComputo(name);
    boost::shared_ptr<QMap<QString, double> > resumen = c->getResumenMateriasPrimas();
    foreach (QString nombreElemento, resumen->keys())
    {
        AnalysisElement *ae = new AnalysisElement(nombreElemento, (*resumen)[nombreElemento], this);
        ae->compute();
        analysisElements[nombreElemento] = ae;
    }
}

boost::shared_ptr<QStringList> Analysis::getProvidersNames(QString nombreElemento)
{
    boost::shared_ptr<QStringList> res(new QStringList());
    if (analysisElements.find(nombreElemento) != analysisElements.end())
    {
        AnalysisElement *ae = analysisElements[nombreElemento];
        res = ae->getProvidersNames();
    }
    return res;
}

double Analysis::getTotalCost()
{
    double cost = 0;
    foreach (AnalysisElement *e, analysisElements)
    {
        cost += e->getBestPrice();
    }
    return cost;
}

AnalysisProvider *Analysis::getProvider(QString nombreElemento, QString provider)
{
    return analysisElements[nombreElemento]->getProvider(provider);
}

void Analysis::setSelectedPrice(QString nombreElemento, QString nombreProveedor, QString nombreLista, QString nombrePrecio)
{
    clearSelectedPrices(nombreElemento);
    if ((nombreElemento.size() >0) && (nombreProveedor.size() >0)
            && (nombreLista.size() >0) && (nombrePrecio.size() > 0))
    {
        // Aca se setea el precio del elemento.
        analysisElements[nombreElemento]->setSelectedPrice(nombreProveedor, nombreLista, nombrePrecio);
    }
    else
    {
        // Aca se obtiene el mejor precio
        findBestPrice(nombreElemento);
    }
}

void Analysis::clearSelectedPrices(QString nombreElemento)
{
    if (nombreElemento.size() > 0)
        analysisElements[nombreElemento]->clearSelectedPrices();
    else
    {
        foreach (AnalysisElement* ae, analysisElements.values())
        {
            ae->clearSelectedPrices();
        }
    }
}

void Analysis::findBestPrice(QString nombreElemento)
{
    if (nombreElemento.size() > 0)
        analysisElements[nombreElemento]->findBestPrice();
    else
    {
        foreach (AnalysisElement* ae, analysisElements.values())
        {
            ae->findBestPrice();
        }
    }
}

}}
