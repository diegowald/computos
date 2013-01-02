#ifndef DLGRECTANGULARSURFACE_H
#define DLGRECTANGULARSURFACE_H

#include <QDialog>

namespace Ui {
class dlgRectangularSurface;
}

class dlgRectangularSurface : public QDialog
{
    Q_OBJECT
    
public:
    explicit dlgRectangularSurface(QWidget *parent = 0);
    ~dlgRectangularSurface();
    void setLargo(double largo);
    void setAlto(double alto);
    double getLargo() const;
    double getAlto() const;
    void setFormula(QString formula);
private:
    Ui::dlgRectangularSurface *ui;
};

#endif // DLGRECTANGULARSURFACE_H
