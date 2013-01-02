#include "dlgpriceitem.h"
#include "ui_dlgpriceitem.h"
#include "datastore.h"
#include <boost/shared_ptr.hpp>
#include "dlgnewelement.h"

dlgPriceItem::dlgPriceItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgPriceItem)
{
    ui->setupUi(this);
    loadElementos();
    loadUnits();
}

dlgPriceItem::~dlgPriceItem()
{
    delete ui;
}

void dlgPriceItem::setElementoYMarca(listaPrecios::ListaPrecios *lista, QString elemento, QString Marca)
{
    if (elemento.size() > 0)
    {
        ui->cboElement->setCurrentIndex(ui->cboElement->findText(elemento));
        ui->cboElement->setEnabled(false);
    }
    ui->txtBrand->setText(Marca);

    if ((elemento.size() > 0) && (Marca.size() > 0))
        loadPriceItem(lista);
}

void dlgPriceItem::on_cboElement_currentIndexChanged(const QString &arg1)
{
    if (arg1.size() > 0)
    {
        ui->lblElementUnit->setText(
                    DataStore::getInstance()->getMaterialLibrary()->getElemento(arg1)->getMeasureUnit()->getDisplayName());
        updateRelationLabel();
    }
}


void dlgPriceItem::loadElementos()
{
    ui->cboElement->clear();
    QString filter = "";
    boost::shared_ptr<QStringList> elementos = DataStore::getInstance()->getMaterialLibrary()->getAllNames(filter, false);
    foreach (QString elemento, *elementos)
    {
        ui->cboElement->addItem(elemento, elemento);
    }
}

void dlgPriceItem::loadUnits()
{
    boost::shared_ptr<QStringList> unidades = DataStore::getInstance()->getUnitsLibrary()->getAllInternalNames();
    foreach (QString unidad, *unidades)
    {
        ui->cboSaleUnit->addItem(DataStore::getInstance()->getUnitsLibrary()->getUnit(unidad)->getDisplayName(), unidad);
    }
}

double dlgPriceItem::getPrecio()
{
    return ui->txtPrice->text().toDouble();
}

QString dlgPriceItem::getMarca()
{
    return ui->txtBrand->text();
}

QString dlgPriceItem::getElemento()
{
    return ui->cboElement->currentText();
}

QString dlgPriceItem::getObservaciones()
{
    return ui->txtNotes->toPlainText();
}

QString dlgPriceItem::getUnidadVenta()
{
    return ui->cboSaleUnit->currentText();
}

double dlgPriceItem::getRelacion()
{
    return ui->txtRelation->text().toDouble();
}

bool dlgPriceItem::Divisible()
{
    return ui->chkDivisible->isChecked();
}

void dlgPriceItem::loadPriceItem(listaPrecios::ListaPrecios *lista)
{
    listaPrecios::Precio *p = lista->getPrecio(ui->cboElement->currentText(), ui->txtBrand->text());
    setData(p);
}


void dlgPriceItem::setData(listaPrecios::Precio *precio)
{
    if (precio->getNombreElemento().size() > 0)
        ui->cboElement->setCurrentIndex(ui->cboElement->findText(precio->getNombreElemento()));
    ui->txtPrice->setText(QString::number(precio->getPrecio()));
    ui->txtRelation->setText(QString::number(precio->Relacion()));
    ui->txtNotes->clear();
    ui->txtNotes->insertPlainText(precio->Observaciones());
    ui->chkDivisible->setChecked(precio->esFraccionable());
    if (precio->getUnidadVenta() != NULL)
        ui->cboSaleUnit->setCurrentIndex(ui->cboSaleUnit->findText(precio->getUnidadVenta()->getDisplayName()));
    ui->txtNombreEnListaDePrecios->setText(precio->NombreEnListaPrecios());
    ui->txtPriceListUnitLabel->setText(precio->SalesUnitBrand());
    ui->txtBrand->setText(precio->Marca());
}

void dlgPriceItem::on_btnNewElement_pressed()
{
    dlgNewElement dlg(this);
    dlg.setPosibleNombreElemento(ui->txtNombreEnListaDePrecios->text());
    dlg.setTags(ui->txtNotes->toPlainText());
    dlg.setDescripcion(ui->txtNotes->toPlainText());
    if (dlg.exec() == QDialog::Accepted)
    {
        loadElementos();
        ui->cboElement->setCurrentIndex(ui->cboElement->findText(dlg.NombreElemento()));
    }
}


void dlgPriceItem::updateRelationLabel()
{
    QString relationLabel = tr("Relation %1/%2").arg(ui->lblElementUnit->text()).arg(ui->cboSaleUnit->currentText());
    ui->lblRelation->setText(relationLabel);
}

void dlgPriceItem::on_cboSaleUnit_currentIndexChanged(const QString &)
{
    updateRelationLabel();
}
