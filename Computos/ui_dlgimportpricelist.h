/********************************************************************************
** Form generated from reading UI file 'dlgimportpricelist.ui'
**
** Created: Fri Dec 28 16:08:59 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGIMPORTPRICELIST_H
#define UI_DLGIMPORTPRICELIST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dlgImportPriceList
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout_5;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *txtfilename;
    QPushButton *btnOpenFileDialog;
    QHBoxLayout *horizontalLayout_6;
    QFormLayout *formLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QComboBox *cboProviders;
    QLineEdit *txtProvider;
    QFormLayout *formLayout_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *cboPriceLists;
    QLineEdit *txtPriceList;
    QHBoxLayout *horizontalLayout_3;
    QFormLayout *formLayout_3;
    QLabel *label_3;
    QLineEdit *txtRecordSeparator;
    QFormLayout *formLayout_4;
    QLabel *label_4;
    QLineEdit *txtStringDelimiter;
    QCheckBox *chkHeadersOnFirstRow;
    QTreeWidget *treeCSV;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lblRecordCount;
    QSpacerItem *horizontalSpacer;
    QProgressBar *progress;
    QPushButton *btnCancel;
    QPushButton *btnImport;

    void setupUi(QDialog *dlgImportPriceList)
    {
        if (dlgImportPriceList->objectName().isEmpty())
            dlgImportPriceList->setObjectName(QString::fromUtf8("dlgImportPriceList"));
        dlgImportPriceList->resize(678, 417);
        verticalLayout = new QVBoxLayout(dlgImportPriceList);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        label_5 = new QLabel(dlgImportPriceList);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        txtfilename = new QLineEdit(dlgImportPriceList);
        txtfilename->setObjectName(QString::fromUtf8("txtfilename"));

        horizontalLayout_4->addWidget(txtfilename);

        btnOpenFileDialog = new QPushButton(dlgImportPriceList);
        btnOpenFileDialog->setObjectName(QString::fromUtf8("btnOpenFileDialog"));
        btnOpenFileDialog->setMaximumSize(QSize(20, 16777215));

        horizontalLayout_4->addWidget(btnOpenFileDialog);


        formLayout_5->setLayout(0, QFormLayout::FieldRole, horizontalLayout_4);


        verticalLayout->addLayout(formLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(dlgImportPriceList);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cboProviders = new QComboBox(dlgImportPriceList);
        cboProviders->setObjectName(QString::fromUtf8("cboProviders"));

        horizontalLayout->addWidget(cboProviders);

        txtProvider = new QLineEdit(dlgImportPriceList);
        txtProvider->setObjectName(QString::fromUtf8("txtProvider"));

        horizontalLayout->addWidget(txtProvider);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout);


        horizontalLayout_6->addLayout(formLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_2 = new QLabel(dlgImportPriceList);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        cboPriceLists = new QComboBox(dlgImportPriceList);
        cboPriceLists->setObjectName(QString::fromUtf8("cboPriceLists"));

        horizontalLayout_2->addWidget(cboPriceLists);

        txtPriceList = new QLineEdit(dlgImportPriceList);
        txtPriceList->setObjectName(QString::fromUtf8("txtPriceList"));

        horizontalLayout_2->addWidget(txtPriceList);


        formLayout_2->setLayout(0, QFormLayout::FieldRole, horizontalLayout_2);


        horizontalLayout_6->addLayout(formLayout_2);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label_3 = new QLabel(dlgImportPriceList);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_3);

        txtRecordSeparator = new QLineEdit(dlgImportPriceList);
        txtRecordSeparator->setObjectName(QString::fromUtf8("txtRecordSeparator"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, txtRecordSeparator);


        horizontalLayout_3->addLayout(formLayout_3);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        label_4 = new QLabel(dlgImportPriceList);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_4);

        txtStringDelimiter = new QLineEdit(dlgImportPriceList);
        txtStringDelimiter->setObjectName(QString::fromUtf8("txtStringDelimiter"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, txtStringDelimiter);


        horizontalLayout_3->addLayout(formLayout_4);

        chkHeadersOnFirstRow = new QCheckBox(dlgImportPriceList);
        chkHeadersOnFirstRow->setObjectName(QString::fromUtf8("chkHeadersOnFirstRow"));

        horizontalLayout_3->addWidget(chkHeadersOnFirstRow);


        verticalLayout->addLayout(horizontalLayout_3);

        treeCSV = new QTreeWidget(dlgImportPriceList);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeCSV->setHeaderItem(__qtreewidgetitem);
        treeCSV->setObjectName(QString::fromUtf8("treeCSV"));
        treeCSV->setContextMenuPolicy(Qt::CustomContextMenu);
        treeCSV->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeCSV->setAlternatingRowColors(true);

        verticalLayout->addWidget(treeCSV);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lblRecordCount = new QLabel(dlgImportPriceList);
        lblRecordCount->setObjectName(QString::fromUtf8("lblRecordCount"));

        horizontalLayout_5->addWidget(lblRecordCount);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        progress = new QProgressBar(dlgImportPriceList);
        progress->setObjectName(QString::fromUtf8("progress"));
        progress->setValue(24);

        horizontalLayout_5->addWidget(progress);

        btnCancel = new QPushButton(dlgImportPriceList);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setDefault(true);

        horizontalLayout_5->addWidget(btnCancel);

        btnImport = new QPushButton(dlgImportPriceList);
        btnImport->setObjectName(QString::fromUtf8("btnImport"));

        horizontalLayout_5->addWidget(btnImport);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(dlgImportPriceList);
        QObject::connect(btnCancel, SIGNAL(clicked()), dlgImportPriceList, SLOT(reject()));

        QMetaObject::connectSlotsByName(dlgImportPriceList);
    } // setupUi

    void retranslateUi(QDialog *dlgImportPriceList)
    {
        dlgImportPriceList->setWindowTitle(QApplication::translate("dlgImportPriceList", "Import Pricelist", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("dlgImportPriceList", "File to import", 0, QApplication::UnicodeUTF8));
        btnOpenFileDialog->setText(QApplication::translate("dlgImportPriceList", "...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("dlgImportPriceList", "Provider", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("dlgImportPriceList", "Pricelist name", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("dlgImportPriceList", "Record Separator", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("dlgImportPriceList", "String delimiter", 0, QApplication::UnicodeUTF8));
        chkHeadersOnFirstRow->setText(QApplication::translate("dlgImportPriceList", "Headers on first Line", 0, QApplication::UnicodeUTF8));
        lblRecordCount->setText(QApplication::translate("dlgImportPriceList", "TextLabel", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("dlgImportPriceList", "Cancel", 0, QApplication::UnicodeUTF8));
        btnImport->setText(QApplication::translate("dlgImportPriceList", "Import", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dlgImportPriceList: public Ui_dlgImportPriceList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGIMPORTPRICELIST_H
