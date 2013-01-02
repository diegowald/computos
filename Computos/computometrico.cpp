#include "computometrico.h"

namespace computo {


ComputoMetrico::ComputoMetrico(QObject *parent, proyecto::Proyecto *proyectoAsignado,
                               bool doAutomaticCalculations)
    : QObject(parent)
{
    proyecto = proyectoAsignado;
    automaticCalculations = doAutomaticCalculations;
    resumenComputoMateriasPrimas.clear();
    if (automaticCalculations)
    {
        // Aca hay que conectar las señales que emite el proyecto
        // con los slots del computo metrico.
    }
}

ComputoMetrico::~ComputoMetrico()
{
}

void ComputoMetrico::Compute()
{
    if (!automaticCalculations)
    {
        elementosComputo.clear();
        resumenComputoMateriasPrimas.clear();
        foreach(QString nombre, *proyecto->getAllElementoConstructivoNames())
        {
            elementosComputo[nombre] =
                    new ElementoComputo(this,
                                        proyecto->getElementoConstructivo(nombre));
            elementosComputo[nombre]->Compute();
            addToResumenMateriasPrimas(elementosComputo[nombre]);
        }
    }
}

void ComputoMetrico::addToResumenMateriasPrimas(ElementoComputo *elementoComputo)
{
    QMap<QString, double> *materiales = elementoComputo->getResumenMateriales();

    foreach(QString material, materiales->keys())
    {
        double cantidad = 0;
        if (resumenComputoMateriasPrimas.contains(material))
            cantidad = resumenComputoMateriasPrimas[material];
        resumenComputoMateriasPrimas[material] = cantidad + (*materiales)[material];
    }
}

boost::shared_ptr<QStringList> ComputoMetrico::getElementosComputoNames()
{
    boost::shared_ptr<QStringList> names(new QStringList());

    foreach(QString name, elementosComputo.keys())
    {
        names->push_back(name);
    }

    return names;
}

ElementoComputo *ComputoMetrico::getElementoComputo(QString &name)
{
    return elementosComputo[name];
}

boost::shared_ptr<QMap<QString, double> > ComputoMetrico::getResumenMateriasPrimas()
{
    boost::shared_ptr<QMap<QString, double> > aux(new QMap<QString, double>(resumenComputoMateriasPrimas));
    return aux;
}

}
