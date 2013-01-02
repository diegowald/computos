#ifndef ELEMENTOCONSTRUCTIVO_H
#define ELEMENTOCONSTRUCTIVO_H

#include <QObject>
#include <QVector>
#include "xmlnode.h"
#include "cantidad.h"
#include "elemento.h"

namespace proyecto {
// El elemento constructivo es empleado en un proyecto
class ElementoConstructivo : public QObject
{
    Q_OBJECT
public:
    explicit ElementoConstructivo(QObject *parent = 0);
    virtual ~ElementoConstructivo();

    cantidades::Cantidad *getCantidad();
    void setCantidad(cantidades::Cantidad *newCantidad);

    materialLibrary::Elemento *getElemento();
    void setElemento(materialLibrary::Elemento *newElemento);

    QString getName();
    void setName(QString &newName);

    friend QDataStream &operator <<(QDataStream &stream, ElementoConstructivo &e);
    friend QDataStream &operator >>(QDataStream &stream, ElementoConstructivo &e);
    bool loadFromXMLTree(xml::XMLNode_ptr tree);
    xml::XMLNode_ptr toXMLTree();

private:

    QString name; // Descripcion del elemento constructivo, por ej: pared 1
    cantidades::Cantidad *cantidad; // Cantidad necesaria de elemento para poder construir
    materialLibrary::Elemento *elemento; // Elemento necesario para poder realizar el elemento constructivo
    
signals:
    
public slots:
public:
    static QString PART_TAG;
    static QString NAME_TAG;
    static QString ELEMENT_TAG;
};

}
#endif // ELEMENTOCONSTRUCTIVO_H

