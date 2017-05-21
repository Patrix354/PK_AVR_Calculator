#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QProcess>
#include <QRadioButton>
#include <QCheckBox>
#include <QLabel>
#include <QApplication>
#include <QFileDialog>

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    std::fstream file;
    std::string avrdude;

    QString uc_codes[uC_AMOUNT] =
    {
        "usb82", "usb162", "usb1287", "usb1286", "usb647","usb646",
        "pwm3b", "pwm3", "pwm2b", "pwm2", "c32", "c64", "c128", "8535", "8515", "4434", "4433", "2343",
        "2333", "2313", "4414", "1200", "m640", "m1280", "m1281", "m1284p", "m2560", "m2561", "m8",
        "m48", "m88", "m168", "m328p", "m161", "m8535", "m8515", "m6490", "m164p", "m324p", "m644",
        "m644p", "m16", "m32", "m32u4", "m64", "m128", "m325", "m3250", "m645", "m6450",
        "m103", "m163", "m162", "m169", "m329", "m329p", "m649", "m3290", "m3290p", "t84", "t44",
        "t24", "t85", "t45", "t25", "t88", "t2313", "t861", "t461", "t261", "t26", "t15", "t13", "t12", "t11"
    };

    QString uc_names[uC_AMOUNT] =
    {
        "AT90USB82", "AT90USB162", "AT90USB1287", "AT90USB1286", "AT90USB647", "AT90USB646", "AT90PWM3B",
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
        "USBasp", "USBtiny"
    };

    QString prog_codes[PROG_AMOUNT] =
    {
        "usbasp", "usbtiny"
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

    file.open(PATH_FILE, ios::in);
    if(file.good())
    {
        getline(file, avrdude);
        ui->AVRDUDE_path->setText(QString::fromStdString(avrdude));
        AVRDUDE = QString::fromStdString(avrdude);
    }
    file.close();
    file.clear();

    Clear_fuses(false);
    Set_ui_fuses();
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
    Set_ui_fuses();
}

void MainWindow::on_Prog_list_activated(const QString &arg1)
{
    if(arg1 == "USBtiny" || arg1 == "USBasp")
    {
        ui->SCK_list->setVisible(true);
    }
    else
    {
        ui->SCK_list->setVisible(false);
    }

    Set_ui_fuses();
}

void MainWindow::on_Main_button_clicked()
{
    QString exec = AVRDUDE;
    QStringList params;

    ui->ERR_Main_Label->clear();
    ui->ERR_Main_Label->update();                   // This is "Bandaid solution" ;)
    QApplication::instance()->processEvents();      // http://stackoverflow.com/questions/27884662/cant-change-qlabel-text-twice-in-a-slot

    params << uC_codes[ui->uC_list->currentIndex()] << Prog_codes[ui->Prog_list->currentIndex()] << SCK_codes[ui->SCK_list->currentIndex()];
    Safe_output_to_file(exec, params, OUTPUT_FILE, 1);

    params << "-Usignature:r:-:h";
    Safe_output_to_file(exec, params, SIGNATURE_FILE, 0);

    if(Search_ERR(SIGNATURE_FILE) == true)
    {
        ui->ERR_Main_Label->setText(OK);
    }
    else
    {
        ui->ERR_Main_Label->setText(AVRDUDE_ERR);
        Print_ERR(OUTPUT_FILE);
    }
}

