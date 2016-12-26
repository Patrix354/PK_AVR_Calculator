#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSound>

#include "lpt_schematic.h"
#include "kanda_schematic.h"
#include "attiny_con_schematic.h"
#include "ubrr_calculator.h"

#define uC_AMOUNT 62
#define PROG_AMOUNT 3
#define SCK_AMOUNT 13
#define ERR_AMOUNT 3
#define SCK_SPECIALS 2
#define FILE_PATH "C:/Program Files/PK_AVR_Calculator/command.log"

#define AVRDUDE_ERR "Błąd AVRDUDE!"
#define PROG_ERR "Błąd Programatora!"
#define UNKNOWN_ERR "???"
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

private:
    Ui::MainWindow *ui;

    bool file_flag;

    QString uC_codes[uC_AMOUNT];
    QString uC_names[uC_AMOUNT];
    QString Prog_names[PROG_AMOUNT];
    QString Prog_codes[PROG_AMOUNT];
    QString SCK_names[SCK_AMOUNT];
    QString SCK_codes[SCK_AMOUNT];
    QString SCK_special[SCK_SPECIALS];
    QString ERR_names[ERR_AMOUNT];

    LPT_Schematic* Prog_Dialog;
    KANDA_Schematic* KANDA_Dialog;
    ATtiny_CON_Schematic* ATtiny_CON_Dialog;
    UBRR_Calculator* UART_Calculator;

    void Safe_to_file(QString exec, QStringList params, string path_to_file);
    int Search_ERR(string path_to_file);
    int Search_uC(string path_to_file);
};

#endif // MAINWINDOW_H
