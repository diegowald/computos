#ifndef PERIMETROCIRCULAR_H
#define PERIMETROCIRCULAR_H
#include "cantidad.h"

namespace cantidades
{

class PerimetroCircular : public Cantidad
{
    Q_OBJECT
public:
    explicit PerimetroCircular(QObject *parent = 0);
    virtual ~PerimetroCircular();

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
};

}
#endif // PERIMETROCIRCULAR_H
