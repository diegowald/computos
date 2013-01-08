#ifndef PDFREDLINING_H
#define PDFREDLINING_H

#include <QObject>
#include <QMap>
#include "redline.h"

namespace pdf
{
class PDFRedLining : public QObject
{
    Q_OBJECT
public:
    explicit PDFRedLining(QObject *parent = 0);
    QString name() const;
    QList<Redline> getRedlines();
private:
    QString filename;
    QMap<QString, RedLineElement*> redlines;
signals:

public slots:

private:


};
}
#endif // PDFREDLINING_H
