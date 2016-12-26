#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QMessageBox>
#include <QProcess>
#include <QSound>
#include <QSysInfo>

#include <fstream>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    file_flag = true;

    QString uc_codes[uC_AMOUNT] =
    {
        "m6450", "m3250", "m645", "usb1287", "usb1286", "usb647", "usb646", "t84", "t44",
        "t24", "m2561", "m2560", "m1281", "m1280", "m640", "t85", "t45", "t25", "pwm3",
        "pwm2", "t2313", "m168", "m88", "m48", "t861", "t461", "t261", "t26", "m8535",
        "m8515", "m8", "m161", "m32", "m6490", "m649", "m3290", "m329", "m169", "m163",
        "m162", "m644", "m324", "m328p", "m164", "m16", "c128", "m128","m64","m103","8535","8515",
        "4434","4433","2343","2333","2313","4414","1200","t15", "t13", "t12", "t11"
    };

    QString uc_names[uC_AMOUNT] =
    {
        "ATmega6450", "ATmega3250", "ATmega645", "AT90USB1287", "AT90USB1286", "AT90USB647", "AT90USB646", "ATtiny84",
        "ATtiny44", "ATtiny24", "ATmega2561", "ATmega2560", "ATmega1281", "ATmega1280", "ATmega640", "ATtiny85",
        "ATtiny45", "ATtiny25", "AT90PWM3", "AT90PWM2", "ATtiny2313", "ATmega168", "ATmega88", "ATmega48", "ATtiny861",
        "ATtiny461", "ATtiny261", "ATtiny26", "ATmega8535", "ATmega8515", "ATmega8", "ATmega161", "ATmega32", "ATmega6490",
        "ATmega649", "ATmega3290", "ATmega329", "ATmega169", "ATmega163", "ATmega162", "ATmega644", "ATmega324", "ATmega328P",
        "ATmega164","ATmega16", "AT90CAN128", "ATmega128", "ATmega64", "ATmega103", "AT90S8535", "AT90S8515", "AT90S4434", "AT90S4433",
        "AT90S2343", "AT90S2333", "AT90S2313", "AT90S4414", "AT90S1200", "ATtiny15", "ATtiny13", "ATtiny12", "ATtiny11"
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
        "avrdude: AVR device initialized", "avrdude: error: programm enable", "avrdude: error: could not find "
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
}

MainWindow::~MainWindow()
{
    delete ui;
}

//
//  Slots
//

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
}

void MainWindow::on_Main_button_clicked()
{
    QString exec = "avrdude";
    QStringList params;

    int uc_index = ui->uC_list->currentIndex();
    int prog_index = ui->Prog_list->currentIndex();
    int sck_index = ui->SCK_list->currentIndex();
    int err_value = 0;
    int search_value = 0;

    ui->ERR_Main_Label->setText("Odczyt");

    params << uC_codes[uc_index] << Prog_codes[prog_index] << SCK_codes[sck_index];

    Safe_to_file(exec, params, FILE_PATH);
    err_value = Search_ERR(FILE_PATH);
    search_value = Search_uC(FILE_PATH);

    if(search_value >= 7)
    {
        ui->ERR_Main_Label->setText(AVRDUDE_ERR);
        return;
    }

    switch (err_value)
    {
        case 0:     ui->ERR_Main_Label->setText(OK);                break;
        case 1:     ui->ERR_Main_Label->setText(AVRDUDE_ERR);       break;
        case 2:     ui->ERR_Main_Label->setText(PROG_ERR);          break;
        default:    ui->ERR_Main_Label->setText(UNKNOWN_ERR);       break;
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

//
//  Other Methods
//

void MainWindow::Safe_to_file(QString exec, QStringList params, string path_to_file)
{
    QObject parent;
    QProcess* AVRProcess;
    std::fstream file;

    AVRProcess = new QProcess(&parent);
    AVRProcess->start(exec, params);
    AVRProcess->waitForFinished();
    QString Qoutput(AVRProcess->readAllStandardError());
    AVRProcess->close();

    std::string output = Qoutput.toLocal8Bit().constData();

    file.open(path_to_file.c_str(), ios::out);
    file << output;
    file.close();
    file.clear();
}

int MainWindow::Search_ERR(string path_to_file)
{
    std::fstream file;
    std::string line;
    std::string sub_line;

    file.open(path_to_file.c_str(), ios::in);

    if(file.good() == false)
    {
        file_flag = false;
        QMessageBox::critical(this, "LOG ERR", "Can't open log file");
        return -1;
    }

    while(getline(file, line))
    {
        if(line.length() <= 2)
        {
            continue;
        }
        else
        {
            sub_line =  line.substr(0,31);
            for(int i = 0; i < ERR_AMOUNT; i++)
            {
                if(sub_line == ERR_names[0].toLocal8Bit().constData())
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
