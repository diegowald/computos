#include "printablewindow.h"

PrintableWindow::PrintableWindow(QWidget *parent) :
    QMainWindow(parent)
{
}

QString PrintableWindow::toHtml()
{
    QString header = "";
    QString body = getHtmlContents();
    QString footer = "";
    return header + body + footer;
}
