#ifndef DLGIMPORTPRICELIST_H
#define DLGIMPORTPRICELIST_H

#include <QDialog>
#include "csvreader.h"
#include <QAction>
#include <precio.h>

namespace Ui {
class dlgImportPriceList;
}

class dlgImportPriceList : public QDialog
{
    Q_OBJECT
    
public:
    explicit dlgImportPriceList(QWidget *parent = 0);
    ~dlgImportPriceList();
    
private slots:
    void on_cboProviders_currentIndexChanged(const QString &arg1);

    void on_btnOpenFileDialog_pressed();

    void on_chkHeadersOnFirstRow_stateChanged(int arg1);

    void on_treeCSV_customContextMenuRequested(const QPoint &pos);
    void mapField(QAction* action);

    void on_btnImport_pressed();

    void on_cboPriceLists_currentIndexChanged(const QString &arg1);

private:
    Ui::dlgImportPriceList *ui;
    QString newProvider;
    QString newPriceList;

    void loadProviders();
    void loadPriceLists();
    void openFile();
    void fillData();
    void addToMenu(QMenu * menu, QString text);
    void actualizarPrecio(QStringList record, listaPrecios::Precio *precio);
    QString getRecordValue(QStringList record, QString Field);
    bool editPriceListItem(listaPrecios::Precio *precio);
    CSVReader *csv;

    QString SalesName;
    QString PriceLabel;
    QString ElementLabel;
    QString SalesUnitLabel;
    QString RatioLabel;
    QString BrandLabel;
    QString NotesLabel;
    QString RemoveMappingLabel;
    QString addToFilterLabel;
    QString removeFromFilter;

    int columnSelected;
    int SalesNameColumn;
    QMap<int, QString> fieldMapping;
    boost::shared_ptr<QStringList> filter;
};

#endif // DLGIMPORTPRICELIST_H
