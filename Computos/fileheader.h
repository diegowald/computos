#ifndef FILEHEADER_H
#define FILEHEADER_H

#include <QObject>
#include "xmlnode.h"

class FileHeader : public QObject
{
    Q_OBJECT
public:
    explicit FileHeader(QString version, QString name, QObject *parent = 0);

    xml::XMLNode_ptr toXMLTree();
    
    friend QDataStream &operator <<(QDataStream &stream, FileHeader &fh);
    friend QDataStream &operator >>(QDataStream &stream, FileHeader &fh);

    bool isValidFile();
signals:
    
public slots:
    
private:
    QString appVersion;
    QString objectVersion;
    QString objectName;
    QString magicNumber;

    QString readAppVersion;
    QString readObjectVersion;
    QString readObjectName;
    QString readMagicNumber;

};

#endif // FILEHEADER_H
