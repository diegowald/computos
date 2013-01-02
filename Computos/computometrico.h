#ifndef COMPUTOMETRICO_H
#define COMPUTOMETRICO_H
#include <boost/shared_ptr.hpp>
#include <QObject>
#include <QMap>
#include <QStringList>
#include "proyecto.h"
#include "elementocomputo.h"


namespace computo {
// Esta es la clase principal para realizar el computo metrico de materiales.
// Basicamente contiene una lista de los materiales empleados en el proyecto y
// la cantidad necesaria.
class ComputoMetrico : public QObject
{
    Q_OBJECT
public:
    explicit ComputoMetrico(QObject *parent, proyecto::Proyecto *proyectoAsignado, bool doAutomaticCalculations);
    virtual ~ComputoMetrico();

    proyecto::Proyecto *getProyecto();

    void Compute();

    boost::shared_ptr<QStringList> getElementosComputoNames();
    ElementoComputo *getElementoComputo(QString &name);

    boost::shared_ptr<QMap<QString, double> > getResumenMateriasPrimas();

private:
    proyecto::Proyecto *proyecto;
    bool automaticCalculations;

    QMap<QString, ElementoComputo*> elementosComputo;
    QMap<QString, double> resumenComputoMateriasPrimas;


    void addToResumenMateriasPrimas(ElementoComputo *elementoComputo);

signals:
    
public slots:
    
};

}
#endif // COMPUTOMETRICO_H
