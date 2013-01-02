#ifndef UNIT_H
#define UNIT_H

#include <QObject>
#include "Dimension.h"

namespace unidades {


class Unit : public QObject
{
    Q_OBJECT
public:
    explicit Unit(QObject *parent = 0);
    virtual ~Unit();
    
    dimension::DIMENSION Dimension() const;
    void Dimension(dimension::DIMENSION newDimension);

    QString getInternalName() const;
    void setInternalName(QString newName);

    QString getDisplayName() const;
    void setDisplayName(QString newDisplayName);

    QString getDescription() const;
    void setDescription(QString newDescription);
private:
    dimension::DIMENSION dimension;
    QString internalname;
    QString displayName;
    QString description;

signals:
    
public slots:
    
};
}
#endif // UNIT_H
