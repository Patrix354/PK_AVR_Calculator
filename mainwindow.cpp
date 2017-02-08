#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QMessageBox>
#include <QProcess>
#include <QRadioButton>
#include <QCheckBox>
#include <QLabel>
#include <QApplication>
#include <QDebug>

#include <fstream>
#include <string>
#include <cstdlib>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    file_flag = true;

    QString uc_codes[uC_AMOUNT] =
    {
        "usb82", "usb162", "usb1287", "usb1286", "usb647","usb676",
        "pwm3b", "pwm3", "pwm2b", "pwm2", "c32", "c64", "c128", "8535", "8515", "4434", "4433", "2343",
        "2333", "2313", "4414", "1200", "m640", "m1280", "m1281", "m1284p", "m2560", "m2561", "m8",
        "m48", "m88", "m168", "m328p", "m161", "m8535", "m8515", "m6490", "m164p", "m324p", "m644",
        "m644p", "m16", "m32", "m32u4", "m64", "m128", "m325", "m3250", "m645", "m6450",
        "m103", "m163", "m162", "m169", "m329", "m329p", "m649", "m3290", "m3290p", "t84", "t44",
        "t24", "t85", "t45", "t25", "t88", "t2313", "t861", "t461", "t261", "t26", "t15", "t13", "t12", "t11"
    };

    QString uc_names[uC_AMOUNT] =
    {
        "AT90USB82", "AT90USB162", "AT90USB1287", "AT90USB1286", "AT90USB647", "AT90USB676", "AT90PWM3B",
        "AT90PWM3", "AT90PWM2B", "AT90PWM2", "AT90CAN32", "AT90CAN64", "AT90CAN128", "AT90S8535", "AT90S8515",
        "AT90S4434", "AT90S4433", "AT90S2343", "AT90S2333", "AT90S2313", "AT90S4414", "AT90S1200", "ATmega640",
        "ATmega1280", "ATmega1281", "ATmega1284p", "ATmega2560", "ATmega2561", "ATmega8", "ATmega48", "ATmega88",
        "ATmega168", "ATmega328p", "ATmega161", "ATmega8535", "ATmega8515", "ATmega6490", "ATmega164p", "ATmega324p",
        "ATmega644", "ATmega644p", "ATmega16", "ATmega32", "ATmega32u4", "ATmega64", "ATmega128",
        "ATmega325", "ATmega3250", "ATmega645", "ATmega6450", "ATmega103", "ATmega163", "ATmega162", "ATmega169",
        "ATmega329", "ATmega329p", "ATmega649", "ATmega3290", "ATmega3290p", "ATtiny84", "ATtiny44", "ATtiny24",
        "ATtiny85", "ATtiny45", "ATtiny25", "ATtiny88", "ATtiny2313", "ATtiny861", "ATtiny461", "ATtiny261", "ATtiny26",
        "ATtiny15", "ATtiny13", "ATtiny12", "ATtiny11"
    };

    QString prog_names[PROG_AMOUNT] =
    {
        "USBasp", "USBtiny", "AVRisp"
    };

    QString prog_codes[PROG_AMOUNT] =
    {
        "usbasp", "usbtiny", "avrisp"
    };

    QString sck_names[SCK_AMOUNT] =
    {
        "None", "0.5 - 1.0 -> 1.5 MHz", "1.0 - 2.0 -> 750 kHz", "2.0 - 4.0 -> 375 kHz", "4.0 - 8.0 -> 187.5 kHz",
        "8.0 - 20.96 -> 93.75 kHz", "20.96 - 46.88 -> 32 kHz", "46.88 - 93.75 -> 16 kHz", "93.75 - 187.5 -> 8 kHz",
        "187.5 - 375.0 -> 4 kHz", "375.0 - 750.0 -> 2 kHz", "750.0 - 1500.0 -> 1 kHz", "More than 1500 -> 500 Hz "
    };

    QString sck_codes[SCK_AMOUNT] =
    {
        "", "1", "2", "4", "8", "20", "46", "93", "187", "375", "750", "1500", "2000"
    };

    QString sck_special[SCK_SPECIALS] =
    {
        "USBasp", "USBtiny"
    };

    QString err_names[ERR_AMOUNT]
    {
        "avrdude: AVR device initialized", "avrdude: error: programm enable"
    };

    for(int i = 0; i < uC_AMOUNT; i++)
    {
        ui->uC_list->addItem(uc_names[i]);
        uC_names[i] = uc_names[i];
        uC_codes[i] = "-p" + uc_codes[i];
    }

    for(int i = 0; i < PROG_AMOUNT; i++)
    {
        ui->Prog_list->addItem(prog_names[i]);
        Prog_names[i] = prog_names[i];
        Prog_codes[i] = "-c" + prog_codes[i];
    }

    for(int i = 0; i < SCK_AMOUNT; i++)
    {
        ui->SCK_list->addItem(sck_names[i]);
        SCK_names[i] = sck_names[i];
        if(i != 0)
        {
            SCK_codes[i] = "-B" + sck_codes[i];
        }
    }

    for(int i = 0; i < SCK_SPECIALS; i++)
    {
        SCK_special[i] = sck_special[i];
    }

    for(int i = 0; i < ERR_AMOUNT; i++)
    {
        ERR_names[i] = err_names[i];
    }

    Clear_fuses();
    Set_ui_fuses(ui->uC_list->currentText());
}

