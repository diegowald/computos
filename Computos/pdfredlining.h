#ifndef PDFREDLINING_H
#define PDFREDLINING_H

#include <QObject>
#include <QMap>
#include "redline.h"
#include "xmlnode.h"

namespace pdf
{
class PDFRedLining : public QObject
{
    Q_OBJECT
public:
    explicit PDFRedLining(QString FileName, QObject *parent = 0);
    QString name() const;
    QList<Redline> getRedlines();
    bool loadFromXMLTree(xml::XMLNode_ptr tree);
    xml::XMLNode_ptr toXMLTree();
private:
    QString filename;
    QMap<QString, RedLineElement*> redlines;
signals:

public slots:

private:

public:
    static QString PDF_TAG;
    static QString NAME_TAG;
    static QString REDLINES_TAG;
    static QString COUNT_TAG;
};
}
#endif // PDFREDLINING_H