void MainWindow::on_Command_exec_clicked()
{
    QObject parent;
    QString exec = AVRDUDE;
    QStringList params;

    params << uC_codes[ui->uC_list->currentIndex()] << Prog_codes[ui->Prog_list->currentIndex()] << SCK_codes[ui->SCK_list->currentIndex()];
    Safe_output_to_file(exec, params, OUTPUT_FILE, 1);

    params << "-Usignature:r:-:h";
    Safe_output_to_file(exec, params, SIGNATURE_FILE, 0);

    if(Search_ERR(SIGNATURE_FILE) == false)
    {
          ui->ERR_Main_Label->setText(AVRDUDE_ERR);
          Print_ERR(OUTPUT_FILE);
          ui->lock_lbl->clear();
          return;
    }
    else
    {
          ui->ERR_Main_Label->setText(OK);
    }

    if(ui->Fuse_bits->isChecked())
    {
        if(ui->Read->isChecked())
        {
            QString lfuse_Qstr;
            QString hfuse_Qstr;
            QString efuse_Qstr;
            QStringList lfuse_params;
            QStringList hfuse_params;
            QStringList efuse_params;

            lfuse_params << uC_codes[ui->uC_list->currentIndex()] << Prog_codes[ui->Prog_list->currentIndex()] << SCK_codes[ui->SCK_list->currentIndex()] << "-Ulfuse:r:-:h";
            hfuse_params << uC_codes[ui->uC_list->currentIndex()] << Prog_codes[ui->Prog_list->currentIndex()] << SCK_codes[ui->SCK_list->currentIndex()] << "-Uhfuse:r:-:h";
            efuse_params << uC_codes[ui->uC_list->currentIndex()] << Prog_codes[ui->Prog_list->currentIndex()] << SCK_codes[ui->SCK_list->currentIndex()] << "-Uefuse:r:-:h";

            Safe_output_to_file(exec, lfuse_params, OUTPUT_FILE, 0);
            lfuse_Qstr = Search_fuse(OUTPUT_FILE);
            lfuse_Qstr.remove(0, 2);
            lfuse_Qstr = lfuse_Qstr.toUpper();

            Safe_output_to_file(exec, hfuse_params, OUTPUT_FILE, 0);
            hfuse_Qstr = Search_fuse(OUTPUT_FILE);
            hfuse_Qstr.remove(0, 2);
            hfuse_Qstr = hfuse_Qstr.toUpper();

            Safe_output_to_file(exec, efuse_params, OUTPUT_FILE, 0);
            efuse_Qstr = Search_fuse(OUTPUT_FILE);
            efuse_Qstr.remove(0, 2);
            efuse_Qstr = efuse_Qstr.toUpper();

            ui->lfuse_lbl->setText(lfuse_Qstr);
            ui->hfuse_lbl->setText(hfuse_Qstr);
            ui->efuse_lbl->setText(efuse_Qstr);
            ui->ERR_Main_Label->setText(OK);

            lfuse = lfuse_Qstr.toInt(nullptr, 16);
            hfuse = hfuse_Qstr.toInt(nullptr, 16);
            efuse = efuse_Qstr.toInt(nullptr, 16);

            Count_ui_fuses(lfuse, hfuse);
        }
    }
    else if(ui->Lock_bits->isChecked())
    {
        if(ui->Read->isChecked())
        {
            QString lock_Qstr;
            QStringList lock_params;

            lock_params << uC_codes[ui->uC_list->currentIndex()] << Prog_codes[ui->Prog_list->currentIndex()] << SCK_codes[ui->SCK_list->currentIndex()] << "-Ulock:r:-:h";

            Safe_output_to_file(exec, lock_params, OUTPUT_FILE, 0);
            lock_Qstr = Search_fuse(OUTPUT_FILE);
            lock_Qstr.remove(0, 2);
            lock_Qstr = lock_Qstr.toUpper();

            ui->lock_lbl->setText(lock_Qstr);
            ui->ERR_Main_Label->setText(OK);

            lock = lock_Qstr.toInt(nullptr, 16);
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
    Clear_int_osc_fuses();
}

void MainWindow::on_EXT_OSC_2_clicked()
{
    Clear_int_osc_fuses();
}

void MainWindow::on_EXT_OSC_3_clicked()
{
    Clear_int_osc_fuses();
}

void MainWindow::on_EXT_OSC_4_clicked()
{
    Clear_int_osc_fuses();
}

void MainWindow::on_CKOPT_clicked()
{
    Clear_int_osc_fuses();
}

void MainWindow::on_OSC_1_clicked()
{
    Clear_ext_osc_fuses();
    Check(ui->CKOPT, false);
}

void MainWindow::on_OSC_2_clicked()
{
    Clear_ext_osc_fuses();
    Check(ui->CKOPT, false);
}

void MainWindow::on_OSC_3_clicked()
{
    Clear_ext_osc_fuses();
    Check(ui->CKOPT, false);
}

void MainWindow::on_OSC_4_clicked()
{
    Clear_ext_osc_fuses();
    Check(ui->CKOPT, false);
}

void MainWindow::on_Set_AVRDUDE_path_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Otwórz plik AVRDUDE.exe"), "C://", tr("Executable files (*.exe)"));
    std::string avrdude;
    std::fstream file;

    ui->AVRDUDE_path->setText(fileName);
    file.open(PATH_FILE, ios::out);
    file << fileName.toLocal8Bit().constData();
    file.close();
    file.clear();

    file.open(PATH_FILE, ios::in);
    if(file.good())
    {
        getline(file, avrdude);
        ui->AVRDUDE_path->setText(QString::fromStdString(avrdude));
        AVRDUDE = QString::fromStdString(avrdude);
    }
    file.close();
    file.clear();
}

//
//  Other Methods
//

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

void MainWindow::Clear_fuses(bool visible)
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

    ui->CKDIV8->setVisible(visible);
    ui->CKOPT->setVisible(visible);
    Set_enabled_INT_fuses(visible);
    Set_enabled_EXT_fuses(visible);

}

