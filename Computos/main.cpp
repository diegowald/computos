#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include "mainwindowapplication.h"

#include "updatevalidator.h"
#include <QFile>

// Used for datastore initialization
#include "datastore.h"

#define APPNAME "Computos"
#define ORGNAME "mksIngenieria"

void createUpdateFile()
{
    UpdateValidator uv(1094, QDateTime::currentDateTime());
    QFile f("./updates.dat");
    if (!f.open(QIODevice::WriteOnly))
    {
        return;
    }

    QDataStream dsOut(&f);
    dsOut.setVersion(QDataStream::Qt_4_8);
    dsOut << uv;
}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QCoreApplication::setApplicationName(APPNAME);
    QCoreApplication::setOrganizationName(ORGNAME);

    QTranslator appTranslator;

    DataStore::getInstance()->setParent(&a);

    if (appTranslator.load("computos_" + QLocale::system().name(), a.applicationDirPath()))
    //if (appTranslator.load("computos.qm", a.applicationDirPath()))
        a.installTranslator(&appTranslator);

    //createUpdateFile();

    MainWindowApplication w;
    w.show();
    
    return a.exec();
}
