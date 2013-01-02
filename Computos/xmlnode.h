#ifndef XMLNODE_H
#define XMLNODE_H

#include <QObject>
#include <boost/shared_ptr.hpp>
#include <QVector>
#include <QXmlStreamWriter>

namespace xml
{

class XMLNode;

typedef boost::shared_ptr<XMLNode> XMLNode_ptr;

class XMLNode : public QObject
{
    Q_OBJECT
public:
    static XMLNode_ptr createNode(QString Name, QObject *parent = 0);
    explicit XMLNode(QString Name, QObject *parent = 0);
    explicit XMLNode(QString Name, QString Value, QObject *parent = 0);

    virtual ~XMLNode();

    QString Name();
    virtual QString Value();

    virtual void setValue(QString newValue);
    bool saveIntoXML(QXmlStreamWriter &stream);

    QString getChildValue(QString key, bool mandatory, QString defaultValue = "");

    virtual void addAttribute(QString attrName, QString attrValue);
    virtual void addChild(XMLNode_ptr child);

    XMLNode_ptr getChildNode(QString key, bool mandatory);
    XMLNode_ptr getChildNode(int index, bool mandatory);
signals:
    
public slots:

private:
    QString name;
    QString value;
    QVector<XMLNode_ptr> children;
};

}
#endif // XMLNODE_H
