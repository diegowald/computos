#include "pdfredlining.h"


namespace pdf
{
QString PDFRedLining::PDF_TAG = "pdf";
QString PDFRedLining::NAME_TAG = "name";
QString PDFRedLining::REDLINES_TAG = "annotations";
QString PDFRedLining::COUNT_TAG = "count";

PDFRedLining::PDFRedLining(QObject *parent) :
    QObject(parent)
{
    filename = "";
}

PDFRedLining::PDFRedLining(QString FileName, QObject *parent) :
    QObject(parent), filename(FileName)
{
}

QString PDFRedLining::name() const
{
    return filename;
}

QList<Redline> PDFRedLining::getRedlines()
{
    QList<Redline> res;
    foreach(RedLineElement *e, redlines.values())
    {
        res.push_back(e->asRedline());
    }
    return res;
}

void PDFRedLining::addRedline(Redline redline)
{
    RedLineElement *element = new RedLineElement(redline, this);
    redlines[element->name()] = element;
}

bool PDFRedLining::loadFromXMLTree(xml::XMLNode_ptr tree)
{
    filename = tree->getChildValue(NAME_TAG, true);

    xml::XMLNode_ptr xmlredlines = tree->getChildNode(REDLINES_TAG, true);
    int count = xmlredlines->getChildValue(COUNT_TAG, true).toInt();
    for (int i = 1; i <= count; i++)
    {
        RedLineElement *el = new RedLineElement(this);
        el->loadFromXMLTree(xmlredlines->getChildNode(i, true));
        redlines[el->name()] = el;
    }
    return true;
}

xml::XMLNode_ptr PDFRedLining::toXMLTree()
{
    xml::XMLNode_ptr node(new xml::XMLNode(PDF_TAG));
    node->addAttribute(NAME_TAG, name());
    xml::XMLNode_ptr xmlredlines(new xml::XMLNode(REDLINES_TAG));
    node->addChild(xmlredlines);

    xmlredlines->addAttribute(COUNT_TAG, QString::number(redlines.count()));
    foreach(QString redline, redlines.keys())
    {
        xmlredlines->addChild(redlines[redline]->toXMLTree());
    }
    return node;
}

}
