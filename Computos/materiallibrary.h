#ifndef MATERIALLIBRARY_H
#define MATERIALLIBRARY_H

#include <QObject>
#include <QMap>
#include "elemento.h"
#include <QDateTime>
#include <boost/shared_ptr.hpp>
#include "xmlnode.h"

namespace materialLibrary {
class MaterialLibrary : public QObject
{
    Q_OBJECT
public:
    explicit MaterialLibrary(QObject *parent = 0);
    virtual ~MaterialLibrary();

    bool load();
    bool reload();
    bool loadCustomLibrary(QString &customLibrary);
    bool save();
    bool saveAs(QString &library);
    Elemento *getElemento(QString name);

    boost::shared_ptr<QStringList> getAllLibraries();
    boost::shared_ptr<QStringList> getAllNames(bool soloUsables);
    boost::shared_ptr<QStringList> getAllNames(QString &filter, bool soloUsables);
    boost::shared_ptr<QStringList> getAllNames(QString &library, QString &filter, bool soloUsables);

    void addMaterial(QString MaterialName, QString library);
    void addMaterial(Elemento *newElement, QString library = "base");

    QDateTime getLastUpdate();

private:
    bool saveAsStream(QString &library);
    bool saveAsXML(QString &library);

    bool loadFromStream(QString &library);
    bool loadFromXML(QString &library);
    bool loadFromXMLTree(xml::XMLNode_ptr tree, QString &filename);
    xml::XMLNode_ptr createMaterialXMLTree(QString &library);

    boost::shared_ptr<QStringList> filtrarMateriales(QString &filename);

private:
    QMap<QString, Elemento*> materiales;
    QDateTime creation;
    QDateTime lastUpdate;
    QString _filename;
    QString _extension;

    QMap<QString, QString> libraries;

    static QString objectVersion;
    static QString objectName;

signals:
    void saved();
    
public slots:
    
};

}
#endif // MATERIALLIBRARY_H
