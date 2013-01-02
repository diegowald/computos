/********************************************************************************
** Form generated from reading UI file 'dlgrectangularsurface.ui'
**
** Created: Fri Dec 28 16:08:59 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGRECTANGULARSURFACE_H
#define UI_DLGRECTANGULARSURFACE_H

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

class Ui_dlgRectangularSurface
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *txtLargo;
    QLabel *label_2;
    QLineEdit *txtAlto;
    QLabel *label_3;
    QLabel *lblFormula;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dlgRectangularSurface)
    {
        if (dlgRectangularSurface->objectName().isEmpty())
            dlgRectangularSurface->setObjectName(QString::fromUtf8("dlgRectangularSurface"));
        dlgRectangularSurface->resize(237, 173);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/dlg/dock/rectangularArea"), QSize(), QIcon::Normal, QIcon::Off);
        dlgRectangularSurface->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(dlgRectangularSurface);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(dlgRectangularSurface);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        txtLargo = new QLineEdit(dlgRectangularSurface);
        txtLargo->setObjectName(QString::fromUtf8("txtLargo"));

        formLayout->setWidget(0, QFormLayout::FieldRole, txtLargo);

        label_2 = new QLabel(dlgRectangularSurface);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        txtAlto = new QLineEdit(dlgRectangularSurface);
        txtAlto->setObjectName(QString::fromUtf8("txtAlto"));

        formLayout->setWidget(1, QFormLayout::FieldRole, txtAlto);

        label_3 = new QLabel(dlgRectangularSurface);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        lblFormula = new QLabel(dlgRectangularSurface);
        lblFormula->setObjectName(QString::fromUtf8("lblFormula"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lblFormula);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(dlgRectangularSurface);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(dlgRectangularSurface);
        QObject::connect(buttonBox, SIGNAL(accepted()), dlgRectangularSurface, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dlgRectangularSurface, SLOT(reject()));

        QMetaObject::connectSlotsByName(dlgRectangularSurface);
    } // setupUi

    void retranslateUi(QDialog *dlgRectangularSurface)
    {
        dlgRectangularSurface->setWindowTitle(QApplication::translate("dlgRectangularSurface", "Rectangular Surface", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("dlgRectangularSurface", "Length", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("dlgRectangularSurface", "Height", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("dlgRectangularSurface", "Calculation", 0, QApplication::UnicodeUTF8));
        lblFormula->setText(QApplication::translate("dlgRectangularSurface", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dlgRectangularSurface: public Ui_dlgRectangularSurface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGRECTANGULARSURFACE_H
