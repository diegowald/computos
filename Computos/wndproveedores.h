#ifndef WNDPROVEEDORES_H
#define WNDPROVEEDORES_H

#include "printablewindow.h"
#include <QModelIndex>

namespace Ui {
class wndProveedores;
}

class wndProveedores : public PrintableWindow
{
    Q_OBJECT
    
public:
    explicit wndProveedores(QWidget *parent = 0);
    ~wndProveedores();

    virtual QString getHtmlContents();
    
private slots:
    void on_actionAdd_Provider_triggered();
    void on_treeProveedores_itemSelectionChanged();
    void on_treeProveedores_customContextMenuRequested(const QPoint &pos);
    void on_treeProveedores_doubleClicked(const QModelIndex &index);
    void on_treeListas_customContextMenuRequested(const QPoint &pos);
    void on_actionDelete_Provider_triggered();
    void on_actionNew_List_triggered();
    void on_actionDelete_List_triggered();
    void on_treeListas_doubleClicked(const QModelIndex &index);

private:
    Ui::wndProveedores *ui;

    void loadProviders();
    void editProvider(QString providerName);
    void editList(QString providerName, QString listName);
};

#endif // WNDPROVEEDORES_H
