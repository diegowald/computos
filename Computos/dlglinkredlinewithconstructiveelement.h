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

    void setImage(QImage image);
    QString Author();
    QColor Color();
    QString Annotation();
    QString Element();

private slots:
    void on_btnNewMaterial_pressed();

    void on_btnPickColor_pressed();

private:
    Ui::dlgLinkRedlineWithConstructiveElement *ui;
};

#endif // DLGLINKREDLINEWITHCONSTRUCTIVEELEMENT_H
