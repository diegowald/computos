#ifndef WNDPRICELIST_H
#define WNDPRICELIST_H

#include "printablewindow.h"
#include <QModelIndex>

namespace Ui {
class wndPriceList;
}

class wndPriceList : public PrintableWindow
{
    Q_OBJECT
    
public:
    explicit wndPriceList(QWidget *parent = 0);
    ~wndPriceList();

    virtual QString getHtmlContents();
    
    void setProvider(QString providerName);
    void setPriceList(QString priceListName);

private slots:
    void on_treePriceList_customContextMenuRequested(const QPoint &pos);

    void on_actionAdd_Price_Item_triggered();

    void on_actionRemove_Price_Item_triggered();

    void on_treePriceList_doubleClicked(const QModelIndex &);

private:
    Ui::wndPriceList *ui;

    void clearPriceList();
    void loadPricelist();
    void editPriceItem(QString elemento, QString marca);
};

#endif // WNDPRICELIST_H
