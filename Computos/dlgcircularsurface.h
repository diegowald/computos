#ifndef DLGCIRCULARSURFACE_H
#define DLGCIRCULARSURFACE_H

#include <QDialog>

namespace Ui {
class dlgCircularSurface;
}

class dlgCircularSurface : public QDialog
{
    Q_OBJECT
    
public:
    explicit dlgCircularSurface(QWidget *parent = 0);
    ~dlgCircularSurface();

    void setRadius(double radius);
    double getRadius() const;
    void setFormula(QString formula);
    
private:
    Ui::dlgCircularSurface *ui;
};

#endif // DLGCIRCULARSURFACE_H
