#include "menusql.h"
#include<QMessageBox>
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery> //sql查询语句
#include<QtDebug>
#include<QCoreApplication> // 用于获取数据库文件路径
#include<QTime>
menusql * menusql::ptrmenuSql = nullptr;
menusql::menusql(QObject *parent)
    : QObject{parent}
{
    //连接数据库
    //init();

//    //添加新菜品
//    dishInfo d;
//    d.id=3;
//    d.name="剁椒鱼头";
//    addDish(d);

//    //删除不方便供应旧菜品
//    QString name = "剁椒鱼头";
//    delDish(8);

//    //修改现有菜品信息（信息得写全）
//    dishInfo d;
//    d.id=2;
//    d.type="强推";
//    updateDish(d);

    //查看现有菜品信息
    //auto l = getAllDish();
    //QSqlQuery q("", db);
    //q.exec("INSERT INTO menu VALUES (3, '土豆炖牛肉', '招牌', '土豆、牛肉、葱姜蒜等', 49)");

//    //添加用户
//    userInfo u;
//    u.account="555555";
//    u.password="666666";
//    adduser(u);
    //auto q = getq1();
//    QTime time = QTime::currentTime(); //获取系统时间
//    queInfo q;
//    q.qno="005";
//    q.qcno = "006";
//    q.qnum = 8;
//    q.qontime = time.toString("hh:mm:ss");;
//    qDebug() << time.toString("hh:mm:ss");
//    addLine(q);
}

void menusql::init()
{
    if (QSqlDatabase::drivers().isEmpty())
        qDebug()<<"No database drivers found";

    //连接数据库
    m_db = QSqlDatabase::addDatabase("QODBC"); //建立连接
    m_db.setHostName("mycgck.mysql.database.azure.com");  //连接本地主机
    m_db.setPort(3306);
    m_db.setDatabaseName("my_restaurant");
    m_db.setUserName("swjtuAdmin");
    m_db.setPassword("77597759Abc");
    bool ok =m_db.open();
    if(ok)qDebug()<<"\n\nopen success!\n\n";
    else qDebug()<<m_db.lastError().text();


/*
    auto str = QCoreApplication::applicationDirPath()+"data.db"; //获取数据库文件路径
    qDebug()<<str; //输出
*/
    // m_db.setDatabaseName("../data.db");   //关联数据库
    // if(!m_db.open())                          //打开数据库
    //     qDebug()<<"database open failed";
}

//显示菜品信息 已测
//NOW UPDATED
QList<dishInfo> menusql::getAllDish()
{
    QList<dishInfo> l;
    QSqlQuery sql(m_db);
    sql.exec("select * from 菜品");
    //sql.exec("select * from dishes");
    dishInfo info;
    while(sql.next()){
        info.name = sql.value(0).toString();
        info.price =  sql.value(1).toFloat();
        info.discount = sql.value(2).toFloat();
        info.material = sql.value(3).toString();
        info.type = sql.value(4).toString();
        l.push_back(info);
    }
    return l;
}

//添加新菜品  已测
bool menusql::addDish(dishInfo info)
{
    QSqlQuery sql(m_db);
    QString strSql = QString("insert into 菜品 values('%1', %2, %3, '%4', '%5')").
            arg(info.name).
            arg(info.price).
            arg(info.discount).
            arg(info.material).
            arg(info.type);
    if(!sql.exec(strSql)){
        qDebug()<<sql.lastError().text();
        return false;
    }return true;
}

//删除不方便供应旧菜品 已测
bool menusql::delDish(QString name)
{
    QSqlQuery sql(m_db);
    QString strSql=QString("delete from 菜品 where 菜名 = '%1' ").arg(name);
    if(!sql.exec(strSql)){
        qDebug()<<sql.lastError().text();
        return false;
    }return true;
}

//修改现有菜品信息 已测
//NOW UPDATED
void menusql::updateDish(dishInfo info,QString _name)
{
    QSqlQuery sql(m_db);
    QString strSql = QString("update 菜品 set 菜名 = '%1',价格 = %2,折扣 = %3,材料 = '%4',类型 = '%5' where 菜名 = '%6'").
                     arg(info.name).
                     arg(info.price).
                     arg(info.discount).
                     arg(info.material).
                     arg(info.type).
                     arg(_name);
    if(!sql.exec(strSql))qDebug()<<sql.lastError().text();
}

//添加用户 已测
bool menusql::adduser(userInfo info)
{
    QSqlQuery sql(m_db);
    QString strSql = QString("insert into user values('%1','%2')").
            arg(info.account).
            arg(info.password);
    qDebug()<<sql.exec(strSql);
    return sql.exec(strSql);
}

//显示餐桌信息
QList<tableInfo> menusql::getAlltable()
{
    QList<tableInfo> l;
    QSqlQuery sql(m_db);
    sql.exec("select * from 餐桌");
    tableInfo info;
    while(sql.next()){
        info.id = sql.value(0).toString();
        info.capacity = sql.value(1).toUInt();
        info.status = sql.value(2).toString();
        l.push_back(info);
    }
    if(!sql.last())qDebug()<<sql.lastError().text();
    return l;
}

