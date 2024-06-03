/********************************************************************************
** Form generated from reading UI file 'dlg_addtable.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLG_ADDTABLE_H
#define UI_DLG_ADDTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_dlg_addTable
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *btn_save;
    QPushButton *btn_cancel;
    QLineEdit *lineEdit_id;
    QLineEdit *lineEdit_cap;
    QLineEdit *lineEdit_status;

    void setupUi(QDialog *dlg_addTable)
    {
        if (dlg_addTable->objectName().isEmpty())
            dlg_addTable->setObjectName("dlg_addTable");
        dlg_addTable->resize(384, 300);
        label = new QLabel(dlg_addTable);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 40, 81, 31));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label_2 = new QLabel(dlg_addTable);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 100, 91, 31));
        label_2->setFont(font);
        label_3 = new QLabel(dlg_addTable);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 160, 91, 31));
        label_3->setFont(font);
        btn_save = new QPushButton(dlg_addTable);
        btn_save->setObjectName("btn_save");
        btn_save->setGeometry(QRect(60, 220, 93, 29));
        btn_cancel = new QPushButton(dlg_addTable);
        btn_cancel->setObjectName("btn_cancel");
        btn_cancel->setGeometry(QRect(220, 220, 93, 29));
        lineEdit_id = new QLineEdit(dlg_addTable);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setGeometry(QRect(150, 40, 171, 31));
        lineEdit_cap = new QLineEdit(dlg_addTable);
        lineEdit_cap->setObjectName("lineEdit_cap");
        lineEdit_cap->setGeometry(QRect(150, 100, 171, 31));
        lineEdit_status = new QLineEdit(dlg_addTable);
        lineEdit_status->setObjectName("lineEdit_status");
        lineEdit_status->setGeometry(QRect(150, 160, 171, 31));

        retranslateUi(dlg_addTable);

        QMetaObject::connectSlotsByName(dlg_addTable);
    } // setupUi

    void retranslateUi(QDialog *dlg_addTable)
    {
        dlg_addTable->setWindowTitle(QCoreApplication::translate("dlg_addTable", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("dlg_addTable", "\351\244\220\346\241\214\347\274\226\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("dlg_addTable", "\351\244\220\346\241\214\345\256\271\351\207\217", nullptr));
        label_3->setText(QCoreApplication::translate("dlg_addTable", "\351\244\220\346\241\214\347\212\266\346\200\201", nullptr));
        btn_save->setText(QCoreApplication::translate("dlg_addTable", "\344\277\235\345\255\230", nullptr));
        btn_cancel->setText(QCoreApplication::translate("dlg_addTable", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dlg_addTable: public Ui_dlg_addTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLG_ADDTABLE_H
