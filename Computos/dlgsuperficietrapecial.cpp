#include "dlgsuperficietrapecial.h"
#include "ui_dlgsuperficietrapecial.h"

dlgSuperficieTrapecial::dlgSuperficieTrapecial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgSuperficieTrapecial)
{
    ui->setupUi(this);
}

dlgSuperficieTrapecial::~dlgSuperficieTrapecial()
{
    delete ui;
}

void dlgSuperficieTrapecial::setLargo(double largo)
{
    ui->txtLargo->setText(QString::number(largo));
}

void dlgSuperficieTrapecial::setAlto1(double alto1)
{
    ui->txtAlto1->setText(QString::number(alto1));
}

void dlgSuperficieTrapecial::setAlto2(double alto2)
{
    ui->txtAlto2->setText(QString::number(alto2));
}

void dlgSuperficieTrapecial::setFormula(QString formula)
{
    ui->lblFormula->setText(formula);
}

double dlgSuperficieTrapecial::getLargo() const
{
    return ui->txtLargo->text().toDouble();
}

double dlgSuperficieTrapecial::getAlto1() const
{
    return ui->txtAlto1->text().toDouble();
}

double dlgSuperficieTrapecial::getAlto2() const
{
    return ui->txtAlto2->text().toDouble();
}
