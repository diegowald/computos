#ifndef PRINTABLEWINDOW_H
#define PRINTABLEWINDOW_H

#include <QMainWindow>

class PrintableWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit PrintableWindow(QWidget *parent = 0);
    virtual QString toHtml();
protected:
    virtual QString getHtmlContents() = 0;
signals:
    
public slots:
    
};

#endif // PRINTABLEWINDOW_H
