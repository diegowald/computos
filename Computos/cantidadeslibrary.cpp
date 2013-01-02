#include "cantidadeslibrary.h"
#include "cantidadlineal.h"
#include "circularsurface.h"
#include "rectangularsurface.h"
#include "superficietrapecial.h"
#include "superficiepoligonal.h"
#include "cantidadunitaria.h"
#include "perimetrocircular.h"
#include "prismatrapecial.h"
#include "cilindro.h"
//#include "tiempo.h"
#include "rawvalue.h"

namespace cantidades {

CantidadesLibrary::CantidadesLibrary(QObject *parent) :
    QObject(parent)
{
    mapaCantidades[CantidadUnitaria().getimmutableName()] = CantidadUnitaria().getDimension();
    mapaCantidades[cantidades::DimensionLessValue().getimmutableName()] = DimensionLessValue().getDimension();

    mapaCantidades[CantidadLineal().getimmutableName()] = CantidadLineal().getDimension();
    mapaCantidades[PerimetroCircular().getimmutableName()] = PerimetroCircular().getDimension();
    mapaCantidades[LinearValue().getimmutableName()] = LinearValue().getDimension();

    mapaCantidades[CircularSurface().getimmutableName()] = CircularSurface().getDimension();
    mapaCantidades[RectangularSurface().getimmutableName()] = RectangularSurface().getDimension();
    mapaCantidades[SuperficieTrapecial().getimmutableName()] = SuperficieTrapecial().getDimension();
    mapaCantidades[SuperficiePoligonal().getimmutableName()] = SuperficiePoligonal().getDimension();
    mapaCantidades[SurfaceValue().getimmutableName()] = SurfaceValue().getDimension();

    mapaCantidades[PrismaTrapecial().getimmutableName()] = PrismaTrapecial().getDimension();
    mapaCantidades[Cilindro().getimmutableName()] = Cilindro().getDimension();
    mapaCantidades[VolumeValue().getimmutableName()] = VolumeValue().getDimension();

    //mapaCantidades[Tiempo().getimmutableName()] = Tiempo().getDimension();
    mapaCantidades[TimeValue().getimmutableName()] = TimeValue().getDimension();

}

CantidadesLibrary::~CantidadesLibrary()
{
}

cantidades::Cantidad *CantidadesLibrary::createCantidad(QString name)
{
    if (name == CantidadUnitaria().getimmutableName())
        return new CantidadUnitaria(this);
    else if (name == CantidadLineal().getimmutableName())
        return new CantidadLineal(this);
    else if (name == PerimetroCircular().getimmutableName())
        return new PerimetroCircular(this);
    else if (name == CircularSurface().getimmutableName())
        return new CircularSurface(this);
    else if (name == RectangularSurface().getimmutableName())
        return new RectangularSurface(this);
    else if (name == SuperficieTrapecial().getimmutableName())
        return new SuperficieTrapecial(this);
    else if (name == SuperficiePoligonal().getimmutableName())
        return new SuperficiePoligonal(this);
    else if (name == PrismaTrapecial().getimmutableName())
        return new PrismaTrapecial(this);
    else if (name == Cilindro().getimmutableName())
        return new Cilindro(this);
    /*else if (name == Tiempo().getimmutableName())
        return new Tiempo(this);*/
    else if (name == DimensionLessValue().getimmutableName())
        return new DimensionLessValue(this);
    else if (name == LinearValue().getimmutableName())
        return new LinearValue(this);
    else if (name == SurfaceValue().getimmutableName())
        return new SurfaceValue(this);
    else if (name == VolumeValue().getimmutableName())
        return new VolumeValue(this);
    else if (name == TimeValue().getimmutableName())
        return new TimeValue(this);

    return NULL;
}

boost::shared_ptr<QStringList> CantidadesLibrary::getAllNames()
{
    boost::shared_ptr<QStringList> lista(new QStringList());

    foreach (QString nombre, mapaCantidades.keys())
    {
        lista.get()->push_back(nombre);
    }
    return lista;
}

boost::shared_ptr<QStringList>  CantidadesLibrary::getAllNames(dimension::DIMENSION dimensionFilter)
{
    boost::shared_ptr<QStringList> lista(new QStringList());
    foreach (QString nombre, mapaCantidades.keys())
    {
        if (mapaCantidades[nombre] == dimensionFilter)
            lista->push_back(nombre);
    }
    return lista;
}

}
