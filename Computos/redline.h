#ifndef REDLINE_H
#define REDLINE_H

#include <QObject>
#include "../pdfviewer/lib/src/utils/redlininghandler.h"
#include "xmlnode.h"

namespace pdf
{
class RedLineElement : public QObject
{
    Q_OBJECT
public:
    explicit RedLineElement(QObject *parent = 0);
    Redline asRedline();

    QString name();

    bool loadFromXMLTree(xml::XMLNode_ptr tree);
    xml::XMLNode_ptr toXMLTree();
signals:
    
public slots:

private:
    Redline pdfRedline;

public:
    static QString REDLINE_TAG;
    static QString NAME_TAG;
    static QString PAGENUMBER_TAG;
    static QString LEFT_TAG;
    static QString TOP_TAG;
    static QString RIGHT_TAG;
    static QString BOTTOM_TAG;
    static QString AUTHOR_TAG;
    static QString REF_TAG;
    static QString ALPHA_TAG;
    static QString RED_TAG;
    static QString GREEN_TAG;
    static QString BLUE_TAG;
    static QString IMAGE_TAG;

};
}
#endif // REDLINE_H
