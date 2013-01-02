/********************************************************************************
** Form generated from reading UI file 'projectwindow.ui'
**
** Created: Fri Dec 28 16:08:59 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTWINDOW_H
#define UI_PROJECTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProjectWindow
{
public:
    QAction *actionRemove_Build_Part;
    QAction *actionClone_and_set_material;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_3;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *txtNombreProyecto;
    QLabel *label_2;
    QLineEdit *txtPropietarios;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *txtDireccion;
    QTextEdit *txtNotas;
    QLabel *Telefono;
    QLineEdit *txtTelefono;
    QLabel *label_5;
    QLineEdit *txtEMail;
    QWidget *tabProyecto;
    QHBoxLayout *horizontalLayout_4;
    QTreeWidget *treeProyecto;
    QWidget *tabComputo;
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeComputoMetrico;
    QTreeWidget *treeComputoMateriaPrima;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ProjectWindow)
    {
        if (ProjectWindow->objectName().isEmpty())
            ProjectWindow->setObjectName(QString::fromUtf8("ProjectWindow"));
        ProjectWindow->resize(400, 357);
        ProjectWindow->setAcceptDrops(true);
        actionRemove_Build_Part = new QAction(ProjectWindow);
        actionRemove_Build_Part->setObjectName(QString::fromUtf8("actionRemove_Build_Part"));
        actionClone_and_set_material = new QAction(ProjectWindow);
        actionClone_and_set_material->setObjectName(QString::fromUtf8("actionClone_and_set_material"));
        centralWidget = new QWidget(ProjectWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_3 = new QHBoxLayout(tab);
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(2);
        formLayout->setVerticalSpacing(2);
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        txtNombreProyecto = new QLineEdit(tab);
        txtNombreProyecto->setObjectName(QString::fromUtf8("txtNombreProyecto"));

        formLayout->setWidget(0, QFormLayout::FieldRole, txtNombreProyecto);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        txtPropietarios = new QLineEdit(tab);
        txtPropietarios->setObjectName(QString::fromUtf8("txtPropietarios"));

        formLayout->setWidget(1, QFormLayout::FieldRole, txtPropietarios);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_4);

        txtDireccion = new QLineEdit(tab);
        txtDireccion->setObjectName(QString::fromUtf8("txtDireccion"));

        formLayout->setWidget(2, QFormLayout::FieldRole, txtDireccion);

        txtNotas = new QTextEdit(tab);
        txtNotas->setObjectName(QString::fromUtf8("txtNotas"));

        formLayout->setWidget(5, QFormLayout::FieldRole, txtNotas);

        Telefono = new QLabel(tab);
        Telefono->setObjectName(QString::fromUtf8("Telefono"));

        formLayout->setWidget(3, QFormLayout::LabelRole, Telefono);

        txtTelefono = new QLineEdit(tab);
        txtTelefono->setObjectName(QString::fromUtf8("txtTelefono"));

        formLayout->setWidget(3, QFormLayout::FieldRole, txtTelefono);

        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        txtEMail = new QLineEdit(tab);
        txtEMail->setObjectName(QString::fromUtf8("txtEMail"));

        formLayout->setWidget(4, QFormLayout::FieldRole, txtEMail);


        horizontalLayout_3->addLayout(formLayout);

        tabWidget->addTab(tab, QString());
        tabProyecto = new QWidget();
        tabProyecto->setObjectName(QString::fromUtf8("tabProyecto"));
        horizontalLayout_4 = new QHBoxLayout(tabProyecto);
        horizontalLayout_4->setSpacing(2);
        horizontalLayout_4->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        treeProyecto = new QTreeWidget(tabProyecto);
        treeProyecto->setObjectName(QString::fromUtf8("treeProyecto"));
        treeProyecto->setContextMenuPolicy(Qt::CustomContextMenu);
        treeProyecto->setAcceptDrops(false);

        horizontalLayout_4->addWidget(treeProyecto);

        tabWidget->addTab(tabProyecto, QString());
        tabComputo = new QWidget();
        tabComputo->setObjectName(QString::fromUtf8("tabComputo"));
        verticalLayout = new QVBoxLayout(tabComputo);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        treeComputoMetrico = new QTreeWidget(tabComputo);
        treeComputoMetrico->setObjectName(QString::fromUtf8("treeComputoMetrico"));

        verticalLayout->addWidget(treeComputoMetrico);

        treeComputoMateriaPrima = new QTreeWidget(tabComputo);
        treeComputoMateriaPrima->setObjectName(QString::fromUtf8("treeComputoMateriaPrima"));

        verticalLayout->addWidget(treeComputoMateriaPrima);

        tabWidget->addTab(tabComputo, QString());

        horizontalLayout->addWidget(tabWidget);

        ProjectWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ProjectWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ProjectWindow->setStatusBar(statusBar);

        retranslateUi(ProjectWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ProjectWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ProjectWindow)
    {
        ProjectWindow->setWindowTitle(QApplication::translate("ProjectWindow", "Project Window", 0, QApplication::UnicodeUTF8));
        actionRemove_Build_Part->setText(QApplication::translate("ProjectWindow", "Remove Build Part", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionRemove_Build_Part->setToolTip(QApplication::translate("ProjectWindow", "Removes selected Build Part", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionClone_and_set_material->setText(QApplication::translate("ProjectWindow", "Clone and set material", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ProjectWindow", "Name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ProjectWindow", "Owner", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ProjectWindow", "Address", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ProjectWindow", "Notes", 0, QApplication::UnicodeUTF8));
        Telefono->setText(QApplication::translate("ProjectWindow", "Telephone", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ProjectWindow", "e-mail", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ProjectWindow", "Project information", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeProyecto->headerItem();
        ___qtreewidgetitem->setText(5, QApplication::translate("ProjectWindow", "Measure Unit", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(4, QApplication::translate("ProjectWindow", "Quantity", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(3, QApplication::translate("ProjectWindow", "Dimensions", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(2, QApplication::translate("ProjectWindow", "Shape", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("ProjectWindow", "Material", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("ProjectWindow", "Name", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabProyecto), QApplication::translate("ProjectWindow", "Building parts", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem1 = treeComputoMetrico->headerItem();
        ___qtreewidgetitem1->setText(2, QApplication::translate("ProjectWindow", "Unit", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(1, QApplication::translate("ProjectWindow", "Quantity", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(0, QApplication::translate("ProjectWindow", "Part-Material", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem2 = treeComputoMateriaPrima->headerItem();
        ___qtreewidgetitem2->setText(2, QApplication::translate("ProjectWindow", "Unit", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem2->setText(1, QApplication::translate("ProjectWindow", "Quantity", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem2->setText(0, QApplication::translate("ProjectWindow", "Material", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabComputo), QApplication::translate("ProjectWindow", "Material Ammounts", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ProjectWindow: public Ui_ProjectWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTWINDOW_H
