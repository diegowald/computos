#ifndef DATASTORE_H
#define DATASTORE_H

#include "materiallibrary.h"
#include "unitlibrary.h"
#include "proyecto.h"
#include "computometrico.h"
#include "cantidadeslibrary.h"
#include "author.h"
#include "providerslibrary.h"
#include "analysis.h"

class DataStore : public QObject
{
    Q_OBJECT

public:
    static DataStore *getInstance();


    //void cleanUp();

    Author *defaultAuthor();

    materialLibrary::MaterialLibrary *getMaterialLibrary();
    unidades::UnitLibrary *getUnitsLibrary();
    cantidades::CantidadesLibrary *getCantidadesLibrary();

    proyecto::Proyecto *getProject(QString &projectName);
    void LoadProject(QString &filename, QObject *parent);
    void crearProyecto(QString &filename, QObject *parent);
    boost::shared_ptr<QStringList> getProjectNames();

    void crearComputoMetrico(QString projectName, bool withAutomaticCalculations);
    computo::ComputoMetrico *getComputo(QString &projectName);

    computo::analysis::Analysis *getAnalysis(QString &projectName);

    listaPrecios::ProvidersLibrary *getProvidersList();

    virtual ~DataStore();
private:
    DataStore();

    materialLibrary::MaterialLibrary *_materialLibrary;
    listaPrecios::ProvidersLibrary *providersLibrary;
    unidades::UnitLibrary *unitLibrary;

    cantidades::CantidadesLibrary *cantidadesLibrary;

    QMap<QString, proyecto::Proyecto *> projectList;
    QMap<QString, computo::ComputoMetrico *>computoList;
    QMap<QString, computo::analysis::Analysis *> analysisList;

    Author *_author;

    static DataStore *store;
};

#endif // DATASTORE_H
