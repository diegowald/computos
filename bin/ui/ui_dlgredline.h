/********************************************************************************
** Form generated from reading UI file 'dlgredline.ui'
**
** Created: Sun Jan 6 11:09:42 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGREDLINE_H
#define UI_DLGREDLINE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dlgRedline
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *txtName;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QFrame *frmColor;
    QPushButton *btnPickColor;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dlgRedline)
    {
        if (dlgRedline->objectName().isEmpty())
            dlgRedline->setObjectName(QString::fromUtf8("dlgRedline"));
        dlgRedline->resize(253, 127);
        verticalLayout = new QVBoxLayout(dlgRedline);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(dlgRedline);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        txtName = new QLineEdit(dlgRedline);
        txtName->setObjectName(QString::fromUtf8("txtName"));

        formLayout->setWidget(0, QFormLayout::FieldRole, txtName);

        label_2 = new QLabel(dlgRedline);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frmColor = new QFrame(dlgRedline);
        frmColor->setObjectName(QString::fromUtf8("frmColor"));
        frmColor->setAutoFillBackground(true);
        frmColor->setFrameShape(QFrame::StyledPanel);
        frmColor->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frmColor);

        btnPickColor = new QPushButton(dlgRedline);
        btnPickColor->setObjectName(QString::fromUtf8("btnPickColor"));

        horizontalLayout->addWidget(btnPickColor);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(dlgRedline);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(dlgRedline);
        QObject::connect(buttonBox, SIGNAL(accepted()), dlgRedline, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dlgRedline, SLOT(reject()));

        QMetaObject::connectSlotsByName(dlgRedline);
    } // setupUi

    void retranslateUi(QDialog *dlgRedline)
    {
        dlgRedline->setWindowTitle(QApplication::translate("dlgRedline", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("dlgRedline", "Name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("dlgRedline", "Color", 0, QApplication::UnicodeUTF8));
        btnPickColor->setText(QApplication::translate("dlgRedline", "Pick ...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dlgRedline: public Ui_dlgRedline {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGREDLINE_H
