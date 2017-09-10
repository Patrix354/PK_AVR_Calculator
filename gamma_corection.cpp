#include "gamma_corection.h"
#include "ui_gamma_corection.h"

#include <QString>
#include <QPen>
#include <QVector>

#include <cmath>

Gamma_Corection::Gamma_Corection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gamma_Corection)
{
    ui->setupUi(this);

    QString Gamma;
    QString Colors[3] = {"Red", "Green", "Blue"};

    for(int i = 0; i < 3; i++)
    {
        ui->Color_box->addItem(Colors[i]);
    }
    ui->Gamma_Chart->addGraph();
    ui->Gamma_Chart->xAxis->setLabel("Index");
    ui->Gamma_Chart->yAxis->setLabel("PWM");

    ui->Array_width->setValidator( new QIntValidator(0, 65536, this) );
    ui->PWM_res->setValidator( new QIntValidator(0, 65536, this) );

    Only_first_zero = false;
    MakePlot(ui->PWM_res->text().toInt(nullptr, 10), ui->Array_width->text().toInt(nullptr, 10));

    ui->GammaSlider->setRange(5, 100);
    ui->GammaSlider->setValue(25);

    Gamma_factor = static_cast<float>(ui->GammaSlider->value()) / 10.00;
    Gamma.setNum(Gamma_factor, 'g', 2);
    ui->GammaFactor_lbl->setText(Gamma);
}

Gamma_Corection::~Gamma_Corection()
{
    delete ui;
}

void Gamma_Corection::on_PWM_res_textChanged(const QString &arg1)
{
    MakePlot(ui->PWM_res->text().toInt(nullptr, 10), ui->Array_width->text().toInt(nullptr, 10));
}

void Gamma_Corection::on_Array_width_textChanged(const QString &arg1)
{
    MakePlot(ui->PWM_res->text().toInt(nullptr, 10), ui->Array_width->text().toInt(nullptr, 10));
}

void Gamma_Corection::on_First_zero_toggled(bool checked)
{
    Only_first_zero = checked;
    MakePlot(ui->PWM_res->text().toInt(nullptr, 10), ui->Array_width->text().toInt(nullptr, 10));
}

void Gamma_Corection::on_GammaSlider_valueChanged(int value)
{
    QString Gamma;

    Gamma.setNum(static_cast<float>(value) / 10.00, 'g', 2);
    ui->GammaFactor_lbl->setText(Gamma);
    MakePlot(ui->PWM_res->text().toInt(nullptr, 10), ui->Array_width->text().toInt(nullptr, 10));
}

void Gamma_Corection::on_Color_box_activated(const QString &arg1)
{
    MakePlot(ui->PWM_res->text().toInt(nullptr, 10), ui->Array_width->text().toInt(nullptr, 10));
}

void Gamma_Corection::on_Reset_clicked()
{
    ui->Array_width->setText("256");
    ui->PWM_res->setText("256");
    ui->GammaSlider->setValue(25);
    ui->First_zero->setChecked(false);
}

//
//  Other Methods
//

void Gamma_Corection::MakePlot(int Resolution, int Width)
{
    QString value;
    QPen pen;
    QVector<double> x(65537), y(65537);

    switch(ui->Color_box->currentIndex())
    {
        case 0: pen.setColor(QColor(0xFF,0,0)); break;
        case 1: pen.setColor(QColor(0,0xFF,0)); break;
        case 2: pen.setColor(QColor(0,0,0xFF)); break;
    }

    for (int i=0; i < Width; i++)
    {
      x[i] = i;
      y[i] = static_cast<int>(pow(static_cast<float>(i) / static_cast<float>(Width), ui->GammaFactor_lbl->text().toFloat(nullptr)) * Resolution + 0.5);
      if(i != 0 && y[i] == 0 && Only_first_zero)
      {
          y[i] = 1;
      }
    }

    ui->Source_data->clear();

    switch(ui->Color_box->currentIndex())
    {
        case 0:
        {
            Print(QString::fromStdString("// ------ gamma  RED  = ") + QString::number(ui->GammaFactor_lbl->text().toFloat(nullptr), 'g', 2), 0x008000, true);
            Print("const ", 0x800080, false);
            if(y[Width-1] > 0xff)
            {
                Print("uint16_t Gamma_correctionR", 0x0000ff, false);
            }
            else
            {
                Print("uint8_t Gamma_correctionR", 0x0000ff, false);
            }
            ui->Source_data->insertHtml("[ ] ");
            Print("PROGMEM ", 0x0000ff, false);
            ui->Source_data->insertHtml(" = { <br>");
            break;
        }
        case 1:
        {
            Print(QString::fromStdString("// ------ gamma  GREEN  = ") + QString::number(ui->GammaFactor_lbl->text().toFloat(nullptr), 'g', 2), 0x008000, true);
            Print("const ", 0x800080, false);
            if(y[Width-1] > 0xff)
            {
                Print("uint16_t Gamma_correctionG", 0x0000ff, false);
            }
            else
            {
                Print("uint8_t Gamma_correctionG", 0x0000ff, false);
            }
            ui->Source_data->insertHtml("[ ] ");
            Print("PROGMEM ", 0x0000ff, false);
            ui->Source_data->insertHtml(" = { <br>");
            break;
        }

        case 2:
        {
            Print(QString::fromStdString("// ------ gamma  BLUE  = ") + QString::number(ui->GammaFactor_lbl->text().toFloat(nullptr), 'g', 2), 0x008000, true);

            Print("const ", 0x800080, false);
            if(y[Width-1] > 0xff)
            {
                Print("uint16_t Gamma_correctionB", 0x0000ff, false);
            }
            else
            {
                Print("uint8_t Gamma_correctionB", 0x0000ff, false);
            }
            ui->Source_data->insertHtml("[ ] ");
            Print("PROGMEM ", 0x0000ff, false);
            ui->Source_data->insertHtml(" = { <br>");
            break;
        }
    }

    value = "";
    for(int i = 0; i < Width; i++)
    {
        if(i == Width-1)
        {
            value += QString::fromStdString("<font color=\"#800080\">") + QString::number(y[i], 'g', 5) + QString::fromStdString("</font>");
        }
        else
        {
            value += QString::fromStdString("<font color=\"#800080\">") + QString::number(y[i], 'g', 5) + QString::fromStdString("</font>") + QString::fromStdString(", ");
        }
    }

    ui->Source_data->insertHtml(value);
    ui->Source_data->insertHtml("<br>};");

    ui->Gamma_Chart->graph(0)->setPen(pen);
    ui->Gamma_Chart->graph(0)->setData(x, y);

    ui->Gamma_Chart->xAxis->setRange(0, Width);
    ui->Gamma_Chart->yAxis->setRange(0, Resolution);
    ui->Gamma_Chart->replot();
}

void Gamma_Corection::Print(QString text, int color, bool new_line)
{
    QString color_QStr;
    QString line;

    color_QStr = QString::number(color, 16);

    while(color_QStr.length() != 6)
    {
        color_QStr = QString::fromStdString("0") + color_QStr;
    }

    if(new_line)
    {
        line = QString::fromStdString("<font color=\"#") + color_QStr + "\">" + text + QString::fromStdString("</font><br>");
    }
    else
    {
        line = QString::fromStdString("<font color=\"#") + color_QStr +"\">" + text + QString::fromStdString("</font>");
    }
    ui->Source_data->insertHtml(line);
}
