#include "dlgproveedor.h"
#include "ui_dlgproveedor.h"

dlgProveedor::dlgProveedor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgProveedor)
{
    ui->setupUi(this);
}

dlgProveedor::~dlgProveedor()
{
    delete ui;
}

void dlgProveedor::setNombre(QString value)
{
    ui->txtName->setText(value);
}

void dlgProveedor::setAddress(QString value)
{
    ui->txtAddress->setPlainText(value);
}

void dlgProveedor::setContactName(QString value)
{
    ui->txtContact->setText(value);
}

void dlgProveedor::setTelephone(QString value)
{
    ui->txtTelephone->setText(value);
}

void dlgProveedor::setEmail(QString value)
{
    ui->txtEMail->setText(value);
}

QString dlgProveedor::Nombre()
{
    return ui->txtName->text();
}

QString dlgProveedor::Address()
{
    return ui->txtAddress->toPlainText();
}

QString dlgProveedor::ContactName()
{
    return ui->txtContact->text();
}

QString dlgProveedor::Telephone()
{
    return ui->txtTelephone->text();
}

QString dlgProveedor::EMail()
{
    return ui->txtEMail->text();
}