MainWindow::~MainWindow()
{
    delete ui;
}

//
//  Slots
//

void MainWindow::on_uC_list_activated(const QString &arg1)
{
    Set_ui_fuses(arg1);
}

void MainWindow::on_Prog_list_activated(const QString &arg1)
{
    for(int i = 0; i <= SCK_SPECIALS; i++)
    {
        if(arg1 == SCK_special[i])
        {
           ui->SCK_list->setVisible(true);
           break;
        }
        else
        {
            ui->SCK_list->setVisible(false);
        }
    }

    Set_ui_fuses(ui->uC_list->currentText());
}

void MainWindow::on_Main_button_clicked()
{
    QString exec = "avrdude";
    QStringList params;

    ui->ERR_Main_Label->clear();
    ui->ERR_Main_Label->update();                   // This is "Bandaid solution" ;)
    QApplication::instance()->processEvents();      // http://stackoverflow.com/questions/27884662/cant-change-qlabel-text-twice-in-a-slot

    params << uC_codes[ui->uC_list->currentIndex()] << Prog_codes[ui->Prog_list->currentIndex()] << SCK_codes[ui->SCK_list->currentIndex()];

    Safe_to_file(exec, params, FILE_PATH, 1);

    if(Search_uC(FILE_PATH) >= 7)
    {
        ui->ERR_Main_Label->setText(AVRDUDE_ERR);
        return;
    }

    switch(Search_ERR(FILE_PATH))
    {
        case -1:    ui->ERR_Main_Label->setText(AVRDUDE_ERR);       break;
        case 0:     ui->ERR_Main_Label->setText(OK);                break;
        case 1:     ui->ERR_Main_Label->setText(AVRDUDE_ERR);       break;
        default:    ui->ERR_Main_Label->setText(AVRDUDE_ERR);       break;
    }
}

void MainWindow::on_Command_exec_clicked()
{
    if(ui->Fuse_bits->isChecked())
    {
        if(ui->Read->isChecked())
        {
            QObject parent;
            QString exec = "avrdude";
            QStringList params;
            QStringList lfuse_params;
            QStringList hfuse_params;
            QStringList efuse_params;

            lfuse_params << uC_codes[ui->uC_list->currentIndex()] << Prog_codes[ui->Prog_list->currentIndex()] << SCK_codes[ui->SCK_list->currentIndex()] << "-Ulfuse:r:-:h";
            hfuse_params << uC_codes[ui->uC_list->currentIndex()] << Prog_codes[ui->Prog_list->currentIndex()] << SCK_codes[ui->SCK_list->currentIndex()] << "-Uhfuse:r:-:h";
            efuse_params << uC_codes[ui->uC_list->currentIndex()] << Prog_codes[ui->Prog_list->currentIndex()] << SCK_codes[ui->SCK_list->currentIndex()] << "-Uefuse:r:-:h";

            params << uC_codes[ui->uC_list->currentIndex()] << Prog_codes[ui->Prog_list->currentIndex()] << SCK_codes[ui->SCK_list->currentIndex()];

            Safe_to_file(exec, params, FILE_PATH, 1);

            if(Search_uC(FILE_PATH) >= 7)
            {
                QMessageBox::critical(this, "AVRDUDE_ERR", AVRDUDE_ERR);
                return;
            }

            switch(Search_ERR(FILE_PATH))
            {
                case 0:
                {
                    ;
                    break;
                }
                case 1:
                case 2:
                default:
                {
                    ui->ERR_Main_Label->setText(AVRDUDE_ERR);
                    return;
                    break;
                }
            }

            Safe_to_file(exec, lfuse_params, FILE_PATH, 0);
            lfuse_Qstr = Search_fuse(FILE_PATH);
            Safe_to_file(exec, hfuse_params, FILE_PATH, 0);
            hfuse_Qstr = Search_fuse(FILE_PATH);
            Safe_to_file(exec, efuse_params, FILE_PATH, 0);
            efuse_Qstr = Search_fuse(FILE_PATH);

            ui->lfuse_lbl->setText(lfuse_Qstr);
            ui->hfuse_lbl->setText(hfuse_Qstr);
            ui->efuse_lbl->setText(efuse_Qstr);
        }
    }
}

