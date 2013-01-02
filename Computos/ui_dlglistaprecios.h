/********************************************************************************
** Form generated from reading UI file 'dlglistaprecios.ui'
**
** Created: Fri Dec 28 16:08:59 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGLISTAPRECIOS_H
#define UI_DLGLISTAPRECIOS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dlgListaPrecios
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *txtName;
    QLabel *label_2;
    QDateEdit *dtValidity;
    QLabel *label_3;
    QLabel *lblProvider;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dlgListaPrecios)
    {
        if (dlgListaPrecios->objectName().isEmpty())
            dlgListaPrecios->setObjectName(QString::fromUtf8("dlgListaPrecios"));
        dlgListaPrecios->resize(400, 142);
        verticalLayout = new QVBoxLayout(dlgListaPrecios);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(dlgListaPrecios);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        txtName = new QLineEdit(dlgListaPrecios);
        txtName->setObjectName(QString::fromUtf8("txtName"));

        formLayout->setWidget(1, QFormLayout::FieldRole, txtName);

        label_2 = new QLabel(dlgListaPrecios);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        dtValidity = new QDateEdit(dlgListaPrecios);
        dtValidity->setObjectName(QString::fromUtf8("dtValidity"));

        formLayout->setWidget(2, QFormLayout::FieldRole, dtValidity);

        label_3 = new QLabel(dlgListaPrecios);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        lblProvider = new QLabel(dlgListaPrecios);
        lblProvider->setObjectName(QString::fromUtf8("lblProvider"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lblProvider);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(dlgListaPrecios);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(dlgListaPrecios);
        QObject::connect(buttonBox, SIGNAL(accepted()), dlgListaPrecios, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dlgListaPrecios, SLOT(reject()));

        QMetaObject::connectSlotsByName(dlgListaPrecios);
    } // setupUi

    void retranslateUi(QDialog *dlgListaPrecios)
    {
        dlgListaPrecios->setWindowTitle(QApplication::translate("dlgListaPrecios", "Price List", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("dlgListaPrecios", "Name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("dlgListaPrecios", "Validity", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("dlgListaPrecios", "Provider", 0, QApplication::UnicodeUTF8));
        lblProvider->setText(QApplication::translate("dlgListaPrecios", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dlgListaPrecios: public Ui_dlgListaPrecios {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGLISTAPRECIOS_H
