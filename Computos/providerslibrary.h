#ifndef PROVIDERSLIBRARY_H
#define PROVIDERSLIBRARY_H

#include <QObject>
#include "proveedor.h"
#include "xmlnode.h"

namespace listaPrecios
{

class ProvidersLibrary : public QObject
{
    Q_OBJECT
public:
    explicit ProvidersLibrary(QObject *parent = 0);

    bool load();
    bool save();
    Proveedor *getProveedor(QString name);

    boost::shared_ptr<QStringList> getAllProveedores();
    boost::shared_ptr<QStringList> getProveedores(QString elementFilter);

    void addProveedor(Proveedor *newProveedor);

    void deleteProveedor(QString nombre);

private:
    bool loadFromStream();
    bool loadFromXML();
    bool loadFromXMLTree(xml::XMLNode_ptr tree);

    bool saveAsStream();
    bool saveAsXML();
    xml::XMLNode_ptr toXMLTree();

signals:
    
public slots:
    
private:
    QMap<QString, Proveedor*> proveedores;
    QString _filename;
    QString _extension;
    static QString objectName;
    static QString objectVersion;
};

}
#endif // PROVIDERSLIBRARY_H
