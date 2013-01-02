#ifndef SUPERFICIEPOLIGONAL_H
#define SUPERFICIEPOLIGONAL_H

#include <QVector>

#include "cantidad.h"

namespace cantidades {

struct POINT_2D
{
    double x;
    double y;
};

class SuperficiePoligonal : public Cantidad
{
    Q_OBJECT
public:
    explicit SuperficiePoligonal(QObject *parent = 0);
    virtual ~SuperficiePoligonal();
    
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
    QVector<POINT_2D> coordinates;
    double area;
    bool areaCalculada;
};

}
#endif // SUPERFICIEPOLIGONAL_H
