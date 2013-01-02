#ifndef DLGLISTAPRECIOS_H
#define DLGLISTAPRECIOS_H

#include <QDialog>
#include <QDateTime>

namespace Ui {
class dlgListaPrecios;
}

class dlgListaPrecios : public QDialog
{
    Q_OBJECT
    
public:
    explicit dlgListaPrecios(QWidget *parent = 0);
    ~dlgListaPrecios();

    void setProviderName(QString providerName);
    void setNombreLista(QString ListName);
    void setVigencia(QDateTime vigencia);
    QString NombreLista();
    QDateTime Vigencia();
private:
    Ui::dlgListaPrecios *ui;
};

#endif // DLGLISTAPRECIOS_H
