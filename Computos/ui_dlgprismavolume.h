/********************************************************************************
** Form generated from reading UI file 'dlgprismavolume.ui'
**
** Created: Fri Dec 28 16:08:59 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGPRISMAVOLUME_H
#define UI_DLGPRISMAVOLUME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dlgPrismaVolume
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *txtLargo;
    QLabel *label_2;
    QLineEdit *txtAlto1;
    QLabel *label_3;
    QLineEdit *txtAlto2;
    QFormLayout *formLayout_2;
    QLabel *label_4;
    QLineEdit *txtHeight2;
    QFormLayout *formLayout_3;
    QLabel *label_5;
    QLabel *lblFormula;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dlgPrismaVolume)
    {
        if (dlgPrismaVolume->objectName().isEmpty())
            dlgPrismaVolume->setObjectName(QString::fromUtf8("dlgPrismaVolume"));
        dlgPrismaVolume->resize(400, 256);
        verticalLayout = new QVBoxLayout(dlgPrismaVolume);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(dlgPrismaVolume);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        txtLargo = new QLineEdit(groupBox);
        txtLargo->setObjectName(QString::fromUtf8("txtLargo"));

        formLayout->setWidget(0, QFormLayout::FieldRole, txtLargo);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        txtAlto1 = new QLineEdit(groupBox);
        txtAlto1->setObjectName(QString::fromUtf8("txtAlto1"));

        formLayout->setWidget(1, QFormLayout::FieldRole, txtAlto1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        txtAlto2 = new QLineEdit(groupBox);
        txtAlto2->setObjectName(QString::fromUtf8("txtAlto2"));

        formLayout->setWidget(2, QFormLayout::FieldRole, txtAlto2);


        horizontalLayout->addLayout(formLayout);


        verticalLayout->addWidget(groupBox);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_4 = new QLabel(dlgPrismaVolume);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_4);

        txtHeight2 = new QLineEdit(dlgPrismaVolume);
        txtHeight2->setObjectName(QString::fromUtf8("txtHeight2"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, txtHeight2);


        verticalLayout->addLayout(formLayout_2);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setHorizontalSpacing(2);
        formLayout_3->setVerticalSpacing(2);
        label_5 = new QLabel(dlgPrismaVolume);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_5);

        lblFormula = new QLabel(dlgPrismaVolume);
        lblFormula->setObjectName(QString::fromUtf8("lblFormula"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, lblFormula);


        verticalLayout->addLayout(formLayout_3);

        buttonBox = new QDialogButtonBox(dlgPrismaVolume);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(dlgPrismaVolume);
        QObject::connect(buttonBox, SIGNAL(accepted()), dlgPrismaVolume, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dlgPrismaVolume, SLOT(reject()));

        QMetaObject::connectSlotsByName(dlgPrismaVolume);
    } // setupUi

    void retranslateUi(QDialog *dlgPrismaVolume)
    {
        dlgPrismaVolume->setWindowTitle(QApplication::translate("dlgPrismaVolume", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("dlgPrismaVolume", "Surface definition", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("dlgPrismaVolume", "Length", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("dlgPrismaVolume", "Height 1", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("dlgPrismaVolume", "Height 2", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("dlgPrismaVolume", "Height", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("dlgPrismaVolume", "Calculation", 0, QApplication::UnicodeUTF8));
        lblFormula->setText(QApplication::translate("dlgPrismaVolume", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dlgPrismaVolume: public Ui_dlgPrismaVolume {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGPRISMAVOLUME_H
