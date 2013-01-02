#ifndef DLGRAWVALUE_H
#define DLGRAWVALUE_H

#include <QDialog>

namespace Ui {
class dlgRawValue;
}

class dlgRawValue : public QDialog
{
    Q_OBJECT
    
public:
    explicit dlgRawValue(QWidget *parent = 0);
    ~dlgRawValue();

    void setValue(double value);
    double Value();
    
private:
    Ui::dlgRawValue *ui;
};

#endif // DLGRAWVALUE_H
