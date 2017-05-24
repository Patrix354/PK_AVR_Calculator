#ifndef UBRR_CALCULATOR_H
#define UBRR_CALCULATOR_H

#include <QDialog>
#include <QLabel>

#define F_OSC_AMOUNT 16

namespace Ui {
class UBRR_Calculator;
}

class UBRR_Calculator : public QDialog
{
    Q_OBJECT

public:
    explicit UBRR_Calculator(QWidget *parent = 0);
    ~UBRR_Calculator();

private slots:

    void on_F_OSC_list_activated(int index);

    void on_baud_edit_textChanged(const QString &arg1);

private:
    Ui::UBRR_Calculator *ui;

    int F_OSC_Speed [F_OSC_AMOUNT];

    int UBRR_0X_PREV;
    int UBRR_2X_PREV;

    float round_to(float rounded, float scale);
    void set_line(int baud, int F_OSC, QLabel* _UBRR_0X, QLabel* _UBRR_2X, QLabel* _error_0X, QLabel* _error_2X);
};

#endif // UBRR_CALCULATOR_H
