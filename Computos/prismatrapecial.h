#ifndef PRISMATRAPECIAL_H
#define PRISMATRAPECIAL_H
#include "cantidad.h"
#include "superficietrapecial.h"

namespace cantidades
{

class PrismaTrapecial : public Cantidad
{
    Q_OBJECT
public:
    explicit PrismaTrapecial(QObject *parent = 0);
    virtual ~PrismaTrapecial();

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
    SuperficieTrapecial trapecio;
    double alto;
    
};

}
#endif // PRISMATRAPECIAL_H
