#include "author.h"
#include "xmlhelper.h"

QString Author::AUTHOR_TAG = "author";
QString Author::NAME_TAG = "name";
QString Author::EMAIL_TAG = "email";

Author::Author(QObject *parent) :
    QObject(parent)
{
    name = "";
    email = "";
}

Author::~Author()
{
}

QString Author::Name()
{
    return name;
}

void Author::setName(QString newValue)
{
    name = newValue;
}

QString Author::EMail()
{
    return email;
}

void Author::setEMail(QString newEMail)
{
    email = newEMail;
}

bool Author::loadFromXMLTree(xml::XMLNode_ptr tree)
{
    name = tree->getChildValue(NAME_TAG, true);
    email = tree->getChildValue(EMAIL_TAG, true);
    return true;
}

xml::XMLNode_ptr Author::toXMLTree()
{
    xml::XMLNode_ptr node(new xml::XMLNode(AUTHOR_TAG));

    node->addAttribute(NAME_TAG, name);
    node->addAttribute(EMAIL_TAG, email);

    return node;
}
