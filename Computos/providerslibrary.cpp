#include "providerslibrary.h"
#include <QFile>
#include "fileheader.h"
#include "xmlhelper.h"

namespace listaPrecios
{

QString ProvidersLibrary::objectName = "Providers";
QString ProvidersLibrary::objectVersion = "1.0.0";

ProvidersLibrary::ProvidersLibrary(QObject *parent) :
    QObject(parent)
{
    _extension = ".provxml";
    _filename = "providers" + _extension;
}

bool ProvidersLibrary::load()
{
    if (_filename.endsWith(_extension, Qt::CaseInsensitive))
        return loadFromXML();
    else
        return loadFromStream();
}

bool ProvidersLibrary::loadFromStream()
{

    QFile f(_filename);
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
        int cantProveedores = 0;
        dsIn >> cantProveedores;

        for (int i = 0; i < cantProveedores; i++)
        {
            Proveedor *p = new Proveedor(this);
            dsIn >> (*p);
            proveedores[p->Nombre()] = p;
        }
        return true; // EL archivo se cargo OK
    }
    return false;
}

bool ProvidersLibrary::loadFromXML()
{
    xml::XMLNode_ptr res = XMLHelper::readXML(_filename);
    return loadFromXMLTree(res);
}

bool ProvidersLibrary::loadFromXMLTree(xml::XMLNode_ptr tree)
{
    if (tree->Name() != "providers")
        return false;

/*    FileHeader fh(objectVersion, objectName, this);
    fh.loadFromXMLTree(tree->getChildNode(fh*/

    xml::XMLNode_ptr provs = tree->getChildNode("providers", true);

    int provCount = provs->getChildValue("count", true).toInt();
    for (int i = 1; i <= provCount; i++)
    {
        Proveedor *p = new Proveedor(this);
        p->loadFromXMLTree(provs->getChildNode(i, true));
        proveedores[p->Nombre()] = p;
    }
    return true;
}


bool ProvidersLibrary::save()
{
    if(_filename.endsWith(".dat", Qt::CaseInsensitive))
        return saveAsStream();
    else
        return saveAsXML();
}

bool ProvidersLibrary::saveAsStream()
{
    QFile f(_filename);
    if (!f.open(QIODevice::WriteOnly))
    {
        return false;
    }

    QDataStream dsOut(&f);
    dsOut.setVersion(QDataStream::Qt_4_8);

    FileHeader fh(objectVersion, objectName, this);
    dsOut << fh;

    dsOut << proveedores.size();

    foreach(QString key, proveedores.keys())
    {
        dsOut << (*proveedores[key]);
    }

    return true;
}

bool ProvidersLibrary::saveAsXML()
{
    xml::XMLNode_ptr tree = toXMLTree();
    return XMLHelper::saveXMLTree(_filename, tree);
}

xml::XMLNode_ptr ProvidersLibrary::toXMLTree()
{
    xml::XMLNode_ptr tree(new xml::XMLNode("providers"));

/*    FileHeader fh(objectVersion, objectName, this);
    tree->addChild(fh.toXMLTree());*/

    xml::XMLNode_ptr provs(new xml::XMLNode("providers"));
    tree->addChild(provs);
    provs->addAttribute("count", QString::number(proveedores.size()));

    foreach(QString key, proveedores.keys())
    {
        provs->addChild(proveedores[key]->toXMLTree());
    }

    return tree;
}

Proveedor *ProvidersLibrary::getProveedor(QString name)
{
    if (proveedores.find(name) == proveedores.end())
        return NULL;
    else
        return proveedores[name];
}

boost::shared_ptr<QStringList> ProvidersLibrary::getAllProveedores()
{
    boost::shared_ptr<QStringList> res(new QStringList());
    foreach(QString key, proveedores.keys())
    {
        res->push_back(key);
    }
    return res;
}

boost::shared_ptr<QStringList> ProvidersLibrary::getProveedores(QString elementFilter)
{
    boost::shared_ptr<QStringList> res(new QStringList());
    foreach (QString key, proveedores.keys())
    {
        Proveedor *p = proveedores[key];
        if (p->provides(elementFilter))
            res->push_back(key);
    }
    return res;
}

void ProvidersLibrary::addProveedor(Proveedor *newProveedor)
{
    newProveedor->setParent(this);
    proveedores[newProveedor->Nombre()] = newProveedor;
}

void ProvidersLibrary::deleteProveedor(QString nombre)
{
    Proveedor *p = getProveedor(nombre);
    if (p != NULL)
        delete p;
    proveedores.remove(nombre);
}

}
