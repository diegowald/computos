/********************************************************************************
** Form generated from reading UI file 'wndpdfviewer.ui'
**
** Created: Fri Dec 28 16:08:59 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WNDPDFVIEWER_H
#define UI_WNDPDFVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include "../pdfviewer/lib/src/pdfview.h"

QT_BEGIN_NAMESPACE

class Ui_wndPDFViewer
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    PdfView *pdfView;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *wndPDFViewer)
    {
        if (wndPDFViewer->objectName().isEmpty())
            wndPDFViewer->setObjectName(QString::fromUtf8("wndPDFViewer"));
        wndPDFViewer->resize(800, 600);
        centralwidget = new QWidget(wndPDFViewer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pdfView = new PdfView(centralwidget);
        pdfView->setObjectName(QString::fromUtf8("pdfView"));

        horizontalLayout->addWidget(pdfView);

        wndPDFViewer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(wndPDFViewer);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 29));
        wndPDFViewer->setMenuBar(menubar);
        statusbar = new QStatusBar(wndPDFViewer);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        wndPDFViewer->setStatusBar(statusbar);
        toolBar = new QToolBar(wndPDFViewer);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        wndPDFViewer->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(wndPDFViewer);

        QMetaObject::connectSlotsByName(wndPDFViewer);
    } // setupUi

    void retranslateUi(QMainWindow *wndPDFViewer)
    {
        wndPDFViewer->setWindowTitle(QApplication::translate("wndPDFViewer", "MainWindow", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("wndPDFViewer", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class wndPDFViewer: public Ui_wndPDFViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WNDPDFVIEWER_H