void MainWindow::Set_enabled_EXT_fuses(bool visible)
{
    ui->EXT_OSC_1->setVisible(visible);
    ui->EXT_OSC_2->setVisible(visible);
    ui->EXT_OSC_3->setVisible(visible);
    ui->EXT_OSC_4->setVisible(visible);
}

void MainWindow::Set_enabled_INT_fuses(bool visible)
{
    ui->OSC_1->setVisible(visible);
    ui->OSC_2->setVisible(visible);
    ui->OSC_3->setVisible(visible);
    ui->OSC_4->setVisible(visible);
}

void MainWindow::Clear_int_osc_fuses()
{
    Check(ui->OSC_1, false);
    Check(ui->OSC_2, false);
    Check(ui->OSC_3, false);
    Check(ui->OSC_4, false);
}

void MainWindow::Clear_ext_osc_fuses()
{
    Check(ui->EXT_OSC_1, false);
    Check(ui->EXT_OSC_2, false);
    Check(ui->EXT_OSC_3, false);
    Check(ui->EXT_OSC_4, false);
}


bool MainWindow::Search_ERR(string path_to_file)
{
    std::fstream file;
    std::string line;

    file.open(path_to_file.c_str(), ios::in);

    getline(file, line);
    if(line.length() == 0)
    {
        return false;
    }

    file.close();
    file.clear();
    return true;
}

QString MainWindow::Search_fuse(string path_to_file)
{
    std::string line;
    std::fstream file;

    file.open(path_to_file.c_str(), ios::in);

    getline(file, line);
    return QString::fromStdString(line);
}

void MainWindow::Safe_output_to_file(QString exec, QStringList params, string path_to_file, int mode)
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
        output = QString::fromLatin1(AVRProcess->readAllStandardError());
    }
    else if(mode == 0)
    {
        output = QString::fromLatin1(AVRProcess->readAllStandardOutput());
    }

    AVRProcess->close();

    file.open(path_to_file.c_str(), ios::out);
    file << output.toLocal8Bit().constData();
    file.close();
    file.clear();

    delete AVRProcess;
}

void MainWindow::Print_ERR(string path_to_file)
{
    std::string line;
    std::fstream file;

    system("cls");
    file.open(path_to_file.c_str(), ios::in);

    while(getline(file, line))
    {
        cerr << line << endl;
    }

    file.close();
    file.clear();
}

