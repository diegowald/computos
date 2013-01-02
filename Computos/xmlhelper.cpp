#include "xmlhelper.h"
#include "QFile"

XMLHelper::XMLHelper()
{
}

xml::XMLNode_ptr XMLHelper::readXML(QString filename)
{
    xml::XMLNode_ptr res(new xml::XMLNode(""));
    QFile f(filename);
    if (!f.open(QIODevice::ReadOnly))
        return res;

    QXmlStreamReader stream(&f);
    //res->addChild(readXML(stream).get());
    while (!stream.atEnd())
    {
        QXmlStreamReader::TokenType token = stream.readNext();
        if (token == QXmlStreamReader::StartElement)
            return readXMLNode(token, stream);
    }
    return res;
}

xml::XMLNode_ptr XMLHelper::readXML(QXmlStreamReader &stream)
{
    xml::XMLNode_ptr node;
    while (!stream.atEnd())
    {
        QXmlStreamReader::TokenType token = stream.readNext();
        QString name = stream.name().toString();
        switch (token)
        {
        case QXmlStreamReader::StartElement:
        {
            node = xml::XMLNode_ptr(new xml::XMLNode(name));
            if (stream.attributes().size() > 0)
            {
                for (int i = 0; i < stream.attributes().size(); i++)
                {
                    QXmlStreamAttribute attr = stream.attributes().at(i);
                    xml::XMLNode_ptr value(new xml::XMLNode(attr.name().toString(),
                                                                           attr.value().toString(), node.get()));
                    node->addChild(value);
                }
            }
            break;
        }
        case QXmlStreamReader::EndElement:
            if (stream.name().toString().compare(node->Name(), Qt::CaseInsensitive) == 0)
                return node;
            /*else
                throw new boost::exception();*/
            break;
        case QXmlStreamReader::Characters:
            node->setValue(stream.text().toString());
            break;
        default:
            break;
        }
    }
    return node;
}

xml::XMLNode_ptr XMLHelper::readXMLNode(QXmlStreamReader::TokenType token, QXmlStreamReader &stream)
{
    xml::XMLNode_ptr node(new xml::XMLNode(stream.name().toString()));
    QXmlStreamReader::TokenType tt = token;
    if (stream.attributes().size() > 0)
    {
        for (int i = 0; i < stream.attributes().size(); i++)
        {
            QXmlStreamAttribute attr = stream.attributes().at(i);
            xml::XMLNode_ptr value(new xml::XMLNode(attr.name().toString(),
                                                                   attr.value().toString(), node.get()));
            node->addChild(value);
        }
    }
    while (!stream.atEnd())
    {
        tt = stream.readNext();
        switch (tt)
        {
        case QXmlStreamReader::StartElement:
            node->addChild(readXMLNode(tt, stream));
            break;
        case QXmlStreamReader::EndElement:
            if (stream.name().toString().compare(node->Name(), Qt::CaseInsensitive) == 0)
                return node;
            /*else
                throw new boost::exception();*/
            break;
        case QXmlStreamReader::Characters:
            node->setValue(stream.text().toString());
            break;
        default:
            break;
        }

    }
    return node;
}

bool XMLHelper::saveXMLTree(QString &filename, xml::XMLNode_ptr tree)
{
    QFile f(filename);
    if (!f.open(QIODevice::WriteOnly))
        return false;

    QXmlStreamWriter stream(&f);

    stream.setAutoFormatting(true);
    stream.setAutoFormattingIndent(2);
    stream.writeStartDocument();

    bool res = tree->saveIntoXML(stream);

    stream.writeEndDocument();
    return res;
}
