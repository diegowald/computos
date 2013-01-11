#include "redline.h"

namespace pdf
{

QString RedLineElement::REDLINE_TAG = "annotation";
QString RedLineElement::NAME_TAG = "name";
QString RedLineElement::PAGENUMBER_TAG = "page";
QString RedLineElement::LEFT_TAG = "left";
QString RedLineElement::TOP_TAG = "top";
QString RedLineElement::RIGHT_TAG = "right";
QString RedLineElement::BOTTOM_TAG = "bottom";
QString RedLineElement::AUTHOR_TAG = "author";
QString RedLineElement::REF_TAG = "reference";
QString RedLineElement::ALPHA_TAG = "alpha";
QString RedLineElement::RED_TAG = "red";
QString RedLineElement::GREEN_TAG = "green";
QString RedLineElement::BLUE_TAG = "blue";
QString RedLineElement::IMAGE_TAG = "image";

RedLineElement::RedLineElement(QObject *parent) :
    QObject(parent)
{
}

Redline RedLineElement::asRedline()
{
    return  pdfRedline;
}

QString RedLineElement::name()
{
    return pdfRedline.name;
}

bool RedLineElement::loadFromXMLTree(xml::XMLNode_ptr tree)
{
    pdfRedline.name = tree->getChildValue(NAME_TAG, true);
    pdfRedline.pageNumber = tree->getChildValue(PAGENUMBER_TAG, true).toInt();
    pdfRedline.rect.setLeft(tree->getChildValue(LEFT_TAG, true).toFloat());
    pdfRedline.rect.setTop(tree->getChildValue(TOP_TAG, true).toFloat());
    pdfRedline.rect.setRight(tree->getChildValue(RIGHT_TAG, true).toFloat());
    pdfRedline.rect.setBottom(tree->getChildValue(BOTTOM_TAG, true).toFloat());
    pdfRedline.author = tree->getChildValue(AUTHOR_TAG, true);
    pdfRedline.elementReference = tree->getChildValue(REF_TAG, true);
    pdfRedline.color.setAlpha(tree->getChildValue(ALPHA_TAG, true).toInt());
    pdfRedline.color.setRed(tree->getChildValue(RED_TAG, true).toInt());
    pdfRedline.color.setGreen(tree->getChildValue(GREEN_TAG, true).toInt());
    pdfRedline.color.setBlue(tree->getChildValue(BLUE_TAG, true).toInt());

/*    QString img = tree->getChildValue(IMAGE_TAG, true);
    QByteArray ba;
    ba.fromRawData(img.data());
    QDataStream ds;
    ds << ba;
    ds >> pdfRedline.image;*/

    return true;
}

xml::XMLNode_ptr RedLineElement::toXMLTree()
{
    xml::XMLNode_ptr node(new xml::XMLNode(REDLINE_TAG));

    node->addAttribute(NAME_TAG, pdfRedline.name);
    node->addAttribute(PAGENUMBER_TAG, QString::number(pdfRedline.pageNumber));
    node->addAttribute(LEFT_TAG, QString::number(pdfRedline.rect.left()));
    node->addAttribute(TOP_TAG, QString::number(pdfRedline.rect.top()));
    node->addAttribute(RIGHT_TAG, QString::number(pdfRedline.rect.right()));
    node->addAttribute(BOTTOM_TAG, QString::number(pdfRedline.rect.bottom()));
    node->addAttribute(AUTHOR_TAG, pdfRedline.author);
    node->addAttribute(REF_TAG, pdfRedline.elementReference);
    node->addAttribute(ALPHA_TAG, QString::number(pdfRedline.color.alpha()));
    node->addAttribute(RED_TAG, QString::number(pdfRedline.color.red()));
    node->addAttribute(GREEN_TAG, QString::number(pdfRedline.color.green()));
    node->addAttribute(BLUE_TAG, QString::number(pdfRedline.color.blue()));



/*    QDataStream ds;
    ds << pdfRedline.image;
    QByteArray ba;
    ds >> ba;
    node->addAttribute(IMAGE_TAG, ba.data());
    ba.toHex();*/

    return node;
}


}
