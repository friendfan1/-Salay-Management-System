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
bool menusql::updateDish(dishInfo info,QString _name)
{
    QSqlQuery sql(m_db);
    QString strSql = QString("update 菜品 set 菜名 = '%1',价格 = %2,折扣 = %3,材料 = '%4',类型 = '%5' where 菜名 = '%6'").
                     arg(info.name).
                     arg(info.price).
                     arg(info.discount).
                     arg(info.material).
                     arg(info.type).
                     arg(_name);
    if(!sql.exec(strSql)){
        qDebug()<<sql.lastError().text();
        return false;
    }else return true;
}


QList<dishInfo> menusql::getOrderedDish(QString tno){
    QSqlQuery sql(m_db);
    bool ok=sql.exec(QString("CALL 查看已点菜('%1')").arg(tno));
    QList<dishInfo> l;
    dishInfo info;
    while(sql.next()){
        info.name = sql.value(0).toString();
        info.price =  sql.value(1).toFloat();
        info.discount = sql.value(2).toFloat();
        l.push_back(info);
    }
    if(!ok)qDebug()<<sql.lastError().text();
    return l;
}

//添加用户 已测
bool menusql::adduser(userInfo info)
{
    QSqlQuery sql(m_db);
    QString strSql = QString("insert into 账户 values('%1','%2')").
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

QList<tableInfo> menusql::getUsedTable(){
    QList<tableInfo> l;
    QSqlQuery sql(m_db);
    sql.exec("select * from 餐桌 where 状态='忙碌'");
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
    if(!sql.exec(strSql)){
        qDebug()<<sql.lastError();
        return false;
    }
    else return true;
}

//修改餐桌
bool menusql::updateTable(tableInfo info,QString id)
{
    QSqlQuery sql(m_db);
    QString strSql = QString("update 餐桌 set 桌号 = '%1',容量 = %2 ,状态 = '%3' where 桌号 = '%4'").
            arg(info.id).
            arg(info.capacity).
            arg(info.status).
            arg(id);
    if(!sql.exec(strSql)){
        qDebug()<<sql.lastError();
        return false;
    }
    else return true;
}

//删除餐桌
bool menusql::delTable(QString id)
{
    QSqlQuery sql(m_db);
    return sql.exec(QString("delete from 餐桌 where 桌号 = '%1' ").arg(id));
}

QList<tableInfo> menusql::getFreeTable()
{
    QList<tableInfo> l;
    QSqlQuery sql(m_db);
    sql.exec("select * from 餐桌 where 状态 = '空闲' order by 容量 desc");
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

//获取二人桌排队数据
QList<queInfo> menusql::getq1()
{
    QList<queInfo> l;
    QSqlQuery sql(m_db);
    bool ok=sql.exec("select 编号,人数,排队时间 from 来客 where 入座时间 is null and 日期=curdate() and 座位数要求=2 order by 排队时间 asc");
    queInfo info;
    while(sql.next()){
        info.qno = sql.value(0).toString();
        info.qnum = sql.value(1).toString();
        info.qreachtime=sql.value(2).toString();
        l.push_back(info);
    }
    if(!ok)qDebug()<<sql.lastError().text();
    return l;
}

//获取四人桌排队数据
QList<queInfo> menusql::getq2()
{
    QList<queInfo> l;
    QSqlQuery sql(m_db);
    bool ok=sql.exec("select 编号,人数,排队时间 from 来客 where 入座时间 is null and 日期=curdate() and 座位数要求=4 order by 排队时间 asc");
    queInfo info;
    while(sql.next()){
        info.qno = sql.value(0).toString();
        info.qnum = sql.value(1).toString();
        info.qreachtime=sql.value(2).toString();
        l.push_back(info);
    }
    if(!ok)qDebug()<<sql.lastError().text();
    return l;
}

//获取圆桌排队数据
QList<queInfo> menusql::getq3()
{
    QList<queInfo> l;
    QSqlQuery sql(m_db);
    bool ok=sql.exec("select 编号,人数,排队时间 from 来客 where 入座时间 is null and 日期=curdate() and 座位数要求=8 order by 排队时间 asc");
    queInfo info;
    while(sql.next()){
        info.qno = sql.value(0).toString();
        info.qnum = sql.value(1).toString();
        info.qreachtime=sql.value(2).toString();
        l.push_back(info);
    }
    if(!ok)qDebug()<<sql.lastError().text();
    return l;
}

//增加排队数据 已测
bool menusql::addLine(int num,int table_cap)
{
    QSqlQuery sql(m_db);
    QString strSql = QString("CALL 客人到来(%1,%2)").arg(num).arg(table_cap);
    bool ok=sql.exec(strSql);
    if(!ok)qDebug()<<sql.lastError().text();
    return ok;
}

//删除排队记录
bool menusql::delLine(QString qno)
{
    QSqlQuery sql(m_db);
    bool ok = sql.exec(QString("delete from 来客 where 编号 = '%1' and 日期=curdate()").arg(qno));
    if(!ok)qDebug()<<sql.lastError().text();
    return ok;
}


//获取4人桌排队信息

//获取圆桌排队信息


QList<orderInfo> menusql::getAllOrders(){
    QList<orderInfo> l;
    QSqlQuery sql(m_db);
    sql.exec("CALL 查看未上菜()");
    orderInfo info;
    while(sql.next()){
        info.tableid = sql.value(0).toString();
        info.dishname = sql.value(1).toString();
        info.date = sql.value(2).toString();
        info.time = sql.value(3).toString();
        info.orderid = sql.value(4).toString();
        info.status = sql.value(5).toString();
        l.push_back(info);
    }
    if(!sql.last())qDebug()<<sql.lastError().text();
    return l;
}

QList<orderInfo> menusql::getPreviousOrders(){
    QList<orderInfo> l;
    QSqlQuery sql(m_db);
    sql.exec("CALL 查看已上菜()");
    orderInfo info;
    while(sql.next()){
        info.tableid = sql.value(0).toString();
        info.dishname = sql.value(1).toString();
        info.date = sql.value(2).toString();
        info.time = sql.value(3).toString();
        info.orderid = sql.value(4).toString();
        info.status = sql.value(5).toString();
        l.push_back(info);
    }
    if(!sql.last())qDebug()<<sql.lastError().text();
    return l;
}

void menusql::serveOrder(QString orderid,QString date){
    QSqlQuery sql(m_db);
    QString str=QString("CALL 上菜(%1 , '%2')").arg(orderid).arg(date);
    sql.exec(str);
    if(!sql.last())qDebug()<<sql.lastError().text();
}
void menusql::cancelOrder(QString orderid,QString date){
    QSqlQuery sql(m_db);
    QString str=QString("CALL 取消点餐(%1 , '%2')").arg(orderid).arg(date);
    sql.exec(str);
    if(!sql.last())qDebug()<<sql.lastError().text();
}

void menusql::newOrder(QString dishname,QString tableid){
    QSqlQuery sql(m_db);
    QString str=QString("CALL 点菜('%1' , '%2')").arg(tableid).arg(dishname);
    sql.exec(str);
    if(!sql.last())qDebug()<<sql.lastError().text();
}


QList<int> menusql::getAllTableType(){
    QSqlQuery sql(m_db);
    QString str="SELECT 容量 FROM 餐桌 GROUP BY 容量";
    sql.exec(str);
    QList<int> res{};
    while(sql.next()){
        res.append(sql.value(0).toInt());
    }
    if(!sql.last())qDebug()<<sql.lastError().text();
    return res;
}

void menusql::quickTakeSeat(QString tno,QString cap){
    QSqlQuery sql(m_db);
    QString str=QString("select 编号 from 来客 where 日期=curdate() and 座位数要求=%1 and 入座时间 is null order by 排队时间 asc limit 1")
                      .arg(cap);
    if(!sql.exec(str))qDebug()<<sql.lastError().text();
    QString cno;
    if(sql.next()){
        cno=sql.value(0).toString();
        str=QString("CALL 客人上桌(%1,'%2')").arg(cno).arg(tno);
        if(!sql.exec(str))qDebug()<<sql.lastError().text();
        else QMessageBox::information(nullptr,"消息",QString("入座成功! 请%1号客人前往%2餐桌用餐!").arg(cno).arg(tno));
    }else{
        QMessageBox::warning(nullptr,"错误","此类型餐桌暂无正在排队的客人。");
    }
}

void menusql::takeSeat(QString cno,QString tno){
    bool ok;
    if(cno.toInt(&ok)<0||!ok){
        QMessageBox::warning(nullptr,"错误","请选择要入座的客人。");
        return;
    }
    QSqlQuery sql(m_db);
    QString str=QString("CALL 客人上桌(%1,'%2')").arg(cno).arg(tno);
    if(!sql.exec(str))qDebug()<<sql.lastError().text();
    else QMessageBox::information(nullptr,"消息",QString("入座成功! 请%1号客人前往%2餐桌用餐!").arg(cno).arg(tno));
}

bool menusql::checkout(QString tno,QString method){
    QSqlQuery sql(m_db);
    QString str=QString("CALL 结账('%1','%2')").arg(tno).arg(method);
    bool ok=sql.exec(str);
    if(!ok){
        qDebug()<<sql.lastError().text();
        return false;
    }
    else return true;
}


int menusql::getCapNeed(QString cno){
    QSqlQuery sql(m_db);
    QString str=QString("SELECT 座位数要求 FROM 来客 WHERE 编号=%1 AND 日期=CURDATE()").arg(cno);
    bool ok=sql.exec(str);
    if(!ok){
        qDebug()<<sql.lastError().text();
        return -1;
    }
    else {
        sql.next();
        return sql.value(0).toInt();
    }
}
