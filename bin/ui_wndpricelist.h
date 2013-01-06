/********************************************************************************
** Form generated from reading UI file 'wndpricelist.ui'
**
** Created: Sun Jan 6 11:15:32 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WNDPRICELIST_H
#define UI_WNDPRICELIST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QStatusBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_wndPriceList
{
public:
    QAction *actionAdd_Price_Item;
    QAction *actionRemove_Price_Item;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout_2;
    QLabel *label;
    QLabel *lblProvider;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLabel *lblPriceList;
    QTreeWidget *treePriceList;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *wndPriceList)
    {
        if (wndPriceList->objectName().isEmpty())
            wndPriceList->setObjectName(QString::fromUtf8("wndPriceList"));
        wndPriceList->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/dlg/dock/coins"), QSize(), QIcon::Normal, QIcon::Off);
        wndPriceList->setWindowIcon(icon);
        actionAdd_Price_Item = new QAction(wndPriceList);
        actionAdd_Price_Item->setObjectName(QString::fromUtf8("actionAdd_Price_Item"));
        actionRemove_Price_Item = new QAction(wndPriceList);
        actionRemove_Price_Item->setObjectName(QString::fromUtf8("actionRemove_Price_Item"));
        centralwidget = new QWidget(wndPriceList);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setHorizontalSpacing(2);
        formLayout_2->setVerticalSpacing(2);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        lblProvider = new QLabel(centralwidget);
        lblProvider->setObjectName(QString::fromUtf8("lblProvider"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lblProvider);


        horizontalLayout->addLayout(formLayout_2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(2);
        formLayout->setVerticalSpacing(2);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        lblPriceList = new QLabel(centralwidget);
        lblPriceList->setObjectName(QString::fromUtf8("lblPriceList"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lblPriceList);


        horizontalLayout->addLayout(formLayout);


        verticalLayout->addLayout(horizontalLayout);

        treePriceList = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("Product/Brand"));
        treePriceList->setHeaderItem(__qtreewidgetitem);
        treePriceList->setObjectName(QString::fromUtf8("treePriceList"));
        treePriceList->setContextMenuPolicy(Qt::CustomContextMenu);
        treePriceList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treePriceList->setAlternatingRowColors(true);
        treePriceList->setAnimated(true);
        treePriceList->setExpandsOnDoubleClick(false);

        verticalLayout->addWidget(treePriceList);

        wndPriceList->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(wndPriceList);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        wndPriceList->setStatusBar(statusbar);

        retranslateUi(wndPriceList);

        QMetaObject::connectSlotsByName(wndPriceList);
    } // setupUi

    void retranslateUi(QMainWindow *wndPriceList)
    {
        wndPriceList->setWindowTitle(QApplication::translate("wndPriceList", "Price List", 0, QApplication::UnicodeUTF8));
        actionAdd_Price_Item->setText(QApplication::translate("wndPriceList", "Add Price Item", 0, QApplication::UnicodeUTF8));
        actionRemove_Price_Item->setText(QApplication::translate("wndPriceList", "Remove Price Item", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("wndPriceList", "Provider", 0, QApplication::UnicodeUTF8));
        lblProvider->setText(QApplication::translate("wndPriceList", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("wndPriceList", "Price List name", 0, QApplication::UnicodeUTF8));
        lblPriceList->setText(QApplication::translate("wndPriceList", "TextLabel", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treePriceList->headerItem();
        ___qtreewidgetitem->setText(4, QApplication::translate("wndPriceList", "Buying Unit", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(3, QApplication::translate("wndPriceList", "Units", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(2, QApplication::translate("wndPriceList", "Ratio", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("wndPriceList", "Price", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class wndPriceList: public Ui_wndPriceList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WNDPRICELIST_H
