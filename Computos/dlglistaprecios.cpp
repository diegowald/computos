#include "dlglistaprecios.h"
#include "ui_dlglistaprecios.h"

dlgListaPrecios::dlgListaPrecios(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgListaPrecios)
{
    ui->setupUi(this);
    ui->dtValidity->setDateTime(QDateTime::currentDateTime());
}

dlgListaPrecios::~dlgListaPrecios()
{
    delete ui;
}

void dlgListaPrecios::setProviderName(QString providerName)
{
    ui->lblProvider->setText(providerName);
}

void dlgListaPrecios::setNombreLista(QString ListName)
{
    ui->txtName->setText(ListName);
}

void dlgListaPrecios::setVigencia(QDateTime vigencia)
{
    ui->dtValidity->setDateTime(vigencia);
}

QString dlgListaPrecios::NombreLista()
{
    return ui->txtName->text();
}

QDateTime dlgListaPrecios::Vigencia()
{
    return ui->dtValidity->dateTime();
}
