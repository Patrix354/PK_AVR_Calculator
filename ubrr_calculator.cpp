#include "ubrr_calculator.h"
#include "ui_ubrr_calculator.h"

#include <QString>

UBRR_Calculator::UBRR_Calculator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UBRR_Calculator)
{
    ui->setupUi(this);

    int F_OSC_speed[F_OSC_AMOUNT] =
    {
        1000000,
        1843200,
        2000000,
        3686400,
        4000000,
        6000000,
        7372800,
        8000000,
        10000000,
        11059200,
        12000000,
        14745600,
        16000000,
        18432000,
        20000000,
        22118400
    };

    for(int i = 0; i < F_OSC_AMOUNT; i++)
    {
        ui->F_OSC_list->addItem(QString::number(F_OSC_speed[i]));
        F_OSC_Speed[i] = F_OSC_speed[i];
    }

    UBRR_0X_PREV = 1;
    UBRR_2X_PREV = 1;

    emit on_F_OSC_list_activated(0);
}

UBRR_Calculator::~UBRR_Calculator()
{
    delete ui;
}

void UBRR_Calculator::on_F_OSC_list_activated(int index)
{
    UBRR_0X_PREV = 1;
    UBRR_2X_PREV = 1;

    set_line(2400, F_OSC_Speed[index], ui->UBRR_2400_0X, ui->UBRR_2400_2X, ui->error_2400_0X, ui->error_2400_2X);
    set_line(4800, F_OSC_Speed[index], ui->UBRR_4800_0X, ui->UBRR_4800_2X, ui->error_4800_0X, ui->error_4800_2X);
    set_line(9600, F_OSC_Speed[index], ui->UBRR_9600_0X, ui->UBRR_9600_2X, ui->error_9600_0X, ui->error_9600_2X);
    set_line(14400, F_OSC_Speed[index], ui->UBRR_14400_0X, ui->UBRR_14400_2X, ui->error_14400_0X, ui->error_14400_2X);
    set_line(19200, F_OSC_Speed[index], ui->UBRR_19200_0X, ui->UBRR_19200_2X, ui->error_19200_0X, ui->error_19200_2X);
    set_line(28800, F_OSC_Speed[index], ui->UBRR_28800_0X, ui->UBRR_28800_2X, ui->error_28800_0X, ui->error_28800_2X);
    set_line(38400, F_OSC_Speed[index], ui->UBRR_38400_0X, ui->UBRR_38400_2X, ui->error_38400_0X, ui->error_38400_2X);
    set_line(57600, F_OSC_Speed[index], ui->UBRR_57600_0X, ui->UBRR_57600_2X, ui->error_57600_0X, ui->error_57600_2X);
    set_line(76800, F_OSC_Speed[index], ui->UBRR_76800_0X, ui->UBRR_76800_2X, ui->error_76800_0X, ui->error_76800_2X);
    set_line(115200, F_OSC_Speed[index], ui->UBRR_115200_0X, ui->UBRR_115200_2X, ui->error_115200_0X, ui->error_115200_2X);
    set_line(230400, F_OSC_Speed[index], ui->UBRR_230400_0X, ui->UBRR_230400_2X, ui->error_230400_0X, ui->error_230400_2X);
    set_line(250000, F_OSC_Speed[index], ui->UBRR_250000_0X, ui->UBRR_250000_2X, ui->error_250000_0X, ui->error_250000_2X);

    emit on_baud_edit_textChanged(ui->baud_edit->text());
}

void UBRR_Calculator::on_baud_edit_textChanged(const QString &arg1)
{
    QString output;
    int baud = arg1.toInt(nullptr, 10);
    int F_OSC = F_OSC_Speed[ui->F_OSC_list->currentIndex()];

    if(((arg1.toStdString()[(arg1.toStdString().length()) - 1] < 48 ) || (arg1.toStdString()[(arg1.toStdString().length()) - 1] > 57 )) && ( arg1.length() != 0 ))
    {
        ui->baud_edit->backspace();
        return;
    }

    for(float i = 1; i <= 2; i+=1)
    {
        float UBRR = round(static_cast<float>(F_OSC)/((16.00/i)*baud)-1.00);
        float baud_cm = static_cast<float>(F_OSC)/((16.00/i)*(UBRR+1.00));
        float error = (baud_cm/static_cast<float>(baud)-1.00)*100.00;
        error = round_to(error, 10.00);

        if(i == 1)
        {
            if(UBRR > 0xFFF || UBRR < 0)
            {
                ui->UBRR_unknow_0X->setText("-");
                ui->error_unknow_0X->setText("0%");

            }
            else
            {
                output.setNum(static_cast<int>(UBRR), 10);
                ui->UBRR_unknow_0X->setText(output);

                output.setNum(error, 'g', 2);
                ui->error_unknow_0X->setText(output + "%");
            }
        }
        else
        {
            if(UBRR > 0xFFF || UBRR < 0)
            {
                ui->UBRR_unknow_2X->setText("-");
                ui->error_unknow_2X->setText("0%");
            }
            else
            {
                output.setNum(static_cast<int>(UBRR), 10);
                ui->UBRR_unknow_2X->setText(output);

                output.setNum(error, 'g', 2);
                ui->error_unknow_2X->setText(output + "%");
            }
        }
    }
}

//
//  Methods
//

void UBRR_Calculator::set_line(int baud, int F_OSC, QLabel* _UBRR_0X, QLabel* _UBRR_2X, QLabel* _error_0X, QLabel* _error_2X)
{
    QString output;
    float UBRR = round(static_cast<float>(F_OSC)/(16.00*baud)-1.00);
    float baud_cm = static_cast<float>(F_OSC)/(16.00*(UBRR+1.00));
    float error = (baud_cm/static_cast<float>(baud)-1.00)*100.00;
    error = round_to(error, 10.00);

    if(UBRR < 0)
    {
        UBRR = 0;
    }

    if(UBRR_0X_PREV == 0)
    {
        output = "";
        _UBRR_0X->setText(output);
        _error_0X->setText(output);

    }
    else
    {
        output.setNum(static_cast<int>(UBRR), 10);
        _UBRR_0X->setText(output);

        output.setNum(error, 'g', 2);
        _error_0X->setText(output + "%");
    }

    UBRR_0X_PREV = UBRR;

    UBRR = round(static_cast<float>(F_OSC)/(8.00*baud)-1.00);
    baud_cm = static_cast<float>(F_OSC)/(8.00*(UBRR+1.00));
    error = (baud_cm/static_cast<float>(baud)-1.00)*100.00;
    error = round_to(error, 10.00);

    if(UBRR < 0)
    {
        UBRR = 0;
    }

    if(UBRR_2X_PREV == 0)
    {
        output = "";
        _UBRR_2X->setText(output);
        _error_2X->setText(output);
        return;

    }
    else
    {
        output.setNum(static_cast<int>(UBRR), 10);
        _UBRR_2X->setText(output);

        output.setNum(error, 'g', 2);
        _error_2X->setText(output + "%");
    }

    UBRR_2X_PREV = UBRR;

}

float UBRR_Calculator::round_to(float rounded, float scale)
{
    rounded *= scale;
    rounded = round(rounded);
    rounded /= scale;

    return rounded;
}
