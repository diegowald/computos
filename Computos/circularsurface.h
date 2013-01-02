#ifndef CIRCULARSURFACE_H
#define CIRCULARSURFACE_H
#include "cantidad.h"

namespace cantidades {
class CircularSurface : public Cantidad
{
    Q_OBJECT
public:
    explicit CircularSurface(QObject *parent = 0);
    virtual ~CircularSurface();
    
    virtual double getValue();
    virtual QString getFormula();
    virtual void showInputDataDialogBox();
    virtual QString getDimensions();
    virtual QDataStream &save(QDataStream &stream) const;
    virtual QDataStream &load(QDataStream &stream);
    virtual bool loadDataFromXMLTree(xml::XMLNode_ptr tree);
    virtual void dataToXMLTree(xml::XMLNode_ptr node);
private:
    double radius;
signals:
    
public slots:
    
};

}
#endif // CIRCULARSURFACE_H
