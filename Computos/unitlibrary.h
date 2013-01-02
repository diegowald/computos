#ifndef UNITLIBRARY_H
#define UNITLIBRARY_H

#include <QObject>
#include <QMap>
#include <QStringList>
#include <boost/shared_ptr.hpp>
#include "unit.h"

namespace unidades {
class UnitLibrary : public QObject
{
    Q_OBJECT
public:
    explicit UnitLibrary(QObject *parent = 0);
    virtual ~UnitLibrary();

    Unit *getUnit(QString name);
    boost::shared_ptr<QStringList> getAllInternalNames();

    boost::shared_ptr<QStringList> getAllInternalNames(dimension::DIMENSION dimensionFilter);

    void addUnit(QString UnitName, QString displayName, QString description, dimension::DIMENSION unitDimension);

private:
    QMap<QString, Unit*> unidades;

signals:
    
public slots:
    
};
}
#endif // UNITLIBRARY_H
