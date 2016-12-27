/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QGroupBox *groupBox;
    QLabel *ERR_Main_Label;
    QPushButton *Main_button;
    QComboBox *SCK_list;
    QComboBox *Prog_list;
    QWidget *tab;
    QPushButton *LPT_Prog_Schem_Butt;
    QPushButton *KANDA_help;
    QComboBox *uC_list;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(516, 357);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(10, 40, 491, 241));
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 80, 391, 61));
        groupBox->setStyleSheet(QStringLiteral("background-color:  #dcdbff;"));
        ERR_Main_Label = new QLabel(groupBox);
        ERR_Main_Label->setObjectName(QStringLiteral("ERR_Main_Label"));
        ERR_Main_Label->setGeometry(QRect(200, 20, 171, 20));
        ERR_Main_Label->setStyleSheet(QLatin1String("background-color:  #dcdbff;c\n"
"olor: blue;\n"
"font-weight: bold;"));
        Main_button = new QPushButton(tab_2);
        Main_button->setObjectName(QStringLiteral("Main_button"));
        Main_button->setGeometry(QRect(30, 100, 151, 21));
        Main_button->setAutoFillBackground(true);
        Main_button->setStyleSheet(QStringLiteral(""));
        SCK_list = new QComboBox(tab_2);
        SCK_list->setObjectName(QStringLiteral("SCK_list"));
        SCK_list->setEnabled(true);
        SCK_list->setGeometry(QRect(320, 10, 151, 22));
        SCK_list->setMaxVisibleItems(13);
        Prog_list = new QComboBox(tab_2);
        Prog_list->setObjectName(QStringLiteral("Prog_list"));
        Prog_list->setGeometry(QRect(10, 10, 141, 22));
        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        LPT_Prog_Schem_Butt = new QPushButton(tab);
        LPT_Prog_Schem_Butt->setObjectName(QStringLiteral("LPT_Prog_Schem_Butt"));
        LPT_Prog_Schem_Butt->setGeometry(QRect(20, 30, 191, 21));
        KANDA_help = new QPushButton(tab);
        KANDA_help->setObjectName(QStringLiteral("KANDA_help"));
        KANDA_help->setGeometry(QRect(20, 50, 191, 21));
        tabWidget->addTab(tab, QString());
        uC_list = new QComboBox(centralWidget);
        uC_list->setObjectName(QStringLiteral("uC_list"));
        uC_list->setGeometry(QRect(10, 10, 131, 22));
        uC_list->setMaxVisibleItems(20);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 516, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "PK AVR Calculator     ver. 0.1", 0));
        groupBox->setTitle(QString());
        ERR_Main_Label->setText(QString());
        Main_button->setText(QApplication::translate("MainWindow", "Sprawd\305\272 pod\305\202\304\205czony AVR", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Programator AVR", 0));
        LPT_Prog_Schem_Butt->setText(QApplication::translate("MainWindow", "Najprostszy programator LPT", 0));
        KANDA_help->setText(QApplication::translate("MainWindow", "Standard KANDA - Bez Problemu", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Pomoc", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
