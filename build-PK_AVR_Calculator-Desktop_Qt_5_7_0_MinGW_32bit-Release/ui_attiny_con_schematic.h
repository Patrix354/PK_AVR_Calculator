/********************************************************************************
** Form generated from reading UI file 'attiny_con_schematic.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATTINY_CON_SCHEMATIC_H
#define UI_ATTINY_CON_SCHEMATIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ATtiny_CON_Schematic
{
public:
    QLabel *CON_Schem;

    void setupUi(QDialog *ATtiny_CON_Schematic)
    {
        if (ATtiny_CON_Schematic->objectName().isEmpty())
            ATtiny_CON_Schematic->setObjectName(QStringLiteral("ATtiny_CON_Schematic"));
        ATtiny_CON_Schematic->resize(900, 387);
        ATtiny_CON_Schematic->setMinimumSize(QSize(900, 387));
        ATtiny_CON_Schematic->setMaximumSize(QSize(900, 387));
        ATtiny_CON_Schematic->setStyleSheet(QStringLiteral(""));
        CON_Schem = new QLabel(ATtiny_CON_Schematic);
        CON_Schem->setObjectName(QStringLiteral("CON_Schem"));
        CON_Schem->setGeometry(QRect(0, 0, 900, 387));
        CON_Schem->setMinimumSize(QSize(900, 387));
        CON_Schem->setMaximumSize(QSize(900, 387));

        retranslateUi(ATtiny_CON_Schematic);

        QMetaObject::connectSlotsByName(ATtiny_CON_Schematic);
    } // setupUi

    void retranslateUi(QDialog *ATtiny_CON_Schematic)
    {
        ATtiny_CON_Schematic->setWindowTitle(QApplication::translate("ATtiny_CON_Schematic", "Dialog", 0));
        CON_Schem->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ATtiny_CON_Schematic: public Ui_ATtiny_CON_Schematic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATTINY_CON_SCHEMATIC_H
