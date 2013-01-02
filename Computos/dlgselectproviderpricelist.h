#ifndef DLGSELECTPROVIDERPRICELIST_H
#define DLGSELECTPROVIDERPRICELIST_H

#include <QDialog>

namespace Ui {
class dlgSelectProviderPriceList;
}

class dlgSelectProviderPriceList : public QDialog
{
    Q_OBJECT
    
public:
    explicit dlgSelectProviderPriceList(QWidget *parent = 0);
    ~dlgSelectProviderPriceList();
    
    QString Provider();
    QString PriceList();
private slots:
    void on_cboProviders_currentIndexChanged(const QString &arg1);

private:
    Ui::dlgSelectProviderPriceList *ui;

    void loadProviders();
    void loadPriceLists(QString provider);
};

#endif // DLGSELECTPROVIDERPRICELIST_H
