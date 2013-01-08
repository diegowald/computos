#include "pdfredlining.h"

namespace pdf
{
PDFRedLining::PDFRedLining(QObject *parent) :
    QObject(parent)
{
}

QString PDFRedLining::name() const
{
    return filename;
}

QList<Redline> PDFRedLining::getRedlines()
{
    QList<Redline> res;
    foreach(RedLineElement *e, redlines.values())
    {
        res.push_back(e->asRedline());
    }
    return res;
}

}