void MainWindow::on_LPT_Prog_Schem_Butt_clicked()
{
    Prog_Dialog = new LPT_Schematic(this);
    Prog_Dialog->show();
}

void MainWindow::on_KANDA_help_clicked()
{
    KANDA_Dialog = new KANDA_Schematic(this);
    KANDA_Dialog->show();
}

void MainWindow::on_ATtiny_CON_clicked()
{
    ATtiny_CON_Dialog = new ATtiny_CON_Schematic(this);
    ATtiny_CON_Dialog->show();
}

void MainWindow::on_UART_CALC_clicked()
{
    UART_Calculator = new UBRR_Calculator(this);
    UART_Calculator->show();
}

void MainWindow::on_EXT_OSC_1_clicked()
{
    Check(ui->OSC_1, false);
    Check(ui->OSC_2, false);
    Check(ui->OSC_3, false);
    Check(ui->OSC_4, false);
}

void MainWindow::on_EXT_OSC_2_clicked()
{
    Check(ui->OSC_1, false);
    Check(ui->OSC_2, false);
    Check(ui->OSC_3, false);
    Check(ui->OSC_4, false);
}

void MainWindow::on_EXT_OSC_3_clicked()
{
    Check(ui->OSC_1, false);
    Check(ui->OSC_2, false);
    Check(ui->OSC_3, false);
    Check(ui->OSC_4, false);
}

void MainWindow::on_EXT_OSC_4_clicked()
{
    Check(ui->OSC_1, false);
    Check(ui->OSC_2, false);
    Check(ui->OSC_3, false);
    Check(ui->OSC_4, false);
}

void MainWindow::on_CKOPT_clicked()
{
    Check(ui->OSC_1, false);
    Check(ui->OSC_2, false);
    Check(ui->OSC_3, false);
    Check(ui->OSC_4, false);
}

void MainWindow::on_OSC_1_clicked()
{
    Check(ui->EXT_OSC_1, false);
    Check(ui->EXT_OSC_2, false);
    Check(ui->EXT_OSC_3, false);
    Check(ui->EXT_OSC_4, false);
    Check(ui->CKOPT, false);
}

void MainWindow::on_OSC_2_clicked()
{
    Check(ui->EXT_OSC_1, false);
    Check(ui->EXT_OSC_2, false);
    Check(ui->EXT_OSC_3, false);
    Check(ui->EXT_OSC_4, false);
    Check(ui->CKOPT, false);
}

void MainWindow::on_OSC_3_clicked()
{
    Check(ui->EXT_OSC_1, false);
    Check(ui->EXT_OSC_2, false);
    Check(ui->EXT_OSC_3, false);
    Check(ui->EXT_OSC_4, false);
    Check(ui->CKOPT, false);
}

void MainWindow::on_OSC_4_clicked()
{
    Check(ui->EXT_OSC_1, false);
    Check(ui->EXT_OSC_2, false);
    Check(ui->EXT_OSC_3, false);
    Check(ui->EXT_OSC_4, false);
    Check(ui->CKOPT, false);
}

//
//  Other Methods
//

int MainWindow::Search_in_array(QString search, QString* tab, int len)
{
    for(int i = 0; i < len; i++)
    {
        if(search == tab[i])
        {
            return i;
        }
    }

    return -1;
}

