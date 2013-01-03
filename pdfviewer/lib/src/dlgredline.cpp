#include "dlgredline.h"
#include "ui_dlgredline.h"
#include <QColorDialog>

dlgRedline::dlgRedline(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgRedline)
{
    ui->setupUi(this);
}

dlgRedline::~dlgRedline()
{
    delete ui;
}

void dlgRedline::on_btnPickColor_pressed()
{
    QColorDialog dlg(this);
    dlg.exec();
    if (dlg.result() == dlg.Accepted)
    {
        QPalette palette = ui->frmColor->palette();
        palette.setColor(ui->frmColor->backgroundRole(), dlg.currentColor());
        ui->frmColor->setPalette(palette);
    }
}

QString dlgRedline::Name()
{
    return ui->txtName->text();
}

QColor dlgRedline::Color()
{
    QPalette palette = ui->frmColor->palette();
    return palette.color(ui->frmColor->backgroundRole());
}
