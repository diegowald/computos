#include "materiallibrary.h"
#include <QFile>
#include <QDataStream>
#include "datastore.h"
#include "fileheader.h"
#include "xmlhelper.h"

namespace materialLibrary {

QString MaterialLibrary::objectVersion = "1.0.0";
QString MaterialLibrary::objectName = "Materials";

MaterialLibrary::MaterialLibrary(QObject *parent) :
    QObject(parent)
{
    materiales.clear();
    _extension = ".mxml";
    _filename = "./materials" + _extension;
    creation = QDateTime();
    lastUpdate = QDateTime();
    libraries["base"] = _filename;
}

MaterialLibrary::~MaterialLibrary()
{
}

Elemento *MaterialLibrary::getElemento(QString name)
{
    if (name.size() == 0)
        return NULL;
    else
        return materiales[name];
}

boost::shared_ptr<QStringList> MaterialLibrary::getAllLibraries()
{
    boost::shared_ptr<QStringList> res(new QStringList(libraries.keys()));
    return res;
}

boost::shared_ptr<QStringList> MaterialLibrary::getAllNames(bool soloUsables)
{
    boost::shared_ptr<QStringList> materials(new QStringList());
    foreach(QString key, materiales.keys())
    {
        if (soloUsables)
        {
            if (DataStore::getInstance()->getMaterialLibrary()->getElemento(key)->UsableDirectamente())
                materials->push_back(key);
        }
        else
            materials->push_back(key);
    }
    return materials;
}

boost::shared_ptr<QStringList> MaterialLibrary::getAllNames(QString &filter, bool soloUsables)
{
    if (filter.size() == 0)
        return getAllNames(soloUsables);

    boost::shared_ptr<QStringList> materials(new QStringList());
    foreach(Elemento *el, materiales.values())
    {
        bool selected = false;
        if (el->getName().contains(filter, Qt::CaseInsensitive))
            selected = true;
        else if (el->getTagsString().contains(filter, Qt::CaseInsensitive))
            selected = true;

        if (soloUsables)
            selected &= el->UsableDirectamente();

        if (selected)
            materials->push_back(el->getName());
    }
    return materials;
}

boost::shared_ptr<QStringList> MaterialLibrary::getAllNames(QString &library, QString &filter, bool soloUsables)
{
    boost::shared_ptr<QStringList> res(new QStringList());

    boost::shared_ptr<QStringList> mats = getAllNames(filter, soloUsables);

    foreach(QString mat, *mats)
    {
        if (materiales[mat]->belongsTo(library))
            res->push_back(mat);
    }
    return res;
}

void MaterialLibrary::addMaterial(QString MaterialName, QString library)
{
    Elemento *elemento = new Elemento(this);
    elemento->setName(MaterialName);
    elemento->setlibrary(library);
    addMaterial(elemento);
}

void MaterialLibrary::addMaterial(Elemento *newElement, QString library)
{
    newElement->setlibrary(library);
    if (newElement->checkIsComplete())
        materiales[newElement->getName()] = newElement;
    // else throw exception
}

bool MaterialLibrary::load()
{
    materiales.clear();
    bool res = true;
    foreach (QString key, libraries.keys())
    {
        QString filename(libraries[key]);
        if (filename.endsWith(_extension, Qt::CaseInsensitive))
            res &= loadFromXML(key);
        else
            res &= loadFromStream(key);
    }
    return res;
}

bool MaterialLibrary::loadFromStream(QString &library)
{
    QFile f(libraries[library]);
    if (!f.open(QIODevice::ReadOnly))
    {
        //no se puede abrir el archivo
        return false;
    }

    QDataStream dsIn(&f);

    if (dsIn.version() != QDataStream::Qt_4_8)
        return false;

    FileHeader fh(objectVersion, objectName, this);

    dsIn >> fh;
    if (fh.isValidFile())
    {
        Author author;
        dsIn >> author;

        dsIn >> creation;
        dsIn >> lastUpdate;

        int cantMateriales = 0;
        dsIn >> cantMateriales;
        for (int i = 0; i < cantMateriales; i++)
        {
            QString nombreMaterial;
            dsIn >> nombreMaterial;
            Elemento *e = new Elemento(this);
            e->setlibrary(library);
            dsIn >> (*e);
            e->setName(nombreMaterial);
            materiales[nombreMaterial] = e;
        }
        return true; // EL archivo se cargo OK
    }
    return false;
}

bool MaterialLibrary::loadFromXML(QString &library)
{
    xml::XMLNode_ptr res = XMLHelper::readXML(libraries[library]);
    return (res->Name() != "") ? loadFromXMLTree(res, library) : false;
}

bool MaterialLibrary::loadFromXMLTree(xml::XMLNode_ptr tree, QString &library)
{
    creation = QDateTime::fromString(tree->getChildValue("creation", true), Qt::ISODate);
    lastUpdate = QDateTime::fromString(tree->getChildValue("lastUpdate", true), Qt::ISODate);

    QString version = tree->getChildValue("version", true);
    if (version != objectVersion)
        return false;

    QString objName = tree->getChildValue("name", true);
    if (objectName != objName)
        return false;

    xml::XMLNode_ptr mats = tree->getChildNode("materials", true);
    int count = mats->getChildValue("count", true).toInt();
    for (int i = 1; i <= count; i++)
    {
        Elemento* el = new Elemento(this);
        el->setlibrary(library);
        if (!el->loadFromXMLTree(mats->getChildNode(i, true)))
            return false;
        materiales[el->getName()] = el;
    }
    return true;
}

bool MaterialLibrary::reload()
{
    bool result = load();
    emit saved();
    return result;
}

bool MaterialLibrary::save()
{
    bool result = true;
    foreach(QString library, libraries.keys())
    {
        result &= saveAs(library);
    }
    return result;
}

bool MaterialLibrary::saveAs(QString &library)
{
    bool res = false;
    if (libraries[library].endsWith(".mat", Qt::CaseInsensitive))
        res = saveAsStream(library);
    else
        res = saveAsXML(library);

    /*QString x("./materials.xml");
    res = saveAsXML(library);*/

    if (res)
        emit saved();
    return res;
}

bool MaterialLibrary::saveAsStream(QString &library)
{
    QFile f(libraries[library]);
    if (!f.open(QIODevice::WriteOnly))
    {
        return false;
    }

    QDataStream dsOut(&f);
    dsOut.setVersion(QDataStream::Qt_4_8);

    FileHeader fh(objectVersion, objectName, this);

    dsOut << fh;
    dsOut << *DataStore::getInstance()->defaultAuthor();

    lastUpdate = QDateTime();

    dsOut << creation;
    dsOut << lastUpdate;

    boost::shared_ptr<QList<QString> > materialesfiltrados = filtrarMateriales(library);
    dsOut << materialesfiltrados->count();
    foreach(QString elemento, *materialesfiltrados)
    {
            dsOut << elemento;
            dsOut << *materiales[elemento];
    }

    return true;
}

bool MaterialLibrary::saveAsXML(QString &library)
{
    xml::XMLNode_ptr tree = createMaterialXMLTree(library);
    return XMLHelper::saveXMLTree(libraries[library], tree);
}

xml::XMLNode_ptr MaterialLibrary::createMaterialXMLTree(QString &library)
{
    xml::XMLNode_ptr node(new xml::XMLNode("material_library", this));

    node->addAttribute("creation", creation.toString(Qt::ISODate));
    node->addAttribute("lastUpdate", lastUpdate.toString(Qt::ISODate));
    node->addAttribute("version", objectVersion);
    node->addAttribute("name", objectName);

    xml::XMLNode_ptr mats = xml::XMLNode::createNode("materials", node.get());
    node->addChild(mats);
    boost::shared_ptr<QList<QString> > materialesfiltrados = filtrarMateriales(library);
    mats->addAttribute("count", QString::number(materialesfiltrados->count()));
    foreach(QString key, *materialesfiltrados)
    {
        mats->addChild(materiales[key]->toXMLTree());
    }
    return node;
}

QDateTime MaterialLibrary::getLastUpdate()
{
    return lastUpdate;
}

boost::shared_ptr<QStringList> MaterialLibrary::filtrarMateriales(QString &filename)
{
    boost::shared_ptr<QStringList> res(new QStringList());

    foreach(QString elemento, materiales.keys())
    {
        if (materiales[elemento]->belongsTo(filename))
            res->push_back(elemento);
    }

    return res;
}

} // namespace
