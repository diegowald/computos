/********************************************************************************
** Form generated from reading UI file 'wndcostanalysis.ui'
**
** Created: Fri Dec 28 16:08:59 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WNDCOSTANALYSIS_H
#define UI_WNDCOSTANALYSIS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QTabWidget>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_wndCostAnalysis
{
public:
    QAction *actionSelect_this_price;
    QAction *actionSelect_best_price;
    QAction *actionFind_best_prices_for_all;
    QAction *actionGenerate_Summary;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *lblProject;
    QTabWidget *tabWidget;
    QWidget *tabCosts;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *treeAnalysis;
    QWidget *tabSummary;
    QVBoxLayout *verticalLayout_2;
    QTreeWidget *treeSummary;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *lblTotalCost;

    void setupUi(QMainWindow *wndCostAnalysis)
    {
        if (wndCostAnalysis->objectName().isEmpty())
            wndCostAnalysis->setObjectName(QString::fromUtf8("wndCostAnalysis"));
        wndCostAnalysis->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/dlg/dock/dashboard"), QSize(), QIcon::Normal, QIcon::Off);
        wndCostAnalysis->setWindowIcon(icon);
        actionSelect_this_price = new QAction(wndCostAnalysis);
        actionSelect_this_price->setObjectName(QString::fromUtf8("actionSelect_this_price"));
        actionSelect_best_price = new QAction(wndCostAnalysis);
        actionSelect_best_price->setObjectName(QString::fromUtf8("actionSelect_best_price"));
        actionFind_best_prices_for_all = new QAction(wndCostAnalysis);
        actionFind_best_prices_for_all->setObjectName(QString::fromUtf8("actionFind_best_prices_for_all"));
        actionGenerate_Summary = new QAction(wndCostAnalysis);
        actionGenerate_Summary->setObjectName(QString::fromUtf8("actionGenerate_Summary"));
        centralwidget = new QWidget(wndCostAnalysis);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(2);
        formLayout->setVerticalSpacing(2);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lblProject = new QLabel(centralwidget);
        lblProject->setObjectName(QString::fromUtf8("lblProject"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lblProject);


        verticalLayout->addLayout(formLayout);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabCosts = new QWidget();
        tabCosts->setObjectName(QString::fromUtf8("tabCosts"));
        horizontalLayout = new QHBoxLayout(tabCosts);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        treeAnalysis = new QTreeWidget(tabCosts);
        treeAnalysis->setObjectName(QString::fromUtf8("treeAnalysis"));
        treeAnalysis->setContextMenuPolicy(Qt::CustomContextMenu);
        treeAnalysis->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeAnalysis->setAlternatingRowColors(true);

        horizontalLayout->addWidget(treeAnalysis);

        tabWidget->addTab(tabCosts, QString());
        tabSummary = new QWidget();
        tabSummary->setObjectName(QString::fromUtf8("tabSummary"));
        verticalLayout_2 = new QVBoxLayout(tabSummary);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        treeSummary = new QTreeWidget(tabSummary);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("Material"));
        treeSummary->setHeaderItem(__qtreewidgetitem);
        treeSummary->setObjectName(QString::fromUtf8("treeSummary"));

        verticalLayout_2->addWidget(treeSummary);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(tabSummary);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lblTotalCost = new QLabel(tabSummary);
        lblTotalCost->setObjectName(QString::fromUtf8("lblTotalCost"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        lblTotalCost->setFont(font);

        horizontalLayout_2->addWidget(lblTotalCost);


        verticalLayout_2->addLayout(horizontalLayout_2);

        tabWidget->addTab(tabSummary, QString());

        verticalLayout->addWidget(tabWidget);

        wndCostAnalysis->setCentralWidget(centralwidget);

        retranslateUi(wndCostAnalysis);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(wndCostAnalysis);
    } // setupUi

    void retranslateUi(QMainWindow *wndCostAnalysis)
    {
        wndCostAnalysis->setWindowTitle(QApplication::translate("wndCostAnalysis", "Cost Analysis", 0, QApplication::UnicodeUTF8));
        actionSelect_this_price->setText(QApplication::translate("wndCostAnalysis", "Select this price", 0, QApplication::UnicodeUTF8));
        actionSelect_best_price->setText(QApplication::translate("wndCostAnalysis", "Select best price", 0, QApplication::UnicodeUTF8));
        actionFind_best_prices_for_all->setText(QApplication::translate("wndCostAnalysis", "Find best prices for all", 0, QApplication::UnicodeUTF8));
        actionGenerate_Summary->setText(QApplication::translate("wndCostAnalysis", "Generate Summary", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("wndCostAnalysis", "Project", 0, QApplication::UnicodeUTF8));
        lblProject->setText(QApplication::translate("wndCostAnalysis", "TextLabel", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeAnalysis->headerItem();
        ___qtreewidgetitem->setText(6, QApplication::translate("wndCostAnalysis", "Price", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(5, QApplication::translate("wndCostAnalysis", "Relation", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(4, QApplication::translate("wndCostAnalysis", "Buying Unit", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(3, QApplication::translate("wndCostAnalysis", "Quantity to buy", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(2, QApplication::translate("wndCostAnalysis", "Calculation Unit", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("wndCostAnalysis", "Quantity", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("wndCostAnalysis", "Material/Brand", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabCosts), QApplication::translate("wndCostAnalysis", "Costs", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem1 = treeSummary->headerItem();
        ___qtreewidgetitem1->setText(9, QApplication::translate("wndCostAnalysis", "Price", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(8, QApplication::translate("wndCostAnalysis", "Buying Unit", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(7, QApplication::translate("wndCostAnalysis", "New Column", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(6, QApplication::translate("wndCostAnalysis", "Buying Unit", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(5, QApplication::translate("wndCostAnalysis", "New Column", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(4, QApplication::translate("wndCostAnalysis", "Calculation Unit", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(3, QApplication::translate("wndCostAnalysis", "Price List", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(2, QApplication::translate("wndCostAnalysis", "New Column", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(1, QApplication::translate("wndCostAnalysis", "Provider", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("wndCostAnalysis", "Total Cost", 0, QApplication::UnicodeUTF8));
        lblTotalCost->setText(QApplication::translate("wndCostAnalysis", "TextLabel", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabSummary), QApplication::translate("wndCostAnalysis", "Summary", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class wndCostAnalysis: public Ui_wndCostAnalysis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WNDCOSTANALYSIS_H
