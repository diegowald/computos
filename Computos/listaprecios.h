#ifndef LISTAPRECIOS_H
#define LISTAPRECIOS_H

#include <QObject>
#include <QDateTime>
#include <QMultiMap>
#include <boost/shared_ptr.hpp>
#include <QStringList>
#include "precio.h"
#include "xmlnode.h"

/** Esta clase es la que define el "header" de la lista de precios
 *  Contiene una referencia a la empresa que provee la lista de precios.
 *  Contiene la fecha de vigencia de la misma
 *  Contiene un map a los elementos de la lista de precios.
 */

namespace listaPrecios
{


class ListaPrecios : public QObject
{
    Q_OBJECT
public:
    explicit ListaPrecios(QObject *parent = 0);
    
    /** Dado un elemento, se obtiene el mejor precio de esta lista */
    Precio *getMejorPrecio(QString elemento, double cantidad);
    Precio *getPrecio(QString elemento, QString marca);
    Precio *getPrecio(QString nombrePrecioSegunProveedor);
    boost::shared_ptr<QList<Precio *> > getTodosPrecios(QString elemento);

    boost::shared_ptr<QStringList> getTodosElementos();

    void addPrecio(Precio* precio);
    void deletePriceItem(QString elemento, QString marca);
    bool provides(QString elemento);

    QDateTime Vigencia();
    void setVigencia(QDateTime value);

    QString Name();
    void setName(QString newName);

    xml::XMLNode_ptr toXMLTree();
    bool loadFromXMLTree(xml::XMLNode_ptr tree);

    friend QDataStream &operator <<(QDataStream &stream, ListaPrecios &p);
    friend QDataStream &operator >>(QDataStream &stream, ListaPrecios &p);

signals:
    
public slots:

private:
    QString name;
    QDateTime vigenciaDesde;
    QMultiMap<QString, Precio*> lista;
    QMap <QString, Precio*> listaPorNombreProveedor;

};

}
#endif // LISTAPRECIOS_H
