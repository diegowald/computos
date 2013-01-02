#include "perimetrocircular.h"
#include <math.h>
#include "xmlhelper.h"

namespace cantidades
{

PerimetroCircular::PerimetroCircular(QObject *parent) :
    Cantidad(dimension::LINEAR, "Circular Perimeter", tr("Circular Perimeter"), ":/dlg/dock/areaCircular", parent)
{
    value = 0;
}
PerimetroCircular::~PerimetroCircular()
{
}

double PerimetroCircular::getValue()
{
    return M_PI * value * 2.0;
}

QString PerimetroCircular::getFormula()
{
    return tr("pi * radius * 2.0");
}

void PerimetroCircular::showInputDataDialogBox()
{
    //dlg.setFormula(getFormula());
}

QString PerimetroCircular::getDimensions()
{
    return "r=" + QString::number(value);
}

QDataStream &PerimetroCircular::save(QDataStream &stream) const
{
    stream << value;

    return stream;
}

QDataStream &PerimetroCircular::load(QDataStream &stream)
{
    stream >> value;

    return stream;
}

void PerimetroCircular::dataToXMLTree(xml::XMLNode_ptr node)
{
    node->addAttribute("value", QString::number(value));
}

bool PerimetroCircular::loadDataFromXMLTree(xml::XMLNode_ptr tree)
{
    value = tree->getChildValue("value", true).toDouble();
    return true;
}

}
