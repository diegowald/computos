#include "elementoconstructivo.h"
#include "datastore.h"
#include "xmlhelper.h"

namespace proyecto {

QString ElementoConstructivo::PART_TAG = "part";
QString ElementoConstructivo::NAME_TAG = "name";
QString ElementoConstructivo::ELEMENT_TAG = "element";


ElementoConstructivo::ElementoConstructivo(QObject *parent) :
    QObject(parent)
{
    cantidad = NULL;
}

ElementoConstructivo::~ElementoConstructivo()
{
}

cantidades::Cantidad *ElementoConstructivo::getCantidad()
{
    return cantidad;
}

void ElementoConstructivo::setCantidad(cantidades::Cantidad *newCantidad)
{
    if (cantidad != NULL)
        delete cantidad;
    cantidad = newCantidad;
}


materialLibrary::Elemento *ElementoConstructivo::getElemento()
{
    return elemento;
}

void ElementoConstructivo::setElemento(materialLibrary::Elemento *newElemento)
{
    elemento = newElemento;
}

QString ElementoConstructivo::getName()
{
    return name;
}

void ElementoConstructivo::setName(QString &newName)
{
    name = newName;
}

QDataStream &operator <<(QDataStream &stream, proyecto::ElementoConstructivo &e)
{
    stream << e.getName();
    stream << e.getCantidad()->getimmutableName();
    stream << *e.getCantidad();
    stream << e.getElemento()->getName();

    return stream;
}

QDataStream &operator >>(QDataStream &stream, proyecto::ElementoConstructivo &e)
{
    QString aux;
    stream >> aux;
    e.setName(aux);
    QString nombreCantidad = "";
    stream >> nombreCantidad;
    cantidades::Cantidad *c = DataStore::getInstance()->getCantidadesLibrary()->createCantidad(nombreCantidad);
    e.setCantidad(c);
    stream >> *c;
    QString nombreElemento = "";
    stream >> nombreElemento;
    e.setElemento(DataStore::getInstance()->getMaterialLibrary()->getElemento(nombreElemento));

    return stream;
}

xml::XMLNode_ptr ElementoConstructivo::toXMLTree()
{
    xml::XMLNode_ptr node(new xml::XMLNode(PART_TAG));
    node->addAttribute(NAME_TAG, getName());
    node->addChild(cantidad->toXMLTree());
    node->addAttribute(ELEMENT_TAG, getElemento()->getName());
    return node;
}

bool ElementoConstructivo::loadFromXMLTree(xml::XMLNode_ptr tree)
{
    name = tree->getChildValue(NAME_TAG, true);
    xml::XMLNode_ptr cant = tree->getChildNode(cantidades::Cantidad::CANT_TAG, true);
    cantidad = DataStore::getInstance()->getCantidadesLibrary()->createCantidad(
                cant->getChildValue(cantidades::Cantidad::NAME_TAG, true));
    cantidad->loadFromXMLTree(cant);
    setElemento(DataStore::getInstance()->getMaterialLibrary()->getElemento(
                    tree->getChildValue(ELEMENT_TAG, true)));
    return true;
}

}
