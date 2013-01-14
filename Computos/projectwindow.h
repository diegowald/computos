#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "printablewindow.h"
#include <QModelIndex>
#include <QDragEnterEvent>
#include <QTreeWidgetItem>
#include "elementocomputo.h"

namespace Ui {
class ProjectWindow;
}

class ProjectWindow : public PrintableWindow
{
    Q_OBJECT
    
public:
    explicit ProjectWindow(QWidget *parent = 0);
    ~ProjectWindow();
    void LoadProyecto(QString &filename);

    QString getProjectName();
    void save();
    void saveAs(QString newProjectName);

    void updateProjectInformation();

    virtual QString getHtmlContents();

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
    bool createNewElement(QString material);
public slots:
    void createNewElement();
private slots:

    void on_treeProyecto_doubleClicked(const QModelIndex &index);

    void on_treeProyecto_customContextMenuRequested(const QPoint &pos);

    void on_actionRemove_Build_Part_triggered();

    void on_actionClone_and_set_material_triggered();

private:

    void populateSubtree(QTreeWidgetItem *item, computo::ElementoComputo *elemento);

    Ui::ProjectWindow *ui;

    QString projectName;
};

#endif // MAINWINDOW_H