int MainWindow::Search_ERR(string path_to_file)
{
    std::fstream file;
    std::string line;

    file.open(path_to_file.c_str(), ios::in);

    if(file.good() == false)
    {
        if(file_flag == false)
        {
            file_flag = true;
            QMessageBox::critical(this, "LOG ERR", "Can't open log file");
        }
        return 2;
    }

    while(getline(file, line))
    {
        if(line.length() <= 2)
        {
            continue;
        }
        else
        {
            for(int i = 0; i < ERR_AMOUNT; i++)
            {
                if(line.substr(0,31) == ERR_names[0].toLocal8Bit().constData())
                {
                    return i;
                }
            }
        }
    }
    file.close();
    file.clear();
    return -1;
}

int MainWindow::Search_uC(string path_to_file)
{
    std::fstream file;
    std::string line;
    int line_num = 1;

    file.open(path_to_file.c_str(), ios::in);

    if(file.good() == false)
    {
        if(file_flag == false)
        {
            file_flag = true;
        }
        return -1;
    }

    while(getline(file, line))
    {
        if(line.length() > 5)
        {
            line_num++;
        }

    }
    file.close();
    file.clear();
    return line_num;
}

QString MainWindow::Search_fuse(string path_to_file)
{
    std::string line;
    std::fstream file;

    file.open(path_to_file.c_str(), ios::in);

    if(file.good() == false)
    {
        if(file_flag == false)
        {
            file_flag = true;
            QMessageBox::critical(this, "LOG ERR", "Can't open log file");
        }
        return "ERR";
    }
    getline(file, line);
    return QString::fromStdString(line);
}

void MainWindow::Safe_to_file(QString exec, QStringList params, string path_to_file, int mode)
{
    QObject parent;
    QProcess* AVRProcess;
    QString output;
    std::fstream file;

    AVRProcess = new QProcess(&parent);
    AVRProcess->start(exec, params);
    AVRProcess->waitForFinished();
    if(mode == 1)
    {
        output = AVRProcess->readAllStandardError();
    }
    else if(mode == 0)
    {
        output = AVRProcess->readAllStandardOutput();
    }
    AVRProcess->close();

    file.open(path_to_file.c_str(), ios::out);
    file << output.toLocal8Bit().constData();
    file.close();
    file.clear();
}

void MainWindow::Check(QRadioButton* button, bool pos)
{
    button->setAutoExclusive(false);
    button->setChecked(pos);
    button->setAutoExclusive(true);
}

void MainWindow::Check(QCheckBox* button, bool pos)
{
    button->setAutoExclusive(false);
    button->setChecked(pos);
    button->setAutoExclusive(true);
}

