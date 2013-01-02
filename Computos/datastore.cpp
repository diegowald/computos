#include "datastore.h"

DataStore *DataStore::store = NULL;

DataStore::DataStore() : QObject(NULL)
{
    _materialLibrary = NULL;
    unitLibrary = NULL;
    projectList.clear();
    computoList.clear();
    cantidadesLibrary = NULL;
    providersLibrary = NULL;
    _author = NULL;
}

/*void DataStore::cleanUp()
{
    if (_materialLibrary != NULL)
        delete _materialLibrary;

    if (unitLibrary != NULL)
        delete unitLibrary;

    projectList.clear();
    computoList.clear();

    if (cantidadesLibrary != NULL)
        delete cantidadesLibrary;

    if (_author != NULL)
        delete _author;
}
*/
DataStore::~DataStore()
{
    if (_materialLibrary != NULL)
        delete _materialLibrary;

    if (unitLibrary != NULL)
        delete unitLibrary;

    projectList.clear();
    computoList.clear();

    if (cantidadesLibrary != NULL)
        delete cantidadesLibrary;

    if (_author != NULL)
        delete _author;
}

DataStore *DataStore::getInstance()
{
    if (store == NULL)
        store = new DataStore();
    return store;
}

materialLibrary::MaterialLibrary *DataStore::getMaterialLibrary()
{
    if (_materialLibrary == NULL)
    {
        _materialLibrary = new materialLibrary::MaterialLibrary(this);
        _materialLibrary->load();
    }
    return _materialLibrary;
}

listaPrecios::ProvidersLibrary *DataStore::getProvidersList()
{
    if (providersLibrary == NULL)
    {
        providersLibrary = new listaPrecios::ProvidersLibrary(this);
        providersLibrary->load();
    }
    return providersLibrary;
}

cantidades::CantidadesLibrary *DataStore::getCantidadesLibrary()
{
    if (cantidadesLibrary == NULL)
    {
        cantidadesLibrary = new cantidades::CantidadesLibrary(this);
    }
    return cantidadesLibrary;
}

unidades::UnitLibrary *DataStore::getUnitsLibrary()
{
    if (unitLibrary == NULL)
    {
        unitLibrary = new unidades::UnitLibrary(this);

        // Sin dimension
        unitLibrary->addUnit("unit", QObject::tr("unit"), QObject::tr("Unit"), dimension::DIMENSIONLESS);
        unitLibrary->addUnit("bag", QObject::tr("bag"), QObject::tr("Bag"), dimension::DIMENSIONLESS);

        // Lineal
        unitLibrary->addUnit("m", QObject::tr("m"), QObject::tr("Linear Meter"), dimension::LINEAR);
        unitLibrary->addUnit("in", QObject::tr("in"), QObject::tr("inches"), dimension::LINEAR);

        // Superficie
        unitLibrary->addUnit("m2", QObject::tr("m2"), QObject::tr("Square Meter"), dimension::SURFACE);

        // Volumen, peso
        unitLibrary->addUnit("kg", QObject::tr("kg"), QObject::tr("Kilogram"), dimension::VOLUME);
        unitLibrary->addUnit("m3", QObject::tr("m3"), QObject::tr("Cubic Meter"), dimension::VOLUME);
        unitLibrary->addUnit("l", QObject::tr("l"), QObject::tr("Liter"), dimension::VOLUME);

        // Tiempo
        unitLibrary->addUnit("sec", QObject::tr("sec"), QObject::tr("Second"), dimension::TIME);
        unitLibrary->addUnit("min", QObject::tr("min"), QObject::tr("Minute"), dimension::TIME);
        unitLibrary->addUnit("hr", QObject::tr("hr"), QObject::tr("Hour"), dimension::TIME);

    }
    return unitLibrary;
}

void DataStore::LoadProject(QString &filename, QObject *parent)
{
    proyecto::Proyecto *p = new proyecto::Proyecto(filename, parent);
    if (p->load(filename))
        projectList[filename] = p;
    else
        delete p;
}

void DataStore::crearProyecto(QString &filename, QObject *parent)
{
    proyecto::Proyecto *p = new proyecto::Proyecto(filename, parent);
    projectList[filename] = p;
}

proyecto::Proyecto *DataStore::getProject(QString &projectName)
{
    proyecto::Proyecto *project = projectList[projectName];
    return project;
}

boost::shared_ptr<QStringList> DataStore::getProjectNames()
{
    boost::shared_ptr<QStringList> projects(new QStringList());
    foreach (QString project, projectList.keys())
    {
        projects->push_back(project);
    }
    return projects;
}

void DataStore::crearComputoMetrico(QString projectName, bool withAutomaticCalculations)
{
    computo::ComputoMetrico *c = computoList[projectName];
    if (c != NULL)
        delete c;

    c = new computo::ComputoMetrico(this, projectList[projectName], withAutomaticCalculations);
    c->Compute();
    computoList[projectName] = c;
}

computo::ComputoMetrico *DataStore::getComputo(QString &projectName)
{
    computo::ComputoMetrico *c = computoList[projectName];
    if (c == NULL)
    {
        crearComputoMetrico(projectName, false);
        c = computoList[projectName];
    }

    return c;
}

computo::analysis::Analysis *DataStore::getAnalysis(QString &projectName)
{
    if (analysisList.find(projectName) == analysisList.end())
    {
        computo::analysis::Analysis *a = new computo::analysis::Analysis(projectName, this);
        a->compute();
        analysisList[projectName] = a;
    }
    return analysisList[projectName];
}

Author *DataStore::defaultAuthor()
{
    if (_author == NULL)
        _author = new Author(this);
    return _author;
}
