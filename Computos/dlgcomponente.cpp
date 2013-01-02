#include "dlgcomponente.h"
#include "ui_dlgcomponente.h"
#include "datastore.h"
#include <boost/shared_ptr.hpp>

dlgComponente::dlgComponente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgComponente)
{
    ui->setupUi(this);
    LoadComponentes();
}

dlgComponente::~dlgComponente()
{
    delete ui;
}

void dlgComponente::setMaterial(QString newMaterial)
{
    ui->txtMaterialPadre->setText(newMaterial);
}

void dlgComponente::setComponente(QString newComponente)
{
    int index = ui->cboMaterial->findData(newComponente);
    ui->cboMaterial->setCurrentIndex(index);
}

void dlgComponente::setCantidadComponente(double newCantidad)
{
    ui->txtCantidad->setText(QString::number(newCantidad));
}

QString dlgComponente::Componente()
{
    return ui->cboMaterial->itemText(ui->cboMaterial->currentIndex());
}

double dlgComponente::Cantidad()
{
    return ui->txtCantidad->text().toDouble();
}

void dlgComponente::LoadComponentes()
{
    ui->cboMaterial->clear();
    boost::shared_ptr<QStringList> materiales = DataStore::getInstance()->getMaterialLibrary()->getAllNames(false);
    foreach(QString material, *materiales)
    {
        ui->cboMaterial->addItem(material, material);
    }
}

void dlgComponente::on_cboMaterial_currentIndexChanged(int index)
{
    if (index >= 0)
    {
        QString material = ui->cboMaterial->itemData(index).toString();
        materialLibrary::Elemento *el = DataStore::getInstance()->getMaterialLibrary()->getElemento(material);
        ui->txtUnidad->setText(el->getMeasureUnit()->getDisplayName());
        ui->txtCompuesto->setText(el->esCompuesto() ? tr("Yes") : tr("No"));
    }
    else
    {
        ui->txtUnidad->clear();
        ui->txtCompuesto->clear();
    }
}