void MainWindow::Set_ui_fuses()
{
    //uC's without CKSEL fusebits: AT90S8535 AT90S8515 AT90S4434 AT90S4433 AT90S2343 AT90S2333 AT90S2313
    //                             AT90S4414 AT90S1200 ATmega161 ATmega163 ATmega103 ATtiny11 ATtiny12 ATtiny15

    Clear_fuses(false);

    switch(ui->uC_list->currentIndex())
    {
        case AT90USB82:
        case AT90USB162:
        case AT90USB1287:
        case AT90USB1286:
        case AT90USB647:
        case AT90USB646:
        case AT90PWM3B:
        case AT90PWM3:
        case AT90PWM2B:
        case AT90PWM2:
        case AT90CAN32:
        case AT90CAN64:
        case AT90CAN128:
        case ATmega32u4:
        case ATmega1284p:
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
            ui->CKDIV8->setVisible(true);

            ui->OSC_1->setVisible(true);
            ui->OSC_1->setText("8 MHz");
            Set_enabled_EXT_fuses(true);
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
            Clear_fuses(false);

            ui->CKOPT->setVisible(true);

            ui->OSC_1->setVisible(true);
            ui->OSC_2->setVisible(true);
            ui->OSC_3->setVisible(true);
            ui->OSC_4->setVisible(true);

            ui->OSC_1->setText("1 MHz");
            ui->OSC_2->setText("2 MHz");
            ui->OSC_3->setText("4 MHz");
            ui->OSC_4->setText("8 MHz");
            Set_enabled_EXT_fuses(true);

            ui->EXT_OSC_4->setVisible(false);
            break;
        }
        case ATmega640:
        case ATmega1280:
        case ATmega1281:
        case ATmega2560:
        case ATmega2561:
        case ATmega48:
        case ATmega88:
        case ATmega168:
        case ATmega328p:
        case ATtiny88:
        {
            Clear_fuses(false);
            ui->CKDIV8->setVisible(true);

            ui->OSC_1->setVisible(true);
            ui->OSC_2->setVisible(true);

            ui->OSC_1->setText("128 kHz");
            ui->OSC_2->setText("8 MHz");
            Set_enabled_EXT_fuses(true);
            break;
        }
        case ATtiny13:
        {
            ui->CKDIV8->setVisible(true);

            ui->OSC_1->setVisible(true);
            ui->OSC_2->setVisible(true);
            ui->OSC_3->setVisible(true);

            ui->OSC_1->setText("128 kHz");
            ui->OSC_2->setText("4.8 MHz");
            ui->OSC_3->setText("9.6 MHz");
            Set_enabled_EXT_fuses(false);
            break;
        }
        case ATtiny2313:
        {
            Clear_fuses(false);
            ui->CKDIV8->setVisible(true);

            ui->OSC_1->setVisible(true);
            ui->OSC_2->setVisible(true);
            ui->OSC_3->setVisible(true);

            ui->OSC_1->setText("128 kHz");
            ui->OSC_2->setText("4 MHz");
            ui->OSC_3->setText("8 MHz");

            Set_enabled_EXT_fuses(true);
            break;
        }
        case ATtiny25:
        case ATtiny45:
        case ATtiny85:
        {
            Clear_fuses(false);
            ui->CKDIV8->setVisible(true);

            ui->OSC_1->setVisible(true);
            ui->OSC_2->setVisible(true);

            ui->OSC_1->setText("6.4 MHz");
            ui->OSC_2->setText("8 MHz");

            Set_enabled_EXT_fuses(true);
            break;
        }
    }
}

