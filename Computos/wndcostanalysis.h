#ifndef WNDCOSTANALYSIS_H
#define WNDCOSTANALYSIS_H

#include "printablewindow.h"

namespace Ui {
class wndCostAnalysis;
}

class wndCostAnalysis : public PrintableWindow
{
    Q_OBJECT
    
public:
    explicit wndCostAnalysis(QWidget *parent = 0);
    ~wndCostAnalysis();

    virtual QString getHtmlContents();

    void setProject(QString projectName);
private slots:
    void on_treeAnalysis_customContextMenuRequested(const QPoint &pos);

    void on_actionSelect_this_price_triggered();

    void on_actionSelect_best_price_triggered();

    void on_actionFind_best_prices_for_all_triggered();

    void on_actionGenerate_Summary_triggered();

private:
    Ui::wndCostAnalysis *ui;

    void refreshPriceList();

};

#endif // WNDCOSTANALYSIS_H
