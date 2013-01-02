#ifndef DLGPRISMAVOLUME_H
#define DLGPRISMAVOLUME_H

#include <QDialog>

namespace Ui {
class dlgPrismaVolume;
}

class dlgPrismaVolume : public QDialog
{
    Q_OBJECT
    
public:
    explicit dlgPrismaVolume(QWidget *parent = 0);
    ~dlgPrismaVolume();
    
    void setLargo(double value);
    void setAlto1(double value);
    void setAlto2(double value);
    void setAltura(double value);
    void setFormula(QString formula);
    double getLargo();
    double getAlto1();
    double getAlto2();
    double getAltura();

private:
    Ui::dlgPrismaVolume *ui;
};

#endif // DLGPRISMAVOLUME_H
