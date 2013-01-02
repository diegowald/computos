/********************************************************************************
** Form generated from reading UI file 'materialdockwindow.ui'
**
** Created: Fri Dec 28 16:08:59 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATERIALDOCKWINDOW_H
#define UI_MATERIALDOCKWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MaterialDockWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *txtKeys;
    QPushButton *btnBorrarBusqueda;
    QPushButton *btnBuscar;
    QTreeWidget *treeMateriales;

    void setupUi(QMainWindow *MaterialDockWindow)
    {
        if (MaterialDockWindow->objectName().isEmpty())
            MaterialDockWindow->setObjectName(QString::fromUtf8("MaterialDockWindow"));
        MaterialDockWindow->resize(301, 600);
        MaterialDockWindow->setMaximumSize(QSize(301, 16777215));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/dlg/dock/images/colors.png"), QSize(), QIcon::Normal, QIcon::Off);
        MaterialDockWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MaterialDockWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        txtKeys = new QLineEdit(centralwidget);
        txtKeys->setObjectName(QString::fromUtf8("txtKeys"));

        horizontalLayout->addWidget(txtKeys);

        btnBorrarBusqueda = new QPushButton(centralwidget);
        btnBorrarBusqueda->setObjectName(QString::fromUtf8("btnBorrarBusqueda"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/dlg/dock/delete"), QSize(), QIcon::Normal, QIcon::Off);
        btnBorrarBusqueda->setIcon(icon1);

        horizontalLayout->addWidget(btnBorrarBusqueda);

        btnBuscar = new QPushButton(centralwidget);
        btnBuscar->setObjectName(QString::fromUtf8("btnBuscar"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/dlg/dock/search"), QSize(), QIcon::Normal, QIcon::Off);
        btnBuscar->setIcon(icon2);

        horizontalLayout->addWidget(btnBuscar);


        verticalLayout->addLayout(horizontalLayout);

        treeMateriales = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("Material"));
        treeMateriales->setHeaderItem(__qtreewidgetitem);
        treeMateriales->setObjectName(QString::fromUtf8("treeMateriales"));
        treeMateriales->setDragEnabled(true);
        treeMateriales->setDragDropMode(QAbstractItemView::DragOnly);
        treeMateriales->setAlternatingRowColors(true);

        verticalLayout->addWidget(treeMateriales);

        MaterialDockWindow->setCentralWidget(centralwidget);

        retranslateUi(MaterialDockWindow);

        QMetaObject::connectSlotsByName(MaterialDockWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MaterialDockWindow)
    {
        MaterialDockWindow->setWindowTitle(QApplication::translate("MaterialDockWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MaterialDockWindow", "Find", 0, QApplication::UnicodeUTF8));
        btnBorrarBusqueda->setText(QString());
        btnBuscar->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MaterialDockWindow: public Ui_MaterialDockWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATERIALDOCKWINDOW_H
