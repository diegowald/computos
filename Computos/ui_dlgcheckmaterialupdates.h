/********************************************************************************
** Form generated from reading UI file 'dlgcheckmaterialupdates.ui'
**
** Created: Fri Dec 28 16:08:59 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGCHECKMATERIALUPDATES_H
#define UI_DLGCHECKMATERIALUPDATES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dlgCheckMaterialUpdates
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *btnCheck;
    QLabel *label_2;
    QPushButton *btnDownload;
    QLabel *label_3;
    QPushButton *btnInstall;
    QHBoxLayout *horizontalLayout;
    QLabel *lblLoading;
    QLabel *lblStatus;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dlgCheckMaterialUpdates)
    {
        if (dlgCheckMaterialUpdates->objectName().isEmpty())
            dlgCheckMaterialUpdates->setObjectName(QString::fromUtf8("dlgCheckMaterialUpdates"));
        dlgCheckMaterialUpdates->resize(400, 242);
        verticalLayout = new QVBoxLayout(dlgCheckMaterialUpdates);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(dlgCheckMaterialUpdates);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        btnCheck = new QPushButton(dlgCheckMaterialUpdates);
        btnCheck->setObjectName(QString::fromUtf8("btnCheck"));

        gridLayout->addWidget(btnCheck, 0, 1, 1, 3);

        label_2 = new QLabel(dlgCheckMaterialUpdates);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 2);

        btnDownload = new QPushButton(dlgCheckMaterialUpdates);
        btnDownload->setObjectName(QString::fromUtf8("btnDownload"));

        gridLayout->addWidget(btnDownload, 1, 2, 1, 2);

        label_3 = new QLabel(dlgCheckMaterialUpdates);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 3);

        btnInstall = new QPushButton(dlgCheckMaterialUpdates);
        btnInstall->setObjectName(QString::fromUtf8("btnInstall"));

        gridLayout->addWidget(btnInstall, 2, 3, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lblLoading = new QLabel(dlgCheckMaterialUpdates);
        lblLoading->setObjectName(QString::fromUtf8("lblLoading"));

        horizontalLayout->addWidget(lblLoading);

        lblStatus = new QLabel(dlgCheckMaterialUpdates);
        lblStatus->setObjectName(QString::fromUtf8("lblStatus"));

        horizontalLayout->addWidget(lblStatus);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(dlgCheckMaterialUpdates);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(dlgCheckMaterialUpdates);
        QObject::connect(buttonBox, SIGNAL(accepted()), dlgCheckMaterialUpdates, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dlgCheckMaterialUpdates, SLOT(reject()));

        QMetaObject::connectSlotsByName(dlgCheckMaterialUpdates);
    } // setupUi

    void retranslateUi(QDialog *dlgCheckMaterialUpdates)
    {
        dlgCheckMaterialUpdates->setWindowTitle(QApplication::translate("dlgCheckMaterialUpdates", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("dlgCheckMaterialUpdates", "Press Check to check for updates.", 0, QApplication::UnicodeUTF8));
        btnCheck->setText(QApplication::translate("dlgCheckMaterialUpdates", "Check", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("dlgCheckMaterialUpdates", "There are updates. Press Download.", 0, QApplication::UnicodeUTF8));
        btnDownload->setText(QApplication::translate("dlgCheckMaterialUpdates", "Download", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("dlgCheckMaterialUpdates", "Download OK. Press install to upgrade", 0, QApplication::UnicodeUTF8));
        btnInstall->setText(QApplication::translate("dlgCheckMaterialUpdates", "Install", 0, QApplication::UnicodeUTF8));
        lblLoading->setText(QString());
        lblStatus->setText(QApplication::translate("dlgCheckMaterialUpdates", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dlgCheckMaterialUpdates: public Ui_dlgCheckMaterialUpdates {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGCHECKMATERIALUPDATES_H
