/********************************************************************************
** Form generated from reading UI file 'dlg_queue.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLG_QUEUE_H
#define UI_DLG_QUEUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dlg_queue
{
public:
    QTableWidget *tableWidget_1;
    QTableWidget *tableWidget_3;
    QTableWidget *tableWidget_2;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *widget;
    QPushButton *pushButton;
    QPushButton *btn_seat;
    QWidget *widget_3;
    QLabel *label;
    QPushButton *pushButton_3;
    QPushButton *btn_del2;
    QPushButton *pushButton_5;

    void setupUi(QDialog *dlg_queue)
    {
        if (dlg_queue->objectName().isEmpty())
            dlg_queue->setObjectName("dlg_queue");
        dlg_queue->resize(1087, 624);
        tableWidget_1 = new QTableWidget(dlg_queue);
        tableWidget_1->setObjectName("tableWidget_1");
        tableWidget_1->setGeometry(QRect(30, 120, 311, 451));
        tableWidget_1->setStyleSheet(QString::fromUtf8("border-color: rgb(48, 95, 143);"));
        tableWidget_1->horizontalHeader()->setDefaultSectionSize(60);
        tableWidget_1->horizontalHeader()->setStretchLastSection(true);
        tableWidget_3 = new QTableWidget(dlg_queue);
        tableWidget_3->setObjectName("tableWidget_3");
        tableWidget_3->setGeometry(QRect(740, 120, 321, 451));
        tableWidget_3->horizontalHeader()->setDefaultSectionSize(60);
        tableWidget_3->horizontalHeader()->setStretchLastSection(true);
        tableWidget_2 = new QTableWidget(dlg_queue);
        tableWidget_2->setObjectName("tableWidget_2");
        tableWidget_2->setGeometry(QRect(380, 120, 321, 451));
        tableWidget_2->horizontalHeader()->setDefaultSectionSize(60);
        tableWidget_2->horizontalHeader()->setStretchLastSection(true);
        label_2 = new QLabel(dlg_queue);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(510, 570, 91, 31));
        QFont font;
        font.setPointSize(15);
        label_2->setFont(font);
        label_3 = new QLabel(dlg_queue);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(880, 570, 91, 31));
        label_3->setFont(font);
        widget = new QWidget(dlg_queue);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 1111, 91));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(35, 70, 104);"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(350, 20, 111, 51));
        QFont font1;
        font1.setPointSize(14);
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        btn_seat = new QPushButton(widget);
        btn_seat->setObjectName("btn_seat");
        btn_seat->setGeometry(QRect(620, 20, 101, 51));
        btn_seat->setFont(font);
        btn_seat->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        widget_3 = new QWidget(dlg_queue);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(-40, 599, 1131, 61));
        widget_3->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(35, 70, 104);"));
        label = new QLabel(dlg_queue);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 570, 131, 31));
        label->setFont(font);
        pushButton_3 = new QPushButton(dlg_queue);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(1000, 98, 61, 21));
        btn_del2 = new QPushButton(dlg_queue);
        btn_del2->setObjectName("btn_del2");
        btn_del2->setGeometry(QRect(650, 100, 51, 21));
        pushButton_5 = new QPushButton(dlg_queue);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(290, 100, 51, 21));

        retranslateUi(dlg_queue);

        QMetaObject::connectSlotsByName(dlg_queue);
    } // setupUi

    void retranslateUi(QDialog *dlg_queue)
    {
        dlg_queue->setWindowTitle(QCoreApplication::translate("dlg_queue", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("dlg_queue", "4\344\272\272\346\241\214", nullptr));
        label_3->setText(QCoreApplication::translate("dlg_queue", "\345\244\247\345\234\206\346\241\214", nullptr));
        pushButton->setText(QCoreApplication::translate("dlg_queue", "\346\216\222\351\230\237", nullptr));
        btn_seat->setText(QCoreApplication::translate("dlg_queue", "\345\205\245\345\272\247", nullptr));
        label->setText(QCoreApplication::translate("dlg_queue", "2\344\272\272\346\241\214", nullptr));
        pushButton_3->setText(QCoreApplication::translate("dlg_queue", "\345\210\240\351\231\244", nullptr));
        btn_del2->setText(QCoreApplication::translate("dlg_queue", "\345\210\240\351\231\244", nullptr));
        pushButton_5->setText(QCoreApplication::translate("dlg_queue", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dlg_queue: public Ui_dlg_queue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLG_QUEUE_H
