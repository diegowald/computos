#ifndef WNDPDFVIEWER_H
#define WNDPDFVIEWER_H

#include <QMainWindow>
//#include "../pdfviewer/lib/src/pdfview.h"

namespace Ui {
class wndPDFViewer;
}

class wndPDFViewer : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit wndPDFViewer(QString filename, QWidget *parent = 0);
    ~wndPDFViewer();
    
private:
    Ui::wndPDFViewer *ui;
  //  PdfView *pdfView;
};

#endif // WNDPDFVIEWER_H
