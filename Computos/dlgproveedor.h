#ifndef DLGPROVEEDOR_H
#define DLGPROVEEDOR_H

#include <QDialog>

namespace Ui {
class dlgProveedor;
}

class dlgProveedor : public QDialog
{
    Q_OBJECT
    
public:
    explicit dlgProveedor(QWidget *parent = 0);
    ~dlgProveedor();
    
    void setNombre(QString value);
    void setAddress(QString value);
    void setContactName(QString value);
    void setTelephone(QString value);
    void setEmail(QString value);

    QString Nombre();
    QString Address();
    QString ContactName();
    QString Telephone();
    QString EMail();

private:
    Ui::dlgProveedor *ui;
};

#endif // DLGPROVEEDOR_H
