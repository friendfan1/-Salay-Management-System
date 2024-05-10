/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page1;
    QPushButton *btn_addDish;
    QPushButton *btn_updDish;
    QPushButton *btn_delDish;
    QLineEdit *lineEdit_search;
    QPushButton *btn_search;
    QTableWidget *tableWidget;
    QPushButton *btn_menu_refresh;
    QWidget *page_2;
    QTableWidget *tableWidget_2;
    QPushButton *btn_addTable;
    QPushButton *btn_updTable;
    QPushButton *btn_delTable;
    QPushButton *btn_search2;
    QLineEdit *lineEdit_search2;
    QPushButton *btn_table_refresh;
    QWidget *page_3;
    QPushButton *btn_serve_dish;
    QPushButton *btn_refresh_order;
    QPushButton *btn_cancel_order;
    QTableWidget *tableWidget_3;
    QWidget *page_4;
    QPushButton *btn_checkout;
    QTableWidget *tableWidget_4;
    QPushButton *btn_refresh_cashier;
    QWidget *page_empty;
    QWidget *widget;
    QPushButton *btn_exit;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QTreeWidget *treeWidget;
    QPushButton *btn_1;
    QPushButton *btn_2;
    QPushButton *btn_3;
    QPushButton *pushButton_5;
    QPushButton *btn_queue;
    QPushButton *btn_cashier;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 588);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Logo.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("Qwidget#centralwidget{background-color: rgb(48, 95, 143)};"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(130, 60, 651, 641));
        page1 = new QWidget();
        page1->setObjectName("page1");
        btn_addDish = new QPushButton(page1);
        btn_addDish->setObjectName("btn_addDish");
        btn_addDish->setGeometry(QRect(10, 0, 61, 21));
        btn_updDish = new QPushButton(page1);
        btn_updDish->setObjectName("btn_updDish");
        btn_updDish->setGeometry(QRect(80, 0, 61, 21));
        btn_delDish = new QPushButton(page1);
        btn_delDish->setObjectName("btn_delDish");
        btn_delDish->setGeometry(QRect(150, 0, 61, 20));
        lineEdit_search = new QLineEdit(page1);
        lineEdit_search->setObjectName("lineEdit_search");
        lineEdit_search->setGeometry(QRect(440, 0, 113, 21));
        btn_search = new QPushButton(page1);
        btn_search->setObjectName("btn_search");
        btn_search->setGeometry(QRect(570, 0, 71, 21));
        tableWidget = new QTableWidget(page1);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QFont font;
        font.setUnderline(false);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 30, 631, 451));
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        btn_menu_refresh = new QPushButton(page1);
        btn_menu_refresh->setObjectName("btn_menu_refresh");
        btn_menu_refresh->setGeometry(QRect(300, 0, 61, 21));
        stackedWidget->addWidget(page1);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        tableWidget_2 = new QTableWidget(page_2);
        tableWidget_2->setObjectName("tableWidget_2");
        tableWidget_2->setGeometry(QRect(0, 30, 641, 441));
        tableWidget_2->horizontalHeader()->setStretchLastSection(true);
        btn_addTable = new QPushButton(page_2);
        btn_addTable->setObjectName("btn_addTable");
        btn_addTable->setGeometry(QRect(10, 0, 61, 21));
        btn_updTable = new QPushButton(page_2);
        btn_updTable->setObjectName("btn_updTable");
        btn_updTable->setGeometry(QRect(80, 0, 61, 21));
        btn_delTable = new QPushButton(page_2);
        btn_delTable->setObjectName("btn_delTable");
        btn_delTable->setGeometry(QRect(150, 0, 61, 21));
        btn_search2 = new QPushButton(page_2);
        btn_search2->setObjectName("btn_search2");
        btn_search2->setGeometry(QRect(570, 0, 71, 21));
        lineEdit_search2 = new QLineEdit(page_2);
        lineEdit_search2->setObjectName("lineEdit_search2");
        lineEdit_search2->setGeometry(QRect(430, 0, 121, 21));
        btn_table_refresh = new QPushButton(page_2);
        btn_table_refresh->setObjectName("btn_table_refresh");
        btn_table_refresh->setGeometry(QRect(340, 0, 61, 21));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        btn_serve_dish = new QPushButton(page_3);
        btn_serve_dish->setObjectName("btn_serve_dish");
        btn_serve_dish->setGeometry(QRect(370, 0, 92, 28));
        btn_refresh_order = new QPushButton(page_3);
        btn_refresh_order->setObjectName("btn_refresh_order");
        btn_refresh_order->setGeometry(QRect(110, 0, 92, 28));
        btn_cancel_order = new QPushButton(page_3);
        btn_cancel_order->setObjectName("btn_cancel_order");
        btn_cancel_order->setGeometry(QRect(500, 0, 92, 28));
        tableWidget_3 = new QTableWidget(page_3);
        tableWidget_3->setObjectName("tableWidget_3");
        tableWidget_3->setGeometry(QRect(15, 31, 631, 431));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        btn_checkout = new QPushButton(page_4);
        btn_checkout->setObjectName("btn_checkout");
        btn_checkout->setGeometry(QRect(490, 0, 92, 28));
        tableWidget_4 = new QTableWidget(page_4);
        tableWidget_4->setObjectName("tableWidget_4");
        tableWidget_4->setGeometry(QRect(20, 30, 621, 431));
        btn_refresh_cashier = new QPushButton(page_4);
        btn_refresh_cashier->setObjectName("btn_refresh_cashier");
        btn_refresh_cashier->setGeometry(QRect(100, 0, 92, 28));
        stackedWidget->addWidget(page_4);
        page_empty = new QWidget();
        page_empty->setObjectName("page_empty");
        stackedWidget->addWidget(page_empty);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 801, 51));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(48, 95, 143);\n"
