#include "unitlibrary.h"
namespace unidades {

UnitLibrary::UnitLibrary(QObject *parent) :
    QObject(parent)
{
    unidades.clear();
}

UnitLibrary::~UnitLibrary()
{
}

Unit *UnitLibrary::getUnit(QString internalName)
{
    return unidades[internalName];
}

boost::shared_ptr<QStringList> UnitLibrary::getAllInternalNames()
{
    boost::shared_ptr<QStringList> nombres(new QStringList());
    foreach(QString key, unidades.keys())
    {
        nombres->push_back(key);
    }
    return nombres;
}

boost::shared_ptr<QStringList> UnitLibrary::getAllInternalNames(dimension::DIMENSION dimensionFilter)
{
    boost::shared_ptr<QStringList> nombres(new QStringList());

    foreach(Unit *unit, unidades)
    {
        if (unit->Dimension() == dimensionFilter)
            nombres->push_back(unit->getInternalName());
    }

    return nombres;
}

void UnitLibrary::addUnit(QString UnitName, QString displayName, QString description, dimension::DIMENSION unitDimension)
{
    Unit *unit = new Unit(this);
    unit->setInternalName(UnitName);
    unit->setDisplayName(displayName);
    unit->setDescription(description);
    unit->Dimension(unitDimension);
    unidades[unit->getInternalName()] = unit;
}

}
