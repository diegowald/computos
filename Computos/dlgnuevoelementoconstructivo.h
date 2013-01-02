#ifndef DLGNUEVOELEMENTOCONSTRUCTIVO_H
#define DLGNUEVOELEMENTOCONSTRUCTIVO_H

#include <QDialog>
#include "cantidad.h"

namespace Ui {
class dlgNuevoElementoConstructivo;
}

class dlgNuevoElementoConstructivo : public QDialog
{
    Q_OBJECT
    
public:
    explicit dlgNuevoElementoConstructivo(QWidget *parent = 0);
    ~dlgNuevoElementoConstructivo();
    void setMaterial(QString nombreMaterial);
    QString nombreElementoConstructivo() const;
    QString nombreMaterial() const;
    cantidades::Cantidad *cantidad();

    void setElementoConstructivo(QString name);
    void setCantidad(cantidades::Cantidad *cantidad);
    void setEditMode();


protected:
    void LoadCantidadesPosibles();
    void loadMateriales();
private slots:
    void on_btnIngresarValores_pressed();

    void on_cboCantidad_currentIndexChanged(int index);

    void on_cboMaterial_currentIndexChanged(int index);

private:
    Ui::dlgNuevoElementoConstructivo *ui;

    cantidades::Cantidad *cantidadSeleccionada;
    bool loading;
};

#endif // DLGNUEVOELEMENTOCONSTRUCTIVO_H
