#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>
#include <QDragEnterEvent>
#include <QTreeWidgetItem>
#include "elementocomputo.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void LoadProyecto(QString &filename);

    QString getProjectName();
    void save();
    void saveAs(QString newProjectName);

    void updateProjectInformation();

protected:
    //void LoadMateriales();

    void LoadProyecto();
    void reLoadProyecto();
    void LoadComputo();
    void reLoadComputo();
    void LoadResumenMateriales();
    void reLoadResumenMateriales();
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
public slots:

private slots:

    void on_treeProyecto_doubleClicked(const QModelIndex &index);

private:

    void populateSubtree(QTreeWidgetItem *item, computo::ElementoComputo *elemento);

    Ui::MainWindow *ui;

    QString projectName;
};

#endif // MAINWINDOW_H
