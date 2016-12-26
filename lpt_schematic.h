
#ifndef LPT_SCHEMATIC_H
#define LPT_SCHEMATIC_H

#include <QDialog>

namespace Ui {
class LPT_Schematic;
}

class LPT_Schematic : public QDialog
{
    Q_OBJECT

public:
    explicit LPT_Schematic(QWidget *parent = 0);
    ~LPT_Schematic();

private:
    Ui::LPT_Schematic *ui;
};

#endif // LPT_SCHEMATIC_H
