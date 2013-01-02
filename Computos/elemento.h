#ifndef ELEMENTO_H
#define ELEMENTO_H

#include <boost/shared_ptr.hpp>
#include <QObject>
#include <QStringList>

#include "unit.h"
#include "xmlnode.h"

namespace materialLibrary {

class ComponenteElemento;

// La clase elemento define el elemento en la biblioteca de materiales
// este elemento es el que va a ser usado en el proyecto y en el computo metrico
class Elemento : public QObject
{
    Q_OBJECT
public:
    explicit Elemento(QObject *parent = 0);
    virtual ~Elemento();

    void setlibrary(QString &library);
    bool belongsTo(QString &library);

    bool checkIsComplete() const;

    QString getName() const;
    void setName(QString newName);

    QString getDescription() const;
    void setDescription(QString newDescription);

    unidades::Unit *getMeasureUnit() const;
    void setMeasureUnit(unidades::Unit *newUnit);

    boost::shared_ptr<QList<ComponenteElemento*> > getComponentes();
    void AddComponente(Elemento *newElemento, double cantidad);
    void AddComponente(ComponenteElemento *componente);
    void eliminarTodosComponentes();

    QString getTagsString();
    void addTag(QString newTag);

    void setUsableDirectamente(bool usable);
    bool UsableDirectamente();

    bool esCompuesto() const; // Devuelve true si el elemento esta compuesto por otros materiales.

    xml::XMLNode_ptr toXMLTree();
    bool loadFromXMLTree(xml::XMLNode_ptr tree);

    friend QDataStream &operator <<(QDataStream &stream, Elemento &e);
    friend QDataStream &operator >>(QDataStream &stream, Elemento &e);

private:
    QString name;
    QString description;
    unidades::Unit *measureUnit;
    QList<ComponenteElemento*> elementos;
    QStringList tags;
    bool usableDirectamente;

    QString _library;
    
signals:
    
public slots:
    
};

// La clase ComponenteElemento es la que define los elementos que tiene
// un determinado elemento compuesto.
class ComponenteElemento : public QObject
{
    Q_OBJECT
public:
    explicit ComponenteElemento(QObject *parent = 0);
    virtual ~ComponenteElemento();

    void setElemento(Elemento *newElemento);
    Elemento *getElemento() const;

    void setCantidad(double newCantidad);
    double getCantidad() const;

    xml::XMLNode_ptr toXMLTree();
    bool loadFromXMLTree(xml::XMLNode_ptr tree);

    friend QDataStream &operator <<(QDataStream &stream, ComponenteElemento &e);
    friend QDataStream &operator >>(QDataStream &stream, ComponenteElemento &e);
private:
    Elemento *parentElemento;
    double cantidad;

signals:


public slots:
};

}
#endif // ELEMENTO_H
