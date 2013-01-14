#include "dlglistselector.h"
#include "ui_dlglistselector.h"

dlgListSelector::dlgListSelector(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgListSelector)
{
    ui->setupUi(this);
}

dlgListSelector::~dlgListSelector()
{
    delete ui;
}

void dlgListSelector::addElements(QStringList elements)
{
    ui->cboSelection->clear();
    ui->cboSelection->addItems(elements);
}

QString dlgListSelector::selectedElement()
{
    return ui->cboSelection->currentText();
}
