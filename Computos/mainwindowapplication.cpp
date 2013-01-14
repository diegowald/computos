#include "mainwindowapplication.h"
#include "ui_mainwindowapplication.h"
#include "projectwindow.h"
#include <QMdiSubWindow>
#include <QFileDialog>
#include "wndmateriales.h"
#include "datastore.h"
#include "wndproveedores.h"
#include <QMessageBox>
#include "dlgselectproviderpricelist.h"
#include "wndpricelist.h"
#include "dlgcheckmaterialupdates.h"
#include "wndcostanalysis.h"
#include "dlgsetproject.h"
#include "printablewindow.h"
#include "dlgimportpricelist.h"
#include "dlglistselector.h"

// Printing
#include <QPrintDialog>
#include <QPrinter>
#include <QPainter>
#include <QTextDocument>

// Browsing
#include "wndbrowser.h"

// PDF
#include "wndpdfviewer.h"

/*
La idea es que la aplicacion sea MDI
Cada documento tendra varias solapas
    Una solapa correspondiente a la descripcion del proyecto
    Una solapa correspondiente a la entrada de datos de los elementos constructivos
    Una solapa correspondiente al computo metrico de estos materiales.
    Una solapa correspondiente al listado de materia prima

Tambien existe un dock, en el cual se veran los materiales agrupados de alguna manera.

Se podra hacer drag and drop desde este dock hacia el documento para ir añadiendo materiales
al elemento constructivo.

Este dock contendra las diferentes librerias de materiales que estan instaladas en el sistema.
En una primer version se hara la aplicacion con una sola libreria de materiales.

Mas adelante se podran hacer importaciones de listado de materiales al sistema.... para lograr realizar el presupuesto

Luego se armaran reportes, la idea en ppio es exportarlos en csv y/o pdf


*/

/** Pendientes

  -> Reportes. Hay que hacer varios reportes.
  -> SubProjectos
  -> Definicion de costos indirectos/fijos/directos.

  **/


MainWindowApplication::MainWindowApplication(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowApplication)
{
    ui->setupUi(this);

    materialsWindow = new MaterialDockWindow(this);
    ui->dockMateriales->setWidget(materialsWindow);

    connect(ui->action_New, SIGNAL(triggered()), this, SLOT(newProject()));
    connect(ui->action_Open, SIGNAL(triggered()), this, SLOT(openProject()));
    connect(ui->action_Save, SIGNAL(triggered()), this, SLOT(saveProject()));
    connect(ui->actionSave_As, SIGNAL(triggered()), this, SLOT(saveProjectAs()));
    connect(ui->action_Close, SIGNAL(triggered()), this, SLOT(closeProject()));

    connect(ui->actionEdit_Material_defiinition, SIGNAL(triggered()), this, SLOT(editMaterialLibrary()));

    connect(ui->actionE_xit, SIGNAL(triggered()), this, SLOT(exitApp()));
}



MainWindowApplication::~MainWindowApplication()
{
    //DataStore::getInstance()->cleanUp();
    delete ui;
}


void MainWindowApplication::newProject()
{
    ProjectWindow *newP = new ProjectWindow(this);
    ui->mdiArea->addSubWindow(newP);
    newP->show();
    newP->activateWindow();
}

void MainWindowApplication::openProject()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open Project"), ".",
                                                    tr("Project files (*.pr)")
                                                    + ";;" +
                                                    tr("XML Project files (*.xml)"));
    if (!filename.isEmpty())
    {
        ProjectWindow *newP = new ProjectWindow(this);
        ui->mdiArea->addSubWindow(newP);
        newP->show();
        newP->LoadProyecto(filename);
        newP->activateWindow();
    }
}

void MainWindowApplication::saveProject()
{
    if (qobject_cast<ProjectWindow *>(ui->mdiArea->activeSubWindow()->widget()) != NULL)
    {
        ProjectWindow *w = (ProjectWindow *) ui->mdiArea->activeSubWindow()->widget();
        w->updateProjectInformation();
        if (!w->getProjectName().isEmpty())
        {
            w->save();
        }
        else
        {
            QString filename = QFileDialog::getSaveFileName(this,
                                                            tr("Save Project as..."), ".",
                                                            tr("Project files (*.pr)")
                                                            + ";;" +
                                                            tr("XML Project files (*.xml)"));
            if (!filename.isEmpty())
                w->saveAs(filename);
        }
    }
}

void MainWindowApplication::saveProjectAs()
{
    ProjectWindow *w = qobject_cast<ProjectWindow *>(ui->mdiArea->activeSubWindow()->widget());
    if (w != NULL)
    {
        QString filename = QFileDialog::getSaveFileName(this,
                                                        tr("Save Project as..."), ".",
                                                        tr("Project files (*.pr)")
                                                        + ";;" +
                                                        tr("XML Project files (*.prxml)"));
        if (!filename.isEmpty())
            w->saveAs(filename);
    }
}

void MainWindowApplication::closeProject()
{
    if (ui->mdiArea->activeSubWindow() != NULL)
        ui->mdiArea->activeSubWindow()->close();
}

