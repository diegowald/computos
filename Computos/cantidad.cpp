#include "cantidad.h"

namespace cantidades {

QString Cantidad::CANT_TAG = "quantity";
QString Cantidad::NAME_TAG = "name";


Cantidad::Cantidad(dimension::DIMENSION dim, QString ImmutableName, QString cantName, QString Shape, QObject *parent) :
    QObject(parent), _dimension(dim), immutableName(ImmutableName), name(cantName), shape(Shape)
{
}

Cantidad::~Cantidad()
{

}

QString Cantidad::getName() const
{
    return name;
}

QString Cantidad::getimmutableName() const
{
    return immutableName;
}

QString Cantidad::getShape() const
{
    return shape;
}

dimension::DIMENSION Cantidad::getDimension() const
{
    return _dimension;
}

bool Cantidad::loadFromXMLTree(xml::XMLNode_ptr tree)
{
    return loadDataFromXMLTree(tree);
}

xml::XMLNode_ptr Cantidad::toXMLTree()
{
    xml::XMLNode_ptr node(new xml::XMLNode(CANT_TAG));

    node->addAttribute(NAME_TAG, immutableName);
    dataToXMLTree(node);

    return node;
}

}