void MainWindow::Set_ui_fuses(const QString &arg)
{
    switch(Search_in_array(ui->uC_list->currentText(), uC_names, uC_AMOUNT))
    {
        case AT90USB82:
        case AT90USB162:
        case AT90USB1287:
        case AT90USB1286:
        case AT90USB647:
        case AT90USB676:
        case AT90PWM3B:
        case AT90PWM3:
        case AT90PWM2B:
        case AT90PWM2:
        case AT90CAN32:
        case AT90CAN64:
        case AT90CAN128:
        case ATmega32u4:
        case ATmega640:
        case ATmega1280:
        case ATmega1281:
        case ATmega1284p:
        case ATmega2560:
        case ATmega2561:
        case ATmega6490:
        case ATmega164p:
        case ATmega324p:
        case ATmega644:
        case ATmega644p:
        case ATmega3250:
        case ATmega325:
        case ATmega645:
        case ATmega6450:
        case ATmega169:
        case ATmega162:
        case ATmega329:
        case ATmega329p:
        case ATmega649:
        case ATmega3290:
        case ATmega3290p:
        case ATtiny84:
        case ATtiny44:
        case ATtiny24:
        case ATtiny861:
        case ATtiny461:
        case ATtiny261:
        {
            Clear_fuses();
            ui->CKDIV8->setVisible(true);

            ui->OSC_1->setVisible(true);
            ui->OSC_1->setText("8 MHz");
            Set_EXT_fuses(true);
            break;
        }
        case AT90S8535:
        case AT90S8515:
        case AT90S4434:
        case AT90S4433:
        case AT90S2343:
        case AT90S2333:
        case AT90S2313:
        case AT90S4414:
        case AT90S1200:
        case ATmega161:
        case ATmega163:
        case ATmega103:
        case ATtiny11:
        case ATtiny12:
        case ATtiny15:
        {
            Clear_fuses();
            break;
        }
        case ATtiny26:
        {
            Clear_fuses();
            ui->CKDIV8->setVisible(true);

            ui->OSC_1->setVisible(true);
            ui->OSC_2->setVisible(true);
            ui->OSC_3->setVisible(true);
            ui->OSC_4->setVisible(true);

            ui->OSC_1->setText("1 MHz");
            ui->OSC_2->setText("2 MHz");
            ui->OSC_3->setText("4 MHz");
            ui->OSC_4->setText("8 MHz");
            Set_EXT_fuses(true);
            break;
        }
        case ATmega8:
        case ATmega16:
        case ATmega32:
        case ATmega64:
        case ATmega128:
        case ATmega8535:
        case ATmega8515:
        {
            Clear_fuses();
            ui->CKDIV8->setVisible(true);
            ui->CKOPT->setVisible(true);

            ui->OSC_1->setVisible(true);
            ui->OSC_2->setVisible(true);
            ui->OSC_3->setVisible(true);
            ui->OSC_4->setVisible(true);

            ui->OSC_1->setText("1 MHz");
            ui->OSC_2->setText("2 MHz");
            ui->OSC_3->setText("4 MHz");
            ui->OSC_4->setText("8 MHz");
            Set_EXT_fuses(true);
            break;
        }
        case ATmega48:
        case ATmega88:
        case ATmega168:
        case ATmega328p:
        case ATtiny88:
        {
            Clear_fuses();
            ui->CKDIV8->setVisible(true);

            ui->OSC_1->setVisible(true);
            ui->OSC_2->setVisible(true);

            ui->OSC_1->setText("128 kHz");
            ui->OSC_2->setText("8 MHz");
            Set_EXT_fuses(true);
            break;
        }
        case ATtiny13:
        {
            Clear_fuses();
            ui->CKDIV8->setVisible(true);

            ui->OSC_1->setVisible(true);
            ui->OSC_2->setVisible(true);
            ui->OSC_3->setVisible(true);

            ui->OSC_1->setText("128 kHz");
            ui->OSC_2->setText("4.8 MHz");
            ui->OSC_3->setText("9.6 MHz");
            Set_EXT_fuses(true);
            break;
        }
        case ATtiny2313:
        {
            Clear_fuses();
            ui->CKDIV8->setVisible(true);

            ui->OSC_1->setVisible(true);
            ui->OSC_2->setVisible(true);
            ui->OSC_3->setVisible(true);

            ui->OSC_1->setText("128 kHz");
            ui->OSC_2->setText("4 MHz");
            ui->OSC_3->setText("8 MHz");
            Set_EXT_fuses(true);
            break;
        }
        case ATtiny25:
        case ATtiny45:
        case ATtiny85:
        {
            Clear_fuses();
            ui->CKDIV8->setVisible(true);

            ui->OSC_1->setVisible(true);
            ui->OSC_2->setVisible(true);

            ui->OSC_1->setText("6.4 MHz");
            ui->OSC_2->setText("8 MHz");

            Set_EXT_fuses(true);
            break;
        }
    }
}

void MainWindow::Clear_fuses()
{
    Check(ui->OSC_1, false);
    Check(ui->OSC_2, false);
    Check(ui->OSC_3, false);
    Check(ui->OSC_4, false);
    Check(ui->CKDIV8, false);
    Check(ui->CKOPT, false);
    Check(ui->EXT_OSC_1, false);
    Check(ui->EXT_OSC_2, false);
    Check(ui->EXT_OSC_3, false);
    Check(ui->EXT_OSC_4, false);

    ui->OSC_1->setText("");
    ui->OSC_2->setText("");
    ui->OSC_3->setText("");
    ui->OSC_4->setText("");

    ui->OSC_1->setVisible(false);
    ui->OSC_2->setVisible(false);
    ui->OSC_3->setVisible(false);
    ui->OSC_4->setVisible(false);
    ui->CKDIV8->setVisible(false);
    ui->CKOPT->setVisible(false);
    Set_EXT_fuses(false);

}

void MainWindow::Set_EXT_fuses(bool pos)
{
    ui->EXT_OSC_1->setVisible(pos);
    ui->EXT_OSC_2->setVisible(pos);
    ui->EXT_OSC_3->setVisible(pos);
    ui->EXT_OSC_4->setVisible(pos);
}
