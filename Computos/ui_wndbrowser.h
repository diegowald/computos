/********************************************************************************
** Form generated from reading UI file 'wndbrowser.ui'
**
** Created: Fri Dec 28 16:08:59 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WNDBROWSER_H
#define UI_WNDBROWSER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_wndBrowser
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWebView *webView;

    void setupUi(QMainWindow *wndBrowser)
    {
        if (wndBrowser->objectName().isEmpty())
            wndBrowser->setObjectName(QString::fromUtf8("wndBrowser"));
        wndBrowser->resize(800, 600);
        centralwidget = new QWidget(wndBrowser);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        webView = new QWebView(centralwidget);
        webView->setObjectName(QString::fromUtf8("webView"));
        webView->setUrl(QUrl(QString::fromUtf8("http://www.yahoo.com/")));

        horizontalLayout->addWidget(webView);

        wndBrowser->setCentralWidget(centralwidget);

        retranslateUi(wndBrowser);

        QMetaObject::connectSlotsByName(wndBrowser);
    } // setupUi

    void retranslateUi(QMainWindow *wndBrowser)
    {
        wndBrowser->setWindowTitle(QApplication::translate("wndBrowser", "MainWindow", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class wndBrowser: public Ui_wndBrowser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WNDBROWSER_H
