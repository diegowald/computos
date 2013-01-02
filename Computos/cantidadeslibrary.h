#ifndef CANTIDADESLIBRARY_H
#define CANTIDADESLIBRARY_H

#include <boost/shared_ptr.hpp>
#include <QObject>
#include <QMap>
#include <QStringList>

#include "cantidad.h"

namespace cantidades {

class CantidadesLibrary : public QObject
{
    Q_OBJECT
public:
    explicit CantidadesLibrary(QObject *parent = 0);
    virtual ~CantidadesLibrary();
    
    cantidades::Cantidad *createCantidad(QString name);
    boost::shared_ptr<QStringList> getAllNames();
    boost::shared_ptr<QStringList> getAllNames(dimension::DIMENSION dimensionFilter);
signals:
    
public slots:
    
private:
    QMap<QString, dimension::DIMENSION> mapaCantidades;
};

}
#endif // CANTIDADESLIBRARY_H
