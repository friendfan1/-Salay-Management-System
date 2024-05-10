/********************************************************************************
** Form generated from reading UI file 'dlg_adddish.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLG_ADDDISH_H
#define UI_DLG_ADDDISH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dlg_addDish
{
public:
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *le_name;
    QLineEdit *le_type;
    QLineEdit *le_mat;
    QLineEdit *le_price;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_6;
    QLineEdit *le_dis;

    void setupUi(QDialog *Dlg_addDish)
    {
        if (Dlg_addDish->objectName().isEmpty())
            Dlg_addDish->setObjectName("Dlg_addDish");
        Dlg_addDish->resize(326, 349);
        label_2 = new QLabel(Dlg_addDish);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 90, 69, 20));
        QFont font;
        font.setPointSize(10);
        label_2->setFont(font);
        label_3 = new QLabel(Dlg_addDish);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 130, 69, 20));
        label_3->setFont(font);
        label_4 = new QLabel(Dlg_addDish);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(50, 170, 69, 20));
        label_4->setFont(font);
        label_5 = new QLabel(Dlg_addDish);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(50, 210, 69, 20));
        label_5->setFont(font);
        le_name = new QLineEdit(Dlg_addDish);
        le_name->setObjectName("le_name");
        le_name->setGeometry(QRect(100, 90, 181, 21));
        le_type = new QLineEdit(Dlg_addDish);
        le_type->setObjectName("le_type");
        le_type->setGeometry(QRect(100, 130, 181, 21));
        le_mat = new QLineEdit(Dlg_addDish);
        le_mat->setObjectName("le_mat");
        le_mat->setGeometry(QRect(100, 170, 181, 21));
        le_price = new QLineEdit(Dlg_addDish);
        le_price->setObjectName("le_price");
        le_price->setGeometry(QRect(100, 210, 181, 21));
        pushButton = new QPushButton(Dlg_addDish);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(50, 300, 93, 29));
        pushButton_2 = new QPushButton(Dlg_addDish);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(190, 300, 93, 29));
        label_6 = new QLabel(Dlg_addDish);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(50, 250, 69, 20));
        label_6->setFont(font);
        le_dis = new QLineEdit(Dlg_addDish);
        le_dis->setObjectName("le_dis");
        le_dis->setGeometry(QRect(100, 250, 181, 21));

        retranslateUi(Dlg_addDish);

        QMetaObject::connectSlotsByName(Dlg_addDish);
    } // setupUi

    void retranslateUi(QDialog *Dlg_addDish)
    {
        Dlg_addDish->setWindowTitle(QCoreApplication::translate("Dlg_addDish", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("Dlg_addDish", "\345\220\215\347\247\260", nullptr));
        label_3->setText(QCoreApplication::translate("Dlg_addDish", "\347\261\273\345\210\253", nullptr));
        label_4->setText(QCoreApplication::translate("Dlg_addDish", "\346\235\220\346\226\231", nullptr));
        label_5->setText(QCoreApplication::translate("Dlg_addDish", "\344\273\267\346\240\274", nullptr));
        pushButton->setText(QCoreApplication::translate("Dlg_addDish", "\344\277\235\345\255\230", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Dlg_addDish", "\345\217\226\346\266\210", nullptr));
        label_6->setText(QCoreApplication::translate("Dlg_addDish", "\346\212\230\346\211\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dlg_addDish: public Ui_Dlg_addDish {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLG_ADDDISH_H
