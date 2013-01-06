/********************************************************************************
** Form generated from reading UI file 'wndproveedores.ui'
**
** Created: Sun Jan 6 11:15:32 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WNDPROVEEDORES_H
#define UI_WNDPROVEEDORES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QStatusBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_wndProveedores
{
public:
    QAction *actionAdd_Provider;
    QAction *actionDelete_Provider;
    QAction *actionNew_List;
    QAction *actionDelete_List;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QTreeWidget *treeProveedores;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *lblAddress;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *lblContact;
    QLabel *lblTelephone;
    QLabel *lblEmail;
    QLabel *label_2;
    QTreeWidget *treeListas;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *wndProveedores)
    {
        if (wndProveedores->objectName().isEmpty())
            wndProveedores->setObjectName(QString::fromUtf8("wndProveedores"));
        wndProveedores->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/dlg/dock/calculator"), QSize(), QIcon::Normal, QIcon::Off);
        wndProveedores->setWindowIcon(icon);
        actionAdd_Provider = new QAction(wndProveedores);
        actionAdd_Provider->setObjectName(QString::fromUtf8("actionAdd_Provider"));
        actionDelete_Provider = new QAction(wndProveedores);
        actionDelete_Provider->setObjectName(QString::fromUtf8("actionDelete_Provider"));
        actionNew_List = new QAction(wndProveedores);
        actionNew_List->setObjectName(QString::fromUtf8("actionNew_List"));
        actionDelete_List = new QAction(wndProveedores);
        actionDelete_List->setObjectName(QString::fromUtf8("actionDelete_List"));
        centralwidget = new QWidget(wndProveedores);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        treeProveedores = new QTreeWidget(centralwidget);
        treeProveedores->setObjectName(QString::fromUtf8("treeProveedores"));
        treeProveedores->setMaximumSize(QSize(200, 16777215));
        treeProveedores->setContextMenuPolicy(Qt::CustomContextMenu);

        horizontalLayout_2->addWidget(treeProveedores);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(2);
        formLayout->setVerticalSpacing(2);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lblAddress = new QLabel(groupBox);
        lblAddress->setObjectName(QString::fromUtf8("lblAddress"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lblAddress);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        lblContact = new QLabel(groupBox);
        lblContact->setObjectName(QString::fromUtf8("lblContact"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lblContact);

        lblTelephone = new QLabel(groupBox);
        lblTelephone->setObjectName(QString::fromUtf8("lblTelephone"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lblTelephone);

        lblEmail = new QLabel(groupBox);
        lblEmail->setObjectName(QString::fromUtf8("lblEmail"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lblEmail);


        horizontalLayout->addLayout(formLayout);


        verticalLayout->addWidget(groupBox);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        treeListas = new QTreeWidget(centralwidget);
        treeListas->setObjectName(QString::fromUtf8("treeListas"));
        treeListas->setContextMenuPolicy(Qt::CustomContextMenu);

        verticalLayout->addWidget(treeListas);


        horizontalLayout_2->addLayout(verticalLayout);

        wndProveedores->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(wndProveedores);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        wndProveedores->setStatusBar(statusbar);

        retranslateUi(wndProveedores);

        QMetaObject::connectSlotsByName(wndProveedores);
    } // setupUi

    void retranslateUi(QMainWindow *wndProveedores)
    {
        wndProveedores->setWindowTitle(QApplication::translate("wndProveedores", "Providers", 0, QApplication::UnicodeUTF8));
        actionAdd_Provider->setText(QApplication::translate("wndProveedores", "Add Provider", 0, QApplication::UnicodeUTF8));
        actionDelete_Provider->setText(QApplication::translate("wndProveedores", "Delete Provider", 0, QApplication::UnicodeUTF8));
        actionNew_List->setText(QApplication::translate("wndProveedores", "New List", 0, QApplication::UnicodeUTF8));
        actionDelete_List->setText(QApplication::translate("wndProveedores", "Delete List", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeProveedores->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("wndProveedores", "Provider", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("wndProveedores", "Provider Details", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("wndProveedores", "Address", 0, QApplication::UnicodeUTF8));
        lblAddress->setText(QApplication::translate("wndProveedores", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("wndProveedores", "Contact", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("wndProveedores", "Telephone", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("wndProveedores", "E-mail", 0, QApplication::UnicodeUTF8));
        lblContact->setText(QApplication::translate("wndProveedores", "TextLabel", 0, QApplication::UnicodeUTF8));
        lblTelephone->setText(QApplication::translate("wndProveedores", "TextLabel", 0, QApplication::UnicodeUTF8));
        lblEmail->setText(QApplication::translate("wndProveedores", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("wndProveedores", "Price lists", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem1 = treeListas->headerItem();
        ___qtreewidgetitem1->setText(1, QApplication::translate("wndProveedores", "Valid Since", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(0, QApplication::translate("wndProveedores", "Name", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class wndProveedores: public Ui_wndProveedores {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WNDPROVEEDORES_H
