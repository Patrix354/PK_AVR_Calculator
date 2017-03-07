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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QCheckBox *CKDIV8;
    QGroupBox *groupBox_4;
    QRadioButton *OSC_2;
    QRadioButton *OSC_1;
    QRadioButton *OSC_3;
    QRadioButton *OSC_4;
    QGroupBox *groupBox_5;
    QCheckBox *CKOPT;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *EXT_OSC_1;
    QRadioButton *EXT_OSC_2;
    QRadioButton *EXT_OSC_3;
    QRadioButton *EXT_OSC_4;
    QWidget *tab_2;
    QGroupBox *groupBox;
    QLabel *ERR_Main_Label;
    QPushButton *Main_button;
    QComboBox *SCK_list;
    QComboBox *Prog_list;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QRadioButton *Read;
    QRadioButton *Save;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *Flash;
    QRadioButton *EEPROM;
    QRadioButton *Fuse_bits;
    QRadioButton *Lock_bits;
    QPushButton *Command_exec;
    QWidget *tab;
    QPushButton *LPT_Prog_Schem_Butt;
    QPushButton *KANDA_help;
    QPushButton *ATtiny_CON;
    QPushButton *UART_CALC;
    QComboBox *uC_list;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lfuse_lbl;
    QSpacerItem *horizontalSpacer;
    QLineEdit *hfuse_lbl;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *efuse_lbl;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(640, 419);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(10, 40, 601, 321));
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        CKDIV8 = new QCheckBox(tab_3);
        CKDIV8->setObjectName(QStringLiteral("CKDIV8"));
        CKDIV8->setGeometry(QRect(20, 20, 191, 19));
        groupBox_4 = new QGroupBox(tab_3);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 50, 151, 121));
        OSC_2 = new QRadioButton(groupBox_4);
        OSC_2->setObjectName(QStringLiteral("OSC_2"));
        OSC_2->setGeometry(QRect(13, 51, 131, 16));
        OSC_1 = new QRadioButton(groupBox_4);
        OSC_1->setObjectName(QStringLiteral("OSC_1"));
        OSC_1->setGeometry(QRect(13, 30, 131, 16));
        OSC_3 = new QRadioButton(groupBox_4);
        OSC_3->setObjectName(QStringLiteral("OSC_3"));
        OSC_3->setGeometry(QRect(13, 72, 131, 16));
        OSC_4 = new QRadioButton(groupBox_4);
        OSC_4->setObjectName(QStringLiteral("OSC_4"));
        OSC_4->setGeometry(QRect(13, 93, 131, 16));
        OSC_4->setCheckable(true);
        groupBox_5 = new QGroupBox(tab_3);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(320, 50, 261, 171));
        CKOPT = new QCheckBox(groupBox_5);
        CKOPT->setObjectName(QStringLiteral("CKOPT"));
        CKOPT->setGeometry(QRect(60, 140, 151, 19));
        layoutWidget = new QWidget(groupBox_5);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 22, 256, 96));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        EXT_OSC_1 = new QRadioButton(layoutWidget);
        EXT_OSC_1->setObjectName(QStringLiteral("EXT_OSC_1"));

        verticalLayout->addWidget(EXT_OSC_1);

        EXT_OSC_2 = new QRadioButton(layoutWidget);
        EXT_OSC_2->setObjectName(QStringLiteral("EXT_OSC_2"));

        verticalLayout->addWidget(EXT_OSC_2);

        EXT_OSC_3 = new QRadioButton(layoutWidget);
        EXT_OSC_3->setObjectName(QStringLiteral("EXT_OSC_3"));

        verticalLayout->addWidget(EXT_OSC_3);

        EXT_OSC_4 = new QRadioButton(layoutWidget);
        EXT_OSC_4->setObjectName(QStringLiteral("EXT_OSC_4"));

        verticalLayout->addWidget(EXT_OSC_4);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 50, 391, 61));
        groupBox->setStyleSheet(QStringLiteral("background-color:  #dcdbff;"));
        ERR_Main_Label = new QLabel(groupBox);
        ERR_Main_Label->setObjectName(QStringLiteral("ERR_Main_Label"));
        ERR_Main_Label->setGeometry(QRect(180, 20, 191, 20));
        ERR_Main_Label->setStyleSheet(QLatin1String("background-color:  #dcdbff;\n"
"color: blue;\n"
"font-weight: bold;"));
        Main_button = new QPushButton(groupBox);
        Main_button->setObjectName(QStringLiteral("Main_button"));
        Main_button->setGeometry(QRect(10, 20, 151, 21));
        Main_button->setAutoFillBackground(false);
        Main_button->setStyleSheet(QStringLiteral(""));
        SCK_list = new QComboBox(tab_2);
        SCK_list->setObjectName(QStringLiteral("SCK_list"));
        SCK_list->setEnabled(true);
        SCK_list->setGeometry(QRect(360, 10, 191, 22));
        SCK_list->setMaxVisibleItems(13);
        Prog_list = new QComboBox(tab_2);
        Prog_list->setObjectName(QStringLiteral("Prog_list"));
        Prog_list->setGeometry(QRect(10, 10, 141, 22));
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 120, 191, 51));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Read = new QRadioButton(groupBox_2);
        Read->setObjectName(QStringLiteral("Read"));
        Read->setEnabled(true);

        horizontalLayout->addWidget(Read);

        Save = new QRadioButton(groupBox_2);
        Save->setObjectName(QStringLiteral("Save"));
        Save->setEnabled(false);

        horizontalLayout->addWidget(Save);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(220, 120, 331, 51));
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        Flash = new QRadioButton(groupBox_3);
        Flash->setObjectName(QStringLiteral("Flash"));
        Flash->setEnabled(false);

        horizontalLayout_2->addWidget(Flash);

        EEPROM = new QRadioButton(groupBox_3);
        EEPROM->setObjectName(QStringLiteral("EEPROM"));
        EEPROM->setEnabled(false);

        horizontalLayout_2->addWidget(EEPROM);

        Fuse_bits = new QRadioButton(groupBox_3);
        Fuse_bits->setObjectName(QStringLiteral("Fuse_bits"));
        Fuse_bits->setEnabled(true);

        horizontalLayout_2->addWidget(Fuse_bits);

        Lock_bits = new QRadioButton(groupBox_3);
        Lock_bits->setObjectName(QStringLiteral("Lock_bits"));
        Lock_bits->setEnabled(false);

        horizontalLayout_2->addWidget(Lock_bits);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        Command_exec = new QPushButton(tab_2);
        Command_exec->setObjectName(QStringLiteral("Command_exec"));
        Command_exec->setEnabled(true);
        Command_exec->setGeometry(QRect(20, 190, 80, 21));
        tabWidget->addTab(tab_2, QString());
        groupBox_2->raise();
        groupBox_3->raise();
        groupBox->raise();
        SCK_list->raise();
        Prog_list->raise();
        Command_exec->raise();
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        LPT_Prog_Schem_Butt = new QPushButton(tab);
        LPT_Prog_Schem_Butt->setObjectName(QStringLiteral("LPT_Prog_Schem_Butt"));
        LPT_Prog_Schem_Butt->setGeometry(QRect(20, 30, 191, 21));
        KANDA_help = new QPushButton(tab);
        KANDA_help->setObjectName(QStringLiteral("KANDA_help"));
        KANDA_help->setGeometry(QRect(20, 50, 191, 21));
        ATtiny_CON = new QPushButton(tab);
        ATtiny_CON->setObjectName(QStringLiteral("ATtiny_CON"));
        ATtiny_CON->setGeometry(QRect(20, 70, 191, 21));
        UART_CALC = new QPushButton(tab);
        UART_CALC->setObjectName(QStringLiteral("UART_CALC"));
        UART_CALC->setGeometry(QRect(20, 90, 191, 21));
        tabWidget->addTab(tab, QString());
        uC_list = new QComboBox(centralWidget);
        uC_list->setObjectName(QStringLiteral("uC_list"));
        uC_list->setGeometry(QRect(10, 10, 131, 22));
        uC_list->setMaxVisibleItems(20);
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(490, 10, 121, 47));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_4->addWidget(label_2);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lfuse_lbl = new QLineEdit(layoutWidget1);
        lfuse_lbl->setObjectName(QStringLiteral("lfuse_lbl"));
        lfuse_lbl->setStyleSheet(QLatin1String("color: green;\n"
"font-weight: bold;"));
        lfuse_lbl->setReadOnly(true);

        horizontalLayout_3->addWidget(lfuse_lbl);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        hfuse_lbl = new QLineEdit(layoutWidget1);
        hfuse_lbl->setObjectName(QStringLiteral("hfuse_lbl"));
        hfuse_lbl->setStyleSheet(QLatin1String("color: green;\n"
"font-weight: bold;"));
        hfuse_lbl->setReadOnly(true);

        horizontalLayout_3->addWidget(hfuse_lbl);

        horizontalSpacer_2 = new QSpacerItem(38, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        efuse_lbl = new QLineEdit(layoutWidget1);
        efuse_lbl->setObjectName(QStringLiteral("efuse_lbl"));
        efuse_lbl->setStyleSheet(QLatin1String("color: green;\n"
"font-weight: bold;"));
        efuse_lbl->setReadOnly(true);

        horizontalLayout_3->addWidget(efuse_lbl);


        verticalLayout_2->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 640, 20));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "PK AVR Calculator     ver. Alpha", 0));
        CKDIV8->setText(QApplication::translate("MainWindow", "CKDIV8 - podzielnik zegara przez 8", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Wew. oscylator", 0));
        OSC_2->setText(QString());
        OSC_1->setText(QString());
        OSC_3->setText(QString());
        OSC_4->setText(QString());
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Zew. oscylatyor", 0));
        CKOPT->setText(QApplication::translate("MainWindow", "CKOPT - opcja oscylatora", 0));
        EXT_OSC_1->setText(QApplication::translate("MainWindow", "0.4 MHz - 0.9 MHz - Tylko rezonator ceramiczny", 0));
        EXT_OSC_2->setText(QApplication::translate("MainWindow", "0.9 MHz - 3.0 MHz", 0));
        EXT_OSC_3->setText(QApplication::translate("MainWindow", "3.0 MHz - 8.0 MHz", 0));
        EXT_OSC_4->setText(QApplication::translate("MainWindow", "> 8.0 MHz", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Fusy uproszczone", 0));
        groupBox->setTitle(QString());
        ERR_Main_Label->setText(QString());
        Main_button->setText(QApplication::translate("MainWindow", "Sprawd\305\272 pod\305\202\304\205czony AVR", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Operacja", 0));
        Read->setText(QApplication::translate("MainWindow", "Odczyt", 0));
        Save->setText(QApplication::translate("MainWindow", "Zapis", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Rodzaj pami\304\231ci", 0));
        Flash->setText(QApplication::translate("MainWindow", "Flash", 0));
        EEPROM->setText(QApplication::translate("MainWindow", "EEPROM", 0));
        Fuse_bits->setText(QApplication::translate("MainWindow", "Fuse bity", 0));
        Lock_bits->setText(QApplication::translate("MainWindow", "Lock bity", 0));
        Command_exec->setText(QApplication::translate("MainWindow", "Wykonaj", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Programator AVR", 0));
        LPT_Prog_Schem_Butt->setText(QApplication::translate("MainWindow", "Najprostszy programator LPT", 0));
        KANDA_help->setText(QApplication::translate("MainWindow", "Standard KANDA -  Bez Problemu", 0));
        ATtiny_CON->setText(QApplication::translate("MainWindow", "Pod\305\202\304\205czenie ISP ATtiny 4/5/9/10", 0));
        UART_CALC->setText(QApplication::translate("MainWindow", "UART/USART Calculator", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Pomoc", 0));
        label->setText(QApplication::translate("MainWindow", "lfuse", 0));
        label_2->setText(QApplication::translate("MainWindow", "hfuse", 0));
        label_3->setText(QApplication::translate("MainWindow", "efuse", 0));
        lfuse_lbl->setText(QString());
        hfuse_lbl->setText(QString());
        efuse_lbl->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
