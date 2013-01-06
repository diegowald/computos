/********************************************************************************
** Form generated from reading UI file 'dlgcomponente.ui'
**
** Created: Sun Jan 6 11:15:32 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGCOMPONENTE_H
#define UI_DLGCOMPONENTE_H

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
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dlgComponente
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *txtMaterialPadre;
    QLabel *label_3;
    QComboBox *cboMaterial;
    QLabel *label_4;
    QLineEdit *txtCantidad;
    QLabel *label_5;
    QLabel *txtUnidad;
    QLabel *label_6;
    QLabel *txtCompuesto;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dlgComponente)
    {
        if (dlgComponente->objectName().isEmpty())
            dlgComponente->setObjectName(QString::fromUtf8("dlgComponente"));
        dlgComponente->resize(400, 186);
        verticalLayout = new QVBoxLayout(dlgComponente);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(dlgComponente);
        label->setObjectName(QString::fromUtf8("label"));
        label->setWordWrap(true);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        txtMaterialPadre = new QLabel(dlgComponente);
        txtMaterialPadre->setObjectName(QString::fromUtf8("txtMaterialPadre"));

        formLayout->setWidget(0, QFormLayout::FieldRole, txtMaterialPadre);

        label_3 = new QLabel(dlgComponente);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        cboMaterial = new QComboBox(dlgComponente);
        cboMaterial->setObjectName(QString::fromUtf8("cboMaterial"));

        formLayout->setWidget(1, QFormLayout::FieldRole, cboMaterial);

        label_4 = new QLabel(dlgComponente);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        txtCantidad = new QLineEdit(dlgComponente);
        txtCantidad->setObjectName(QString::fromUtf8("txtCantidad"));

        formLayout->setWidget(2, QFormLayout::FieldRole, txtCantidad);

        label_5 = new QLabel(dlgComponente);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        txtUnidad = new QLabel(dlgComponente);
        txtUnidad->setObjectName(QString::fromUtf8("txtUnidad"));

        formLayout->setWidget(3, QFormLayout::FieldRole, txtUnidad);

        label_6 = new QLabel(dlgComponente);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_6);

        txtCompuesto = new QLabel(dlgComponente);
        txtCompuesto->setObjectName(QString::fromUtf8("txtCompuesto"));

        formLayout->setWidget(4, QFormLayout::FieldRole, txtCompuesto);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(dlgComponente);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(dlgComponente);
        QObject::connect(buttonBox, SIGNAL(accepted()), dlgComponente, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dlgComponente, SLOT(reject()));

        QMetaObject::connectSlotsByName(dlgComponente);
    } // setupUi

    void retranslateUi(QDialog *dlgComponente)
    {
        dlgComponente->setWindowTitle(QApplication::translate("dlgComponente", "Material components", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("dlgComponente", "Base material", 0, QApplication::UnicodeUTF8));
        txtMaterialPadre->setText(QApplication::translate("dlgComponente", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("dlgComponente", "Material", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("dlgComponente", "Quantity", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("dlgComponente", "Measure Unit", 0, QApplication::UnicodeUTF8));
        txtUnidad->setText(QApplication::translate("dlgComponente", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("dlgComponente", "Complex", 0, QApplication::UnicodeUTF8));
        txtCompuesto->setText(QApplication::translate("dlgComponente", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dlgComponente: public Ui_dlgComponente {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGCOMPONENTE_H
