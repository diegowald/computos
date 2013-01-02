#include "dlgrectangularsurface.h"
#include "ui_dlgrectangularsurface.h"

dlgRectangularSurface::dlgRectangularSurface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgRectangularSurface)
{
    ui->setupUi(this);
}

dlgRectangularSurface::~dlgRectangularSurface()
{
    delete ui;
}

void dlgRectangularSurface::setLargo(double largo)
{
    ui->txtLargo->setText(QString::number(largo));
}

void dlgRectangularSurface::setAlto(double alto)
{
    ui->txtAlto->setText(QString::number(alto));
}

double dlgRectangularSurface::getLargo() const
{
    return ui->txtLargo->text().toDouble();
}

double dlgRectangularSurface::getAlto() const
{
    return ui->txtAlto->text().toDouble();
}

void dlgRectangularSurface::setFormula(QString formula)
{
    ui->lblFormula->setText(formula);
}
