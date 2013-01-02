#ifndef CILINDRO_H
#define CILINDRO_H
#include "cantidad.h"

namespace cantidades
{

class Cilindro : public Cantidad
{
    Q_OBJECT
public:
    explicit Cilindro(QObject *parent = 0);
    virtual ~Cilindro();

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
    double radius;
    double height;
    
};

}
#endif // CILINDRO_H
