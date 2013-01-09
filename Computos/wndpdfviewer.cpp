#include "wndpdfviewer.h"
#include "ui_wndpdfviewer.h"

wndPDFViewer::wndPDFViewer(pdf::PDFRedLining *pdfRedLining, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::wndPDFViewer)
{
    ui->setupUi(this);
    //QString filename = "/home/diego/Documents/C++-GUI-Programming-with-Qt-4-1st-ed.pdf";
    m_pdfRedlining = pdfRedLining;
    createActions();
    initialize(pdfRedLining->name());
}

wndPDFViewer::wndPDFViewer(QString filename, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::wndPDFViewer)
{
    ui->setupUi(this);
    //QString filename = "/home/diego/Documents/C++-GUI-Programming-with-Qt-4-1st-ed.pdf";
    m_pdfRedlining = NULL;
    createActions();
    initialize(filename);
}

wndPDFViewer::~wndPDFViewer()
{
    delete ui;
}

void wndPDFViewer::initialize(QString filename)
{
    ui->pdfView->setDisplayRedlineDialog(false);
    ui->pdfView->setEmitRedliningSignals(true);
    ui->pdfView->load(filename);
    if (m_pdfRedlining)
    {
        ui->pdfView->setRedlines(m_pdfRedlining->getRedlines());
    }
    connect(ui->pdfView, SIGNAL(redlineCreated(Redline)), this, SLOT(redlineCreated(Redline)));
    connect(ui->pdfView, SIGNAL(redlineDeleted(Redline)), this, SLOT(redlineDeleted(Redline)));
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

void wndPDFViewer::redlineCreated(Redline redline)
{
}

void wndPDFViewer::redlineDeleted(Redline redline)
{
}