//添加餐桌
bool menusql::addTable(tableInfo info)
{
    QSqlQuery sql(m_db);
    QString strSql = QString("insert into 餐桌 values('%1',%2,'%3')").
            arg(info.id).
            arg(info.capacity).
            arg(info.status);
    if(!sql.exec(strSql))qDebug()<<sql.lastError();
    return sql.last();
}

//修改餐桌
void menusql::updateTable(tableInfo info,QString id)
{
    QSqlQuery sql(m_db);
    QString strSql = QString("update 餐桌 set 桌号 = '%1',容量 = %2 ,状态 = '%3' where 桌号 = '%4'").
            arg(info.id).
            arg(info.capacity).
            arg(info.status).
            arg(id);
    if(!sql.exec(strSql))qDebug()<<sql.lastError();
}

//删除餐桌
bool menusql::delTable(QString id)
{
    QSqlQuery sql(m_db);
    return sql.exec(QString("delete from 餐桌 where 桌号 = '%1' ").arg(id));
}

QList<tableInfo> menusql::getFreetable()
{
    QList<tableInfo> l;
    QSqlQuery sql(m_db);
    sql.exec("select * from 餐桌 where 状态 = '空闲'");
    tableInfo info;
    while(sql.next()){
        info.id = sql.value(0).toString();
        info.capacity = sql.value(1).toUInt();
        info.status = sql.value(2).toString();
        l.push_back(info);
    }
    //qDebug()<<sql.exec("select * from tables");
    return l;
}

//获取二人桌排队数据
QList<queInfo> menusql::getq1()
{
    QList<queInfo> l;
    QSqlQuery sql(m_db);
    sql.exec("select * from queues where qstate= '排队中' and qnum <= 2");
    queInfo info;
    while(sql.next()){
        info.qno = sql.value(0).toString();
        info.qcno = sql.value(1).toString();
        info.qnum = sql.value(2).toUInt();
        info.qstate = sql.value(3).toString();
        info.qontime = sql.value(4).toString();
        l.push_back(info);
    }
    qDebug()<<sql.exec("select * from queues where qstate= '排队中' and qnum <= 2");
    return l;
}

//获取四人桌排队数据
QList<queInfo> menusql::getq2()
{
    QList<queInfo> l;
    QSqlQuery sql(m_db);
    sql.exec("select * from queues where qstate= '排队中' and qnum > 2 and qnum <=4");
    queInfo info;
    while(sql.next()){
        info.qno = sql.value(0).toString();
        info.qcno = sql.value(1).toString();
        info.qnum = sql.value(2).toUInt();
        info.qstate = sql.value(3).toString();
        info.qontime = sql.value(4).toString();
        l.push_back(info);
    }
    //qDebug()<<sql.exec("select * from queues where qstate= '排队中' and qnum <= 2");
    return l;
}

//获取圆桌排队数据
QList<queInfo> menusql::getq3()
{
    QList<queInfo> l;
    QSqlQuery sql(m_db);
    sql.exec("select * from queues where qstate= '排队中' and qnum > 4");
    queInfo info;
    while(sql.next()){
        info.qno = sql.value(0).toString();
        info.qcno = sql.value(1).toString();
        info.qnum = sql.value(2).toUInt();
        info.qstate = sql.value(3).toString();
        info.qontime = sql.value(4).toString();
        l.push_back(info);
    }
    //qDebug()<<sql.exec("select * from queues where qstate= '排队中' and qnum <= 2");
    return l;
}

//增加排队数据 已测
bool menusql::addLine(queInfo info)
{
    QSqlQuery sql(m_db);
    QString strSql = QString("insert into queues values ('%1','%2',%3,'%4','%5','%6')").
            arg(info.qno).
            arg(info.qcno).
            arg(info.qnum).
            arg(info.qstate).
            arg(info.qontime).
            arg(info.qofftime);
    qDebug()<<sql.exec(strSql);
    return sql.exec(strSql);
}

//入座时修改排队信息修改餐桌状态
void menusql::updateLine(tableInfo infot, queInfo infoq)
{
    QTime time = QTime::currentTime(); //获取系统时间
    QSqlQuery sql(m_db);
    QString strSql = QString("update queues set qstate = '已处理',qofftime = '%1' where qno = '%2'").
            arg(time.toString("hh:mm:ss")).
            arg(infoq.qno);
    qDebug()<<sql.exec(strSql);

    QString strSql2 = QString("update tables set status = '使用中' where id = '%1'").
            arg(infot.id);
    qDebug()<<sql.exec(strSql2);
}

//删除排队记录
bool menusql::delLine(QString qno)
{
    QSqlQuery sql(m_db);
    return sql.exec(QString("delete from queues where qno = '%1' ").arg(qno));
}


//获取4人桌排队信息

//获取圆桌排队信息


QList<orderInfo> menusql::getAllOrders(){
    return {{"测试桌号","测试菜名","测试时间","测试编号"}};
}

QList<tableInfo> menusql::getAllUsedTables(){
    return {{"测试桌号",8,"使用中"}};
}
