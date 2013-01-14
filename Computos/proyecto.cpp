#include "proyecto.h"

#include <QFile>
#include <QDataStream>
#include "fileheader.h"

#include "datastore.h"
#include "Dimension.h"
#include "rectangularsurface.h"
#include "xmlhelper.h"


namespace proyecto {

QString Proyecto::objectName = "Project";
QString Proyecto::objectVersion = "1.0.0";

QString Proyecto::PROJECT_TAG = "project";
QString Proyecto::NAME_TAG = "name";
QString Proyecto::OWNER_TAG = "owner";
QString Proyecto::ADDRESS_TAG = "address";
QString Proyecto::TELEPHONE_TAG = "telephone";
QString Proyecto::EMAIL_TAG = "email";
QString Proyecto::NOTES_TAG = "notes";
QString Proyecto::ELEMENTS_TAG = "elements";
QString Proyecto::COUNT_TAG = "count";
QString Proyecto::PDFS_TAG = "pdfs";

Proyecto::Proyecto(QString filename, QObject *parent) :
    QObject(parent), nombre(""), propietarios(""),
    direccion(""), telefono(""), email(""), notas("")
{
    author = DataStore::getInstance()->defaultAuthor();
    fileName = filename;
}

Proyecto::~Proyecto()
{
    foreach(QString key, elementosConstructivos.keys())
    {
        delete elementosConstructivos[key];
    }
    elementosConstructivos.clear();
}

void Proyecto::setNombre(QString Nombre)
{
    nombre = Nombre;
}

QString Proyecto::Nombre() const
{
    return nombre;
}

void Proyecto::setPropietarios(QString Propietarios)
{
    propietarios = Propietarios;
}

QString Proyecto::Propietarios() const
{
    return propietarios;
}

void Proyecto::setDireccion(QString Direccion)
{
    direccion = Direccion;
}

QString Proyecto::Direccion() const
{
    return direccion;
}

void Proyecto::setTelefono(QString Telefono)
{
    telefono = Telefono;
}

QString Proyecto::Telefono() const
{
    return telefono;
}

void Proyecto::setEMail(QString EMail)
{
    email = EMail;
}

QString Proyecto::EMail() const
{
    return email;
}

void Proyecto::setNotas(QString Notas)
{
    notas = Notas;
}

QString Proyecto::Notas() const
{
    return notas;
}

void Proyecto::addElementoConstructivo(ElementoConstructivo *elemento)
{
    elementosConstructivos[elemento->getName()] = elemento;
}

ElementoConstructivo *Proyecto::getElementoConstructivo(QString Name)
{
    return elementosConstructivos[Name];
}

void Proyecto::removeElemento(QString Name)
{
    if (elementosConstructivos.find(Name) != elementosConstructivos.end())
    {
        delete elementosConstructivos[Name];
        elementosConstructivos.remove(Name);
    }
}

boost::shared_ptr<QStringList> Proyecto::getAllElementoConstructivoNames()
{
    boost::shared_ptr<QStringList> res(new QStringList());
    foreach(QString nombre, elementosConstructivos.keys())
    {
        res->push_back(nombre);
    }
    return res;
}

void Proyecto::addPDFToProject(QString pdfFileName)
{
    pdf::PDFRedLining *pdfDoc = new pdf::PDFRedLining(pdfFileName, this);
    pdfs[pdfFileName] = pdfDoc;
}

boost::shared_ptr<QStringList> Proyecto::getAllPDFNames()
{
    boost::shared_ptr<QStringList> res(new QStringList(pdfs.keys()));
    return res;
}

pdf::PDFRedLining *Proyecto::getRedLining(QString pdfName)
{
    if (pdfs.find(pdfName) != pdfs.end())
        return pdfs[pdfName];
    else
        return NULL;
}

bool Proyecto::load(QString &filename)
{
    if (filename.endsWith(".xml", Qt::CaseInsensitive))
        return loadFromXML(filename);
    else if (filename.endsWith(".pr", Qt::CaseInsensitive))
        return loadFromStream(filename);
    else
        return false;
}

bool Proyecto::loadFromStream(QString &filename)
{
    QFile f(filename);
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

        //dsOut << fileName;
        dsIn >> nombre;
        dsIn >> propietarios;
        dsIn >> direccion;
        dsIn >> telefono;
        dsIn >> email;
        dsIn >> notas;

        int cantElementos = 0;
        dsIn >> cantElementos;
        for (int i = 0; i < cantElementos; i++)
        {
            QString nombreElemento;
            dsIn >> nombreElemento;
            ElementoConstructivo *el = new ElementoConstructivo(this);

            dsIn >> (*el);
            elementosConstructivos[nombreElemento] = el;
        }
        return true; // EL archivo se cargo OK
    }
    return false;
}

