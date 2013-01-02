#include "dlgnuevoelementoconstructivo.h"
#include "ui_dlgnuevoelementoconstructivo.h"

#include <QPixmap>
#include "datastore.h"


dlgNuevoElementoConstructivo::dlgNuevoElementoConstructivo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgNuevoElementoConstructivo)
{
    ui->setupUi(this);

    cantidadSeleccionada = NULL;
    ui->txtValue->clear();
    loading = false;
    loadMateriales();
}

dlgNuevoElementoConstructivo::~dlgNuevoElementoConstructivo()
{
    delete ui;
}

void dlgNuevoElementoConstructivo::setMaterial(QString nombreMaterial)
{
    if (nombreMaterial.size() != 0)
    {
        ui->cboMaterial->setCurrentIndex(ui->cboMaterial->findText(nombreMaterial));
        ui->cboMaterial->setEnabled(ui->cboMaterial->currentText().size() > 0);
    }
    else
    {
        ui->cboMaterial->setEnabled(true);
    }
    LoadCantidadesPosibles();
}

QString dlgNuevoElementoConstructivo::nombreElementoConstructivo() const
{
    return ui->txtNombre->text();
}

QString dlgNuevoElementoConstructivo::nombreMaterial() const
{
    return ui->cboMaterial->currentText();
}

cantidades::Cantidad *dlgNuevoElementoConstructivo::cantidad()
{
    return  cantidadSeleccionada;
}

void dlgNuevoElementoConstructivo::LoadCantidadesPosibles()
{
    if (ui->cboMaterial->currentText().size() == 0)
        return;

    materialLibrary::Elemento *elemento =
            DataStore::getInstance()->getMaterialLibrary()->getElemento(
                ui->cboMaterial->currentText());

    if (elemento == NULL)
        return;

    boost::shared_ptr<QStringList> nombresCantidades = DataStore::getInstance()->getCantidadesLibrary()->getAllNames(
                elemento->getMeasureUnit()->Dimension());

    ui->cboCantidad->clear();
    foreach (QString nombre, *nombresCantidades)
    {
        QString x = nombre;

        cantidades::Cantidad  *c = DataStore::getInstance()->getCantidadesLibrary()->createCantidad(nombre);
        QPixmap pixmap(c->getShape());
        QIcon icon(pixmap);
        QString y = c->getimmutableName();
        ui->cboCantidad->addItem(icon, x, y);
        delete c;
    }
}

void dlgNuevoElementoConstructivo::loadMateriales()
{
    loading = true;
    ui->cboMaterial->clear();
    boost::shared_ptr<QStringList> materiales = DataStore::getInstance()->getMaterialLibrary()->getAllNames(false);
    foreach (QString material, *materiales)
    {
        QString x = material;
        ui->cboMaterial->addItem(x);
    }
    loading = false;
}

void dlgNuevoElementoConstructivo::on_btnIngresarValores_pressed()
{
    cantidadSeleccionada->showInputDataDialogBox();
    ui->txtValue->setText(QString::number(cantidadSeleccionada->getValue()));
}

void dlgNuevoElementoConstructivo::setElementoConstructivo(QString name)
{
    ui->txtNombre->setText(name);
}

void dlgNuevoElementoConstructivo::setCantidad(cantidades::Cantidad *cantidad)
{
    cantidadSeleccionada = cantidad;
    int index = ui->cboCantidad->findText(cantidad->getName());
    ui->cboCantidad->setCurrentIndex(index);
}

void dlgNuevoElementoConstructivo::setEditMode()
{
    ui->txtNombre->setEnabled(false);
}

void dlgNuevoElementoConstructivo::on_cboCantidad_currentIndexChanged(int)
{
    // Obtengo el valor del combo y genero el objeto correspondiente
    //QString selectedCantidad = ui->cboCantidad->itemText(ui->cboCantidad->currentIndex());
    QString selectedCantidad = ui->cboCantidad->itemData(ui->cboCantidad->currentIndex()).toString();

    if (selectedCantidad.size() > 0)
    {
        cantidades::Cantidad *c = NULL;
        if (cantidadSeleccionada != NULL)
            if (cantidadSeleccionada->getimmutableName() == selectedCantidad)
                c = cantidadSeleccionada;

        if (c == NULL)
            c = DataStore::getInstance()->getCantidadesLibrary()->createCantidad(selectedCantidad);
        cantidadSeleccionada = c;
        ui->txtValue->setText(QString::number(cantidadSeleccionada->getValue()));
    }
    else
    {
        ui->txtValue->clear();
    }
}

void dlgNuevoElementoConstructivo::on_cboMaterial_currentIndexChanged(int)
{
    if (!loading)
        LoadCantidadesPosibles();
}
