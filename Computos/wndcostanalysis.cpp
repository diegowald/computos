#include "wndcostanalysis.h"
#include "ui_wndcostanalysis.h"
#include "datastore.h"
#include "analysis.h"
#include "analysisprovider.h"
#include "analysispricelist.h"
#include "analysispriceitem.h"
#include <QMenu>
#include "htmlhelper.h"

wndCostAnalysis::wndCostAnalysis(QWidget *parent) :
    PrintableWindow(parent),
    ui(new Ui::wndCostAnalysis)
{
    ui->setupUi(this);
}

wndCostAnalysis::~wndCostAnalysis()
{
    delete ui;
}

void wndCostAnalysis::setProject(QString projectName)
{
    ui->lblProject->setText(projectName);
    //proyecto::Proyecto *project = DataStore::getInstance()->getProject(projectName);
    computo::analysis::Analysis *analysis = DataStore::getInstance()->getAnalysis(projectName);
    computo::ComputoMetrico *computo = DataStore::getInstance()->getComputo(projectName);
    //boost::shared_ptr<QStringList> nombresElementos = project->getAllElementoConstructivoNames();
    boost::shared_ptr<QMap<QString, double> > resumen = computo->getResumenMateriasPrimas();
    //foreach (QString nombreElemento, *nombresElementos)
    foreach (QString nombreElemento, resumen->keys())
    {
        QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeAnalysis);
        item->setText(0, nombreElemento);
        QVariant rowType("elemento");
        item->setData(0, Qt::UserRole, rowType);
        ui->treeAnalysis->insertTopLevelItem(0, item);
        //Ahora debo cargar el analisis de costos aplicados al elemento
        boost::shared_ptr<QStringList> providers = analysis->getProvidersNames(nombreElemento);
        foreach(QString providerName, *providers)
        {
            QTreeWidgetItem *providerItem = new QTreeWidgetItem(item);
            providerItem->setText(0, providerName);
            rowType = "Provider";
            providerItem->setData(0, Qt::UserRole, rowType);
            item->addChild(providerItem);
            computo::analysis::AnalysisProvider *provider = analysis->getProvider(nombreElemento, providerName);
            boost::shared_ptr<QStringList> listas = provider->getListas();
            foreach(QString nombreLista, *listas)
            {
                QTreeWidgetItem *listaItem = new QTreeWidgetItem(providerItem);
                listaItem->setText(0, nombreLista);
                rowType = "Lista";
                listaItem->setData(0, Qt::UserRole, rowType);
                providerItem->addChild(listaItem);
                computo::analysis::AnalysisPriceList *priceList = provider->getLista(nombreLista);
                boost::shared_ptr<QList<computo::analysis::AnalysisPriceItem*> > precios = priceList->getPrecios();
                foreach(computo::analysis::AnalysisPriceItem* priceItem, *precios)
                {
                    QTreeWidgetItem *priceItemW = new QTreeWidgetItem(listaItem);
                    rowType = "Price";
                    priceItemW->setData(0, Qt::UserRole, rowType);
                    priceItemW->setText(0, priceItem->getBrand());
                    priceItemW->setText(1, QString::number(priceItem->getCalculatedQuantity()));
                    priceItemW->setText(2, priceItem->getCalculationUnit());
                    priceItemW->setText(3, QString::number(priceItem->getBuyQuantity()));
                    priceItemW->setText(4, priceItem->getBuyUnit());
                    priceItemW->setText(5, QString::number(priceItem->getRelation()));
                    priceItemW->setText(6, "$ " + QString::number(priceItem->getPrice()));
                    priceItemW->setCheckState(0, priceItem->isSelectedPrice() ? Qt::Checked : Qt::Unchecked);
                }
            }
        }
    }
}

void wndCostAnalysis::on_treeAnalysis_customContextMenuRequested(const QPoint &pos)
{
    if (ui->treeAnalysis->selectedItems().size() > 0)
    {
        QMenu *menu = new QMenu(this);

        menu->addAction(ui->actionFind_best_prices_for_all);

        if (ui->treeAnalysis->selectedItems().at(0)->data(0, Qt::UserRole) == QVariant("Price"))
        {
            menu->addAction(ui->actionSelect_this_price);
        }
        else
        {
            menu->addAction(ui->actionSelect_best_price);
        }
        menu->addSeparator();
        menu->addAction(ui->actionGenerate_Summary);

        menu->exec(ui->treeAnalysis->mapToGlobal(pos));
    }
}

void wndCostAnalysis::on_actionSelect_this_price_triggered()
{
    QString projectName(ui->lblProject->text());
    // obtengo el precio seleccionado
    QTreeWidgetItem *item = ui->treeAnalysis->selectedItems().at(0);
    QString nombrePrecio = item->text(0);
    item = item->parent();
    QString nombreLista = item->text(0);
    item = item->parent();
    QString nombreProveedor = item->text(0);
    item = item->parent();
    QString nombreElemento = item->text(0);
    computo::analysis::Analysis *analysis = DataStore::getInstance()->getAnalysis(projectName);
    analysis->setSelectedPrice(nombreElemento, nombreProveedor, nombreLista, nombrePrecio);
    refreshPriceList();
}

