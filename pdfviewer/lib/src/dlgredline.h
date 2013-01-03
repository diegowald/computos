#ifndef DLGREDLINE_H
#define DLGREDLINE_H

#include <QDialog>

namespace Ui {
class dlgRedline;
}

class dlgRedline : public QDialog
{
    Q_OBJECT
    
public:
    explicit dlgRedline(QWidget *parent = 0);
    ~dlgRedline();

    QString Name();
    QColor Color();
    
private slots:
    void on_btnPickColor_pressed();

private:
    Ui::dlgRedline *ui;
};

#endif // DLGREDLINE_H
