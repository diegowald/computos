#ifndef CANTIDAD_H
#define CANTIDAD_H

#include <QObject>
#include "Dimension.h"
#include <QDataStream>
#include "xmlnode.h"

namespace cantidades {

class Cantidad : public QObject
{
    Q_OBJECT
public:
    explicit Cantidad(dimension::DIMENSION dim, QString ImmutableName, QString cantName, QString Shape, QObject *parent = 0);
    virtual ~Cantidad();

    virtual QString getFormula() = 0;
    virtual double getValue() = 0;
    virtual void showInputDataDialogBox() = 0;
    virtual QDataStream &save(QDataStream &stream) const = 0;
    virtual QDataStream &load(QDataStream &stream) = 0;

    virtual QString getDimensions() = 0;
    bool loadFromXMLTree(xml::XMLNode_ptr tree);
    virtual bool loadDataFromXMLTree(xml::XMLNode_ptr tree) = 0;
    xml::XMLNode_ptr toXMLTree();
    virtual void dataToXMLTree(xml::XMLNode_ptr node) = 0;

    QString getShape() const;
    QString getName() const;
    QString getimmutableName() const;
    dimension::DIMENSION getDimension() const;

    friend QDataStream &operator <<(QDataStream &stream, const Cantidad &c)
    {
        return c.save(stream);
    }

    friend QDataStream &operator >>(QDataStream &stream, Cantidad &c)
    {
        return c.load(stream);
    }

protected:

protected:
    dimension::DIMENSION _dimension;
    QString immutableName;
    QString name;
    QString shape;

signals:
    
public slots:

public:
    static QString CANT_TAG;
    static QString NAME_TAG;

};

}
#endif // CANTIDAD_H
