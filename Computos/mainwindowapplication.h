#ifndef MAINWINDOWAPPLICATOIN_H
#define MAINWINDOWAPPLICATOIN_H

#include <QMainWindow>

#include "materialdockwindow.h"


namespace Ui {
class MainWindowApplication;
}

class MainWindowApplication : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindowApplication(QWidget *parent = 0);
    ~MainWindowApplication();
    
private:
    Ui::MainWindowApplication *ui;
    MaterialDockWindow *materialsWindow;

public slots:
    void newProject();
    void openProject();
    void saveProject();
    void saveProjectAs();
    void closeProject();

    void printProject();

    void exitApp();

    void editMaterialLibrary();
private slots:
    void on_action_About_triggered();
    void on_action_List_triggered();
    void on_action_Price_Lists_triggered();
    void on_actionCheck_for_Materials_update_triggered();
    void on_action_Compute_triggered();
    void on_action_Print_triggered();
    void on_action_Import_Pricelist_triggered();
    void on_openBrowser(QString &search);
    void on_action_Add_PDF_Document_triggered();
};

#endif // MAINWINDOWAPPLICATOIN_H
