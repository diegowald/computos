#include "dlgrawvalue.h"
#include "ui_dlgrawvalue.h"

dlgRawValue::dlgRawValue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgRawValue)
{
    ui->setupUi(this);
}

dlgRawValue::~dlgRawValue()
{
    delete ui;
}

void dlgRawValue::setValue(double value)
{
    ui->txtValue->setText(QString::number(value));
}

double dlgRawValue::Value()
{
    return ui->txtValue->text().toDouble();
}
