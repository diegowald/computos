#include "dlgsetproject.h"
#include "ui_dlgsetproject.h"
#include "datastore.h"
#include <boost/shared_ptr.hpp>

dlgSetProject::dlgSetProject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgSetProject)
{
    ui->setupUi(this);
    loadProjectNames();
}

dlgSetProject::~dlgSetProject()
{
    delete ui;
}

void dlgSetProject::loadProjectNames()
{
    boost::shared_ptr<QStringList> projects = DataStore::getInstance()->getProjectNames();
    ui->cboProject->clear();
    foreach (QString project, *projects)
    {
        ui->cboProject->addItem(project);
    }
}

QString dlgSetProject::Project()
{
    return ui->cboProject->currentText();
}
