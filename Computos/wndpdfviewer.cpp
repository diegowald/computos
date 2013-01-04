#include "wndpdfviewer.h"
#include "ui_wndpdfviewer.h"

wndPDFViewer::wndPDFViewer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::wndPDFViewer)
{
    ui->setupUi(this);
    QString filename = "/home/diego/Documents/C++-GUI-Programming-with-Qt-4-1st-ed.pdf";
    ui->pdfView->load(filename);
    //ui->toolBar->addAction(ui->pdfView->action(PdfView::SetBookmark));
    ui->toolBar->addAction(ui->pdfView->action(PdfView::Bookmarks));
    ui->toolBar->addAction(ui->pdfView->action(PdfView::GoToNextPage));
    ui->toolBar->addAction(ui->pdfView->action(PdfView::MouseToolSelection));
    ui->toolBar->addAction(ui->pdfView->action(PdfView::Redlines));
    ui->toolBar->addAction(ui->pdfView->action(PdfView::MouseToolRedlining));
    ui->toolBar->addAction(ui->pdfView->action(PdfView::Zoom));
    ui->toolBar->addAction(ui->pdfView->action(PdfView::ZoomIn));
    ui->toolBar->addAction(ui->pdfView->action(PdfView::ZoomOut));
}

wndPDFViewer::~wndPDFViewer()
{
    delete ui;
}
