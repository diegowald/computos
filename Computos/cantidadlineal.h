#ifndef CANTIDADLINEAL_H
#define CANTIDADLINEAL_H
#include "cantidad.h"
namespace cantidades {


class CantidadLineal : public Cantidad
{
    Q_OBJECT
public:
    explicit CantidadLineal(QObject *parent = 0);
    virtual ~CantidadLineal();

    virtual double getValue();
    virtual QString getFormula();
    virtual void showInputDataDialogBox();
    virtual QString getDimensions();
    virtual QDataStream &save(QDataStream &stream) const;
    virtual QDataStream &load(QDataStream &stream);
    virtual bool loadDataFromXMLTree(xml::XMLNode_ptr tree);
    virtual void dataToXMLTree(xml::XMLNode_ptr node);

private:
    double value;

signals:
    
public slots:
    
};

}
#endif // CANTIDADLINEAL_H
