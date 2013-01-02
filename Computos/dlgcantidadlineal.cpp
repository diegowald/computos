#include "dlgcantidadlineal.h"
#include "ui_dlgcantidadlineal.h"

dlgCantidadLineal::dlgCantidadLineal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgCantidadLineal)
{
    ui->setupUi(this);
}

dlgCantidadLineal::~dlgCantidadLineal()
{
    delete ui;
}

void dlgCantidadLineal::setLongitud(double value)
{
    ui->txtLongitud->setText(QString::number(value));
}

void dlgCantidadLineal::setFormula(QString)
{
}

void dlgCantidadLineal::setUnit(QString unit)
{
    ui->lblLabel->setText(tr("Length [%1]").arg(unit));
}

double dlgCantidadLineal::getLongitud() const
{
    return ui->txtLongitud->text().toDouble();
}
