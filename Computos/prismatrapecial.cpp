#include "prismatrapecial.h"
#include "dlgprismavolume.h"
#include "xmlhelper.h"

namespace cantidades
{

PrismaTrapecial::PrismaTrapecial(QObject *parent) :
    Cantidad(dimension::VOLUME, "Prism", tr("Prism"), ":/dlg/dock/lineal", parent)
{
}

PrismaTrapecial::~PrismaTrapecial()
{
}

double PrismaTrapecial::getValue()
{
    return trapecio.getValue() * alto;
}

QString PrismaTrapecial::getFormula()
{
    return tr("(%1) * height").arg(trapecio.getFormula());
}

void PrismaTrapecial::showInputDataDialogBox()
{
    dlgPrismaVolume dlg;
    dlg.setLargo(trapecio.getLargo());
    dlg.setAlto1(trapecio.getAlto1());
    dlg.setAlto2(trapecio.getAlto2());
    dlg.setAltura(alto);
    dlg.setFormula(getFormula());
    if (dlg.exec() == QDialog::Accepted)
    {
        trapecio.setLargo(dlg.getLargo());
        trapecio.setAlto1(dlg.getAlto1());
        trapecio.setAlto2(dlg.getAlto2());
        alto = dlg.getAltura();
    }
}

QString PrismaTrapecial::getDimensions()
{
    return trapecio.getDimensions() + ", Height=" + QString::number(alto);
}


QDataStream &PrismaTrapecial::save(QDataStream &stream) const
{
    stream << trapecio;
    stream << alto;
    return stream;
}

QDataStream &PrismaTrapecial::load(QDataStream &stream)
{
    stream >> trapecio;
    stream >> alto;
    return stream;
}

void PrismaTrapecial::dataToXMLTree(xml::XMLNode_ptr node)
{
    node->addChild(trapecio.toXMLTree());
    node->addAttribute("height", QString::number(alto));
}

bool PrismaTrapecial::loadDataFromXMLTree(xml::XMLNode_ptr tree)
{
    trapecio.loadDataFromXMLTree(tree);
    alto = tree->getChildValue("value", true).toDouble();
    return true;
}

}
