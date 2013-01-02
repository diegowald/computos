#ifndef CANTIDADUNITARIA_H
#define CANTIDADUNITARIA_H
#include "cantidad.h"

namespace cantidades {

class CantidadUnitaria : public Cantidad
{
    Q_OBJECT
public:
    explicit CantidadUnitaria(QObject *parent = 0);
    virtual ~CantidadUnitaria();

    virtual double getValue();
    virtual QString getFormula();
    virtual void showInputDataDialogBox();
    virtual QString getDimensions();
    virtual QDataStream &save(QDataStream &stream) const;
    virtual QDataStream &load(QDataStream &stream);
    virtual bool loadDataFromXMLTree(xml::XMLNode_ptr tree);
    virtual void dataToXMLTree(xml::XMLNode_ptr node);

signals:
    
public slots:
    
private:
    double value;
};

}
#endif // CANTIDADUNITARIA_H
