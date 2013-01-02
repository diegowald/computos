#include "circularsurface.h"
#include <math.h>
#include "dlgcircularsurface.h"
#include "xmlhelper.h"

namespace cantidades {
CircularSurface::CircularSurface(QObject *parent) :
    Cantidad(dimension::SURFACE, "Circular Surface", tr("CircularSurface"), ":/dlg/dock/areaCircular", parent)
{
    radius = 1.0;
}

CircularSurface::~CircularSurface()
{
}

double CircularSurface::getValue()
{
    return M_PI * radius * radius;
}

QString CircularSurface::getFormula()
{
    return tr("pi * radius * radius");
}

void CircularSurface::showInputDataDialogBox()
{
    dlgCircularSurface dlg;
    dlg.setRadius(radius);
    dlg.setFormula(getFormula());
    if (dlg.exec() == QDialog::Accepted)
    {
        radius = dlg.getRadius();
    }
}

QString CircularSurface::getDimensions()
{
    return "r=" + QString::number(radius);
}

QDataStream &CircularSurface::save(QDataStream &stream) const
{
    stream << radius;

    return stream;
}

QDataStream &CircularSurface::load(QDataStream &stream)
{
    stream >> radius;

    return stream;
}

void CircularSurface::dataToXMLTree(xml::XMLNode_ptr node)
{
    node->addAttribute("value", QString::number(radius));
}

bool CircularSurface::loadDataFromXMLTree(xml::XMLNode_ptr tree)
{
    radius = tree->getChildValue("value", true).toDouble();
    return true;
}

}