bool Proyecto::loadFromXML(QString &filename)
{
    xml::XMLNode_ptr res = XMLHelper::readXML(filename);
    return loadProjectFromXMLTree(res);
}

bool Proyecto::loadProjectFromXMLTree(xml::XMLNode_ptr tree)
{
    nombre = tree->getChildValue(NAME_TAG, true);
    author->loadFromXMLTree(tree->getChildNode(Author::AUTHOR_TAG, true));
    propietarios = tree->getChildValue(OWNER_TAG, true);
    direccion = tree->getChildValue(ADDRESS_TAG, true);
    telefono = tree->getChildValue(TELEPHONE_TAG, true);
    email = tree->getChildValue(EMAIL_TAG, true);
    notas = tree->getChildValue(NOTES_TAG, true);

    xml::XMLNode_ptr elements = tree->getChildNode(ELEMENTS_TAG, true);
    int numElementos = elements->getChildValue(COUNT_TAG, true).toInt();

    for (int i = 1; i <= numElementos; i++)
    {
        ElementoConstructivo *el = new ElementoConstructivo(this);
        el->loadFromXMLTree(elements->getChildNode(i, true));
        elementosConstructivos[el->getName()] = el;
    }


    xml::XMLNode_ptr _pdfs = tree->getChildNode(PDFS_TAG, true);
    int numPdfs = _pdfs->getChildValue(COUNT_TAG, true).toInt();
    for (int i = 1; i <= numPdfs; i++)
    {
        pdf::PDFRedLining *pdf = new pdf::PDFRedLining(this);
        pdf->loadFromXMLTree(_pdfs->getChildNode(i, true));
        pdfs[pdf->name()] = pdf;
    }


    return true;
}

bool Proyecto::save()
{
    return saveAs(this->fileName);
}

bool Proyecto::saveAs(QString &filename)
{
    if (filename.endsWith(".xml", Qt::CaseInsensitive))
        return saveAsXML(filename);
    else if (filename.endsWith(".pr", Qt::CaseInsensitive))
        return saveAsStream(filename);
    else
        return false;
}

bool Proyecto::saveAsStream(QString &filename)
{
    QFile f(filename);
    if (!f.open(QIODevice::WriteOnly))
    {
        return false;
    }

    QDataStream dsOut(&f);
    dsOut.setVersion(QDataStream::Qt_4_8);

    FileHeader fh(objectVersion, objectName, this);
    dsOut << fh;

    dsOut << *author;

    //dsOut << fileName;
    dsOut << nombre;
    dsOut << propietarios;
    dsOut << direccion;
    dsOut << telefono;
    dsOut << email;
    dsOut << notas;

    dsOut << elementosConstructivos.size();
    foreach(QString elemento, elementosConstructivos.keys())
    {
        dsOut << elemento;
        dsOut << *elementosConstructivos[elemento];
    }
    return true;
}

bool Proyecto::saveAsXML(QString &filename)
{
    xml::XMLNode_ptr tree = createProjectXMLTree();
    return XMLHelper::saveXMLTree(filename, tree);
}

xml::XMLNode_ptr Proyecto::createProjectXMLTree()
{
    xml::XMLNode_ptr node(new xml::XMLNode(PROJECT_TAG));

    node->addAttribute(NAME_TAG, nombre);
    node->addChild(author->toXMLTree());
    node->addAttribute(OWNER_TAG, propietarios);
    node->addAttribute(ADDRESS_TAG, direccion);
    node->addAttribute(TELEPHONE_TAG, telefono);
    node->addAttribute(EMAIL_TAG, email);
    node->addAttribute(NOTES_TAG, notas);

    xml::XMLNode_ptr elementos(new xml::XMLNode(ELEMENTS_TAG));
    node->addChild(elementos);

    elementos->addAttribute(COUNT_TAG, QString::number(elementosConstructivos.size()));
    foreach(QString elemento, elementosConstructivos.keys())
    {
        elementos->addChild(elementosConstructivos[elemento]->toXMLTree());
    }

    xml::XMLNode_ptr _pdfs(new xml::XMLNode(PDFS_TAG));
    node->addChild(_pdfs);
    node->addAttribute(COUNT_TAG, QString::number(pdfs.count()));
    foreach(QString pdf, pdfs.keys())
    {
        _pdfs->addChild(pdfs[pdf]->toXMLTree());
    }

    return node;
}

boost::shared_ptr<QStringList> Proyecto::getValidExtensions()
{
    boost::shared_ptr<QStringList> res(new QStringList());

    res->push_back("Project files (*.xml)");
    res->push_back("Project XML files (*.prxml)");

    return res;
}

}
