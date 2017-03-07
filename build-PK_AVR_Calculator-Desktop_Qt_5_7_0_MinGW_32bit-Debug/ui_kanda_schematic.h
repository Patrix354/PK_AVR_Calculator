/********************************************************************************
** Form generated from reading UI file 'kanda_schematic.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KANDA_SCHEMATIC_H
#define UI_KANDA_SCHEMATIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_KANDA_Schematic
{
public:
    QLabel *Schematic;

    void setupUi(QDialog *KANDA_Schematic)
    {
        if (KANDA_Schematic->objectName().isEmpty())
            KANDA_Schematic->setObjectName(QStringLiteral("KANDA_Schematic"));
        KANDA_Schematic->resize(1280, 406);
        KANDA_Schematic->setMinimumSize(QSize(1280, 406));
        KANDA_Schematic->setMaximumSize(QSize(1280, 406));
        Schematic = new QLabel(KANDA_Schematic);
        Schematic->setObjectName(QStringLiteral("Schematic"));
        Schematic->setGeometry(QRect(0, 0, 1280, 406));

        retranslateUi(KANDA_Schematic);

        QMetaObject::connectSlotsByName(KANDA_Schematic);
    } // setupUi

    void retranslateUi(QDialog *KANDA_Schematic)
    {
        KANDA_Schematic->setWindowTitle(QApplication::translate("KANDA_Schematic", "Standard KANDA -  Bez Problemu", 0));
#ifndef QT_NO_WHATSTHIS
        KANDA_Schematic->setWhatsThis(QApplication::translate("KANDA_Schematic", "Prosta grafika u\305\202atwiaj\304\205ca pod\305\202\304\205czenie programatora z interfejsem KANDA", 0));
#endif // QT_NO_WHATSTHIS
        Schematic->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class KANDA_Schematic: public Ui_KANDA_Schematic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KANDA_SCHEMATIC_H
