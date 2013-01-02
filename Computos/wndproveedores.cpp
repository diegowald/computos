#include "wndproveedores.h"
#include "ui_wndproveedores.h"
#include "datastore.h"
#include "proveedor.h"
#include "dlgproveedor.h"
#include <QMessageBox>
#include <QMenu>
#include "dlglistaprecios.h"
#include "htmlhelper.h"

wndProveedores::wndProveedores(QWidget *parent) :
    PrintableWindow(parent),
    ui(new Ui::wndProveedores)
{
    ui->setupUi(this);

    ui->lblAddress->clear();
    ui->lblContact->clear();
    ui->lblEmail->clear();
    ui->lblTelephone->clear();

    loadProviders();
}

wndProveedores::~wndProveedores()
{
    delete ui;
}

void wndProveedores::loadProviders()
{
    ui->treeProveedores->clear();
    boost::shared_ptr<QStringList> proveedores = DataStore::getInstance()->getProvidersList()->getAllProveedores();
    foreach(QString proveedor, *proveedores)
    {
        QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeProveedores);
        item->setText(0, proveedor);
        ui->treeProveedores->insertTopLevelItem(0, item);
    }
}

void wndProveedores::on_actionAdd_Provider_triggered()
{
    // crea un nuevo proveedor
    editProvider("");
}


void wndProveedores::on_treeProveedores_itemSelectionChanged()
{
    if (ui->treeProveedores->selectedItems().size() > 0)
    {
        QString name = ui->treeProveedores->selectedItems().at(0)->text(0);
        listaPrecios::Proveedor *proveedor = DataStore::getInstance()->getProvidersList()->getProveedor(name);
        if (proveedor != NULL)
        {
            ui->lblAddress->setText(proveedor->Address());
            ui->lblContact->setText(proveedor->ContactName());
            ui->lblEmail->setText(proveedor->EMail());
            ui->lblTelephone->setText(proveedor->Telephone());
            ui->treeListas->clear();
            boost::shared_ptr<QStringList> listas = proveedor->getActiveListaPrecios();
            foreach (QString lista, *listas)
            {
                QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeListas);
                item->setText(0, lista);
                item->setText(1, proveedor->getListaPrecios(lista)->Vigencia().toString("dd/MM/yyyy"));
                ui->treeListas->insertTopLevelItem(0, item);
            }
        }
    }
}

void wndProveedores::on_treeProveedores_customContextMenuRequested(const QPoint &pos)
{
    QMenu *menu = new QMenu(this);

    menu->addAction(ui->actionAdd_Provider);
    if (ui->treeProveedores->selectedItems().size() > 0)
        menu->addAction(ui->actionDelete_Provider);

    menu->exec(ui->treeProveedores->mapToGlobal(pos));
}

void wndProveedores::editProvider(QString providerName)
{
    bool newProvider = (providerName.size() == 0);
    listaPrecios::Proveedor *p = NULL;
    dlgProveedor dlg(this);

    if (!newProvider)
    {
        p = DataStore::getInstance()->getProvidersList()->getProveedor(providerName);
        dlg.setNombre(p->Nombre());
        dlg.setAddress(p->Address());
        dlg.setContactName(p->ContactName());
        dlg.setTelephone(p->Telephone());
        dlg.setEmail(p->EMail());
    }

    if (dlg.exec() == QDialog::Accepted)
    {
        if (newProvider)
        {
            p = new listaPrecios::Proveedor(this);
            p->setNombre(dlg.Nombre());
        }
        p->setAddress(dlg.Address());
        p->setContactName(dlg.ContactName());
        p->setTelephone(dlg.Telephone());
        p->setEMail(dlg.EMail());
        if (newProvider)
            DataStore::getInstance()->getProvidersList()->addProveedor(p);
        loadProviders();
    }
}

void wndProveedores::editList(QString providerName, QString listName)
{
    bool newList = (listName.size() == 0);
    listaPrecios::Proveedor *p = NULL;
    listaPrecios::ListaPrecios *l = NULL;

    dlgListaPrecios dlg(this);
    p = DataStore::getInstance()->getProvidersList()->getProveedor(providerName);
    dlg.setProviderName(p->Nombre());

    if (!newList)
    {
        l = p->getListaPrecios(listName);
        dlg.setNombreLista(l->Name());
        dlg.setVigencia(l->Vigencia());
    }


    if (dlg.exec() == QDialog::Accepted)
    {
        if (newList)
        {
            l = new listaPrecios::ListaPrecios(p);
            l->setName(dlg.NombreLista());
        }
        l->setVigencia(dlg.Vigencia());
        if (newList)
            p->addLista(l);
        DataStore::getInstance()->getProvidersList()->save();
        loadProviders();
    }
}

