/********************************************************************************
** Form generated from reading UI file 'lpt_schematic.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LPT_SCHEMATIC_H
#define UI_LPT_SCHEMATIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_LPT_Schematic
{
public:
    QLabel *Schematic;

    void setupUi(QDialog *LPT_Schematic)
    {
        if (LPT_Schematic->objectName().isEmpty())
            LPT_Schematic->setObjectName(QStringLiteral("LPT_Schematic"));
        LPT_Schematic->resize(907, 375);
        LPT_Schematic->setMinimumSize(QSize(907, 375));
        LPT_Schematic->setMaximumSize(QSize(907, 375));
        LPT_Schematic->setContextMenuPolicy(Qt::DefaultContextMenu);
        Schematic = new QLabel(LPT_Schematic);
        Schematic->setObjectName(QStringLiteral("Schematic"));
        Schematic->setGeometry(QRect(0, 0, 907, 375));
        Schematic->setAlignment(Qt::AlignCenter);

        retranslateUi(LPT_Schematic);

        QMetaObject::connectSlotsByName(LPT_Schematic);
    } // setupUi

    void retranslateUi(QDialog *LPT_Schematic)
    {
        LPT_Schematic->setWindowTitle(QApplication::translate("LPT_Schematic", "Najprostszy programator LPT", 0));
#ifndef QT_NO_WHATSTHIS
        LPT_Schematic->setWhatsThis(QApplication::translate("LPT_Schematic", "<html><head/><body><p>Schmat najprostszego programatora LPT</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        Schematic->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LPT_Schematic: public Ui_LPT_Schematic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LPT_SCHEMATIC_H