void wndCostAnalysis::on_actionSelect_best_price_triggered()
{
    QString projectName(ui->lblProject->text());
    QString nombrePrecio("");
    QString nombreLista("");
    QString nombreProveedor("");
    QString nombreElemento("");

    // obtengo el precio seleccionado
    QTreeWidgetItem *item = ui->treeAnalysis->selectedItems().at(0);
    if (item->data(0, Qt::UserRole) == QVariant("Price"))
    {
        nombrePrecio = item->text(0);
        item = item->parent();
    }
    if (item->data(0, Qt::UserRole) == QVariant("Lista"))
    {
        nombreLista = item->text(0);
        item = item->parent();
    }
    if (item->data(0, Qt::UserRole) == QVariant("Provider"))
    {
        nombreProveedor = item->text(0);
        item = item->parent();
    }
    if (item->data(0, Qt::UserRole) == QVariant("elemento"))
    {
        nombreElemento = item->text(0);
    }
    computo::analysis::Analysis *analysis = DataStore::getInstance()->getAnalysis(projectName);
    analysis->setSelectedPrice(nombreElemento, nombreProveedor, nombreLista, nombrePrecio);
    refreshPriceList();
}

void wndCostAnalysis::refreshPriceList()
{
    QString projectName = ui->lblProject->text();
    QString elemento = "";
    QString proveedor = "";
    QString lista = "";
    QString precio = "";
    computo::analysis::Analysis *analysis = DataStore::getInstance()->getAnalysis(projectName);

    for (int i = 0; i < ui->treeAnalysis->topLevelItemCount(); i++)
    {
        QTreeWidgetItem *itemElemento = ui->treeAnalysis->topLevelItem(i);
        elemento = itemElemento->text(0);
        for (int j = 0; j < itemElemento->childCount(); j++)
        {
            QTreeWidgetItem *itemProveedor = itemElemento->child(j);
            proveedor = itemProveedor->text(0);
            for (int k = 0; k < itemProveedor->childCount(); k++)
            {
                QTreeWidgetItem *itemLista = itemProveedor->child(k);
                lista = itemLista->text(0);
                for (int m = 0; m < itemLista->childCount(); m++)
                {
                    QTreeWidgetItem *itemPrecio = itemLista->child(m);
                    precio = itemPrecio->text(0);
                    itemPrecio->setCheckState(0,
                                              analysis->getProvider(elemento, proveedor)->getLista(lista)->getPrecio(precio)->isSelectedPrice() ?
                                                  Qt::Checked : Qt::Unchecked);
                }
            }
        }
    }
    ui->actionGenerate_Summary->trigger();
}

void wndCostAnalysis::on_actionFind_best_prices_for_all_triggered()
{
    QString projectName(ui->lblProject->text());
    computo::analysis::Analysis *analysis = DataStore::getInstance()->getAnalysis(projectName);
    analysis->setSelectedPrice("", "", "", "");
    refreshPriceList();
}

void wndCostAnalysis::on_actionGenerate_Summary_triggered()
{
    ui->treeSummary->clear();
    QString projectName = ui->lblProject->text();
    QString elemento = "";
    QString proveedor = "";
    QString lista = "";

    for (int i = 0; i < ui->treeAnalysis->topLevelItemCount(); i++)
    {
        QTreeWidgetItem *itemElemento = ui->treeAnalysis->topLevelItem(i);
        elemento = itemElemento->text(0);
        for (int j = 0; j < itemElemento->childCount(); j++)
        {
            QTreeWidgetItem *itemProveedor = itemElemento->child(j);
            proveedor = itemProveedor->text(0);
            for (int k = 0; k < itemProveedor->childCount(); k++)
            {
                QTreeWidgetItem *itemLista = itemProveedor->child(k);
                lista = itemLista->text(0);
                for (int m = 0; m < itemLista->childCount(); m++)
                {
                    QTreeWidgetItem *itemPrecio = itemLista->child(m);
                    if (itemPrecio->checkState(0) == Qt::Checked)
                    {
                        QTreeWidgetItem *itemSummary = new QTreeWidgetItem(ui->treeSummary);
                        itemSummary->setText(0, elemento);
                        itemSummary->setText(1, proveedor);
                        itemSummary->setText(2, lista);
                        itemSummary->setText(3, itemPrecio->text(0));
                        itemSummary->setText(4, itemPrecio->text(1));
                        itemSummary->setText(5, itemPrecio->text(2));
                        itemSummary->setText(6, itemPrecio->text(3));
                        itemSummary->setText(7, itemPrecio->text(4));
                        itemSummary->setText(8, itemPrecio->text(5));
                        itemSummary->setText(9, itemPrecio->text(6));
                        ui->treeSummary->insertTopLevelItem(0, itemSummary);
                        break;
                    }
                }
            }
        }
    }
    computo::analysis::Analysis *analysis = DataStore::getInstance()->getAnalysis(projectName);
    ui->lblTotalCost->setText(QString::number(analysis->getTotalCost()));
/*
            y luego continuar con el download de materiales desde la web
            y luego con un mecanismo para registrar al usuario
            y luego con un mecanismo para chequear que el usuario lo esta empleando*/
}

QString wndCostAnalysis::getHtmlContents()
{
    return HtmlHelper::toHtml(tr("Cost Analysis"), ui->treeSummary, true);
}
