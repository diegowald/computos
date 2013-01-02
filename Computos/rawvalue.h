#ifndef RAWVALUE_H
#define RAWVALUE_H

#include "cantidad.h"
#include "dlgrawvalue.h"
#include <QIcon>
#include "xmlhelper.h"

namespace cantidades {

template <dimension::DIMENSION _dim, const char *_immutableName, const char *_shape>
class RawValue : public Cantidad
{
    //Q_OBJECT
public:
    explicit RawValue(QObject *parent = 0)
     : Cantidad(_dim, _immutableName, tr(_immutableName), _shape, parent), value(0.0)
    {
    }

    virtual ~RawValue()
    {
    }

    virtual double getValue()
    {
        return value;
    }

    virtual QString getFormula()
    {
        return "";
    }

    virtual void showInputDataDialogBox()
    {
        dlgRawValue dlg;
        dlg.setValue(value);
        QPixmap pixmap(shape);
        QIcon icon(pixmap);
        dlg.setWindowIcon(icon);
        if (dlg.exec() == QDialog::Accepted)
        {
            value = dlg.Value();
        }
    }

    virtual QDataStream &save(QDataStream &stream) const
    {
        stream << value;
        return stream;
    }

    virtual QDataStream &load(QDataStream &stream)
    {
        stream >> value;
        return stream;
    }

    virtual QString getDimensions()
    {
        return QString::number(value);
    }

    virtual void dataToXMLTree(xml::XMLNode_ptr node)
    {
        node->addAttribute("value", QString::number(value));
    }

    virtual bool loadDataFromXMLTree(xml::XMLNode_ptr tree)
    {
        value = tree->getChildValue("value", true).toDouble();
        return true;
    }

signals:
    
public slots:
    
private:
    double value;
};

/*char xx[] = "Hola";
typedef RawValue<dimension::LINEAR, xx, xx, xx> x;*/

char ZeroDim_immName[] = "DimensionLessValue";
char ZeroDim_shape[] = ":/dlg/dock/value";
typedef RawValue<dimension::DIMENSIONLESS, ZeroDim_immName, ZeroDim_shape> DimensionLessValue;

char Linear_immName[] = "LinearValue";
char Linear_shape[] = ":/dlg/dock/value";
typedef RawValue<dimension::LINEAR, Linear_immName, Linear_shape> LinearValue;

char Surface_immName[] = "SurfaceValue";
char Surface_shape[] = ":/dlg/dock/value";
typedef RawValue<dimension::SURFACE, Surface_immName, Surface_shape> SurfaceValue;

char Volume_immName[] = "VolumeValue";
char Volume_shape[] = ":/dlg/dock/value";
typedef RawValue<dimension::VOLUME, Volume_immName, Volume_shape> VolumeValue;


char Time_immName[] = "TimeValue";
char Time_shape[] = ":/dlg/dock/time";
typedef RawValue<dimension::TIME, Time_immName, Time_shape> TimeValue;

}
#endif // RAWVALUE_H
