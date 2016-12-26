#ifndef ATTINY_CON_SCHEMATIC_H
#define ATTINY_CON_SCHEMATIC_H

#include <QDialog>

namespace Ui {
class ATtiny_CON_Schematic;
}

class ATtiny_CON_Schematic : public QDialog
{
    Q_OBJECT

public:
    explicit ATtiny_CON_Schematic(QWidget *parent = 0);
    ~ATtiny_CON_Schematic();

private:
    Ui::ATtiny_CON_Schematic *ui;
};

#endif // ATTINY_CON_SCHEMATIC_H
