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
    explicit wndPDFViewer(QString project, QString pdfName, QWidget *parent = 0);
    ~wndPDFViewer();
protected:
    void initialize(QString filename);
    void createActions();

public slots:
    void redlineCreated(Redline &redline);
    void redlineDeleted(Redline redline);
    void tooltipForElement(QString el, QString &tooltip);
signals:
    void createNewElement();
private:
    Ui::wndPDFViewer *ui;
  //  PdfView *pdfView;
    pdf::PDFRedLining *m_pdfRedlining;
    QString projectName;
};

#endif // WNDPDFVIEWER_H
