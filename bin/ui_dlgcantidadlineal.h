/********************************************************************************
** Form generated from reading UI file 'dlgcantidadlineal.ui'
**
** Created: Sun Jan 6 11:15:32 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGCANTIDADLINEAL_H
#define UI_DLGCANTIDADLINEAL_H

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

class Ui_dlgCantidadLineal
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *lblLabel;
    QLineEdit *txtLongitud;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dlgCantidadLineal)
    {
        if (dlgCantidadLineal->objectName().isEmpty())
            dlgCantidadLineal->setObjectName(QString::fromUtf8("dlgCantidadLineal"));
        dlgCantidadLineal->resize(216, 88);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/dlg/dock/lineal"), QSize(), QIcon::Normal, QIcon::Off);
        dlgCantidadLineal->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(dlgCantidadLineal);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        lblLabel = new QLabel(dlgCantidadLineal);
        lblLabel->setObjectName(QString::fromUtf8("lblLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lblLabel);

        txtLongitud = new QLineEdit(dlgCantidadLineal);
        txtLongitud->setObjectName(QString::fromUtf8("txtLongitud"));

        formLayout->setWidget(0, QFormLayout::FieldRole, txtLongitud);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(dlgCantidadLineal);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(dlgCantidadLineal);
        QObject::connect(buttonBox, SIGNAL(accepted()), dlgCantidadLineal, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dlgCantidadLineal, SLOT(reject()));

        QMetaObject::connectSlotsByName(dlgCantidadLineal);
    } // setupUi

    void retranslateUi(QDialog *dlgCantidadLineal)
    {
        dlgCantidadLineal->setWindowTitle(QApplication::translate("dlgCantidadLineal", "Linear Ammount", 0, QApplication::UnicodeUTF8));
        lblLabel->setText(QApplication::translate("dlgCantidadLineal", "Length", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dlgCantidadLineal: public Ui_dlgCantidadLineal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGCANTIDADLINEAL_H
