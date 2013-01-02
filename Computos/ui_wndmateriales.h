/********************************************************************************
** Form generated from reading UI file 'wndmateriales.ui'
**
** Created: Fri Dec 28 16:08:59 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WNDMATERIALES_H
#define UI_WNDMATERIALES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QCommandLinkButton>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_wndMateriales
{
public:
    QAction *actionNewMaterial;
    QAction *actionSaveLibrary;
    QAction *actionSaveMaterial;
    QAction *actionAddComponente;
    QAction *actionDeleteComponente;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeMateriales;
    QGroupBox *grpDetails;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *txtNombre;
    QLabel *label_2;
    QTextEdit *txtDescripcion;
    QLabel *label_3;
    QLineEdit *txtTags;
    QLabel *label_4;
    QComboBox *cboMeasureUnit;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *chkUsableDirectly;
    QCommandLinkButton *cmdGoogleIt;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *treeComponentes;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *wndMateriales)
    {
        if (wndMateriales->objectName().isEmpty())
            wndMateriales->setObjectName(QString::fromUtf8("wndMateriales"));
        wndMateriales->resize(800, 600);
        actionNewMaterial = new QAction(wndMateriales);
        actionNewMaterial->setObjectName(QString::fromUtf8("actionNewMaterial"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/dlg/dock/add"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewMaterial->setIcon(icon);
        actionSaveLibrary = new QAction(wndMateriales);
        actionSaveLibrary->setObjectName(QString::fromUtf8("actionSaveLibrary"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/dlg/dock/save"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveLibrary->setIcon(icon1);
        actionSaveMaterial = new QAction(wndMateriales);
        actionSaveMaterial->setObjectName(QString::fromUtf8("actionSaveMaterial"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/dlg/dock/ok"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveMaterial->setIcon(icon2);
        actionAddComponente = new QAction(wndMateriales);
        actionAddComponente->setObjectName(QString::fromUtf8("actionAddComponente"));
        actionDeleteComponente = new QAction(wndMateriales);
        actionDeleteComponente->setObjectName(QString::fromUtf8("actionDeleteComponente"));
        centralwidget = new QWidget(wndMateriales);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        treeMateriales = new QTreeWidget(centralwidget);
        QFont font;
        font.setKerning(true);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setFont(0, font);
        treeMateriales->setHeaderItem(__qtreewidgetitem);
        treeMateriales->setObjectName(QString::fromUtf8("treeMateriales"));
        treeMateriales->setAlternatingRowColors(true);
        treeMateriales->setRootIsDecorated(false);
        treeMateriales->setItemsExpandable(false);

        verticalLayout->addWidget(treeMateriales);

        grpDetails = new QGroupBox(centralwidget);
        grpDetails->setObjectName(QString::fromUtf8("grpDetails"));
        horizontalLayout_2 = new QHBoxLayout(grpDetails);
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        frame = new QFrame(grpDetails);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
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


        verticalLayout_2->addLayout(formLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        chkUsableDirectly = new QCheckBox(frame);
        chkUsableDirectly->setObjectName(QString::fromUtf8("chkUsableDirectly"));

        horizontalLayout_3->addWidget(chkUsableDirectly);

        cmdGoogleIt = new QCommandLinkButton(frame);
        cmdGoogleIt->setObjectName(QString::fromUtf8("cmdGoogleIt"));

        horizontalLayout_3->addWidget(cmdGoogleIt);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_2->addWidget(frame);

        frame_2 = new QFrame(grpDetails);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        treeComponentes = new QTreeWidget(frame_2);
        treeComponentes->setObjectName(QString::fromUtf8("treeComponentes"));
        treeComponentes->setContextMenuPolicy(Qt::CustomContextMenu);
        treeComponentes->setAlternatingRowColors(true);
        treeComponentes->setRootIsDecorated(false);

        horizontalLayout->addWidget(treeComponentes);


        horizontalLayout_2->addWidget(frame_2);


        verticalLayout->addWidget(grpDetails);

        wndMateriales->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(wndMateriales);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        wndMateriales->setStatusBar(statusbar);
        toolBar = new QToolBar(wndMateriales);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        wndMateriales->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionNewMaterial);
        toolBar->addAction(actionSaveMaterial);
        toolBar->addAction(actionSaveLibrary);
        toolBar->addSeparator();

        retranslateUi(wndMateriales);

        QMetaObject::connectSlotsByName(wndMateriales);
    } // setupUi

    void retranslateUi(QMainWindow *wndMateriales)
    {
        wndMateriales->setWindowTitle(QApplication::translate("wndMateriales", "Material Library", 0, QApplication::UnicodeUTF8));
        actionNewMaterial->setText(QApplication::translate("wndMateriales", "New", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionNewMaterial->setToolTip(QApplication::translate("wndMateriales", "New Material", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSaveLibrary->setText(QApplication::translate("wndMateriales", "SaveLibrary", 0, QApplication::UnicodeUTF8));
        actionSaveMaterial->setText(QApplication::translate("wndMateriales", "Save Material", 0, QApplication::UnicodeUTF8));
        actionAddComponente->setText(QApplication::translate("wndMateriales", "AddComponente", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionAddComponente->setToolTip(QApplication::translate("wndMateriales", "Add Component", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionDeleteComponente->setText(QApplication::translate("wndMateriales", "Remove Component", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeMateriales->headerItem();
        ___qtreewidgetitem->setText(3, QApplication::translate("wndMateriales", "Complex", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(2, QApplication::translate("wndMateriales", "Tags", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("wndMateriales", "Measure Unit", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("wndMateriales", "Name", 0, QApplication::UnicodeUTF8));
        grpDetails->setTitle(QApplication::translate("wndMateriales", "Details", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("wndMateriales", "Name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("wndMateriales", "Description", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("wndMateriales", "Tags", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("wndMateriales", "Measure Unit", 0, QApplication::UnicodeUTF8));
        chkUsableDirectly->setText(QApplication::translate("wndMateriales", "Use directly in project.", 0, QApplication::UnicodeUTF8));
        cmdGoogleIt->setText(QApplication::translate("wndMateriales", "Find in internet", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem1 = treeComponentes->headerItem();
        ___qtreewidgetitem1->setText(3, QApplication::translate("wndMateriales", "Complex", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(2, QApplication::translate("wndMateriales", "Measure Unit", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(1, QApplication::translate("wndMateriales", "Quantity", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(0, QApplication::translate("wndMateriales", "Name", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        treeComponentes->setToolTip(QApplication::translate("wndMateriales", "Componentes que forman este material", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolBar->setWindowTitle(QApplication::translate("wndMateriales", "Materials", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class wndMateriales: public Ui_wndMateriales {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WNDMATERIALES_H
