#ifndef SUPERFICIETRAPECIAL_H
#define SUPERFICIETRAPECIAL_H
#include "cantidad.h"

namespace cantidades {
class SuperficieTrapecial : public Cantidad
{
    Q_OBJECT
public:
    explicit SuperficieTrapecial(QObject *parent = 0);
    virtual ~SuperficieTrapecial();

    virtual double getValue();
    virtual void showInputDataDialogBox();
    virtual QDataStream &save(QDataStream &stream) const;
    virtual QDataStream &load(QDataStream &stream);
    virtual bool loadDataFromXMLTree(xml::XMLNode_ptr tree);
    virtual void dataToXMLTree(xml::XMLNode_ptr node);
    virtual QString getDimensions();
    virtual QString getFormula();

    void setLargo(double value);
    void setAlto1(double value);
    void setAlto2(double value);
    double getLargo();
    double getAlto1();
    double getAlto2();

protected:
    double longitud;
    double h1;
    double h2;
    
signals:
    
public slots:
    
};

}

#endif // SUPERFICIETRAPECIAL_H
