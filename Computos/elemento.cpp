#include "elemento.h"
#include "datastore.h"

namespace materialLibrary {

Elemento::Elemento(QObject *parent) :
    QObject(parent)
{
    name = "";
    measureUnit = NULL;
    elementos.clear();
    usableDirectamente = false;
    _library = "";
}

Elemento::~Elemento()
{
}

void Elemento::setlibrary(QString &library)
{
    _library = library;
}

bool Elemento::belongsTo(QString &library)
{
    return _library == library;
}

bool Elemento::checkIsComplete() const
{
    return (name.size() > 0)
            && (measureUnit != NULL);
}

QString Elemento::getName() const
{
    return name;
}

void Elemento::setName(QString newName)
{
    name = newName;
}

QString Elemento::getDescription() const
{
    return description;
}

void Elemento::setDescription(QString newDescription)
{
    description = newDescription;
}

unidades::Unit *Elemento::getMeasureUnit() const
{
    return measureUnit;
}

void Elemento::setMeasureUnit(unidades::Unit *newUnit)
{
    Q_ASSERT(newUnit);
    measureUnit = newUnit;
}

boost::shared_ptr<QList<ComponenteElemento*> > Elemento::getComponentes()
{
    boost::shared_ptr<QList<ComponenteElemento*> > aux(new QList<ComponenteElemento*>(elementos));
    return aux;
}

void Elemento::AddComponente(Elemento *newElemento, double cantidad)
{
    ComponenteElemento *componente = new ComponenteElemento(this);
    componente->setElemento(newElemento);
    componente->setCantidad(cantidad);
    elementos.push_back(componente);
}

void Elemento::AddComponente(ComponenteElemento *componente)
{
    elementos.push_back(componente);
}

void Elemento::eliminarTodosComponentes()
{
    elementos.clear();
}

QString Elemento::getTagsString()
{
    QString StringTags = "";
    foreach(QString tag, tags)
    {
        StringTags += tag + " ";
    }
    return StringTags;
}

void Elemento::addTag(QString newTag)
{
    tags.push_back(newTag);
}

void Elemento::setUsableDirectamente(bool usable)
{
    usableDirectamente = usable;
}

bool Elemento::UsableDirectamente()
{
    return usableDirectamente;
}


bool Elemento::esCompuesto() const
{
    return elementos.size() > 0;
}

xml::XMLNode_ptr Elemento::toXMLTree()
{
    xml::XMLNode_ptr node(xml::XMLNode::createNode("material"));

    node->addAttribute("name", name);
    node->addAttribute("description", description);
    node->addAttribute("tags", getTagsString());
    node->addAttribute("measureunit", getMeasureUnit()->getInternalName());
    node->addAttribute("usable_in_project", UsableDirectamente() ? "yes" : "no");
    if (esCompuesto())
    {
        xml::XMLNode_ptr componentes(xml::XMLNode::createNode("components", node.get()));
        node->addChild(componentes);
        componentes->addAttribute("count", QString::number(getComponentes()->size()));
        foreach (ComponenteElemento *el, *getComponentes())
        {
            componentes->addChild(el->toXMLTree());
        }
    }
    return node;
}

bool Elemento::loadFromXMLTree(xml::XMLNode_ptr tree)
{
    name = tree->getChildValue("name", true);
    description = tree->getChildValue("description", true);

    measureUnit = DataStore::getInstance()->getUnitsLibrary()->getUnit(tree->getChildValue("measureunit", true));

    usableDirectamente = tree->getChildValue("usable_in_project", true) == "yes" ? true : false;

    xml::XMLNode_ptr componentes = tree->getChildNode("components", false);
    if (componentes.get())
    {
        int compCount = componentes->getChildValue("count", true).toInt();
        for (int i = 1; i <= compCount; i++)
        {
            ComponenteElemento *ce = new ComponenteElemento(this);
            if (!ce->loadFromXMLTree(componentes->getChildNode(i, true)))
                return false;
            AddComponente(ce);
        }
    }
    return true;
}

QDataStream &operator <<(QDataStream &stream, Elemento &e)
{
    if (&e == NULL)
        return stream;
    //stream << e.getName();
    stream << e.getDescription();
    stream << e.tags.size();
    foreach (QString s, e.tags)
    {
        stream << s;
    }

    stream << e.getMeasureUnit()->getInternalName();
    stream << e.UsableDirectamente();
    stream << e.esCompuesto();
    if (e.esCompuesto())
    {
        stream << e.getComponentes()->size();
        foreach (ComponenteElemento *el, *e.getComponentes())
        {
            stream << (*el);
        }
    }
    return stream;
}

QDataStream &operator >>(QDataStream &stream, Elemento &e)
{
    QString s;
    //stream >> s;
    //e.setName(s);
    stream >> s;
    e.setDescription(s);
    int count;
    stream >> count;
    for (int i = 0; i < count; i++)
    {
        stream >> s;
        e.addTag(s);
    }
    stream >> s;
    e.setMeasureUnit(DataStore::getInstance()->getUnitsLibrary()->getUnit(s));

    bool esUsableDirectamente;
    stream >> esUsableDirectamente;
    e.setUsableDirectamente(esUsableDirectamente);

    bool compuesto;
    stream >> compuesto;
    if (compuesto)
    {
        stream >> count;
        for (int i = 0; i < count; i++)
        {
            ComponenteElemento *ce = new ComponenteElemento(&e);
            stream >> *ce;
            e.AddComponente(ce);
        }
    }
    return stream;
}




ComponenteElemento::ComponenteElemento(QObject *parent) :
        QObject(parent)
{
    parentElemento = NULL;
    cantidad = 0;
}

ComponenteElemento::~ComponenteElemento()
{
}

void ComponenteElemento::setElemento(Elemento *newElemento)
{
    parentElemento = newElemento;
}

Elemento *ComponenteElemento::getElemento() const
{
    return parentElemento;
}

void ComponenteElemento::setCantidad(double newCantidad)
{
    cantidad = newCantidad;
}

double ComponenteElemento::getCantidad() const
{
    return cantidad;
}

xml::XMLNode_ptr ComponenteElemento::toXMLTree()
{
    xml::XMLNode_ptr node(xml::XMLNode::createNode("component"));
    node->addAttribute("material", parentElemento->getName());
    node->addAttribute("ammount", QString::number(cantidad));
    return node;
}

bool ComponenteElemento::loadFromXMLTree(xml::XMLNode_ptr tree)
{
    Elemento *pe = DataStore::getInstance()->getMaterialLibrary()->getElemento(
                tree->getChildValue("material", true));
    setElemento(pe);
    cantidad = tree->getChildValue("ammount", true).toDouble();
    return true;
}

QDataStream &operator <<(QDataStream &stream, ComponenteElemento &e)
{
    stream << e.getElemento()->getName();
    stream << e.getCantidad();
    return stream;
}

QDataStream &operator >>(QDataStream &stream, ComponenteElemento &e)
{
    QString s;
    stream >> s;
    Elemento *pe = DataStore::getInstance()->getMaterialLibrary()->getElemento(s);
    e.setElemento(pe);
    double cantidad;
    stream >> cantidad;
    e.setCantidad(cantidad);
    return stream;
}

}
