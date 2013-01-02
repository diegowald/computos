#include "proveedor.h"
namespace listaPrecios
{

Proveedor::Proveedor(QObject *parent) :
    QObject(parent), nombre(""), address(""), contactName(""),
    telephone(""), email("")
{
    listasProveedor.clear();
}

boost::shared_ptr<QStringList> Proveedor::getActiveListaPrecios()
{
    boost::shared_ptr<QStringList> lista(new QStringList());
    if (listasProveedor.size() > 0)
    {
        foreach(QString key, listasProveedor.keys())
        {
            //if (listasProveedor[key]->esActiva())
            lista->push_back(key);
        }
    }
    return lista;
}

ListaPrecios *Proveedor::getListaPrecios(QString nombre)
{
    if (listasProveedor.contains(nombre))
        return listasProveedor[nombre];
    else
        return NULL;
}

void Proveedor::addLista(ListaPrecios *newLista)
{
    listasProveedor[newLista->Name()] = newLista;
}

void Proveedor::deleteLista(QString nombre)
{
    ListaPrecios *l = getListaPrecios(nombre);
    if (l != NULL)
        delete l;
    listasProveedor.remove(nombre);
}

QString Proveedor::Nombre()
{
    return nombre;
}

void Proveedor::setNombre(QString value)
{
    nombre = value;
}

QString Proveedor::Address()
{
    return address;
}

void Proveedor::setAddress(QString value)
{
    address = value;
}

QString Proveedor::ContactName()
{
    return contactName;
}

void Proveedor::setContactName(QString value)
{
    contactName = value;
}

QString Proveedor::Telephone()
{
    return telephone;
}

void Proveedor::setTelephone(QString value)
{
    telephone = value;
}

void Proveedor::setEMail(QString value)
{
    email = value;
}

QString Proveedor::EMail()
{
    return email;
}

xml::XMLNode_ptr Proveedor::toXMLTree()
{
    xml::XMLNode_ptr tree(new xml::XMLNode("provider"));

    tree->addAttribute("name", nombre);
    tree->addAttribute("address", address);
    tree->addAttribute("contact", contactName);
    tree->addAttribute("telephone", telephone);
    tree->addAttribute("email", email);

    xml::XMLNode_ptr listas(new xml::XMLNode("lists"));
    tree->addChild(listas);
    listas->addAttribute("list_count", QString::number(listasProveedor.size()));

    foreach (QString key, listasProveedor.keys())
    {
        listas->addChild(listasProveedor[key]->toXMLTree());
    }

    return tree;
}

bool Proveedor::loadFromXMLTree(xml::XMLNode_ptr tree)
{
    nombre = tree->getChildValue("name", true);
    address = tree->getChildValue("address", true);
    contactName = tree->getChildValue("contact", true);
    telephone = tree->getChildValue("telephone", true);
    email = tree->getChildValue("email", true);

    xml::XMLNode_ptr listas = tree->getChildNode("lists", true);
    int count = listas->getChildValue("list_count", true).toInt();

    for (int i = 1; i <= count; i++)
    {
        ListaPrecios *lp = new ListaPrecios(this);
        lp->loadFromXMLTree(listas->getChildNode(i, true));

        listasProveedor[lp->Name()] = lp;
    }
    return true;
}

QDataStream &operator <<(QDataStream &stream, Proveedor &p)
{
    if (&p == NULL)
        return stream;

    stream << p.nombre;
    stream << p.address;
    stream << p.contactName;
    stream << p.telephone;
    stream << p.email;

    stream << p.listasProveedor.size();

    foreach (QString key, p.listasProveedor.keys())
    {
        stream << (*p.listasProveedor[key]);
    }
    return stream;
}

QDataStream &operator >>(QDataStream &stream, Proveedor &p)
{
    if (&p == NULL)
        return stream;

    stream >> p.nombre;
    stream >> p.address;
    stream >> p.contactName;
    stream >> p.telephone;
    stream >> p.email;

    int cantListas = 0;
    stream >> cantListas;

    for (int i= 0; i < cantListas; i++)
    {
        ListaPrecios *lp = new ListaPrecios(&p);
        stream >> (*lp);

        p.listasProveedor[lp->Name()] = lp;
    }

    return stream;
}

bool Proveedor::provides(QString element)
{
    foreach (ListaPrecios *lp, listasProveedor.values())
    {
        if (lp->provides(element))
            return true;
    }
    return false;
}

}
