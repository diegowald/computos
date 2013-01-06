/********************************************************************************
** Form generated from reading UI file 'dlgsuperficiepoligonal.ui'
**
** Created: Sun Jan 6 11:15:32 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGSUPERFICIEPOLIGONAL_H
#define UI_DLGSUPERFICIEPOLIGONAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dlgSuperficiePoligonal
{
public:
    QAction *actionAddPoint;
    QAction *actionDelete_Coordinate;
    QAction *actionMove_Up;
    QAction *actionMove_Down;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *tblPoints;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLabel *lblFormula;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dlgSuperficiePoligonal)
    {
        if (dlgSuperficiePoligonal->objectName().isEmpty())
            dlgSuperficiePoligonal->setObjectName(QString::fromUtf8("dlgSuperficiePoligonal"));
        dlgSuperficiePoligonal->resize(280, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/dlg/dock/PolygonalArea"), QSize(), QIcon::Normal, QIcon::Off);
        dlgSuperficiePoligonal->setWindowIcon(icon);
        actionAddPoint = new QAction(dlgSuperficiePoligonal);
        actionAddPoint->setObjectName(QString::fromUtf8("actionAddPoint"));
        actionDelete_Coordinate = new QAction(dlgSuperficiePoligonal);
        actionDelete_Coordinate->setObjectName(QString::fromUtf8("actionDelete_Coordinate"));
        actionMove_Up = new QAction(dlgSuperficiePoligonal);
        actionMove_Up->setObjectName(QString::fromUtf8("actionMove_Up"));
        actionMove_Down = new QAction(dlgSuperficiePoligonal);
        actionMove_Down->setObjectName(QString::fromUtf8("actionMove_Down"));
        verticalLayout = new QVBoxLayout(dlgSuperficiePoligonal);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(dlgSuperficiePoligonal);
        label->setObjectName(QString::fromUtf8("label"));
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        tblPoints = new QTableWidget(dlgSuperficiePoligonal);
        tblPoints->setObjectName(QString::fromUtf8("tblPoints"));
        tblPoints->setContextMenuPolicy(Qt::CustomContextMenu);
        tblPoints->setAlternatingRowColors(true);
        tblPoints->setCornerButtonEnabled(false);

        verticalLayout->addWidget(tblPoints);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_2 = new QLabel(dlgSuperficiePoligonal);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        lblFormula = new QLabel(dlgSuperficiePoligonal);
        lblFormula->setObjectName(QString::fromUtf8("lblFormula"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lblFormula);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(dlgSuperficiePoligonal);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(dlgSuperficiePoligonal);
        QObject::connect(buttonBox, SIGNAL(accepted()), dlgSuperficiePoligonal, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dlgSuperficiePoligonal, SLOT(reject()));

        QMetaObject::connectSlotsByName(dlgSuperficiePoligonal);
    } // setupUi

    void retranslateUi(QDialog *dlgSuperficiePoligonal)
    {
        dlgSuperficiePoligonal->setWindowTitle(QApplication::translate("dlgSuperficiePoligonal", "Polygonal surface", 0, QApplication::UnicodeUTF8));
        actionAddPoint->setText(QApplication::translate("dlgSuperficiePoligonal", "Add Coordinate", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionAddPoint->setToolTip(QApplication::translate("dlgSuperficiePoligonal", "Agrega una coordenada a la lista", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionDelete_Coordinate->setText(QApplication::translate("dlgSuperficiePoligonal", "Delete Coordinate", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionDelete_Coordinate->setToolTip(QApplication::translate("dlgSuperficiePoligonal", "Borra la coordenada seleccionada", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionMove_Up->setText(QApplication::translate("dlgSuperficiePoligonal", "Move Up", 0, QApplication::UnicodeUTF8));
        actionMove_Down->setText(QApplication::translate("dlgSuperficiePoligonal", "Move Down", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("dlgSuperficiePoligonal", "Enter coordinates clockwise.", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("dlgSuperficiePoligonal", "Calculation", 0, QApplication::UnicodeUTF8));
        lblFormula->setText(QApplication::translate("dlgSuperficiePoligonal", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dlgSuperficiePoligonal: public Ui_dlgSuperficiePoligonal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGSUPERFICIEPOLIGONAL_H
