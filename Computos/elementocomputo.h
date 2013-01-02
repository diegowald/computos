#ifndef ELEMENTOCOMPUTO_H
#define ELEMENTOCOMPUTO_H

#include <QObject>
#include <QMap>
#include "elementoconstructivo.h"
#include "elemento.h"
#include "cantidad.h"

namespace computo {

class ComponenteElementoComputo;

// El elemento de computo es el elemento empleado en el computo metrico de materiales.
class ElementoComputo : public QObject
{
    Q_OBJECT

public:
    explicit ElementoComputo(QObject *parent,
                             proyecto::ElementoConstructivo *refElementoConstructivo);

    explicit ElementoComputo(QObject *parent, materialLibrary::Elemento *refElemento);
    virtual ~ElementoComputo();

    proyecto::ElementoConstructivo *getElementoConstructivo();
    materialLibrary::Elemento *getElemento();

    void Compute();
    void Compute(double cantidadAComputar);
    double getCantidad();


    QList<ComponenteElementoComputo*> *getComponentes();
    void AddComponente(materialLibrary::Elemento *newElemento, double cantidad);

    bool esCompuesto() const; // Devuelve true si el elemento esta compuesto por otros materiales.
    QMap<QString, double> *getResumenMateriales();

private:
    double cantidad;
    proyecto::ElementoConstructivo *elementoConstructivo;
    materialLibrary::Elemento *elemento;
    QList<ComponenteElementoComputo*> *elementos;

    //QStringList tags;

signals:
    
public slots:
    
};

class ComponenteElementoComputo : public QObject
{
    Q_OBJECT

public:
    explicit ComponenteElementoComputo(QObject *parent,
                                       ElementoComputo *refElemento,
                                       materialLibrary::ComponenteElemento* refComponenteElemento);

    virtual ~ComponenteElementoComputo();

    void setElemento(materialLibrary::Elemento *newElemento);
    ElementoComputo *getElemento() const;

    materialLibrary::ComponenteElemento* getComponente();

    void Compute(double cantidadAComputar);
    //double getCantidad() const;

private:
    ElementoComputo *ElementoBase;
    materialLibrary::ComponenteElemento* ComponenteElementoBase;
    //double cantidad;
};

}
#endif // ELEMENTOCOMPUTO_H
