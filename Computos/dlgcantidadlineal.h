#ifndef DLGCANTIDADLINEAL_H
#define DLGCANTIDADLINEAL_H

#include <QDialog>

namespace Ui {
class dlgCantidadLineal;
}

class dlgCantidadLineal : public QDialog
{
    Q_OBJECT
    
public:
    explicit dlgCantidadLineal(QWidget *parent = 0);
    ~dlgCantidadLineal();

    void setUnit(QString unit);
    void setLongitud(double value);
    void setFormula(QString formula);
    double getLongitud() const;
    
private:
    Ui::dlgCantidadLineal *ui;
};

#endif // DLGCANTIDADLINEAL_H