void MainWindow::Count_ui_fuses(uint8_t low_fuse_byte, uint8_t high_fuse_byte)
{
    //uC's without CKSEL fusebits: AT90S8535 AT90S8515 AT90S4434 AT90S4433 AT90S2343 AT90S2333 AT90S2313
    //                             AT90S4414 AT90S1200 ATmega161 ATmega163 ATmega103 ATtiny11 ATtiny12 ATtiny15

    Check(ui->CKDIV8, false);
    Check(ui->CKOPT, false);

    Clear_int_osc_fuses();
    Clear_ext_osc_fuses();

    switch(ui->uC_list->currentIndex())
    {
        case AT90USB82:
        case AT90USB162:
        case AT90USB1287:
        case AT90USB1286:
        case AT90USB646:
        case AT90USB647:
        case AT90PWM2:
        case AT90PWM3:
        case AT90PWM2B:
        case AT90PWM3B:
        case AT90CAN32:
        case AT90CAN64:
        case AT90CAN128:
        {
           if(~low_fuse_byte & 0x80)
               Check(ui->CKDIV8, true);

           switch(low_fuse_byte & 0x0F)
           {
               case 0x0F:
               case 0x0E: Check(ui->EXT_OSC_4, true);   break;
               case 0x0D:
               case 0x0C: Check(ui->EXT_OSC_3, true);   break;
               case 0x0A:
               case 0x0B: Check(ui->EXT_OSC_2, true);   break;
               case 0x08:
               case 0x09: Check(ui->EXT_OSC_1, true);   break;
               case 0x02: Check(ui->OSC_1, true);       break;
           }
           break;
        }
        case ATmega8:
        case ATmega16:
        case ATmega32:
        case ATmega64:
        case ATmega128:
        case ATmega8535:
        case ATmega8515:
        case ATtiny26:
        {
            if(~high_fuse_byte & 0x08)
                Check(ui->CKOPT, true);

            switch(low_fuse_byte & 0x0F)
            {
                case 0x0F:
                case 0x0E: Check(ui->EXT_OSC_3, true);  break;
                case 0x0D:
                case 0x0C: Check(ui->EXT_OSC_2, true);  break;
                case 0x0B:
                case 0x0A: Check(ui->EXT_OSC_1, true);  break;
                case 0x01: Check(ui->OSC_1, true);      break;
                case 0x02: Check(ui->OSC_2, true);      break;
                case 0x03: Check(ui->OSC_3, true);      break;
                case 0x04: Check(ui->OSC_4, true);      break;
            }
            break;
        }
        case ATmega640:
        case ATmega1280:
        case ATmega1281:
        case ATmega2560:
        case ATmega2561:
        case ATmega1284p:
        case ATmega48:
        case ATmega88:
        case ATmega168:
        case ATmega328p:
        case ATtiny88:
        {
            if(~low_fuse_byte & 0x80)
                Check(ui->CKDIV8, true);

            switch(low_fuse_byte & 0x0F)
            {
                case 0x0F:
                case 0x0E: Check(ui->EXT_OSC_4, true);  break;
                case 0x0D:
                case 0x0C: Check(ui->EXT_OSC_3, true);  break;
                case 0x0B:
                case 0x0A: Check(ui->EXT_OSC_2, true);  break;
                case 0x09:
                case 0x08: Check(ui->EXT_OSC_1, true);  break;
                case 0x03: Check(ui->OSC_1, true);      break;
                case 0x02: Check(ui->OSC_2, true);      break;
            }
            break;
        }
        case ATtiny13:
        {
            if(~low_fuse_byte & 0x80)
                Check(ui->CKDIV8, true);

            switch(low_fuse_byte & 0x03)
            {
                case 0x03: Check(ui->OSC_3, true);  break;
                case 0x02: Check(ui->OSC_2, true);  break;
                case 0x01: Check(ui->OSC_1, true);  break;
            }
            break;
        }
        case ATtiny2313:
        {
            if(~low_fuse_byte & 0x80)
                Check(ui->CKDIV8, true);

            switch(low_fuse_byte & 0x0F)
            {
                case 0x0F:
                case 0x0E: Check(ui->EXT_OSC_4, true);  break;
                case 0x0D:
                case 0x0C: Check(ui->EXT_OSC_3, true);  break;
                case 0x0B:
                case 0x0A: Check(ui->EXT_OSC_2, true);  break;
                case 0x09:
                case 0x08: Check(ui->EXT_OSC_1, true);  break;
                case 0x06: Check(ui->OSC_1, true);      break;
                case 0x02: Check(ui->OSC_2, true);      break;
                case 0x04: Check(ui->OSC_3, true);      break;
            }
            break;
        }
        case ATtiny25:
        case ATtiny45:
        case ATtiny85:
        {
            if(~low_fuse_byte & 0x80)
                Check(ui->CKDIV8, true);

            switch(low_fuse_byte & 0x0F)
            {
                case 0x0F:
                case 0x0E: Check(ui->EXT_OSC_4, true);  break;
                case 0x0D:
                case 0x0C: Check(ui->EXT_OSC_3, true);  break;
                case 0x0B:
                case 0x0A: Check(ui->EXT_OSC_2, true);  break;
                case 0x09:
                case 0x08: Check(ui->EXT_OSC_1, true);  break;
                case 0x04: Check(ui->OSC_1, true);      break;
                case 0x03: Check(ui->OSC_2, true);      break;
                case 0x02: Check(ui->OSC_3, true);      break;
            }
            break;
        }
    }
}
