/********************************************************************************
** Form generated from reading UI file 'dlgcircularsurface.ui'
**
** Created: Fri Dec 28 16:08:59 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGCIRCULARSURFACE_H
#define UI_DLGCIRCULARSURFACE_H

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

class Ui_dlgCircularSurface
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *txtRadius;
    QLabel *label_2;
    QLabel *lblFormula;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dlgCircularSurface)
    {
        if (dlgCircularSurface->objectName().isEmpty())
            dlgCircularSurface->setObjectName(QString::fromUtf8("dlgCircularSurface"));
        dlgCircularSurface->resize(227, 115);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/dlg/dock/areaCircular"), QSize(), QIcon::Normal, QIcon::Off);
        dlgCircularSurface->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(dlgCircularSurface);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(dlgCircularSurface);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        txtRadius = new QLineEdit(dlgCircularSurface);
        txtRadius->setObjectName(QString::fromUtf8("txtRadius"));

        formLayout->setWidget(0, QFormLayout::FieldRole, txtRadius);

        label_2 = new QLabel(dlgCircularSurface);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lblFormula = new QLabel(dlgCircularSurface);
        lblFormula->setObjectName(QString::fromUtf8("lblFormula"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lblFormula);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(dlgCircularSurface);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(dlgCircularSurface);
        QObject::connect(buttonBox, SIGNAL(accepted()), dlgCircularSurface, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dlgCircularSurface, SLOT(reject()));

        QMetaObject::connectSlotsByName(dlgCircularSurface);
    } // setupUi

    void retranslateUi(QDialog *dlgCircularSurface)
    {
        dlgCircularSurface->setWindowTitle(QApplication::translate("dlgCircularSurface", "Circular Surface", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("dlgCircularSurface", "Radius", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("dlgCircularSurface", "Calculation", 0, QApplication::UnicodeUTF8));
        lblFormula->setText(QApplication::translate("dlgCircularSurface", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dlgCircularSurface: public Ui_dlgCircularSurface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGCIRCULARSURFACE_H
