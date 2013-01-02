#include "superficietrapecial.h"
#include "dlgsuperficietrapecial.h"
#include "xmlhelper.h"

namespace cantidades {

SuperficieTrapecial::SuperficieTrapecial(QObject *parent) :
    Cantidad(dimension::SURFACE, "Trapecial Surface", tr("Trapecial Surface"), ":/dlg/dock/TrapecialArea", parent)
{
    longitud = 1.0;
    h1 = 1.0;
    h2 = 1.0;
}

SuperficieTrapecial::~SuperficieTrapecial()
{
}

double SuperficieTrapecial::getValue()
{
    return longitud * (h1 + h2) / 2;
}

QString SuperficieTrapecial::getFormula()
{
    return tr("L * (h1 + h2) / 2");
}

void SuperficieTrapecial::showInputDataDialogBox()
{
    dlgSuperficieTrapecial dlg;
    dlg.setLargo(longitud);
    dlg.setAlto1(h1);
    dlg.setAlto2(h2);
    dlg.setFormula(getFormula());
    if (dlg.exec() == QDialog::Accepted)
    {
        longitud = dlg.getLargo();
        h1 = dlg.getAlto1();
        h2 = dlg.getAlto2();
    }
}


void SuperficieTrapecial::setLargo(double value)
{
    longitud = value;
}

void SuperficieTrapecial::setAlto1(double value)
{
    h1 = value;
}

void SuperficieTrapecial::setAlto2(double value)
{
    h2 = value;
}

double SuperficieTrapecial::getLargo()
{
    return longitud;
}

double SuperficieTrapecial::getAlto1()
{
    return h1;
}

double SuperficieTrapecial::getAlto2()
{
    return h2;
}

QString SuperficieTrapecial::getDimensions()
{
    return "L=" + QString::number(longitud) + ", h1=" + QString::number(h1)
            + "h2=" + QString::number(h2);
}

QDataStream &SuperficieTrapecial::save(QDataStream &stream) const
{
    stream << longitud;
    stream << h1;
    stream << h2;

    return stream;
}

QDataStream &SuperficieTrapecial::load(QDataStream &stream)
{
    stream >> longitud;
    stream >> h1;
    stream >> h2;

    return stream;
}

bool SuperficieTrapecial::loadDataFromXMLTree(xml::XMLNode_ptr tree)
{
    longitud = tree->getChildValue("length", true).toDouble();
    h1 = tree->getChildValue("height1", true).toDouble();
    h2 = tree->getChildValue("height2", true).toDouble();
    return true;
}

void SuperficieTrapecial::dataToXMLTree(xml::XMLNode_ptr node)
{
    node->addAttribute("length", QString::number(longitud));
    node->addAttribute("height1", QString::number(h1));
    node->addAttribute("height2", QString::number(h2));
}

}