void MainWindowApplication::printProject()
{
    if (qobject_cast<PrintableWindow *>(ui->mdiArea->activeSubWindow()->widget()) != NULL)
    {
        PrintableWindow *wnd = qobject_cast<PrintableWindow *>(ui->mdiArea->activeSubWindow()->widget());
        QPrinter printer;
        QPrintDialog printDialog(&printer, this);
        if (printDialog.exec())
        {
            //QPainter painter(&printer);
            QTextDocument textDocument;
            textDocument.setHtml(wnd->toHtml());

            textDocument.print(&printer);
        }
    }
}

void MainWindowApplication::exitApp()
{
    close();
}

void MainWindowApplication::editMaterialLibrary()
{
    // Aca se abre la ventana de edicion de materiales
    wndMateriales *newP = new wndMateriales(this);
    ui->mdiArea->addSubWindow(newP);
    connect(newP, SIGNAL(openBrowser(QString&)), this, SLOT(on_openBrowser(QString&)));
    newP->show();
    newP->activateWindow();
}


void MainWindowApplication::on_action_About_triggered()
{
    QMessageBox::about(this,
                       tr("About Computos"),
                       tr("2012 - mksIngenieria\n"
                          "info@mksIngenieria.com.ar"));
}

void MainWindowApplication::on_action_List_triggered()
{
    // Aca se abre la ventana de edicion de proveedores
    wndProveedores *newP = new wndProveedores(this);
    ui->mdiArea->addSubWindow(newP);
    newP->show();
    newP->activateWindow();
}

void MainWindowApplication::on_action_Price_Lists_triggered()
{
    dlgSelectProviderPriceList dlg(this);
    if (dlg.exec() == QDialog::Accepted)
    {
        // Aca se abre la ventanad de edicion de listas de precios
        wndPriceList *newPL = new wndPriceList(this);
        newPL->setProvider(dlg.Provider());
        newPL->setPriceList(dlg.PriceList());
        ui->mdiArea->addSubWindow(newPL);
        newPL->show();
        newPL->activateWindow();
    }
}

void MainWindowApplication::on_actionCheck_for_Materials_update_triggered()
{
    dlgCheckMaterialUpdates dlg(this);
    dlg.exec();
}

void MainWindowApplication::on_action_Compute_triggered()
{
    /*La idea aca es mostrar una pantalla que tenga el listado de materiales y luego el costo de cada proveedor con la marca que ofrece.
            Si el proveedor no provee ese material, entonces se marca de manera diferente
*/
    dlgSetProject dlg(this);
    if (dlg.exec() == QDialog::Accepted)
    {
        wndCostAnalysis *wnd = new wndCostAnalysis(this);
        wnd->setProject(dlg.Project());
        ui->mdiArea->addSubWindow(wnd);
        wnd->show();
        wnd->activateWindow();
    }
}

void MainWindowApplication::on_action_Print_triggered()
{
    printProject();
}

void MainWindowApplication::on_action_Import_Pricelist_triggered()
{
    dlgImportPriceList dlg(this);
    if (dlg.exec() == QDialog::Accepted)
    {
    }
}

void MainWindowApplication::on_openBrowser(QString &search)
{
    wndBrowser *wnd = new wndBrowser(search, this);
    ui->mdiArea->addSubWindow(wnd);
    wnd->show();
    wnd->activateWindow();
}

void MainWindowApplication::on_action_Add_PDF_Document_triggered()
{
    if (ui->mdiArea->activeSubWindow() == NULL)
        return;
    ProjectWindow *w = qobject_cast<ProjectWindow *>(ui->mdiArea->activeSubWindow()->widget());
    if (w != NULL)
    {
        QString filename = QFileDialog::getOpenFileName(this,
                                                        tr("Include PDF Document"), ".",
                                                        tr("Adobe Acrobat pdf files (*.pdf)"));

        if (!filename.isEmpty())
        {
            QString projectName = w->getProjectName();
            proyecto::Proyecto *p = DataStore::getInstance()->getProject(projectName);
            p->addPDFToProject(filename);


            wndPDFViewer *newPDF = new wndPDFViewer(projectName, filename, this);
            connect(newPDF, SIGNAL(createNewElement()), w, SLOT(createNewElement()));
            ui->mdiArea->addSubWindow(newPDF);
            newPDF->show();
            newPDF->activateWindow();
        }
    }
}

void MainWindowApplication::on_actionOpen_PDF_triggered()
{
    if (ui->mdiArea->activeSubWindow() == NULL)
        return;
    ProjectWindow *w = qobject_cast<ProjectWindow *>(ui->mdiArea->activeSubWindow()->widget());
    if (w != NULL)
    {
        dlgListSelector dlg(this);
        QString projectName = w->getProjectName();
        dlg.addElements(*DataStore::getInstance()->getProject(projectName)->getAllPDFNames());
        if (dlg.exec() == QDialog::Accepted)
        {
            wndPDFViewer *pdf = new wndPDFViewer(projectName, dlg.selectedElement(), this);
            connect(pdf, SIGNAL(createNewElement()), w, SLOT(createNewElement()));
            ui->mdiArea->addSubWindow(pdf);
            pdf->show();
            pdf->activateWindow();
        }
    }
}
