/********************************************************************************
** Form generated from reading UI file 'dlgrawvalue.ui'
**
** Created: Sun Jan 6 11:15:32 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGRAWVALUE_H
#define UI_DLGRAWVALUE_H

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
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dlgRawValue
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *Value;
    QLineEdit *txtValue;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dlgRawValue)
    {
        if (dlgRawValue->objectName().isEmpty())
            dlgRawValue->setObjectName(QString::fromUtf8("dlgRawValue"));
        dlgRawValue->resize(240, 91);
        verticalLayout = new QVBoxLayout(dlgRawValue);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        Value = new QLabel(dlgRawValue);
        Value->setObjectName(QString::fromUtf8("Value"));

        formLayout->setWidget(0, QFormLayout::LabelRole, Value);

        txtValue = new QLineEdit(dlgRawValue);
        txtValue->setObjectName(QString::fromUtf8("txtValue"));

        formLayout->setWidget(0, QFormLayout::FieldRole, txtValue);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(dlgRawValue);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(dlgRawValue);
        QObject::connect(buttonBox, SIGNAL(accepted()), dlgRawValue, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dlgRawValue, SLOT(reject()));

        QMetaObject::connectSlotsByName(dlgRawValue);
    } // setupUi

    void retranslateUi(QDialog *dlgRawValue)
    {
        dlgRawValue->setWindowTitle(QApplication::translate("dlgRawValue", "Direct value", 0, QApplication::UnicodeUTF8));
        Value->setText(QApplication::translate("dlgRawValue", "Value", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dlgRawValue: public Ui_dlgRawValue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGRAWVALUE_H
