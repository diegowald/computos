/********************************************************************************
** Form generated from reading UI file 'mainwindowapplication.ui'
**
** Created: Fri Dec 28 16:08:59 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWAPPLICATION_H
#define UI_MAINWINDOWAPPLICATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMdiArea>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowApplication
{
public:
    QAction *action_New;
    QAction *action_Open;
    QAction *action_Close;
    QAction *action_Print;
    QAction *actionE_xit;
    QAction *actionEdit_Material_defiinition;
    QAction *action_Save;
    QAction *action_About;
    QAction *action_List;
    QAction *action_Price_Lists;
    QAction *actionCheck_for_Materials_update;
    QAction *action_Compute;
    QAction *action_Import_Pricelist;
    QAction *actionSave_As;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QMdiArea *mdiArea;
    QMenuBar *menubar;
    QMenu *menu_File;
    QMenu *menuMaterials;
    QMenu *menu_Help;
    QMenu *menu_Providers;
    QMenu *menu_Cost_Analysis;
    QStatusBar *statusbar;
    QDockWidget *dockMateriales;
    QWidget *dockWidgetContents_2;

    void setupUi(QMainWindow *MainWindowApplication)
    {
        if (MainWindowApplication->objectName().isEmpty())
            MainWindowApplication->setObjectName(QString::fromUtf8("MainWindowApplication"));
        MainWindowApplication->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/dlg/dock/main"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindowApplication->setWindowIcon(icon);
        MainWindowApplication->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks|QMainWindow::VerticalTabs);
        action_New = new QAction(MainWindowApplication);
        action_New->setObjectName(QString::fromUtf8("action_New"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/dlg/dock/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_New->setIcon(icon1);
        action_New->setIconVisibleInMenu(true);
        action_Open = new QAction(MainWindowApplication);
        action_Open->setObjectName(QString::fromUtf8("action_Open"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/dlg/dock/images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Open->setIcon(icon2);
        action_Open->setIconVisibleInMenu(true);
        action_Close = new QAction(MainWindowApplication);
        action_Close->setObjectName(QString::fromUtf8("action_Close"));
        action_Print = new QAction(MainWindowApplication);
        action_Print->setObjectName(QString::fromUtf8("action_Print"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/dlg/dock/images/print.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Print->setIcon(icon3);
        action_Print->setIconVisibleInMenu(true);
        actionE_xit = new QAction(MainWindowApplication);
        actionE_xit->setObjectName(QString::fromUtf8("actionE_xit"));
        actionEdit_Material_defiinition = new QAction(MainWindowApplication);
        actionEdit_Material_defiinition->setObjectName(QString::fromUtf8("actionEdit_Material_defiinition"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/dlg/dock/images/colors.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEdit_Material_defiinition->setIcon(icon4);
        actionEdit_Material_defiinition->setIconVisibleInMenu(true);
        action_Save = new QAction(MainWindowApplication);
        action_Save->setObjectName(QString::fromUtf8("action_Save"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/dlg/dock/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Save->setIcon(icon5);
        action_Save->setIconVisibleInMenu(true);
        action_About = new QAction(MainWindowApplication);
        action_About->setObjectName(QString::fromUtf8("action_About"));
        action_List = new QAction(MainWindowApplication);
        action_List->setObjectName(QString::fromUtf8("action_List"));
        action_Price_Lists = new QAction(MainWindowApplication);
        action_Price_Lists->setObjectName(QString::fromUtf8("action_Price_Lists"));
        actionCheck_for_Materials_update = new QAction(MainWindowApplication);
        actionCheck_for_Materials_update->setObjectName(QString::fromUtf8("actionCheck_for_Materials_update"));
        action_Compute = new QAction(MainWindowApplication);
        action_Compute->setObjectName(QString::fromUtf8("action_Compute"));
        action_Import_Pricelist = new QAction(MainWindowApplication);
        action_Import_Pricelist->setObjectName(QString::fromUtf8("action_Import_Pricelist"));
        actionSave_As = new QAction(MainWindowApplication);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionSave_As->setIcon(icon5);
        centralwidget = new QWidget(MainWindowApplication);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        mdiArea = new QMdiArea(centralwidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));

        horizontalLayout->addWidget(mdiArea);

        MainWindowApplication->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowApplication);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 29));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menuMaterials = new QMenu(menubar);
        menuMaterials->setObjectName(QString::fromUtf8("menuMaterials"));
        menu_Help = new QMenu(menubar);
        menu_Help->setObjectName(QString::fromUtf8("menu_Help"));
        menu_Providers = new QMenu(menubar);
        menu_Providers->setObjectName(QString::fromUtf8("menu_Providers"));
        menu_Cost_Analysis = new QMenu(menubar);
        menu_Cost_Analysis->setObjectName(QString::fromUtf8("menu_Cost_Analysis"));
        MainWindowApplication->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowApplication);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindowApplication->setStatusBar(statusbar);
        dockMateriales = new QDockWidget(MainWindowApplication);
        dockMateriales->setObjectName(QString::fromUtf8("dockMateriales"));
        dockMateriales->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        dockMateriales->setWidget(dockWidgetContents_2);
        MainWindowApplication->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockMateriales);

        menubar->addAction(menu_File->menuAction());
        menubar->addAction(menu_Cost_Analysis->menuAction());
        menubar->addAction(menuMaterials->menuAction());
        menubar->addAction(menu_Providers->menuAction());
        menubar->addAction(menu_Help->menuAction());
        menu_File->addAction(action_New);
        menu_File->addAction(action_Open);
        menu_File->addAction(action_Save);
        menu_File->addAction(actionSave_As);
        menu_File->addAction(action_Close);
        menu_File->addSeparator();
        menu_File->addAction(action_Print);
        menu_File->addSeparator();
        menu_File->addAction(actionE_xit);
        menuMaterials->addAction(actionEdit_Material_defiinition);
        menuMaterials->addSeparator();
        menuMaterials->addAction(actionCheck_for_Materials_update);
        menu_Help->addAction(action_About);
        menu_Providers->addAction(action_List);
        menu_Providers->addSeparator();
        menu_Providers->addAction(action_Price_Lists);
        menu_Providers->addAction(action_Import_Pricelist);
        menu_Cost_Analysis->addAction(action_Compute);

        retranslateUi(MainWindowApplication);

        QMetaObject::connectSlotsByName(MainWindowApplication);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowApplication)
    {
        MainWindowApplication->setWindowTitle(QApplication::translate("MainWindowApplication", "Metric", 0, QApplication::UnicodeUTF8));
        action_New->setText(QApplication::translate("MainWindowApplication", "&New", 0, QApplication::UnicodeUTF8));
        action_New->setShortcut(QApplication::translate("MainWindowApplication", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        action_Open->setText(QApplication::translate("MainWindowApplication", "&Open", 0, QApplication::UnicodeUTF8));
        action_Open->setShortcut(QApplication::translate("MainWindowApplication", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        action_Close->setText(QApplication::translate("MainWindowApplication", "&Close", 0, QApplication::UnicodeUTF8));
        action_Close->setShortcut(QApplication::translate("MainWindowApplication", "Ctrl+W", 0, QApplication::UnicodeUTF8));
        action_Print->setText(QApplication::translate("MainWindowApplication", "&Print", 0, QApplication::UnicodeUTF8));
        action_Print->setShortcut(QApplication::translate("MainWindowApplication", "Ctrl+P", 0, QApplication::UnicodeUTF8));
        actionE_xit->setText(QApplication::translate("MainWindowApplication", "E&xit", 0, QApplication::UnicodeUTF8));
        actionE_xit->setShortcut(QApplication::translate("MainWindowApplication", "Ctrl+Q, Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionEdit_Material_defiinition->setText(QApplication::translate("MainWindowApplication", "Edit Material defiinition", 0, QApplication::UnicodeUTF8));
        action_Save->setText(QApplication::translate("MainWindowApplication", "&Save", 0, QApplication::UnicodeUTF8));
        action_Save->setShortcut(QApplication::translate("MainWindowApplication", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        action_About->setText(QApplication::translate("MainWindowApplication", "&About", 0, QApplication::UnicodeUTF8));
        action_List->setText(QApplication::translate("MainWindowApplication", "&List", 0, QApplication::UnicodeUTF8));
        action_Price_Lists->setText(QApplication::translate("MainWindowApplication", "&Price Lists", 0, QApplication::UnicodeUTF8));
        actionCheck_for_Materials_update->setText(QApplication::translate("MainWindowApplication", "Check for Materials update...", 0, QApplication::UnicodeUTF8));
        action_Compute->setText(QApplication::translate("MainWindowApplication", "&Compute", 0, QApplication::UnicodeUTF8));
        action_Import_Pricelist->setText(QApplication::translate("MainWindowApplication", "&Import Pricelist", 0, QApplication::UnicodeUTF8));
        actionSave_As->setText(QApplication::translate("MainWindowApplication", "Save &As...", 0, QApplication::UnicodeUTF8));
        menu_File->setTitle(QApplication::translate("MainWindowApplication", "&Project", 0, QApplication::UnicodeUTF8));
        menuMaterials->setTitle(QApplication::translate("MainWindowApplication", "&Materials", 0, QApplication::UnicodeUTF8));
        menu_Help->setTitle(QApplication::translate("MainWindowApplication", "&Help", 0, QApplication::UnicodeUTF8));
        menu_Providers->setTitle(QApplication::translate("MainWindowApplication", "&Providers", 0, QApplication::UnicodeUTF8));
        menu_Cost_Analysis->setTitle(QApplication::translate("MainWindowApplication", "&Cost Analysis", 0, QApplication::UnicodeUTF8));
        dockMateriales->setWindowTitle(QApplication::translate("MainWindowApplication", "Material Library", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowApplication: public Ui_MainWindowApplication {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWAPPLICATION_H
