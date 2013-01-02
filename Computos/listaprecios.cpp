#include "listaprecios.h"

namespace listaPrecios
{

ListaPrecios::ListaPrecios(QObject *parent) :
    QObject(parent), name("")
{
    lista.clear();
    listaPorNombreProveedor.clear();
}

Precio *ListaPrecios::getMejorPrecio(QString elemento, double cantidad)
{
    Precio *mejorPrecio = NULL;
    QList<Precio*> precios = lista.values(elemento);
    foreach(Precio *precio, precios)
    {
        if (mejorPrecio == NULL)
        {
            mejorPrecio = precio;
        }
        else
        {
            if (precio->calcularPrecio(cantidad) < mejorPrecio->calcularPrecio(cantidad))
            {
                mejorPrecio = precio;
            }
        }
    }
    return mejorPrecio;
}

Precio *ListaPrecios::getPrecio(QString elemento, QString marca)
{
    QList<Precio*> precios = lista.values(elemento);
    foreach(Precio *precio, precios)
    {
        if (precio->Marca() == marca)
            return precio;
    }
    return NULL;
}

Precio *ListaPrecios::getPrecio(QString nombrePrecioSegunProveedor)
{
    if (listaPorNombreProveedor.find(nombrePrecioSegunProveedor) == listaPorNombreProveedor.end())
        return NULL;
    else
        return listaPorNombreProveedor[nombrePrecioSegunProveedor];
}

void ListaPrecios::deletePriceItem(QString elemento, QString marca)
{
    Precio *precio = getPrecio(elemento, marca);
    if (precio != NULL)
    {
        lista.remove(elemento, precio);
    }
    listaPorNombreProveedor.remove(precio->NombreEnListaPrecios());
    delete precio;
}

boost::shared_ptr<QList<Precio *> > ListaPrecios::getTodosPrecios(QString elemento)
{
    boost::shared_ptr<QList<Precio *> > res(new QList<Precio *>());
    foreach(Precio *precio, lista.values(elemento))
    {
        res->push_back(precio);
    }
    return res;
}

boost::shared_ptr<QStringList> ListaPrecios::getTodosElementos()
{
    boost::shared_ptr<QStringList> res(new QStringList());
    foreach(QString key, lista.uniqueKeys())
    {
        res->push_back(key);
    }
    return res;
}

void ListaPrecios::addPrecio(Precio* precio)
{
    lista.insert(precio->getNombreElemento(), precio);
    listaPorNombreProveedor[precio->NombreEnListaPrecios()] = precio;
}

QDateTime ListaPrecios::Vigencia()
{
    return vigenciaDesde;
}

void ListaPrecios::setVigencia(QDateTime value)
{
    vigenciaDesde = value;
}

QString ListaPrecios::Name()
{
    return name;
}

void ListaPrecios::setName(QString newName)
{
    name = newName;
}

bool ListaPrecios::provides(QString elemento)
{
    foreach (QString key, lista.uniqueKeys())
    {
        if (key == elemento)
            return true;
    }
    return false;
}

xml::XMLNode_ptr ListaPrecios::toXMLTree()
{
    xml::XMLNode_ptr tree(new xml::XMLNode("price_list"));

    tree->addAttribute("name", name);
    tree->addAttribute("since", vigenciaDesde.toString(Qt::ISODate));

    xml::XMLNode_ptr l(new xml::XMLNode("list"));
    tree->addChild(l);
    l->addAttribute("count", QString::number(lista.size()));

    foreach(QString key, lista.uniqueKeys())
    {
        xml::XMLNode_ptr ps(new xml::XMLNode("prices"));
        l->addChild(ps);
        QList<Precio *> precios = lista.values(key);
        ps->addAttribute("count", QString::number(precios.size()));
        foreach(Precio *precio, precios)
        {
            ps->addChild(precio->toXMLTree());
        }
    }
    return tree;
}

bool ListaPrecios::loadFromXMLTree(xml::XMLNode_ptr tree)
{
    if (tree->Name() != "price_list")
        return false;

    name = tree->getChildValue("name", true);
    vigenciaDesde = QDateTime::fromString(tree->getChildValue("since", true), Qt::ISODate);


    xml::XMLNode_ptr l = tree->getChildNode("list", true);

    int count = l->getChildValue("count", true).toInt();

    for (int i = 1; i <= count; i++)
    {
        xml::XMLNode_ptr ps = l->getChildNode("prices", true);
        int cantPreciosElemento = ps->getChildValue("count", true).toInt();
        for (int j = 1; j <= cantPreciosElemento; j++)
        {
            Precio *p = new Precio(this);
            p->loadFromXMLTree(ps->getChildNode(j, true));
            lista.insert(p->getNombreElemento(), p);
            listaPorNombreProveedor[p->NombreEnListaPrecios()] = p;
        }
    }
    return true;
}

QDataStream &operator <<(QDataStream &stream, ListaPrecios &lp)
{
    if (&lp == NULL)
        return stream;

    stream << lp.name;
    stream << lp.vigenciaDesde;

    stream << lp.lista.size();

    foreach(QString key, lp.lista.uniqueKeys())
    {
        QList<Precio *> precios = lp.lista.values(key);
        stream << precios.size();
        foreach(Precio *precio, precios)
        {
            stream << (*precio);
        }
    }

    return stream;
}

QDataStream &operator >>(QDataStream &stream, ListaPrecios &lp)
{
    if (&lp == NULL)
        return stream;

    stream >> lp.name;
    stream >> lp.vigenciaDesde;

    int cantElementos = 0;
    stream >> cantElementos;

    for (int i = 0; i < cantElementos; i++)
    {
        int cantPreciosElemento = 0;
        stream >> cantPreciosElemento;
        for (int j = 0; j < cantPreciosElemento; j++)
        {
            Precio *p = new Precio(&lp);
            stream >> (*p);
            lp.lista.insert(p->getNombreElemento(), p);
            lp.listaPorNombreProveedor[p->NombreEnListaPrecios()] = p;
        }
    }

    return stream;
}


}
