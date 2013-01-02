/********************************************************************************
** Form generated from reading UI file 'dlgnewelement.ui'
**
** Created: Fri Dec 28 16:08:59 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGNEWELEMENT_H
#define UI_DLGNEWELEMENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dlgNewElement
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *grpDetails;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *txtNombre;
    QLabel *label_2;
    QTextEdit *txtDescripcion;
    QLabel *label_3;
    QLineEdit *txtTags;
    QLabel *label_4;
    QComboBox *cboMeasureUnit;
    QCheckBox *chkUsableDirectly;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dlgNewElement)
    {
        if (dlgNewElement->objectName().isEmpty())
            dlgNewElement->setObjectName(QString::fromUtf8("dlgNewElement"));
        dlgNewElement->resize(417, 328);
        verticalLayout = new QVBoxLayout(dlgNewElement);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        grpDetails = new QGroupBox(dlgNewElement);
        grpDetails->setObjectName(QString::fromUtf8("grpDetails"));
        horizontalLayout_2 = new QHBoxLayout(grpDetails);
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        frame = new QFrame(grpDetails);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        formLayout = new QFormLayout(frame);
        formLayout->setContentsMargins(0, 0, 0, 0);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setHorizontalSpacing(0);
        formLayout->setVerticalSpacing(2);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        txtNombre = new QLineEdit(frame);
        txtNombre->setObjectName(QString::fromUtf8("txtNombre"));

        formLayout->setWidget(0, QFormLayout::FieldRole, txtNombre);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        txtDescripcion = new QTextEdit(frame);
        txtDescripcion->setObjectName(QString::fromUtf8("txtDescripcion"));
        txtDescripcion->setMaximumSize(QSize(16777215, 120));

        formLayout->setWidget(1, QFormLayout::FieldRole, txtDescripcion);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        txtTags = new QLineEdit(frame);
        txtTags->setObjectName(QString::fromUtf8("txtTags"));

        formLayout->setWidget(2, QFormLayout::FieldRole, txtTags);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        cboMeasureUnit = new QComboBox(frame);
        cboMeasureUnit->setObjectName(QString::fromUtf8("cboMeasureUnit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, cboMeasureUnit);

        chkUsableDirectly = new QCheckBox(frame);
        chkUsableDirectly->setObjectName(QString::fromUtf8("chkUsableDirectly"));

        formLayout->setWidget(4, QFormLayout::SpanningRole, chkUsableDirectly);


        horizontalLayout_2->addWidget(frame);

        frame_2 = new QFrame(grpDetails);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        horizontalLayout_2->addWidget(frame_2);


        verticalLayout->addWidget(grpDetails);

        buttonBox = new QDialogButtonBox(dlgNewElement);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(dlgNewElement);
        QObject::connect(buttonBox, SIGNAL(accepted()), dlgNewElement, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dlgNewElement, SLOT(reject()));

        QMetaObject::connectSlotsByName(dlgNewElement);
    } // setupUi

    void retranslateUi(QDialog *dlgNewElement)
    {
        dlgNewElement->setWindowTitle(QApplication::translate("dlgNewElement", "Dialog", 0, QApplication::UnicodeUTF8));
        grpDetails->setTitle(QApplication::translate("dlgNewElement", "Details", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("dlgNewElement", "Name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("dlgNewElement", "Description", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("dlgNewElement", "Tags", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("dlgNewElement", "Measure Unit", 0, QApplication::UnicodeUTF8));
        chkUsableDirectly->setText(QApplication::translate("dlgNewElement", "Use directly in project.", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dlgNewElement: public Ui_dlgNewElement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGNEWELEMENT_H
