#include "page_login.h"
#include "ui_page_login.h"
#include "menusql.h"
#include<QMessageBox>
#include<QSqlQuery> //sql查询语句
#include<QSqlError>
Page_Login::Page_Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Page_Login)
{
    ui->setupUi(this);
}

Page_Login::~Page_Login()
{
    delete ui;
}

void Page_Login::on_btn_login_clicked()
{
    menusql::getinstance();
    //获取输入信息
    userInfo info;
    //auto ptr = menusql::getinstance();
    info.account = ui->le_userID->text();
    info.password = ui->le_password->text();
    //数据库查找用户名和密码
<<<<<<< HEAD
=======
    QSqlQuery query;
    QString strSql = QString("select * from 账户 where 账号 = '%1' and 密码 = '%2'").
            arg(info.account).
            arg(info.password);
    //失败则提示
    if(!query.exec(strSql)){
        qDebug()<<query.lastError().text();
        return;
    }
>>>>>>> 59da75d0ba258f52cfc308c99957e53ad349abd3

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("mycgck.mysql.database.azure.com"); // Azure数据库主机名
    db.setDatabaseName("餐馆信息管理系统"); // 数据库名
    db.setUserName("swjtuAdmin"); // 用户名
    db.setPassword("77597759Abc"); // 密码
    db.setPort(3306); // 端口号，默认为3306

    bool ok = db.open();
    if (ok) {
        qDebug() << "Database connected successfully with SSL.";
    } else {
        qDebug() << "Database connection failed with SSL:";
    }

    // QSqlQuery query;
    // QString strSql = QString("select * from user where account = '%1' and password = '%2'").
    //         arg(info.account).
    //         arg(info.password);
    // //失败则提示
    // if(!query.exec(strSql)){
    //     qDebug()<<query.exec(strSql);
    //     return;
    // }

    // //成功进入主界面
    // if(query.next()){
    //     emit sendLoginSuccess(); //进入主界面并发一个消息
    //     this->hide(); //隐藏登录界面
    // }
    // else{
    //      QMessageBox::information(nullptr,"信息","账号或密码错误");
    // }


}


void Page_Login::on_btn_exit_clicked()
{
    exit(0);//退出
}




void Page_Login::on_btn_reg_clicked()
{

    userInfo info;
    auto ptr = menusql::getinstance();
    info.account = ui->le_userID->text();
    info.password = ui->le_password->text();
    ptr->adduser(info);

//    if(m_isAdd){
//        ptr->addDish(info);
//    }
//    else{
//        ptr ->updateDish(info);
//    }
    QMessageBox::information(nullptr,"注册","注册成功");

}

