#include "attiny_con_schematic.h"
#include "ui_attiny_con_schematic.h"

#include <QPixmap>

ATtiny_CON_Schematic::ATtiny_CON_Schematic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ATtiny_CON_Schematic)
{
    ui->setupUi(this);

    int w = ui->CON_Schem->width();
    int h = ui->CON_Schem->height();

    QPixmap pix(":/FOTO/FOTO/ATtiny10-TPI-Prog.png");
    ui->CON_Schem->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

ATtiny_CON_Schematic::~ATtiny_CON_Schematic()
{
    delete ui;
}
