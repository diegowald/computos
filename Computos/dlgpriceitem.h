#ifndef DLGPRICEITEM_H
#define DLGPRICEITEM_H

#include <QDialog>
#include <listaprecios.h>

namespace Ui {
class dlgPriceItem;
}

class dlgPriceItem : public QDialog
{
    Q_OBJECT
    
public:
    explicit dlgPriceItem(QWidget *parent = 0);
    ~dlgPriceItem();
    
    void setElementoYMarca(listaPrecios::ListaPrecios *lista, QString elemento, QString Marca);

    void setData(listaPrecios::Precio *precio);


    double getPrecio();
    QString getMarca();
    QString getObservaciones();
    QString getUnidadVenta();
    double getRelacion();
    QString getElemento();
    bool Divisible();

private slots:
    void on_cboElement_currentIndexChanged(const QString &arg1);

    void on_btnNewElement_pressed();

    void on_cboSaleUnit_currentIndexChanged(const QString &arg1);

private:
    Ui::dlgPriceItem *ui;

    void loadElementos();
    void loadUnits();
    void loadPriceItem(listaPrecios::ListaPrecios *lista);
    void updateRelationLabel();
};

#endif // DLGPRICEITEM_H
