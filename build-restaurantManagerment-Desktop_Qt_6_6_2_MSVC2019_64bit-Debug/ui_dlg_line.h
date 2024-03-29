/********************************************************************************
** Form generated from reading UI file 'dlg_line.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLG_LINE_H
#define UI_DLG_LINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_dlg_line
{
public:
    QPushButton *btn_save;
    QPushButton *btn_exit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_qno;
    QLineEdit *lineEdit_cno;
    QLineEdit *lineEdit_qnum;

    void setupUi(QDialog *dlg_line)
    {
        if (dlg_line->objectName().isEmpty())
            dlg_line->setObjectName("dlg_line");
        dlg_line->resize(399, 275);
        btn_save = new QPushButton(dlg_line);
        btn_save->setObjectName("btn_save");
        btn_save->setGeometry(QRect(60, 210, 93, 29));
        QFont font;
        font.setPointSize(12);
        btn_save->setFont(font);
        btn_exit = new QPushButton(dlg_line);
        btn_exit->setObjectName("btn_exit");
        btn_exit->setGeometry(QRect(240, 210, 93, 29));
        btn_exit->setFont(font);
        label = new QLabel(dlg_line);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 50, 101, 20));
        label->setFont(font);
        label_2 = new QLabel(dlg_line);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 100, 121, 20));
        label_2->setFont(font);
        label_3 = new QLabel(dlg_line);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(80, 150, 69, 20));
        label_3->setFont(font);
        lineEdit_qno = new QLineEdit(dlg_line);
        lineEdit_qno->setObjectName("lineEdit_qno");
        lineEdit_qno->setGeometry(QRect(190, 43, 141, 31));
        lineEdit_cno = new QLineEdit(dlg_line);
        lineEdit_cno->setObjectName("lineEdit_cno");
        lineEdit_cno->setGeometry(QRect(190, 93, 141, 31));
        lineEdit_qnum = new QLineEdit(dlg_line);
        lineEdit_qnum->setObjectName("lineEdit_qnum");
        lineEdit_qnum->setGeometry(QRect(190, 143, 141, 31));

        retranslateUi(dlg_line);

        QMetaObject::connectSlotsByName(dlg_line);
    } // setupUi

    void retranslateUi(QDialog *dlg_line)
    {
        dlg_line->setWindowTitle(QCoreApplication::translate("dlg_line", "Dialog", nullptr));
        btn_save->setText(QCoreApplication::translate("dlg_line", "\344\277\235\345\255\230", nullptr));
        btn_exit->setText(QCoreApplication::translate("dlg_line", "\345\217\226\346\266\210", nullptr));
        label->setText(QCoreApplication::translate("dlg_line", "\346\216\222\351\230\237\347\274\226\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("dlg_line", "\345\256\242\346\210\267\347\274\226\345\217\267", nullptr));
        label_3->setText(QCoreApplication::translate("dlg_line", "\344\272\272\346\225\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dlg_line: public Ui_dlg_line {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLG_LINE_H
