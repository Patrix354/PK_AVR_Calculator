#ifndef KANDA_SCHEMATIC_H
#define KANDA_SCHEMATIC_H

#include <QDialog>

namespace Ui {
class KANDA_Schematic;
}

class KANDA_Schematic : public QDialog
{
    Q_OBJECT

public:
    explicit KANDA_Schematic(QWidget *parent = 0);
    ~KANDA_Schematic();

private:
    Ui::KANDA_Schematic *ui;
};

#endif // KANDA_SCHEMATIC_H
