#include "cilindro.h"
#include <math.h>

namespace cantidades
{

Cilindro::Cilindro(QObject *parent) :
    Cantidad(dimension::VOLUME, "Cilinder", tr("Cilinder"), ":/dlg/dock/lineal", parent)
{
    radius = 0.0;
    height = 0.0;
}

Cilindro::~Cilindro()
{
}

double Cilindro::getValue()
{
    return M_PI * radius * radius * height;
}

QString Cilindro::getFormula()
{
    return tr("pi * radius * radius * height");
}

void Cilindro::showInputDataDialogBox()
{
    //dlg.setFormula(getFormula());
}

QString Cilindro::getDimensions()
{
    return "r=" + QString::number(radius) +
            ", h=" + QString::number(height);
}

QDataStream &Cilindro::save(QDataStream &stream) const
{
    stream << radius;
    stream << height;

    return stream;
}

QDataStream &Cilindro::load(QDataStream &stream)
{
    stream >> radius;
    stream >> height;

    return stream;
}

void Cilindro::dataToXMLTree(xml::XMLNode_ptr node)
{
    node->addAttribute("radius", QString::number(radius));
    node->addAttribute("height", QString::number(height));
}

bool Cilindro::loadDataFromXMLTree(xml::XMLNode_ptr tree)
{
    radius = tree->getChildValue("radius", true).toDouble();
    height = tree->getChildValue("height", true).toDouble();
    return true;
}

}
