#include "unit.h"

namespace unidades {


Unit::Unit(QObject *parent) :
    QObject(parent)
{
}

Unit::~Unit()
{
}

dimension::DIMENSION Unit::Dimension() const
{
    return dimension;
}

void Unit::Dimension(dimension::DIMENSION newDimension)
{
    dimension = newDimension;
}

QString Unit::getInternalName() const
{
    return internalname;
}

void Unit::setInternalName(QString newName)
{
    internalname = newName;
}

QString Unit::getDescription() const
{
    return description;
}

void Unit::setDescription(QString newDescription)
{
    description = newDescription;
}

QString Unit::getDisplayName() const
{
    return displayName;
}

void Unit::setDisplayName(QString newDisplayName)
{
    displayName = newDisplayName;
}


}