"color: rgb(255, 255, 255);"));
        btn_exit = new QPushButton(widget);
        btn_exit->setObjectName("btn_exit");
        btn_exit->setGeometry(QRect(720, 20, 71, 21));
        btn_exit->setStyleSheet(QString::fromUtf8("background-color: rgb(35, 70, 104);\n"
"color: rgb(255, 255, 255);"));
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(650, 20, 61, 20));
        QFont font1;
        font1.setPointSize(11);
        label_3->setFont(font1);
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(610, 20, 31, 31));
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/user.jpg);"));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(320, 0, 221, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Microsoft YaHei UI")});
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setItalic(false);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"Microsoft YaHei UI\";"));
        treeWidget = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setGeometry(QRect(0, 50, 131, 491));
        treeWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(35, 70, 104);\n"
"color: rgb(255, 255, 255);"));
        treeWidget->header()->setVisible(false);
        btn_1 = new QPushButton(centralwidget);
        btn_1->setObjectName("btn_1");
        btn_1->setGeometry(QRect(0, 50, 131, 31));
        btn_1->setStyleSheet(QString::fromUtf8("background-color: rgb(35, 70, 104);\n"
"alternate-background-color: rgb(48, 95, 143);\n"
"border-color: rgb(35, 70, 104);\n"
"color: rgb(255, 255, 255);"));
        btn_2 = new QPushButton(centralwidget);
        btn_2->setObjectName("btn_2");
        btn_2->setGeometry(QRect(0, 80, 131, 31));
        btn_2->setStyleSheet(QString::fromUtf8("background-color: rgb(35, 70, 104);\n"
"border-color: rgb(35, 70, 104);\n"
"color: rgb(255, 255, 255);"));
        btn_3 = new QPushButton(centralwidget);
        btn_3->setObjectName("btn_3");
        btn_3->setGeometry(QRect(0, 110, 131, 31));
        btn_3->setStyleSheet(QString::fromUtf8("background-color: rgb(35, 70, 104);\n"
"border-color: rgb(35, 70, 104);\n"
"color: rgb(255, 255, 255);"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(0, 140, 131, 31));
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: rgb(35, 70, 104);\n"
"border-color: rgb(35, 70, 104);\n"
"color: rgb(255, 255, 255);"));
        btn_queue = new QPushButton(centralwidget);
        btn_queue->setObjectName("btn_queue");
        btn_queue->setGeometry(QRect(0, 170, 131, 31));
        btn_queue->setStyleSheet(QString::fromUtf8("background-color: rgb(35, 70, 104);\n"
"border-color: rgb(35, 70, 104);\n"
"color: rgb(255, 255, 255);"));
        btn_cashier = new QPushButton(centralwidget);
        btn_cashier->setObjectName("btn_cashier");
        btn_cashier->setGeometry(QRect(0, 200, 131, 31));
        btn_cashier->setStyleSheet(QString::fromUtf8("background-color: rgb(35, 70, 104);\n"
"border-color: rgb(35, 70, 104);\n"
"color: rgb(255, 255, 255);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\351\244\220\351\246\206\344\277\241\346\201\257\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
#if QT_CONFIG(tooltip)
        MainWindow->setToolTip(QCoreApplication::translate("MainWindow", "\350\277\231\346\230\257\351\244\220\345\216\205\344\277\241\346\201\257\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_addDish->setText(QCoreApplication::translate("MainWindow", "\345\242\236\345\212\240", nullptr));
        btn_updDish->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271", nullptr));
        btn_delDish->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        btn_search->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\350\217\234\345\223\201\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\345\210\206\347\261\273", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\344\270\273\350\246\201\346\235\220\346\226\231", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "\344\273\267\346\240\274", nullptr));
        btn_menu_refresh->setText(QCoreApplication::translate("MainWindow", "\345\210\267\346\226\260", nullptr));
        btn_addTable->setText(QCoreApplication::translate("MainWindow", "\345\242\236\345\212\240", nullptr));
        btn_updTable->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271", nullptr));
        btn_delTable->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        btn_search2->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
        btn_table_refresh->setText(QCoreApplication::translate("MainWindow", "\345\210\267\346\226\260", nullptr));
        btn_serve_dish->setText(QCoreApplication::translate("MainWindow", "\344\270\212\350\217\234", nullptr));
        btn_refresh_order->setText(QCoreApplication::translate("MainWindow", "\345\210\267\346\226\260", nullptr));
        btn_cancel_order->setText(QCoreApplication::translate("MainWindow", "\345\217\226\346\266\210\347\202\271\350\217\234", nullptr));
        btn_checkout->setText(QCoreApplication::translate("MainWindow", "\347\273\223\350\264\246", nullptr));
        btn_refresh_cashier->setText(QCoreApplication::translate("MainWindow", "\345\210\267\346\226\260", nullptr));
        btn_exit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "admin", nullptr));
        label_2->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "\351\244\220\351\246\206\344\277\241\346\201\257\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        btn_1->setText(QCoreApplication::translate("MainWindow", "\350\217\234\345\223\201\347\256\241\347\220\206", nullptr));
        btn_2->setText(QCoreApplication::translate("MainWindow", "\351\244\220\346\241\214\347\256\241\347\220\206", nullptr));
        btn_3->setText(QCoreApplication::translate("MainWindow", "\347\202\271\350\217\234", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\346\216\222\346\241\214", nullptr));
        btn_queue->setText(QCoreApplication::translate("MainWindow", "\346\216\222\351\230\237", nullptr));
        btn_cashier->setText(QCoreApplication::translate("MainWindow", "\346\224\266\351\223\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
