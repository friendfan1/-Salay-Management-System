#ifndef MENUSQL_H
#define MENUSQL_H

#include <QObject>
#include<QSqlDatabase>
struct dishInfo{
    QString name;//菜名
    float price;//价格
    float discount;//折扣
    QString material;//材料
    QString type;//类型
};
struct userInfo{
    QString account;
    QString password;
};

struct tableInfo{
    QString id;
    int capacity;
    QString status;
};

struct orderInfo{
    QString tableid;
    QString dishname;
    QString date;
    QString time;
    QString orderid;
    QString status;
};

struct queInfo{
    QString qno;
    QString qnum;
    QString qreachtime;
};

class menusql : public QObject
{
    Q_OBJECT
public:
    static menusql *ptrmenuSql;
    static menusql *getinstance(){
        if(nullptr == ptrmenuSql){
            ptrmenuSql = new menusql;
            ptrmenuSql->init();
        }
        return ptrmenuSql;
    }

    //菜品函数
    //1.查看现有菜品信息s
    QList<dishInfo> getAllDish();
    //2.增加研制的新菜品
    bool addDish(dishInfo info);
    //3.删除不方便供应旧菜品
    bool delDish(QString name);
    //4.修改现有菜品信息
    bool updateDish(dishInfo info,QString _name);//NOW UPDATED
    //查看桌号对应的已点的菜品
    QList<dishInfo> getOrderedDish(QString tno);

    //用户函数
    //用户注册（添加用户）
    bool adduser(userInfo info);

    //餐桌函数
    //1.查看餐桌信息
    QList<tableInfo> getAlltable();
    //2.增加餐桌
    bool addTable(tableInfo info);
    //3.修改餐桌
    bool updateTable(tableInfo info, QString id);
    //4.删除不方便供应旧菜品
     bool delTable(QString id);
    //5.获取空闲餐桌
    QList<tableInfo> getFreeTable();
    //获取占用的餐桌
    QList<tableInfo> getUsedTable();

    //获取当日所有订单
    QList<orderInfo> getAllOrders();
    //获取历史订单
    QList<orderInfo> getPreviousOrders();
    //点菜
    void newOrder(QString dishname,QString tableid);
    //上菜
    void serveOrder(QString orderid,QString date);
    //取消点菜
    void cancelOrder(QString orderid,QString date);

    //获取所有餐桌种类
    QList<int> getAllTableType();

    //获取二人桌排队数据
    QList<queInfo> getq1();
    //获取四人桌排队数据
    QList<queInfo> getq2();
    //获取圆桌排队数据
    QList<queInfo> getq3();

    int getCapNeed(QString cno);
    //获取客人需要的座位数

    //增加排队数据
    bool addLine(int num,int table_cap);
    //入座时修改排队信息修改餐桌状态
    void updateLine(tableInfo infot,queInfo infoq);
    //删除排队记录
    bool delLine(QString qno);
    //上桌用餐
    void quickTakeSeat(QString tno,QString cap);
    void takeSeat(QString cno,QString tno);

    bool checkout(QString tno,QString method);

signals:
private:
    //单例模式，构造函数私有化
    void init();
    explicit menusql(QObject *parent = nullptr);
    QSqlDatabase m_db;  //声明QSqlDatabase的成员变量
};

#endif // MENUSQL_H
