#ifndef AUTHOR_H
#define AUTHOR_H

#include <QObject>
#include <QDataStream>
#include "xmlnode.h"

class Author : public QObject
{
    Q_OBJECT
public:
    explicit Author(QObject *parent = 0);
    virtual ~Author();

    QString Name();
    void setName(QString newValue);
    QString EMail();
    void setEMail(QString newEMail);

    bool loadFromXMLTree(xml::XMLNode_ptr tree);
    xml::XMLNode_ptr toXMLTree();

    friend QDataStream &operator <<(QDataStream &stream, const Author &author)
    {
        stream << author.name;
        stream << author.email;

        return stream;
    }

    friend QDataStream &operator >>(QDataStream &stream, Author &author)
    {
        stream >> author.name;
        stream >> author.email;

        return stream;
    }

    static QString AUTHOR_TAG;
    static QString NAME_TAG;
    static QString EMAIL_TAG;
signals:
    
public slots:
    
private:
    QString name;
    QString email;
};

#endif // AUTHOR_H
