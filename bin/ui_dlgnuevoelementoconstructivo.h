/********************************************************************************
** Form generated from reading UI file 'dlgnuevoelementoconstructivo.ui'
**
** Created: Sun Jan 6 11:15:32 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGNUEVOELEMENTOCONSTRUCTIVO_H
#define UI_DLGNUEVOELEMENTOCONSTRUCTIVO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dlgNuevoElementoConstructivo
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *lblNombre;
    QLineEdit *txtNombre;
    QLabel *lblMaterial;
    QLabel *lblCantidad;
    QHBoxLayout *horizontalLayout;
    QComboBox *cboCantidad;
    QPushButton *btnIngresarValores;
    QLabel *label;
    QLabel *txtValue;
    QComboBox *cboMaterial;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dlgNuevoElementoConstructivo)
    {
        if (dlgNuevoElementoConstructivo->objectName().isEmpty())
            dlgNuevoElementoConstructivo->setObjectName(QString::fromUtf8("dlgNuevoElementoConstructivo"));
        dlgNuevoElementoConstructivo->resize(400, 204);
        verticalLayout = new QVBoxLayout(dlgNuevoElementoConstructivo);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        lblNombre = new QLabel(dlgNuevoElementoConstructivo);
        lblNombre->setObjectName(QString::fromUtf8("lblNombre"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lblNombre);

        txtNombre = new QLineEdit(dlgNuevoElementoConstructivo);
        txtNombre->setObjectName(QString::fromUtf8("txtNombre"));

        formLayout->setWidget(0, QFormLayout::FieldRole, txtNombre);

        lblMaterial = new QLabel(dlgNuevoElementoConstructivo);
        lblMaterial->setObjectName(QString::fromUtf8("lblMaterial"));

        formLayout->setWidget(2, QFormLayout::LabelRole, lblMaterial);

        lblCantidad = new QLabel(dlgNuevoElementoConstructivo);
        lblCantidad->setObjectName(QString::fromUtf8("lblCantidad"));

        formLayout->setWidget(3, QFormLayout::LabelRole, lblCantidad);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cboCantidad = new QComboBox(dlgNuevoElementoConstructivo);
        cboCantidad->setObjectName(QString::fromUtf8("cboCantidad"));

        horizontalLayout->addWidget(cboCantidad);

        btnIngresarValores = new QPushButton(dlgNuevoElementoConstructivo);
        btnIngresarValores->setObjectName(QString::fromUtf8("btnIngresarValores"));

        horizontalLayout->addWidget(btnIngresarValores);


        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout);

        label = new QLabel(dlgNuevoElementoConstructivo);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label);

        txtValue = new QLabel(dlgNuevoElementoConstructivo);
        txtValue->setObjectName(QString::fromUtf8("txtValue"));

        formLayout->setWidget(4, QFormLayout::FieldRole, txtValue);

        cboMaterial = new QComboBox(dlgNuevoElementoConstructivo);
        cboMaterial->setObjectName(QString::fromUtf8("cboMaterial"));

        formLayout->setWidget(2, QFormLayout::FieldRole, cboMaterial);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(dlgNuevoElementoConstructivo);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(dlgNuevoElementoConstructivo);
        QObject::connect(buttonBox, SIGNAL(accepted()), dlgNuevoElementoConstructivo, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dlgNuevoElementoConstructivo, SLOT(reject()));

        QMetaObject::connectSlotsByName(dlgNuevoElementoConstructivo);
    } // setupUi

    void retranslateUi(QDialog *dlgNuevoElementoConstructivo)
    {
        dlgNuevoElementoConstructivo->setWindowTitle(QApplication::translate("dlgNuevoElementoConstructivo", "Build part", 0, QApplication::UnicodeUTF8));
        lblNombre->setText(QApplication::translate("dlgNuevoElementoConstructivo", "Name", 0, QApplication::UnicodeUTF8));
        lblMaterial->setText(QApplication::translate("dlgNuevoElementoConstructivo", "Material", 0, QApplication::UnicodeUTF8));
        lblCantidad->setText(QApplication::translate("dlgNuevoElementoConstructivo", "Quantity", 0, QApplication::UnicodeUTF8));
        btnIngresarValores->setText(QApplication::translate("dlgNuevoElementoConstructivo", "Set up values", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("dlgNuevoElementoConstructivo", "Value", 0, QApplication::UnicodeUTF8));
        txtValue->setText(QApplication::translate("dlgNuevoElementoConstructivo", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dlgNuevoElementoConstructivo: public Ui_dlgNuevoElementoConstructivo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGNUEVOELEMENTOCONSTRUCTIVO_H
