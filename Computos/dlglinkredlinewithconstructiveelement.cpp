#include "dlglinkredlinewithconstructiveelement.h"
#include "ui_dlglinkredlinewithconstructiveelement.h"

dlgLinkRedlineWithConstructiveElement::dlgLinkRedlineWithConstructiveElement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgLinkRedlineWithConstructiveElement)
{
    ui->setupUi(this);
}

dlgLinkRedlineWithConstructiveElement::~dlgLinkRedlineWithConstructiveElement()
{
    delete ui;
}
