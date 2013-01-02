#ifndef DLGSUPERFICIETRAPECIAL_H
#define DLGSUPERFICIETRAPECIAL_H

#include <QDialog>

namespace Ui {
class dlgSuperficieTrapecial;
}

class dlgSuperficieTrapecial : public QDialog
{
    Q_OBJECT
    
public:
    explicit dlgSuperficieTrapecial(QWidget *parent = 0);
    ~dlgSuperficieTrapecial();
    
    void setLargo(double largo);
    void setAlto1(double alto1);
    void setAlto2(double alto2);
    void setFormula(QString formula);
    double getLargo() const;
    double getAlto1() const;
    double getAlto2() const;
private:
    Ui::dlgSuperficieTrapecial *ui;
};

#endif // DLGSUPERFICIETRAPECIAL_H
