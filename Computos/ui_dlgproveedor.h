/********************************************************************************
** Form generated from reading UI file 'dlgproveedor.ui'
**
** Created: Fri Dec 28 16:08:59 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGPROVEEDOR_H
#define UI_DLGPROVEEDOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dlgProveedor
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *txtName;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *txtTelephone;
    QLabel *label_5;
    QLineEdit *txtEMail;
    QPlainTextEdit *txtAddress;
    QLineEdit *txtContact;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dlgProveedor)
    {
        if (dlgProveedor->objectName().isEmpty())
            dlgProveedor->setObjectName(QString::fromUtf8("dlgProveedor"));
        dlgProveedor->resize(400, 291);
        verticalLayout = new QVBoxLayout(dlgProveedor);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(dlgProveedor);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        txtName = new QLineEdit(dlgProveedor);
        txtName->setObjectName(QString::fromUtf8("txtName"));

        formLayout->setWidget(0, QFormLayout::FieldRole, txtName);

        label_2 = new QLabel(dlgProveedor);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(dlgProveedor);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(dlgProveedor);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        txtTelephone = new QLineEdit(dlgProveedor);
        txtTelephone->setObjectName(QString::fromUtf8("txtTelephone"));

        formLayout->setWidget(4, QFormLayout::FieldRole, txtTelephone);

        label_5 = new QLabel(dlgProveedor);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        txtEMail = new QLineEdit(dlgProveedor);
        txtEMail->setObjectName(QString::fromUtf8("txtEMail"));

        formLayout->setWidget(5, QFormLayout::FieldRole, txtEMail);

        txtAddress = new QPlainTextEdit(dlgProveedor);
        txtAddress->setObjectName(QString::fromUtf8("txtAddress"));
        txtAddress->setMaximumSize(QSize(16777215, 80));

        formLayout->setWidget(1, QFormLayout::FieldRole, txtAddress);

        txtContact = new QLineEdit(dlgProveedor);
        txtContact->setObjectName(QString::fromUtf8("txtContact"));

        formLayout->setWidget(2, QFormLayout::FieldRole, txtContact);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(dlgProveedor);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(dlgProveedor);
        QObject::connect(buttonBox, SIGNAL(accepted()), dlgProveedor, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dlgProveedor, SLOT(reject()));

        QMetaObject::connectSlotsByName(dlgProveedor);
    } // setupUi

    void retranslateUi(QDialog *dlgProveedor)
    {
        dlgProveedor->setWindowTitle(QApplication::translate("dlgProveedor", "Material Provideer", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("dlgProveedor", "Name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("dlgProveedor", "Address", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("dlgProveedor", "Contact", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("dlgProveedor", "Telephone", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("dlgProveedor", "EMail", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dlgProveedor: public Ui_dlgProveedor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGPROVEEDOR_H
