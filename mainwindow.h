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
#include "gamma_corection.h"

#define uC_AMOUNT 95
#define PROG_AMOUNT 2
#define SCK_AMOUNT 13
#define LOCK_LB_AMOUNT 3
#define LOCK_BLB0_AMOUNT 4
#define LOCK_BLB1_AMOUNT 4
#define ERR_AMOUNT 2
#define PORT_AMOUNT 2

#define OUTPUT_FILE "C://PK_AVR_Calculator//command.log"
#define SIGNATURE_FILE "C://PK_AVR_Calculator//signature.log"
#define SAVE_FILE "C://PK_AVR_Calculator//save.log"

#define AVRDUDE_ERR "Błąd AVRDUDE!"
#define ERR "Error"
#define WAIT "Czekaj"
#define DONE "Done"
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

public slots:
    void checkPorts(void);

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
    void on_Set_AVRDUDE_path_clicked();
    void on_Slow_SCK_Enable_1_toggled(bool checked);
    void on_CheckFuseBits_toggled(bool checked);
    void on_Slow_SCK_Enable_2_toggled(bool checked);
    void on_Gamma_Cor_clicked();

    void on_Reset_button_clicked();

    void on_set_eeprom_path_clicked();

    void on_set_flash_path_clicked();

private:
    Ui::MainWindow *ui;

    enum uc_names_enu
    {
        AT90USB82, AT90USB162, AT90USB1287, AT90USB1286, AT90USB647, AT90USB646, AT90PWM3B,
        AT90PWM3, AT90PWM2B, AT90PWM2, AT90CAN32, AT90CAN64, AT90CAN128, AT90S8535, AT90S8515,
        AT90S4434, AT90S4433, AT90S2343, AT90S2333, AT90S2313, AT90S4414, AT90S1200, ATmega640,
        ATmega1280, ATmega1281, ATmega1284, ATmega1284P, ATmega1284PA, ATmega2560, ATmega2561, ATmega8, ATmega8A, ATmega8U2,
        ATmega48, ATmega48P, ATmega48PA, ATmega88, ATmega88P, ATmega88PA, ATmega168, ATmega168P, ATmega168PA,
        ATmega328, ATmega328P, ATmega328PA, ATmega161, ATmega8535, ATmega8515, ATmega6490, ATmega164P, ATmega164A, ATmega324P, ATmega324PA,
        ATmega644, ATmega644P, ATmega644PA, ATmega16, ATmega16A, ATmega32, ATmega32A, ATmega32U2, ATmega32U4, ATmega64, ATmega128, ATmega128A,
        ATmega325, ATmega3250, ATmega645, ATmega6450, ATmega103, ATmega163, ATmega162, ATmega169, ATmega329, ATmega329P,
        ATmega649, ATmega3290, ATmega3290P,ATtiny84, ATtiny44, ATtiny24, ATtiny85, ATtiny45, ATtiny25, ATtiny88, ATtiny2313,
        ATtiny861, ATtiny461, ATtiny261, ATtiny26, ATtiny15, ATtiny13, ATtiny12, ATtiny11
    };

    bool Auto_Slow_SCK;
    bool CheckFuses;
    uint8_t lfuse;
    uint8_t hfuse;
    uint8_t efuse;
    uint8_t lock;
    QString AVRDUDE_path;
    QTimer* Port_timer;

    QString uC_codes[uC_AMOUNT];
    QString uC_names[uC_AMOUNT];
    QString Prog_names[PROG_AMOUNT];
    QString Prog_codes[PROG_AMOUNT];
    QString SCK_names[SCK_AMOUNT];
    QString SCK_codes[SCK_AMOUNT];

    LPT_Schematic* Prog_Dialog;
    KANDA_Schematic* KANDA_Dialog;
    ATtiny_CON_Schematic* ATtiny_CON_Dialog;
    UBRR_Calculator* UART_Calculator;
    Gamma_Corection* Corection;

    bool Search_ERR(string path_to_file);
    QString Search_fuse(string path_to_file);
    void Safe_output_to_file(QString exec, QStringList params, string path_to_file, int mode);
    void Print_ERR(string path_to_file);
    void Set_ui_lock(uint8_t lock_byte, uint8_t mode);
    void Set_ui_fuses(uint8_t lfuse_byte, uint8_t hfuse_byte, uint8_t mode);
    void Set_ui_jtag_fuse(uint8_t hfuse_byte, uint8_t mode);
    void Set_enabled_EXT_fuses(bool visible);
    void Set_enabled_INT_fuses(bool visible);
    void Clear_int_osc_fuses();
    void Clear_ext_osc_fuses();
    void Clear_fuses(bool visible);
};

#endif // MAINWINDOW_H
