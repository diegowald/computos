#include "elementocomputo.h"

namespace computo {

ElementoComputo::ElementoComputo(QObject *parent, proyecto::ElementoConstructivo *refElementoConstructivo) :
    QObject(parent)
{
    elementoConstructivo = refElementoConstructivo;
    elemento = refElementoConstructivo->getElemento();
    elementos = new QList<ComponenteElementoComputo*>();
    if (elemento->esCompuesto())
    {
        foreach(materialLibrary::ComponenteElemento *componente, *elemento->getComponentes())
        {
            ElementoComputo *ec = new ElementoComputo(this, componente->getElemento());
            ComponenteElementoComputo *e = new ComponenteElementoComputo(this, ec, componente);
            elementos->push_back(e);
       }
    }
    //tags.clear();
}

ElementoComputo::ElementoComputo(QObject *parent, materialLibrary::Elemento *refElemento) :
    QObject(parent)
{
    elementoConstructivo = NULL;
    elemento = refElemento;
    elementos = new QList<ComponenteElementoComputo*>();
    if (elemento->esCompuesto())
    {
        foreach(materialLibrary::ComponenteElemento *componente, *elemento->getComponentes())
        {
            ElementoComputo *ec = new ElementoComputo(this, componente->getElemento());
            ComponenteElementoComputo *e = new ComponenteElementoComputo(this, ec, componente);
            elementos->push_back(e);
        }
    }
    //tags.clear();
}

ElementoComputo::~ElementoComputo()
{
}

proyecto::ElementoConstructivo *ElementoComputo::getElementoConstructivo()
{
    return elementoConstructivo;
}

materialLibrary::Elemento *ElementoComputo::getElemento()
{
    return elemento;
}

void ElementoComputo::Compute()
{
    Compute(elementoConstructivo->getCantidad()->getValue());
}

void ElementoComputo::Compute(double cantidadAComputar)
{
    cantidad = cantidadAComputar;
    foreach(ComponenteElementoComputo* elemento, *elementos)
    {
        elemento->Compute(cantidad);
    }
}

double ElementoComputo::getCantidad()
{
    return cantidad;
}

QList<ComponenteElementoComputo *> *ElementoComputo::getComponentes()
{
    return elementos;
}

/*void ElementoComputo::AddComponente(materialLibrary::Elemento *newElemento, double cantidad)
{
}*/

bool ElementoComputo::esCompuesto() const // Devuelve true si el elemento esta compuesto por otros materiales.
{
    return elementos->size() > 0;
}

QMap<QString, double> *ElementoComputo::getResumenMateriales()
{
    QMap<QString, double> *resultado = new QMap<QString, double>();
    if (esCompuesto())
    {
        foreach(ComponenteElementoComputo* componente, *elementos)
        {
            QMap<QString, double> *materiales = componente->getElemento()->getResumenMateriales();

            foreach(QString material, materiales->keys())
            {
                double cantidad = 0;
                if (resultado->contains(material))
                    cantidad = (*resultado)[material];
                (*resultado)[material] = cantidad + (*materiales)[material];
            }
        }
    }
    else
    {
        (*resultado)[getElemento()->getName()] = getCantidad();
    }
    return resultado;
}

ComponenteElementoComputo::ComponenteElementoComputo(QObject *parent,
                                                     ElementoComputo *elementoRelacionado,
                                                     materialLibrary::ComponenteElemento* refComponenteElemento) :
    QObject(parent)
{
    ComponenteElementoBase = refComponenteElemento;
    ElementoBase = elementoRelacionado;
}

ComponenteElementoComputo::~ComponenteElementoComputo()
{
}

ElementoComputo *ComponenteElementoComputo::getElemento() const
{
    return ElementoBase;
}

materialLibrary::ComponenteElemento* ComponenteElementoComputo::getComponente()
{
    return ComponenteElementoBase;
}

void ComponenteElementoComputo::Compute(double cantidadAComputar)
{
    getElemento()->Compute(cantidadAComputar * ComponenteElementoBase->getCantidad());
}

}
