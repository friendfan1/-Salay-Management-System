/********************************************************************************
** Form generated from reading UI file 'page_login.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE_LOGIN_H
#define UI_PAGE_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Page_Login
{
public:
    QLineEdit *le_userID;
    QLineEdit *le_password;
    QPushButton *btn_login;
    QPushButton *btn_exit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *Page_Login)
    {
        if (Page_Login->objectName().isEmpty())
            Page_Login->setObjectName("Page_Login");
        Page_Login->resize(400, 240);
        Page_Login->setMinimumSize(QSize(400, 240));
        Page_Login->setMaximumSize(QSize(400, 240));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Logo.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Page_Login->setWindowIcon(icon);
        le_userID = new QLineEdit(Page_Login);
        le_userID->setObjectName("le_userID");
        le_userID->setGeometry(QRect(140, 70, 201, 31));
        le_userID->setMaxLength(8);
        le_password = new QLineEdit(Page_Login);
        le_password->setObjectName("le_password");
        le_password->setGeometry(QRect(140, 120, 201, 31));
        le_password->setMaxLength(8);
        le_password->setEchoMode(QLineEdit::Password);
        btn_login = new QPushButton(Page_Login);
        btn_login->setObjectName("btn_login");
        btn_login->setGeometry(QRect(80, 180, 93, 29));
        btn_exit = new QPushButton(Page_Login);
        btn_exit->setObjectName("btn_exit");
        btn_exit->setGeometry(QRect(240, 180, 93, 29));
        label = new QLabel(Page_Login);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 70, 71, 31));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);
        label_2 = new QLabel(Page_Login);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 120, 61, 31));
        label_2->setFont(font);
        label_3 = new QLabel(Page_Login);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(90, 0, 231, 61));
        QFont font1;
        font1.setPointSize(16);
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);

        retranslateUi(Page_Login);

        QMetaObject::connectSlotsByName(Page_Login);
    } // setupUi

    void retranslateUi(QWidget *Page_Login)
    {
        Page_Login->setWindowTitle(QCoreApplication::translate("Page_Login", "\347\231\273\345\275\225", nullptr));
#if QT_CONFIG(tooltip)
        Page_Login->setToolTip(QCoreApplication::translate("Page_Login", "\350\277\231\346\230\257\347\231\273\345\275\225\347\252\227\345\217\243", nullptr));
#endif // QT_CONFIG(tooltip)
        le_userID->setPlaceholderText(QCoreApplication::translate("Page_Login", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", nullptr));
        le_password->setText(QString());
        le_password->setPlaceholderText(QCoreApplication::translate("Page_Login", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        btn_login->setText(QCoreApplication::translate("Page_Login", "\347\231\273\345\275\225", nullptr));
        btn_exit->setText(QCoreApplication::translate("Page_Login", "\351\200\200\345\207\272", nullptr));
        label->setText(QCoreApplication::translate("Page_Login", "\350\264\246\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("Page_Login", "\345\257\206   \347\240\201", nullptr));
        label_3->setText(QCoreApplication::translate("Page_Login", "\351\244\220\345\216\205\344\277\241\346\201\257\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Page_Login: public Ui_Page_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE_LOGIN_H
