#ifndef REDLINE_H
#define REDLINE_H

#include <QObject>
#include "../pdfviewer/lib/src/utils/redlininghandler.h"

namespace pdf
{
class RedLineElement : public QObject
{
    Q_OBJECT
public:
    explicit RedLineElement(QObject *parent = 0);
    
signals:
    
public slots:

private:
    Redline pdfRedline;
};
}
#endif // REDLINE_H
