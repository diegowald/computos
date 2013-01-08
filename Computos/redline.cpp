#include "redline.h"

namespace pdf
{


RedLineElement::RedLineElement(QObject *parent) :
    QObject(parent)
{
}

Redline RedLineElement::asRedline()
{
    return  pdfRedline;
}

}
