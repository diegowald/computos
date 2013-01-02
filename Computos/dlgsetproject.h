#ifndef DLGSETPROJECT_H
#define DLGSETPROJECT_H

#include <QDialog>

namespace Ui {
class dlgSetProject;
}

class dlgSetProject : public QDialog
{
    Q_OBJECT
    
public:
    explicit dlgSetProject(QWidget *parent = 0);
    ~dlgSetProject();
    
    QString Project();
private:
    Ui::dlgSetProject *ui;

    void loadProjectNames();
};

#endif // DLGSETPROJECT_H
