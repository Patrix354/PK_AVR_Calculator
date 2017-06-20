#ifndef GAMMA_CORECTION_H
#define GAMMA_CORECTION_H

#include <QDialog>

#include "qcustomplot.h"

namespace Ui {
class Gamma_Corection;
}

class Gamma_Corection : public QDialog
{
    Q_OBJECT

public:
    explicit Gamma_Corection(QWidget *parent = 0);
    ~Gamma_Corection();

private slots:
    void MakePlot(int Resolution, int Width);
    void on_GammaSlider_valueChanged(int value);
    void on_PWM_res_textChanged(const QString &arg1);
    void on_Array_width_textChanged(const QString &arg1);
    void on_First_zero_toggled(bool checked);
    void on_Color_box_activated(const QString &arg1);
    void on_Reset_clicked();

private:
    bool Only_first_zero;
    float Gamma_factor;

    void Print(QString text, int color, bool new_line);

    Ui::Gamma_Corection *ui;
};

#endif // GAMMA_CORECTION_H
