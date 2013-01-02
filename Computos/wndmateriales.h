#ifndef WNDMATERIALES_H
#define WNDMATERIALES_H

#include "printablewindow.h"
#include <QModelIndex>
#include <QComboBox>

namespace Ui {
class wndMateriales;
}

class wndMateriales : public PrintableWindow
{
    Q_OBJECT
    
public:
    explicit wndMateriales(QWidget *parent = 0);
    ~wndMateriales();

    virtual QString getHtmlContents();

signals:
    void openBrowser(QString &search);
    
private slots:
    void on_treeMateriales_itemSelectionChanged();

    void on_txtNombre_textEdited(const QString &arg1);
    void on_txtDescripcion_textChanged();
    void on_txtTags_textEdited(const QString &arg1);
    void on_cboMeasureUnit_currentIndexChanged(const QString &arg1);
    void on_cboLibraries_currentIndexChanged(const QString &arg1);
    void on_actionNewMaterial_triggered();
    void on_actionSaveLibrary_triggered();
    void on_actionSaveMaterial_triggered();
    void on_actionAddComponente_triggered();
    void on_actionDeleteComponente_triggered();
    void on_treeComponentes_customContextMenuRequested(const QPoint &pos);

    void on_treeComponentes_doubleClicked(const QModelIndex &index);

    void on_chkUsableDirectly_stateChanged(int );

    void on_cmdGoogleIt_pressed();

private:
    Ui::wndMateriales *ui;

    void loadLibraries();
    void loadMateriales(QString library);
    void loadComboMeasureUnits();
    void editMaterial(QString materialName);
    void saveMaterial();
    void discardChanges();
    void saveLibrary();
    void editComponente(int row);

    void setMaterialDirty();

    bool materialDirty;
    bool libraryDirty;
    bool loadingElemento;
    bool loadingLibraries;
    bool newElement;

    QString title;
    QString detailsTitle;
    QComboBox *cboLibraries;
};

#endif // WNDMATERIALES_H
