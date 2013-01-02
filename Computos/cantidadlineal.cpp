#include "cantidadlineal.h"
#include "dlgcantidadlineal.h"
#include "xmlhelper.h"

namespace cantidades {


CantidadLineal::CantidadLineal(QObject *parent) :
    Cantidad(dimension::LINEAR, "Linear Quantity", tr("Linear Quantity"), ":/dlg/dock/lineal", parent)
{
}

CantidadLineal::~CantidadLineal()
{

}

double CantidadLineal::getValue()
{
    return value;
}

QString CantidadLineal::getFormula()
{
    return "";
}

void CantidadLineal::showInputDataDialogBox()
{
    dlgCantidadLineal dlg;
    dlg.setLongitud(value);
    dlg.setFormula(getFormula());
    if (dlg.exec() == QDialog::Accepted)
    {
        value = dlg.getLongitud();
    }
}

QString CantidadLineal::getDimensions()
{
    return "";
}

QDataStream &CantidadLineal::save(QDataStream &stream) const
{
    stream << value;

    return stream;
}

QDataStream &CantidadLineal::load(QDataStream &stream)
{
    stream >> value;

    return stream;
}

void CantidadLineal::dataToXMLTree(xml::XMLNode_ptr node)
{
    node->addAttribute("value", QString::number(value));
}

bool CantidadLineal::loadDataFromXMLTree(xml::XMLNode_ptr tree)
{
    value = tree->getChildValue("value", true).toDouble();
    return true;
}

}
