#include "cantidadunitaria.h"
#include "dlgcantidadlineal.h"
#include "xmlhelper.h"

namespace cantidades {

CantidadUnitaria::CantidadUnitaria(QObject *parent) :
    Cantidad(dimension::DIMENSIONLESS, "Unit Quantity", tr("Unit Quantity"), ":/dlg/dock/lineal", parent)
{
}

CantidadUnitaria::~CantidadUnitaria()
{
}

double CantidadUnitaria::getValue()
{
    return value;
}

QString CantidadUnitaria::getFormula()
{
    return "";
}

void CantidadUnitaria::showInputDataDialogBox()
{
    dlgCantidadLineal dlg;
    dlg.setLongitud(value);
    dlg.setFormula(getFormula());
    if (dlg.exec() == QDialog::Accepted)
    {
        value = dlg.getLongitud();
    }
}

QString CantidadUnitaria::getDimensions()
{
    return "";
}

QDataStream &CantidadUnitaria::save(QDataStream &stream) const
{
    stream << value;

    return stream;
}

QDataStream &CantidadUnitaria::load(QDataStream &stream)
{
    stream >> value;

    return stream;
}

void CantidadUnitaria::dataToXMLTree(xml::XMLNode_ptr node)
{
    node->addAttribute("value", QString::number(value));
}

bool CantidadUnitaria::loadDataFromXMLTree(xml::XMLNode_ptr tree)
{
    value = tree->getChildValue("value", true).toDouble();
    return true;
}

}

