/********************************************************************************
** Form generated from reading UI file 'dlgpriceitem.ui'
**
** Created: Sun Jan 6 11:15:32 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGPRICEITEM_H
#define UI_DLGPRICEITEM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_dlgPriceItem
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QComboBox *cboElement;
    QPushButton *btnNewElement;
    QLabel *lblPricelistName;
    QLineEdit *txtNombreEnListaDePrecios;
    QLabel *label_2;
    QLineEdit *txtBrand;
    QLabel *label_3;
    QLabel *lblElementUnit;
    QLabel *label_4;
    QComboBox *cboSaleUnit;
    QLabel *lblRelation;
    QLineEdit *txtRelation;
    QLabel *label_8;
    QLineEdit *txtPriceListUnitLabel;
    QCheckBox *chkDivisible;
    QLabel *label_6;
    QLineEdit *txtPrice;
    QLabel *label_7;
    QPlainTextEdit *txtNotes;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dlgPriceItem)
    {
        if (dlgPriceItem->objectName().isEmpty())
            dlgPriceItem->setObjectName(QString::fromUtf8("dlgPriceItem"));
        dlgPriceItem->resize(358, 459);
        formLayout = new QFormLayout(dlgPriceItem);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(dlgPriceItem);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cboElement = new QComboBox(dlgPriceItem);
        cboElement->setObjectName(QString::fromUtf8("cboElement"));

        horizontalLayout->addWidget(cboElement);

        btnNewElement = new QPushButton(dlgPriceItem);
        btnNewElement->setObjectName(QString::fromUtf8("btnNewElement"));

        horizontalLayout->addWidget(btnNewElement);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout);

        lblPricelistName = new QLabel(dlgPriceItem);
        lblPricelistName->setObjectName(QString::fromUtf8("lblPricelistName"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lblPricelistName);

        txtNombreEnListaDePrecios = new QLineEdit(dlgPriceItem);
        txtNombreEnListaDePrecios->setObjectName(QString::fromUtf8("txtNombreEnListaDePrecios"));

        formLayout->setWidget(1, QFormLayout::FieldRole, txtNombreEnListaDePrecios);

        label_2 = new QLabel(dlgPriceItem);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        txtBrand = new QLineEdit(dlgPriceItem);
        txtBrand->setObjectName(QString::fromUtf8("txtBrand"));

        formLayout->setWidget(2, QFormLayout::FieldRole, txtBrand);

        label_3 = new QLabel(dlgPriceItem);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        lblElementUnit = new QLabel(dlgPriceItem);
        lblElementUnit->setObjectName(QString::fromUtf8("lblElementUnit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lblElementUnit);

        label_4 = new QLabel(dlgPriceItem);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        cboSaleUnit = new QComboBox(dlgPriceItem);
        cboSaleUnit->setObjectName(QString::fromUtf8("cboSaleUnit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, cboSaleUnit);

        lblRelation = new QLabel(dlgPriceItem);
        lblRelation->setObjectName(QString::fromUtf8("lblRelation"));

        formLayout->setWidget(5, QFormLayout::LabelRole, lblRelation);

        txtRelation = new QLineEdit(dlgPriceItem);
        txtRelation->setObjectName(QString::fromUtf8("txtRelation"));

        formLayout->setWidget(5, QFormLayout::FieldRole, txtRelation);

        label_8 = new QLabel(dlgPriceItem);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_8);

        txtPriceListUnitLabel = new QLineEdit(dlgPriceItem);
        txtPriceListUnitLabel->setObjectName(QString::fromUtf8("txtPriceListUnitLabel"));

        formLayout->setWidget(6, QFormLayout::FieldRole, txtPriceListUnitLabel);

        chkDivisible = new QCheckBox(dlgPriceItem);
        chkDivisible->setObjectName(QString::fromUtf8("chkDivisible"));

        formLayout->setWidget(7, QFormLayout::LabelRole, chkDivisible);

        label_6 = new QLabel(dlgPriceItem);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_6);

        txtPrice = new QLineEdit(dlgPriceItem);
        txtPrice->setObjectName(QString::fromUtf8("txtPrice"));

        formLayout->setWidget(8, QFormLayout::FieldRole, txtPrice);

        label_7 = new QLabel(dlgPriceItem);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_7);

        txtNotes = new QPlainTextEdit(dlgPriceItem);
        txtNotes->setObjectName(QString::fromUtf8("txtNotes"));

        formLayout->setWidget(9, QFormLayout::FieldRole, txtNotes);

        buttonBox = new QDialogButtonBox(dlgPriceItem);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(10, QFormLayout::SpanningRole, buttonBox);


        retranslateUi(dlgPriceItem);
        QObject::connect(buttonBox, SIGNAL(accepted()), dlgPriceItem, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dlgPriceItem, SLOT(reject()));

        QMetaObject::connectSlotsByName(dlgPriceItem);
    } // setupUi

    void retranslateUi(QDialog *dlgPriceItem)
    {
        dlgPriceItem->setWindowTitle(QApplication::translate("dlgPriceItem", "Price Item", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("dlgPriceItem", "Element", 0, QApplication::UnicodeUTF8));
        btnNewElement->setText(QApplication::translate("dlgPriceItem", "New...", 0, QApplication::UnicodeUTF8));
        lblPricelistName->setText(QApplication::translate("dlgPriceItem", "Price list name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("dlgPriceItem", "Brand", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("dlgPriceItem", "Element Unit", 0, QApplication::UnicodeUTF8));
        lblElementUnit->setText(QApplication::translate("dlgPriceItem", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("dlgPriceItem", "Sale Unit", 0, QApplication::UnicodeUTF8));
        lblRelation->setText(QApplication::translate("dlgPriceItem", "Relation", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("dlgPriceItem", "Price list unit label", 0, QApplication::UnicodeUTF8));
        chkDivisible->setText(QApplication::translate("dlgPriceItem", "Divisible", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("dlgPriceItem", "Price", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("dlgPriceItem", "Notes", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dlgPriceItem: public Ui_dlgPriceItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGPRICEITEM_H