void wndProveedores::on_treeProveedores_doubleClicked(const QModelIndex &)
{
    if (ui->treeProveedores->selectedItems().size() > 0)
    {
        QString proveedor = ui->treeProveedores->selectedItems().at(0)->text(0);
        editProvider(proveedor);
    }
}

void wndProveedores::on_treeListas_customContextMenuRequested(const QPoint &pos)
{
    if (ui->treeProveedores->selectedItems().size() > 0)
    {
        QMenu *menu = new QMenu(this);
        menu->addAction(ui->actionNew_List);
        if (ui->treeListas->selectedItems().size() > 0)
            menu->addAction(ui->actionDelete_List);

        menu->exec(ui->treeListas->mapToGlobal(pos));
    }
}

void wndProveedores::on_actionDelete_Provider_triggered()
{
    if (ui->treeProveedores->selectedItems().size() > 0)
    {
        QString proveedor = ui->treeProveedores->selectedItems().at(0)->text(0);
        int r = QMessageBox::warning(this, tr("Delete Provider"),
                                     tr("Are you sure you want to delete %1?").arg(proveedor),
                                     QMessageBox::Yes,
                                     QMessageBox::No | QMessageBox::Default | QMessageBox::Cancel);
        if (r == QMessageBox::Yes)
        {
            DataStore::getInstance()->getProvidersList()->deleteProveedor(proveedor);
            loadProviders();
        }
    }
}

void wndProveedores::on_actionNew_List_triggered()
{
    if (ui->treeProveedores->selectedItems().size() > 0)
    {
        QString proveedor = ui->treeProveedores->selectedItems().at(0)->text(0);
        editList(proveedor, "");
    }
}

void wndProveedores::on_actionDelete_List_triggered()
{
    if (ui->treeListas->selectedItems().size() > 0)
    {
        QString proveedor = ui->treeProveedores->selectedItems().at(0)->text(0);
        QString lista = ui->treeListas->selectedItems().at(0)->text(0);
        int r = QMessageBox::warning(this, tr("Delete Provider"),
                                     tr("Are you sure you want to delete list %1 of %2?").arg(lista, proveedor),
                                     QMessageBox::Yes,
                                     QMessageBox::No | QMessageBox::Default | QMessageBox::Cancel);
        if (r == QMessageBox::Yes)
        {
            DataStore::getInstance()->getProvidersList()->getProveedor(proveedor)->deleteLista(lista);
            DataStore::getInstance()->getProvidersList()->save();
            loadProviders();
        }
    }
}

void wndProveedores::on_treeListas_doubleClicked(const QModelIndex &)
{
    if (ui->treeListas->selectedItems().size() > 0)
    {
        QString proveedor = ui->treeProveedores->selectedItems().at(0)->text(0);
        QString lista = ui->treeListas->selectedItems().at(0)->text(0);
        editList(proveedor, lista);
    }
}

QString wndProveedores::getHtmlContents()
{
    QStringList headers;
    headers << tr("Name") << tr("Address")
               << tr("Contact") << tr("Telephone")
                  << tr("e-mail");

    QVector<QStringList> body;

    boost::shared_ptr<QStringList> proveedores = DataStore::getInstance()->getProvidersList()->getAllProveedores();
    foreach (QString name, *proveedores)
    {
        QStringList aux;
        listaPrecios::Proveedor *p = DataStore::getInstance()->getProvidersList()->getProveedor(name);
        aux << name << p->Address() << p->ContactName()
               << p->Telephone() << p->EMail();
        body.push_back(aux);
    }
    return HtmlHelper::toHtml(tr("Providers"), headers, body);

/*  QString html = "";
          html = "<table width=\"100%\" border=1 cellspacing=0>\n";

    html += "<tr><td colspan=5 align=\"center\">" + tr("Providers") + "</td></tr>";

    html += "<tr><td>" + tr("Name") + "</td></tr>";
    html += "<tr><td>" + tr("Address") + "</td></tr>";
    html += "<tr><td>" + tr("Contact") + "</td></tr>";
    html += "<tr><td>" + tr("Telephone") + "</td></tr>";
    html += "<tr><td>" + tr("e-mail") + "</td></tr>";

    boost::shared_ptr<QStringList> proveedores = DataStore::getInstance()->getProvidersList()->getAllProveedores();
    foreach (QString name, *proveedores)
    {
        listaPrecios::Proveedor *p = DataStore::getInstance()->getProvidersList()->getProveedor(name);
        html += "<tr>";
        html += "<td>" + name + "</td>";
        html += "<td>" + p->Address() + "</td>";
        html += "<td>" + p->ContactName() + "</td>";
        html += "<td>" + p->Telephone() + "</td>";
        html += "<td>" + p->EMail() + "</td>";
        html += "</tr>";
    }
    html += "</table>";

    return html;*/
}
