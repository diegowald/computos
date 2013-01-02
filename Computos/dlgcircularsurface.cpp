#include "dlgcircularsurface.h"
#include "ui_dlgcircularsurface.h"

dlgCircularSurface::dlgCircularSurface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgCircularSurface)
{
    ui->setupUi(this);
}

dlgCircularSurface::~dlgCircularSurface()
{
    delete ui;
}

void dlgCircularSurface::setRadius(double radius)
{
    ui->txtRadius->setText(QString::number(radius));
}

double dlgCircularSurface::getRadius() const
{
    return ui->txtRadius->text().toDouble();
}

void dlgCircularSurface::setFormula(QString formula)
{
    ui->lblFormula->setText(formula);
}
