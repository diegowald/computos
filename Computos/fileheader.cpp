#include "fileheader.h"

FileHeader::FileHeader(QString version, QString name, QObject *parent) :
    QObject(parent)
{
    appVersion = "1.0.0";
    objectVersion = version;
    objectName = name;
    magicNumber = "3001197330071971";
}

bool FileHeader::isValidFile()
{
    return ((appVersion == readAppVersion)
            && (objectVersion == readObjectVersion)
            && (objectName == readObjectName)
            && (magicNumber == readMagicNumber));
}

xml::XMLNode_ptr FileHeader::toXMLTree()
{
    xml::XMLNode_ptr tree(new xml::XMLNode("header", this));

    tree->addAttribute("app_version", appVersion);
    tree->addAttribute("object_version", objectVersion);
    tree->addAttribute("object_name", objectName);

    return tree;
}

QDataStream &operator <<(QDataStream &stream, FileHeader &fh)
{
    if (&fh == NULL)
        return stream;

    stream << fh.magicNumber;
    stream << fh.appVersion;
    stream << fh.objectName;
    stream << fh.objectVersion;

    return stream;
}

QDataStream &operator >>(QDataStream &stream, FileHeader &fh)
{
    if (&fh == NULL)
        return stream;

    stream >> fh.readMagicNumber;
    stream >> fh.readAppVersion;
    stream >> fh.readObjectName;
    stream >> fh.readObjectVersion;

    return stream;
}
