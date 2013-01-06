/********************************************************************************
** Form generated from reading UI file 'dlgsuperficietrapecial.ui'
**
** Created: Sun Jan 6 11:15:32 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGSUPERFICIETRAPECIAL_H
#define UI_DLGSUPERFICIETRAPECIAL_H

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

class Ui_dlgSuperficieTrapecial
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *txtLargo;
    QLabel *label_2;
    QLineEdit *txtAlto1;
    QLabel *label_3;
    QLineEdit *txtAlto2;
    QLabel *label_4;
    QLabel *lblFormula;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dlgSuperficieTrapecial)
    {
        if (dlgSuperficieTrapecial->objectName().isEmpty())
            dlgSuperficieTrapecial->setObjectName(QString::fromUtf8("dlgSuperficieTrapecial"));
        dlgSuperficieTrapecial->resize(247, 189);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/dlg/dock/TrapecialArea"), QSize(), QIcon::Normal, QIcon::Off);
        dlgSuperficieTrapecial->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(dlgSuperficieTrapecial);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(dlgSuperficieTrapecial);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        txtLargo = new QLineEdit(dlgSuperficieTrapecial);
        txtLargo->setObjectName(QString::fromUtf8("txtLargo"));

        formLayout->setWidget(0, QFormLayout::FieldRole, txtLargo);

        label_2 = new QLabel(dlgSuperficieTrapecial);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        txtAlto1 = new QLineEdit(dlgSuperficieTrapecial);
        txtAlto1->setObjectName(QString::fromUtf8("txtAlto1"));

        formLayout->setWidget(1, QFormLayout::FieldRole, txtAlto1);

        label_3 = new QLabel(dlgSuperficieTrapecial);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        txtAlto2 = new QLineEdit(dlgSuperficieTrapecial);
        txtAlto2->setObjectName(QString::fromUtf8("txtAlto2"));

        formLayout->setWidget(2, QFormLayout::FieldRole, txtAlto2);

        label_4 = new QLabel(dlgSuperficieTrapecial);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        lblFormula = new QLabel(dlgSuperficieTrapecial);
        lblFormula->setObjectName(QString::fromUtf8("lblFormula"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lblFormula);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(dlgSuperficieTrapecial);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(dlgSuperficieTrapecial);
        QObject::connect(buttonBox, SIGNAL(accepted()), dlgSuperficieTrapecial, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dlgSuperficieTrapecial, SLOT(reject()));

        QMetaObject::connectSlotsByName(dlgSuperficieTrapecial);
    } // setupUi

    void retranslateUi(QDialog *dlgSuperficieTrapecial)
    {
        dlgSuperficieTrapecial->setWindowTitle(QApplication::translate("dlgSuperficieTrapecial", "Trapecial Surface", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("dlgSuperficieTrapecial", "Length", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("dlgSuperficieTrapecial", "Height 1", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("dlgSuperficieTrapecial", "Height 2", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("dlgSuperficieTrapecial", "Calculation", 0, QApplication::UnicodeUTF8));
        lblFormula->setText(QApplication::translate("dlgSuperficieTrapecial", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dlgSuperficieTrapecial: public Ui_dlgSuperficieTrapecial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGSUPERFICIETRAPECIAL_H
