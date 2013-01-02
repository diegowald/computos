#include "precio.h"
#include "datastore.h"
#include <math.h>

namespace listaPrecios
{

Precio::Precio(QObject *parent) :
    QObject(parent)
{
    precio = 0.0;
    nombreEnListaPrecios = "";
    nombreElemento = "";
    unidadVenta = NULL;
    nombreUnidadVentaSegunProveedor = "";
    relacion = 0.0; // Cantidad definida en elemento que entran en 1 unidad de Venta.
    // Ejemplo: Cemento: se emplea por kg,. pero se compra en bolsa de 50Kg.

    marca = "";
    observaciones = "";
    fraccionable = false;
}

double Precio::getPrecio()
{
    return precio;
}

void Precio::setPrecio(double newValue)
{
    precio = newValue;
}

QString Precio::getNombreElemento()
{
    return nombreElemento;
}

void Precio::setNombreElemento(QString newNombre)
{
    nombreElemento = newNombre;
}

unidades::Unit *Precio::getUnidadVenta()
{
    return unidadVenta;
}

void Precio::setUnidadVenta(unidades::Unit *newCantidad)
{
    unidadVenta = newCantidad;
}

double Precio::Relacion()
{
    return relacion;
}

void Precio::setRelacion(double newRelacion)
{
    relacion = newRelacion;
}

QString Precio::Marca()
{
    return marca;
}

void Precio::setMarca(QString newMarca)
{
    marca = newMarca;
}

QString Precio::Observaciones()
{
    return observaciones;
}

void Precio::setObservaciones(QString newObservacion)
{
    observaciones = newObservacion;
}

bool Precio::esFraccionable()
{
    return fraccionable;
}

void Precio::setFraccionable(bool newValue)
{
    fraccionable = newValue;
}

double Precio::calcularCantidadAComprar(double cantidadCalculada)
{
    double cantidadAComprar = cantidadCalculada / relacion;
    if (!fraccionable)
        cantidadAComprar = floor(cantidadAComprar) + 1.0;
    return cantidadAComprar;
}

double Precio::calcularPrecio(double cantidad)
{
    return calcularCantidadAComprar(cantidad) * precio;
}

QString Precio::NombreEnListaPrecios()
{
    return nombreEnListaPrecios;
}

void Precio::setNombreEnListaPrecios(QString newValue)
{
    nombreEnListaPrecios = newValue;
}

void Precio::setSalesUnitBrand(QString newValue)
{
    nombreUnidadVentaSegunProveedor = newValue;
}

QString Precio::SalesUnitBrand()
{
    return nombreUnidadVentaSegunProveedor;
}

xml::XMLNode_ptr Precio::toXMLTree()
{
    xml::XMLNode_ptr tree(new xml::XMLNode("price"));

    tree->addAttribute("ammount", QString::number(precio));
    tree->addAttribute("name", nombreElemento);
    tree->addAttribute("pricelist_name", nombreEnListaPrecios);
    tree->addAttribute("sales_unit", unidadVenta->getInternalName());
    tree->addAttribute("provider_sales_unit", nombreUnidadVentaSegunProveedor);
    tree->addAttribute("ratio", QString::number(relacion));
    tree->addAttribute("brand", marca);
    tree->addAttribute("notes", observaciones);
    tree->addAttribute("divisible", fraccionable ? "yes" : "no");

    return tree;
}

bool Precio::loadFromXMLTree(xml::XMLNode_ptr tree)
{
    precio = tree->getChildValue("ammount", true).toDouble();
    nombreElemento = tree->getChildValue("name", true);
    nombreEnListaPrecios = tree->getChildValue("pricelist_name", true);
    unidadVenta = DataStore::getInstance()->getUnitsLibrary()->getUnit(tree->getChildValue("sales_unit", true));
    nombreUnidadVentaSegunProveedor = tree->getChildValue("provider_sales_unit", true);
    relacion = tree->getChildValue("ratio", true).toDouble();
    marca = tree->getChildValue("brand", true);
    observaciones = tree->getChildValue("notes", true);
    fraccionable = (tree->getChildValue("divisible", true) == "yes");

    return true;
}

QDataStream &operator <<(QDataStream &stream, Precio &p)
{
    if (&p == NULL)
        return stream;

    stream << p.precio;
    stream << p.nombreElemento;
    stream << p.nombreEnListaPrecios;
    stream << p.unidadVenta->getInternalName();
    stream << p.nombreUnidadVentaSegunProveedor;
    stream << p.relacion;
    stream << p.marca;
    stream << p.observaciones;
    stream << p.fraccionable;
    return stream;
}

QDataStream &operator >>(QDataStream &stream, Precio &p)
{
    if (&p == NULL)
        return stream;

    stream >> p.precio;
    stream >> p.nombreElemento;
    stream >> p.nombreEnListaPrecios;
    QString aux = "";
    stream >> aux;
    p.unidadVenta = DataStore::getInstance()->getUnitsLibrary()->getUnit(aux);
    stream >> p.nombreUnidadVentaSegunProveedor;
    stream >> p.relacion;
    stream >> p.marca;
    stream >> p.observaciones;
    stream >> p.fraccionable;

    return stream;
}

}
