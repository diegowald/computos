#ifndef DLGCOMPONENTE_H
#define DLGCOMPONENTE_H

#include <QDialog>

namespace Ui {
class dlgComponente;
}

class dlgComponente : public QDialog
{
    Q_OBJECT
    
public:
    explicit dlgComponente(QWidget *parent = 0);
    ~dlgComponente();

    void setMaterial(QString newMaterial);
    void setComponente(QString newComponente);
    void setCantidadComponente(double newCantidad);

    QString Componente();
    double Cantidad();

private slots:
    void on_cboMaterial_currentIndexChanged(int index);

private:
    Ui::dlgComponente *ui;

    void LoadComponentes();
};

#endif // DLGCOMPONENTE_H
