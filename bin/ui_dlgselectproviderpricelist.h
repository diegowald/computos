/********************************************************************************
** Form generated from reading UI file 'dlgselectproviderpricelist.ui'
**
** Created: Sun Jan 6 11:15:32 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGSELECTPROVIDERPRICELIST_H
#define UI_DLGSELECTPROVIDERPRICELIST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dlgSelectProviderPriceList
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *cboProviders;
    QLabel *label_2;
    QComboBox *cboPriceLists;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dlgSelectProviderPriceList)
    {
        if (dlgSelectProviderPriceList->objectName().isEmpty())
            dlgSelectProviderPriceList->setObjectName(QString::fromUtf8("dlgSelectProviderPriceList"));
        dlgSelectProviderPriceList->resize(400, 125);
        verticalLayout = new QVBoxLayout(dlgSelectProviderPriceList);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(dlgSelectProviderPriceList);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        cboProviders = new QComboBox(dlgSelectProviderPriceList);
        cboProviders->setObjectName(QString::fromUtf8("cboProviders"));

        formLayout->setWidget(0, QFormLayout::FieldRole, cboProviders);

        label_2 = new QLabel(dlgSelectProviderPriceList);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        cboPriceLists = new QComboBox(dlgSelectProviderPriceList);
        cboPriceLists->setObjectName(QString::fromUtf8("cboPriceLists"));

        formLayout->setWidget(1, QFormLayout::FieldRole, cboPriceLists);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(dlgSelectProviderPriceList);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(dlgSelectProviderPriceList);
        QObject::connect(buttonBox, SIGNAL(accepted()), dlgSelectProviderPriceList, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dlgSelectProviderPriceList, SLOT(reject()));

        QMetaObject::connectSlotsByName(dlgSelectProviderPriceList);
    } // setupUi

    void retranslateUi(QDialog *dlgSelectProviderPriceList)
    {
        dlgSelectProviderPriceList->setWindowTitle(QApplication::translate("dlgSelectProviderPriceList", "Select a price list", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("dlgSelectProviderPriceList", "Provider", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("dlgSelectProviderPriceList", "Price list", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dlgSelectProviderPriceList: public Ui_dlgSelectProviderPriceList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGSELECTPROVIDERPRICELIST_H
