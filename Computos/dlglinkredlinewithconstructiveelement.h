#ifndef DLGLINKREDLINEWITHCONSTRUCTIVEELEMENT_H
#define DLGLINKREDLINEWITHCONSTRUCTIVEELEMENT_H

#include <QDialog>

namespace Ui {
class dlgLinkRedlineWithConstructiveElement;
}

class dlgLinkRedlineWithConstructiveElement : public QDialog
{
    Q_OBJECT
    
public:
    explicit dlgLinkRedlineWithConstructiveElement(QWidget *parent = 0);
    ~dlgLinkRedlineWithConstructiveElement();
    
private:
    Ui::dlgLinkRedlineWithConstructiveElement *ui;
};

#endif // DLGLINKREDLINEWITHCONSTRUCTIVEELEMENT_H
