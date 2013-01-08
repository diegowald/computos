#ifndef WNDPDFVIEWER_H
#define WNDPDFVIEWER_H

#include <QMainWindow>
//#include "../pdfviewer/lib/src/pdfview.h"
#include "pdfredlining.h"

namespace Ui {
class wndPDFViewer;
}

class wndPDFViewer : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit wndPDFViewer(pdf::PDFRedLining *pdfRedLining, QWidget *parent = 0);
    explicit wndPDFViewer(QString filename, QWidget *parent = 0);
    ~wndPDFViewer();
    
private:
    Ui::wndPDFViewer *ui;
  //  PdfView *pdfView;
    pdf::PDFRedLining *m_pdfRedlining;
};

#endif // WNDPDFVIEWER_H
