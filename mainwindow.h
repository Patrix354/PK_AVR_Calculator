#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QRadioButton>
#include <QCheckBox>

#include "lpt_schematic.h"
#include "kanda_schematic.h"
#include "attiny_con_schematic.h"
#include "ubrr_calculator.h"

#define AT90USB82 0
#define AT90USB162 1
#define AT90USB1287 2
#define AT90USB1286 3
#define AT90USB647 4
#define AT90USB646 5

#define AT90PWM3B 6
#define AT90PWM3 7
#define AT90PWM2B 8
#define AT90PWM2 9

#define AT90CAN32 10
#define AT90CAN64 11
#define AT90CAN128 12

#define AT90S8535 13
#define AT90S8515 14
#define AT90S4434 15
#define AT90S4433 16
#define AT90S2343 17
#define AT90S2333 18
#define AT90S2313 19
#define AT90S4414 20
#define AT90S1200 21

#define ATmega640 22
#define ATmega1280 23
#define ATmega1281 24
#define ATmega1284p 25
#define ATmega2560 26
#define ATmega2561 27
#define ATmega8 28
#define ATmega48 29
#define ATmega88 30
#define ATmega168 31
#define ATmega328p 32
#define ATmega161 33
#define ATmega8535 34
#define ATmega8515 35
#define ATmega6490 36
#define ATmega164p 37
#define ATmega324p 38
#define ATmega644 39
#define ATmega644p 40
#define ATmega16 41
#define ATmega32 42
#define ATmega32u4 43
#define ATmega64 44
#define ATmega128 45
#define ATmega325 46
#define ATmega3250 47
#define ATmega645 48
#define ATmega6450 49
#define ATmega103 50
#define ATmega163 51
#define ATmega162 52
#define ATmega169 53
#define ATmega329 54
#define ATmega329p 55
#define ATmega649 56
#define ATmega3290 57
#define ATmega3290p 58

#define ATtiny84 59
#define ATtiny44 60
#define ATtiny24 61
#define ATtiny85 62
#define ATtiny45 63
#define ATtiny25 64
#define ATtiny88 65
#define ATtiny2313 66
#define ATtiny861 67
#define ATtiny461 68
#define ATtiny261 69
#define ATtiny26 70
#define ATtiny15 71
#define ATtiny13 72
#define ATtiny12 73
#define ATtiny11 74


#define uC_AMOUNT 75
#define PROG_AMOUNT 3
#define SCK_AMOUNT 13
#define ERR_AMOUNT 2

#define FILE_PATH "C:/PK_AVR_Calculator/command.log"
#define SIGNATURE_FILE_PATH "C:/PK_AVR_Calculator/signature.log"

#define AVRDUDE_ERR "Błąd AVRDUDE!"
#define OK "OK"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Prog_list_activated(const QString &arg1);
    void on_Main_button_clicked();
    void on_LPT_Prog_Schem_Butt_clicked();
    void on_KANDA_help_clicked();
    void on_ATtiny_CON_clicked();
    void on_UART_CALC_clicked();
    void on_EXT_OSC_1_clicked();
    void on_EXT_OSC_2_clicked();
    void on_EXT_OSC_3_clicked();
    void on_EXT_OSC_4_clicked();
    void on_CKOPT_clicked();
    void on_OSC_1_clicked();
    void on_OSC_2_clicked();
    void on_OSC_3_clicked();
    void on_OSC_4_clicked();
    void on_uC_list_activated(const QString &arg1);
    void on_Command_exec_clicked();

private:
    Ui::MainWindow *ui;

    uint8_t lfuse;
    uint8_t hfuse;
    uint8_t efuse;

    QString uC_codes[uC_AMOUNT];
    QString uC_names[uC_AMOUNT];
    QString Prog_names[PROG_AMOUNT];
    QString Prog_codes[PROG_AMOUNT];
    QString SCK_names[SCK_AMOUNT];
    QString SCK_codes[SCK_AMOUNT];

    QString lfuse_Qstr;
    QString hfuse_Qstr;
    QString efuse_Qstr;

    LPT_Schematic* Prog_Dialog;
    KANDA_Schematic* KANDA_Dialog;
    ATtiny_CON_Schematic* ATtiny_CON_Dialog;
    UBRR_Calculator* UART_Calculator;

    bool Search_ERR(string path_to_file);
    QString Search_fuse(string path_to_file);
    void Safe_to_file(QString exec, QStringList params, string path_to_file, int mode);
    void Print_ERR(string path_to_file);
    void Check(QRadioButton* button, bool pos);
    void Check(QCheckBox* button, bool pos);
    void Set_ui_fuses();
    void Count_ui_fuses(uint8_t fuse_byte);
    void Set_enabled_EXT_fuses(bool visible);
    void Clear_int_osc_fuses();
    void Clear_ext_osc_fuses();
    void Clear_fuses(bool visible);
};

#endif // MAINWINDOW_H
