#include "kanda_schematic.h"
#include "ui_kanda_schematic.h"

#include <QPixmap>

KANDA_Schematic::KANDA_Schematic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KANDA_Schematic)
{
    ui->setupUi(this);

    int w = ui->Schematic->width();
    int h = ui->Schematic->height();

    QPixmap pix(":/FOTO/FOTO/Help_KANDA.png");
    ui->Schematic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

KANDA_Schematic::~KANDA_Schematic()
{
    delete ui;
}
