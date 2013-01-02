#include "dlgprismavolume.h"
#include "ui_dlgprismavolume.h"

dlgPrismaVolume::dlgPrismaVolume(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgPrismaVolume)
{
    ui->setupUi(this);
}

dlgPrismaVolume::~dlgPrismaVolume()
{
    delete ui;
}

void dlgPrismaVolume::setLargo(double value)
{
    ui->txtLargo->setText(QString::number(value));
}

void dlgPrismaVolume::setAlto1(double value)
{
    ui->txtAlto1->setText(QString::number(value));
}

void dlgPrismaVolume::setAlto2(double value)
{
    ui->txtAlto2->setText(QString::number(value));
}

void dlgPrismaVolume::setAltura(double value)
{
    ui->txtHeight2->setText(QString::number(value));
}

void dlgPrismaVolume::setFormula(QString formula)
{
    ui->lblFormula->setText(formula);
}

double dlgPrismaVolume::getLargo()
{
    return ui->txtLargo->text().toDouble();
}

double dlgPrismaVolume::getAlto1()
{
    return ui->txtAlto1->text().toDouble();
}

double dlgPrismaVolume::getAlto2()
{
    return ui->txtAlto2->text().toDouble();
}

double dlgPrismaVolume::getAltura()
{
    return ui->txtHeight2->text().toDouble();
}
