#include "lpt_schematic.h"
#include "ui_lpt_schematic.h"

#include <QPixmap>

LPT_Schematic::LPT_Schematic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LPT_Schematic)
{
    ui->setupUi(this);

    int w = ui->Schematic->width();
    int h = ui->Schematic->height();

    QPixmap pix(":/FOTO/FOTO/LPT_Schematic.png");
    ui->Schematic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

LPT_Schematic::~LPT_Schematic()
{
    delete ui;
}
