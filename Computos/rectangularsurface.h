#ifndef RECTANGULARSURFACE_H
#define RECTANGULARSURFACE_H

#include "superficietrapecial.h"

namespace cantidades {


class RectangularSurface : public SuperficieTrapecial
{
    Q_OBJECT
public:
    explicit RectangularSurface(QObject *parent = 0);
    virtual ~RectangularSurface();
    virtual void showInputDataDialogBox();
    virtual QString getDimensions();
signals:
    
public slots:
    
};

}

#endif // RECTANGULARSURFACE_H
