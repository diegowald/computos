#include "wndpdfviewer.h"
#include "ui_wndpdfviewer.h"
#include "dlglinkredlinewithconstructiveelement.h"
#include "datastore.h"

wndPDFViewer::wndPDFViewer(QString project, QString pdfName, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::wndPDFViewer)
{
    projectName = project;
    ui->setupUi(this);
    //QString filename = "/home/diego/Documents/C++-GUI-Programming-with-Qt-4-1st-ed.pdf";
    m_pdfRedlining = DataStore::getInstance()->getProject(project)->getRedLining(pdfName);
    createActions();
    initialize(m_pdfRedlining->name());
}

wndPDFViewer::~wndPDFViewer()
{
    delete ui;
}

void wndPDFViewer::initialize(QString filename)
{
    ui->pdfView->load(filename);
    ui->pdfView->setDisplayRedlineDialog(false);
    ui->pdfView->setEmitRedliningSignals(true);
    if (m_pdfRedlining)
    {
        ui->pdfView->setRedlines(m_pdfRedlining->getRedlines());
    }
    connect(ui->pdfView, SIGNAL(redlineCreated(Redline&)), this, SLOT(redlineCreated(Redline&)));
    connect(ui->pdfView, SIGNAL(redlineDeleted(Redline)), this, SLOT(redlineDeleted(Redline)));
    connect(ui->pdfView, SIGNAL(tooltipForElement(QString,QString&)), this, SLOT(tooltipForElement(QString,QString&)));
}

void wndPDFViewer::createActions()
{
    //ui->toolBar->addAction(ui->pdfView->action(PdfView::SetBookmark));
    //ui->toolBar->addAction(ui->pdfView->action(PdfView::Bookmarks));
    ui->toolBar->addAction(ui->pdfView->action(PdfView::GoToNextPage));
    ui->toolBar->addAction(ui->pdfView->action(PdfView::GoToPreviousPage));
    ui->toolBar->addAction(ui->pdfView->action(PdfView::MouseToolSelection));
    //ui->toolBar->addAction(ui->pdfView->action(PdfView::Redlines));
    ui->toolBar->addAction(ui->pdfView->action(PdfView::MouseToolRedlining));
    ui->toolBar->addAction(ui->pdfView->action(PdfView::Zoom));
    ui->toolBar->addAction(ui->pdfView->action(PdfView::ZoomIn));
    ui->toolBar->addAction(ui->pdfView->action(PdfView::ZoomOut));
}

void wndPDFViewer::redlineCreated(Redline &redline)
{
    dlgLinkRedlineWithConstructiveElement dlg(projectName, this);
    QObject::connect(&dlg, SIGNAL(createNewElement(void)), this, SIGNAL(createNewElement(void)));
    dlg.setImage(redline.image);
    if (dlg.exec() == QDialog::Accepted)
    {
        if (dlg.Element() != "")
        {
            redline.author = dlg.Author();
            redline.color = dlg.Color();
            redline.deleted = false;
            redline.name = dlg.Annotation();
            redline.elementReference.push_back(dlg.Element());
            m_pdfRedlining->addRedline(redline);
        }
        else
        {
            // redline will be cancelled since it requires a constructive element.
            redline.deleted = true;
        }
    }
    else
    {
        // Redline will be cancelled.
        redline.deleted = true;
    }
}

void wndPDFViewer::redlineDeleted(Redline redline)
{
}


void wndPDFViewer::tooltipForElement(QString el, QString &tooltip)
{
    tooltip = el;
}
