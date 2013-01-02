#ifndef XMLHELPER_H
#define XMLHELPER_H

#include <QString>
#include <QXmlStreamReader>
#include "xmlnode.h"

class XMLHelper
{
public:
    static xml::XMLNode_ptr readXML(QString filename);
    static bool saveXMLTree(QString &filename, xml::XMLNode_ptr tree);

private:
    XMLHelper();
    static xml::XMLNode_ptr readXML(QXmlStreamReader &stream);
    static xml::XMLNode_ptr readXMLNode(QXmlStreamReader::TokenType token, QXmlStreamReader &stream);
};

#endif // XMLHELPER_H
