#include "rectangularsurface.h"
#include "dlgrectangularsurface.h"

namespace cantidades {

RectangularSurface::RectangularSurface(QObject *parent) :
    SuperficieTrapecial(parent)
{
    _dimension = dimension::SURFACE;
    name = tr("Rectangular Surface");
    longitud = 1.0;
    h1 = 1.0;
    h2 = 1.0;
    shape = ":/dlg/dock/rectangularArea";
}

RectangularSurface::~RectangularSurface()
{
}

void RectangularSurface::showInputDataDialogBox()
{
    dlgRectangularSurface dlg;
    dlg.setLargo(longitud);
    dlg.setAlto(h1);
    dlg.setFormula(getFormula());
    if (dlg.exec() == QDialog::Accepted)
    {
        longitud = dlg.getLargo();
        h1 = dlg.getAlto();
        h2 = h1;
    }
}

QString RectangularSurface::getDimensions()
{
    return "L=" + QString::number(longitud) +
            ", H=" + QString::number(h1);
}

}
