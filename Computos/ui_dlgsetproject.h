/********************************************************************************
** Form generated from reading UI file 'dlgsetproject.ui'
**
** Created: Fri Dec 28 16:08:59 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGSETPROJECT_H
#define UI_DLGSETPROJECT_H

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
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dlgSetProject
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *cboProject;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dlgSetProject)
    {
        if (dlgSetProject->objectName().isEmpty())
            dlgSetProject->setObjectName(QString::fromUtf8("dlgSetProject"));
        dlgSetProject->resize(343, 88);
        verticalLayout = new QVBoxLayout(dlgSetProject);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(dlgSetProject);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        cboProject = new QComboBox(dlgSetProject);
        cboProject->setObjectName(QString::fromUtf8("cboProject"));

        formLayout->setWidget(0, QFormLayout::FieldRole, cboProject);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(dlgSetProject);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(dlgSetProject);
        QObject::connect(buttonBox, SIGNAL(accepted()), dlgSetProject, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dlgSetProject, SLOT(reject()));

        QMetaObject::connectSlotsByName(dlgSetProject);
    } // setupUi

    void retranslateUi(QDialog *dlgSetProject)
    {
        dlgSetProject->setWindowTitle(QApplication::translate("dlgSetProject", "Select Project", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("dlgSetProject", "Project", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dlgSetProject: public Ui_dlgSetProject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGSETPROJECT_H
