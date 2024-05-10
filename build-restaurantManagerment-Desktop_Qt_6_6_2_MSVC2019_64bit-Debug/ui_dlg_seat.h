/********************************************************************************
** Form generated from reading UI file 'dlg_seat.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLG_SEAT_H
#define UI_DLG_SEAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_dlg_seat
{
public:
    QPushButton *btn_enter;
    QPushButton *btn_exit;
    QTableWidget *tableWidget;

    void setupUi(QDialog *dlg_seat)
    {
        if (dlg_seat->objectName().isEmpty())
            dlg_seat->setObjectName("dlg_seat");
        dlg_seat->resize(371, 491);
        btn_enter = new QPushButton(dlg_seat);
        btn_enter->setObjectName("btn_enter");
        btn_enter->setGeometry(QRect(60, 440, 93, 29));
        btn_exit = new QPushButton(dlg_seat);
        btn_exit->setObjectName("btn_exit");
        btn_exit->setGeometry(QRect(220, 440, 93, 29));
        tableWidget = new QTableWidget(dlg_seat);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 10, 331, 411));
        tableWidget->horizontalHeader()->setStretchLastSection(true);

        retranslateUi(dlg_seat);

        QMetaObject::connectSlotsByName(dlg_seat);
    } // setupUi

    void retranslateUi(QDialog *dlg_seat)
    {
        dlg_seat->setWindowTitle(QCoreApplication::translate("dlg_seat", "Dialog", nullptr));
        btn_enter->setText(QCoreApplication::translate("dlg_seat", "\347\241\256\345\256\232", nullptr));
        btn_exit->setText(QCoreApplication::translate("dlg_seat", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dlg_seat: public Ui_dlg_seat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLG_SEAT_H
