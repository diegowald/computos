#include "dlgnewelement.h"
#include "ui_dlgnewelement.h"
#include <boost/shared_ptr.hpp>
#include "datastore.h"

dlgNewElement::dlgNewElement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgNewElement)
{
    ui->setupUi(this);
    LoadComboMeasureUnits();
}

dlgNewElement::~dlgNewElement()
{
    delete ui;
}

void dlgNewElement::setPosibleNombreElemento(QString nombre)
{
    ui->txtNombre->setText(nombre);
}

QString dlgNewElement::NombreElemento()
{
    return ui->txtNombre->text();
}

void dlgNewElement::setTags(QString tags)
{
    ui->txtTags->setText(tags);
}

QString dlgNewElement::Tags()
{
    return ui->txtTags->text();
}

void dlgNewElement::setDescripcion(QString descripcion)
{
    ui->txtDescripcion->setText(descripcion);
}

QString dlgNewElement::Descripcion()
{
    return ui->txtDescripcion->toPlainText();
}

void dlgNewElement::LoadComboMeasureUnits()
{
    ui->cboMeasureUnit->clear();

    boost::shared_ptr<QStringList> nombres = DataStore::getInstance()->getUnitsLibrary()->getAllInternalNames();
    foreach(QString nombre, *nombres)
    {
        ui->cboMeasureUnit->addItem(DataStore::getInstance()->getUnitsLibrary()->getUnit(nombre)->getDisplayName(), nombre);
    }
}

void dlgNewElement::on_buttonBox_accepted()
{
    materialLibrary::Elemento *e = DataStore::getInstance()->getMaterialLibrary()->getElemento(
                ui->txtNombre->text().simplified());
    if (e == NULL)
    {
        e = new materialLibrary::Elemento(DataStore::getInstance()->getMaterialLibrary());
        e->setName(ui->txtNombre->text().simplified());
    }

    e->setDescription(ui->txtDescripcion->toHtml());

    QStringList tags = ui->txtTags->text().split(" ", QString::SkipEmptyParts);
    foreach (QString tag, tags)
    {
        e->addTag(tag);
    }

    e->setUsableDirectamente(ui->chkUsableDirectly->isChecked());
    e->setMeasureUnit(DataStore::getInstance()->getUnitsLibrary()->getUnit(ui->cboMeasureUnit->currentText()));

    DataStore::getInstance()->getMaterialLibrary()->addMaterial(e);
}
