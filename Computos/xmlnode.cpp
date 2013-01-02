#include "xmlnode.h"
#include "xmlkeynotfoundexception.h"

namespace xml
{

XMLNode_ptr XMLNode::createNode(QString Name, QObject *parent)
{
    return XMLNode_ptr(new XMLNode(Name, parent));
}

XMLNode::XMLNode(QString Name, QObject *parent) :
    QObject(parent), name(Name), value("")
{
    children.clear();
}

XMLNode::XMLNode(QString Name, QString Value, QObject *parent):
    QObject(parent), name(Name), value(Value)
{
}


XMLNode::~XMLNode()
{
}

QString XMLNode::Name()
{
    return name;
}

QString XMLNode::Value()
{
    return value;
}

void XMLNode::setValue(QString newValue)
{
    value = newValue;
}

QString XMLNode::getChildValue(QString key, bool mandatory, QString defaultValue)
{
    try
    {
        XMLNode_ptr node = getChildNode(key, true);
        return node->Value();
    }
    catch (xml::XMLKeyNotFoundException *ex)
    {
        if (mandatory)
            throw;
        return defaultValue;
    }
}

XMLNode_ptr XMLNode::getChildNode(int index, bool mandatory)
{
    if ((index < 0) || (index >= children.size()))
    {
        if (mandatory)
            throw new xml::XMLKeyNotFoundException();
        else
            return XMLNode_ptr();
    }
    return children[index];
}

XMLNode_ptr XMLNode::getChildNode(QString key, bool mandatory)
{
    for (int i = 0; i < children.size(); i++)
    {
        if (children[i]->Name() == key)
            return children[i];
    }
    // Nothing found
    if (mandatory)
        throw new xml::XMLKeyNotFoundException();

    return XMLNode_ptr();
}

void XMLNode::addChild(XMLNode_ptr child)
{
    child->setParent(this);
    children.push_back(child);
}

bool XMLNode::saveIntoXML(QXmlStreamWriter &stream)
{


    if (children.size() > 0)
    {
        stream.writeStartElement(name);
        foreach(XMLNode_ptr node, children)
        {
            node->saveIntoXML(stream);
        }
        stream.writeEndElement();

    }
    else
    {
        stream.writeTextElement(name, value);
    }

    return true;
}

void XMLNode::addAttribute(QString attrName, QString attrValue)
{
    XMLNode_ptr node(new XMLNode(attrName, attrValue, this));
    addChild(node);
}

}
