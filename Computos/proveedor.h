#ifndef PROVEEDOR_H
#define PROVEEDOR_H

#include <QObject>
#include <QMap>
#include <QStringList>

#include <boost/shared_ptr.hpp>

#include "listaprecios.h"
#include "xmlnode.h"

namespace listaPrecios
{

class Proveedor : public QObject
{
    Q_OBJECT
public:
    explicit Proveedor(QObject *parent = 0);
    
    boost::shared_ptr<QStringList> getActiveListaPrecios();
    ListaPrecios *getListaPrecios(QString nombre);
    void addLista(ListaPrecios *newLista);
    void deleteLista(QString nombre);

    bool provides(QString element);

    QString Nombre();
    void setNombre(QString value);

    QString Address();
    void setAddress(QString value);

    QString ContactName();
    void setContactName(QString value);

    QString Telephone();
    void setTelephone(QString value);

    QString EMail();
    void setEMail(QString value);

    xml::XMLNode_ptr toXMLTree();
    bool loadFromXMLTree(xml::XMLNode_ptr tree);

    friend QDataStream &operator <<(QDataStream &stream, Proveedor &p);
    friend QDataStream &operator >>(QDataStream &stream, Proveedor &p);
signals:
    
public slots:
    
private:
    QString nombre;
    QString address;
    QString contactName;
    QString telephone;
    QString email;
    QMap<QString, ListaPrecios*> listasProveedor;

};

}
#endif // PROVEEDOR_H
