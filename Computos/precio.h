#ifndef PRECIO_H
#define PRECIO_H

#include <QObject>
#include "unit.h"
#include "xmlnode.h"

namespace listaPrecios
{

class Precio : public QObject
{
    Q_OBJECT
public:
    explicit Precio(QObject *parent = 0);

    double getPrecio();
    void setPrecio(double newValue);

    double calcularPrecio(double cantidad);
    double calcularCantidadAComprar(double cantidadCalculada);

    QString getNombreElemento();
    void setNombreElemento(QString newNombre);

    unidades::Unit *getUnidadVenta();
    void setUnidadVenta(unidades::Unit *newCantidad);

    double Relacion(); // Cantidad definida en elemento que entran en 1 unidad de Venta.
    void setRelacion(double newRelacion); // Cantidad definida en elemento que entran en 1 unidad de Venta.

    QString Marca();
    void setMarca(QString newMarca);

    QString Observaciones();
    void setObservaciones(QString newObservacion);

    bool esFraccionable();
    void setFraccionable(bool newValue);

    QString NombreEnListaPrecios();
    void setNombreEnListaPrecios(QString newValue);


    void setSalesUnitBrand(QString newValue);
    QString SalesUnitBrand();

    xml::XMLNode_ptr toXMLTree();
    bool loadFromXMLTree(xml::XMLNode_ptr tree);

    friend QDataStream &operator <<(QDataStream &stream, Precio &p);
    friend QDataStream &operator >>(QDataStream &stream, Precio &p);

signals:
    
public slots:
    
private:
    double precio;
    QString nombreEnListaPrecios;
    QString nombreElemento;
    unidades::Unit *unidadVenta;
    QString nombreUnidadVentaSegunProveedor;
    double relacion; // Cantidad definida en elemento que entran en 1 unidad de Venta.
    // Ejemplo: Cemento: se emplea por kg,. pero se compra en bolsa de 50Kg.

    QString marca;
    QString observaciones;
    bool fraccionable;
};

}
#endif // PRECIO_H
