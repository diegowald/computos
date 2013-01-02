#include "superficiepoligonal.h"
#include "dlgsuperficiepoligonal.h"

namespace cantidades {

SuperficiePoligonal::SuperficiePoligonal(QObject *parent) :
    Cantidad(dimension::SURFACE, "Polygonal Surface",tr("Polygonal Surface"), ":/dlg/dock/PolygonalArea", parent)
{
    coordinates.clear();
    area = 0;
    areaCalculada = false;
}

SuperficiePoligonal::~SuperficiePoligonal()
{
}

double SuperficiePoligonal::getValue()
{
    if (areaCalculada)
        return area;
    if (coordinates.size() < 3)
        return 0;

    POINT_2D ptFirst = coordinates[0];
    POINT_2D ptAnt = coordinates[0];
    area = 0;

    for (int i = 1; i < coordinates.size(); i++)
    {
        POINT_2D pt = coordinates[i];
        area += (pt.y + ptAnt.y) * (pt.x - ptAnt.x);
        ptAnt = pt;
    }
    area += (ptAnt.y + ptFirst.y) * (ptAnt.x - ptFirst.x);
    area /= 2.0;
    areaCalculada = true;
    return area;
}

QString SuperficiePoligonal::getFormula()
{
    return tr("See \"http://www.mathopenref.com/coordpolygonarea2.html\"");
}

void SuperficiePoligonal::showInputDataDialogBox()
{
    dlgSuperficiePoligonal dlg;
    dlg.setCoordinates(coordinates);
    dlg.setFormula(getFormula());
    if (dlg.exec() == QDialog::Accepted)
    {
        coordinates = dlg.Coordinates();
        areaCalculada = false;
    }
}

QString SuperficiePoligonal::getDimensions()
{
    return "...";
}

QDataStream &SuperficiePoligonal::save(QDataStream &stream) const
{
    stream << coordinates.size();
    for (int i = 0; i < coordinates.size(); i++)
    {
        stream << coordinates[i].x;
        stream << coordinates[i].y;
    }

    return stream;
}

QDataStream &SuperficiePoligonal::load(QDataStream &stream)
{
    int coordsCount = 0;
    stream >> coordsCount;

    for (int i = 0; i < coordsCount; i++)
    {
        POINT_2D pt;
        stream >> pt.x;
        stream >> pt.y;

        coordinates.push_back(pt);
    }
    areaCalculada = false;
    return stream;
}

void SuperficiePoligonal::dataToXMLTree(xml::XMLNode_ptr node)
{
    xml::XMLNode_ptr pts(new xml::XMLNode("points"));
    node->addChild(pts);

    pts->addAttribute("count", QString::number(coordinates.size()));

    for (int i = 0; i < coordinates.size(); i++)
    {
        xml::XMLNode_ptr pt(new xml::XMLNode("point"));
        pts->addChild(pt);
        pt->addAttribute("x", QString::number(coordinates[i].x));
        pt->addAttribute("y", QString::number(coordinates[i].y));
    }
}

bool SuperficiePoligonal::loadDataFromXMLTree(xml::XMLNode_ptr tree)
{
    int numPoints = tree->getChildValue("count", true).toInt();

    for (int i = 1; i <= numPoints; i++)
    {
        POINT_2D pt;
        xml::XMLNode_ptr p = tree->getChildNode(i, true);
        pt.x = p->getChildValue("x", true).toDouble();
        pt.y = p->getChildValue("y", true).toDouble();
        coordinates.push_back(pt);
    }
    return true;
}

} // namespace
