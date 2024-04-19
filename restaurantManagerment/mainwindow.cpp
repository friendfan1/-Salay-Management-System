#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_dlgLogin.show(); //阻塞一下
    //this->hide(); //隐藏主界面
    // auto f = [&](){
    //     this->show();
    // };
    connect(&m_dlgLogin,&Page_Login::sendLoginSuccess,this,&MainWindow::show);  //收到发送成功，自动跳到主界面
//    ui->treeWidget->clear(); //我
//    ui->treeWidget->setColumnCount(1); //设置列数

//    QStringList l;
//    l<<"业务服务";
//    QTreeWidgetItem *pf = new QTreeWidgetItem(ui->treeWidget,l);
//    ui->treeWidget->addTopLevelItem(pf); //设置选项

//    l.clear();
//    l<<"菜品管理";
//    QTreeWidgetItem *p1 = new QTreeWidgetItem(pf,l);

//    l.clear();
//    l<<"餐桌管理";
//    QTreeWidgetItem *p2 = new QTreeWidgetItem(pf,l);

//    l.clear();
//    l<<"点菜";
//    QTreeWidgetItem *p3 = new QTreeWidgetItem(pf,l);

//    l.clear();
//    l<<"排座";
//    QTreeWidgetItem *p4 = new QTreeWidgetItem(pf,l);

//    l.clear();
//    l<<"排队";
//    QTreeWidgetItem *p5 = new QTreeWidgetItem(pf,l);

//    l.clear();
//    l<<"收银";
//    QTreeWidgetItem *p6 = new QTreeWidgetItem(pf,l);

//    pf->addChild(p1);
//    pf->addChild(p2);
//    pf->addChild(p3);
//    pf->addChild(p4);
//    pf->addChild(p5);
//    pf->addChild(p6);
//    ui->treeWidget->expandAll(); //默认展开目录

    m_ptrmenusql = menusql::getinstance();

//    //显示表格内容
//    QList<dishInfo> ldishes = m_ptrmenusql->getAllDish();
//    ui ->tableWidget ->setRowCount(ldishes.size());
//    for(int i = 0;i<ldishes.size();i++){
//        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(ldishes[i].id )));
//        ui->tableWidget->setItem(i,1,new QTableWidgetItem(ldishes[i].name ));
//        ui->tableWidget->setItem(i,2,new QTableWidgetItem(ldishes[i].type ));
//        ui->tableWidget->setItem(i,3,new QTableWidgetItem(ldishes[i].material ));
//        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(ldishes[i].price )));
//    }
    updateTable();
    updateTable2();
    updateTable_order();
    updateTable_cashier();
    ui->stackedWidget->setCurrentIndex(4);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_exit_clicked()
{
    exit(0);
}

//增加菜品
void MainWindow::on_btn_addDish_clicked()
{
    m_dlgAdddish.setType(true);
    m_dlgAdddish.exec();    //显示添加菜品界面并阻塞（禁止其他界面操作）
    updateTable();
}

//更新菜品表格
void MainWindow::updateTable()
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(5);
    QStringList l;
    l<<"菜名"<<"价格"<<"折扣"<<"原料"<<"类型";
    ui->tableWidget->setHorizontalHeaderLabels(l);

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); // 只选中行
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //显示表格内容
    QList<dishInfo> ldishes = m_ptrmenusql->getAllDish();
    ui ->tableWidget ->setRowCount(ldishes.size());
    for(int i = 0;i<ldishes.size();i++){
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(ldishes[i].name));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(ldishes[i].price)));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(ldishes[i].discount)));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(ldishes[i].material ));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(ldishes[i].type));
    }
}

//更新餐桌表格
void MainWindow::updateTable2()
{
    ui->tableWidget_2->clear();
    ui->tableWidget_2->setColumnCount(3);
    QStringList l;
    l<<"餐桌序号"<<"餐桌容量"<<"餐桌状态";
    ui->tableWidget_2->setHorizontalHeaderLabels(l);

    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows); // 只选中行
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //显示表格内容
    QList<tableInfo> ltables = m_ptrmenusql->getAlltable();
    ui ->tableWidget_2 ->setRowCount(ltables.size());
    for(int i = 0;i<ltables.size();i++){
        ui->tableWidget_2->setItem(i,0,new QTableWidgetItem(ltables[i].id ));
        ui->tableWidget_2->setItem(i,1,new QTableWidgetItem(QString::number(ltables[i].capacity)));
        ui->tableWidget_2->setItem(i,2,new QTableWidgetItem(ltables[i].status ));
    }
}


void MainWindow::updateTable_order(){
    ui->tableWidget_3->clear();
    ui->tableWidget_3->setColumnCount(6);
    QStringList l;
    l<<"桌号"<<"菜名"<<"日期"<<"时间"<<"点菜编号"<<"状态";
    ui->tableWidget_3->setHorizontalHeaderLabels(l);

    ui->tableWidget_3->setSelectionBehavior(QAbstractItemView::SelectRows); // 只选中行
    ui->tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //显示表格内容
    QList<orderInfo> lorders = m_ptrmenusql->getAllOrders();
    ui ->tableWidget_3 ->setRowCount(lorders.size());
    for(int i = 0;i<lorders.size();i++){
        ui->tableWidget_3->setItem(i,0,new QTableWidgetItem(lorders[i].tableid ));
        ui->tableWidget_3->setItem(i,1,new QTableWidgetItem(lorders[i].dishname));
        ui->tableWidget_3->setItem(i,2,new QTableWidgetItem(lorders[i].date ));
        ui->tableWidget_3->setItem(i,3,new QTableWidgetItem(lorders[i].time ));
        ui->tableWidget_3->setItem(i,4,new QTableWidgetItem(lorders[i].orderid ));
        ui->tableWidget_3->setItem(i,5,new QTableWidgetItem(lorders[i].status ));
    }
}

void MainWindow::updateTable_cashier(){
    ui->tableWidget_4->clear();
    ui->tableWidget_4->setColumnCount(3);
    QStringList l;
    l<<"餐桌序号"<<"餐桌容量"<<"餐桌状态";
    ui->tableWidget_4->setHorizontalHeaderLabels(l);

    ui->tableWidget_4->setSelectionBehavior(QAbstractItemView::SelectRows); // 只选中行
    ui->tableWidget_4->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //显示表格内容
    QList<tableInfo> ltables = m_ptrmenusql->getAllUsedTables();
    ui ->tableWidget_4 ->setRowCount(ltables.size());
    for(int i = 0;i<ltables.size();i++){
        ui->tableWidget_4->setItem(i,0,new QTableWidgetItem(ltables[i].id ));
        ui->tableWidget_4->setItem(i,1,new QTableWidgetItem(QString::number(ltables[i].capacity)));
        ui->tableWidget_4->setItem(i,2,new QTableWidgetItem(ltables[i].status ));
    }
}

//删除菜品
void MainWindow::on_btn_delDish_clicked()
{
    int i = ui->tableWidget->currentRow();
    qDebug()<<i;
    if(i >= 0){
        //int id = ui->tableWidget->item(i,1)->text().toUInt(); //有问题 无法正常获取id
        QString name=ui->tableWidget->item(i,0)->text();
        qDebug()<<name;
        m_ptrmenusql->delDish(name); //直接用行号代替了id  要求id务必和行号相同
        updateTable();
        QMessageBox::information(nullptr,"信息","删除成功");
    }
}

//更新菜品
void MainWindow::on_btn_updDish_clicked()
{
    dishInfo info;
    int i = ui->tableWidget->currentRow();
    if(i>=0){
        info.name = ui->tableWidget->item(i,0)->text();
        info.type = ui->tableWidget->item(i,4)->text();
        info.material = ui->tableWidget->item(i,3)->text();
        info.price = ui->tableWidget->item(i,1)->text().toFloat();
        info.discount=ui->tableWidget->item(i,2)->text().toFloat();
        m_dlgAdddish.setType(false,info);
        m_dlgAdddish.exec();
        updateTable();
    }
}




void MainWindow::on_btn_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_btn_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_btn_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_btn_cashier_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

//增加餐桌
void MainWindow::on_btn_addTable_clicked()
{
    m_dlgAddtable.setType(true);
    m_dlgAddtable.exec();    //显示添加菜品界面并阻塞（禁止其他界面操作）
    updateTable2();
}

//修改餐桌
void MainWindow::on_btn_updTable_clicked()
{
    tableInfo info;
    int i = ui->tableWidget_2->currentRow();
    if(i>=0){
        info.id = ui->tableWidget_2->item(i,0)->text();
        info.capacity = ui->tableWidget_2->item(i,1)->text().toUInt();
        info.status = ui->tableWidget_2->item(i,2)->text();
        m_dlgAddtable.setType(false,info);
        m_dlgAddtable.exec();
        updateTable2();
    }
}

//删除餐桌
void MainWindow::on_btn_delTable_clicked()
{
    int i = ui->tableWidget_2->currentRow();
    qDebug()<<i;
    if(i > 0){
        QString id = ui->tableWidget_2->item(i,0)->text();
        //int id=i+1;
        qDebug()<<id;
        m_ptrmenusql->delTable(id); //直接用行号代替了id  要求id务必和行号相同
        updateTable2();
        QMessageBox::information(nullptr,"信息","删除成功");
    }
}


void MainWindow::on_btn_queue_clicked()
{
    m_dlgQueue.exec();
}


//搜索菜品
void MainWindow::on_btn_search_clicked()
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(5);
    QStringList l;
    l<<"菜名"<<"价格"<<"折扣"<<"原料"<<"类型";
    ui->tableWidget->setHorizontalHeaderLabels(l);

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); // 只选中行
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //显示表格内容
    QList<dishInfo> ldishes = m_ptrmenusql->getAllDish();
    ui ->tableWidget ->setRowCount(ldishes.size());

    QString strFiter = ui->lineEdit_search->text();
    int index = 0;
    for(int i = 0;i<ldishes.size();i++){
        if(!ldishes[i].name.contains(strFiter)){
            continue;
        }
        ui->tableWidget->setItem(index,0,new QTableWidgetItem(ldishes[i].name));
        ui->tableWidget->setItem(index,1,new QTableWidgetItem(QString::number(ldishes[i].price)));
        ui->tableWidget->setItem(index,2,new QTableWidgetItem(QString::number(ldishes[i].discount)));
        ui->tableWidget->setItem(index,3,new QTableWidgetItem(ldishes[i].material ));
        ui->tableWidget->setItem(index,4,new QTableWidgetItem(ldishes[i].type));
        index++;
    }
    for(int i=index;i<ldishes.size();++i)ui->tableWidget->removeRow(index);
}


void MainWindow::on_btn_search2_clicked()
{
    ui->tableWidget_2->clear();
    ui->tableWidget_2->setColumnCount(3);
    QStringList l;
    l<<"餐桌序号"<<"餐桌容量"<<"餐桌状态";
    ui->tableWidget_2->setHorizontalHeaderLabels(l);

    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows); // 只选中行
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //显示表格内容
    QList<tableInfo> ltables = m_ptrmenusql->getAlltable();

    ui ->tableWidget_2 ->setRowCount(ltables.size());
    QString strFiter = ui->lineEdit_search2->text();
    int index = 0;
    for(int i = 0;i<ltables.size();i++){
        if(!ltables[i].id.contains(strFiter)){
            continue;
        }
        ui->tableWidget_2->setItem(index,0,new QTableWidgetItem(ltables[i].id ));
        ui->tableWidget_2->setItem(index,1,new QTableWidgetItem(QString::number(ltables[i].capacity)));
        ui->tableWidget_2->setItem(index,2,new QTableWidgetItem(ltables[i].status ));
        index++;
    }for(int i=index;i<ltables.size();++i)ui ->tableWidget_2 ->removeRow(index);
}


void MainWindow::on_btn_refresh_order_clicked()
{
    updateTable_order();
}


void MainWindow::on_btn_serve_dish_clicked()
{
    int row = ui->tableWidget_3->currentRow();
    qDebug()<<row;
    if(row >= 0){
        if(ui->tableWidget_3->item(row,5)->text()=="已上菜")return;
        QString orderid=ui->tableWidget_3->item(row,4)->text();
        QString date=ui->tableWidget_3->item(row,2)->text();
        qDebug()<<orderid;
        m_ptrmenusql->serveOrder(orderid,date);
        QMessageBox::information(nullptr,"信息","上菜成功");
        updateTable_order();
    }
}


void MainWindow::on_btn_cancel_order_clicked()
{
    int row = ui->tableWidget_3->currentRow();
    qDebug()<<row;
    if(row >= 0){
        if(ui->tableWidget_3->item(row,5)->text()=="已上菜")return;
        QString orderid=ui->tableWidget_3->item(row,4)->text();
        QString date=ui->tableWidget_3->item(row,2)->text();
        qDebug()<<orderid;
        m_ptrmenusql->cancelOrder(orderid,date);
        QMessageBox::information(nullptr,"信息","取消成功");
        updateTable_order();
    }
}



void MainWindow::on_btn_menu_refresh_clicked()
{
    updateTable();
}


void MainWindow::on_btn_table_refresh_clicked()
{
    updateTable2();
}


void MainWindow::on_btn_previous_order_clicked()
{
    ui->tableWidget_3->clear();
    ui->tableWidget_3->setColumnCount(6);
    QStringList l;
    l<<"桌号"<<"菜名"<<"日期"<<"时间"<<"点菜编号"<<"状态";
    ui->tableWidget_3->setHorizontalHeaderLabels(l);

    ui->tableWidget_3->setSelectionBehavior(QAbstractItemView::SelectRows); // 只选中行
    ui->tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //显示表格内容
    QList<orderInfo> lorders = m_ptrmenusql->getPreviousOrders();
    ui ->tableWidget_3 ->setRowCount(lorders.size());
    for(int i = 0;i<lorders.size();i++){
        ui->tableWidget_3->setItem(i,0,new QTableWidgetItem(lorders[i].tableid ));
        ui->tableWidget_3->setItem(i,1,new QTableWidgetItem(lorders[i].dishname));
        ui->tableWidget_3->setItem(i,2,new QTableWidgetItem(lorders[i].date ));
        ui->tableWidget_3->setItem(i,3,new QTableWidgetItem(lorders[i].time ));
        ui->tableWidget_3->setItem(i,4,new QTableWidgetItem(lorders[i].orderid ));
        ui->tableWidget_3->setItem(i,5,new QTableWidgetItem(lorders[i].status ));
    }
}

void MainWindow::update_ordermenu(){
    ui->tableWidget_ordermenu->clear();
    ui->tableWidget_ordermenu->setColumnCount(3);
    QStringList l;
    l<<"菜名"<<"价格"<<"类型";
    ui->tableWidget_ordermenu->setHorizontalHeaderLabels(l);
    ui->tableWidget_ordermenu->setColumnWidth(0, ui->tableWidget_ordermenu->width()/3);
    ui->tableWidget_ordermenu->setColumnWidth(1, ui->tableWidget_ordermenu->width()/3);
    ui->tableWidget_ordermenu->setColumnWidth(2, ui->tableWidget_ordermenu->width()/3-20);

    ui->tableWidget_ordermenu->setSelectionBehavior(QAbstractItemView::SelectRows); // 只选中行
    ui->tableWidget_ordermenu->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //显示表格内容
    QList<dishInfo> ldishes = m_ptrmenusql->getAllDish();
    ui ->tableWidget_ordermenu->setRowCount(ldishes.size());
    for(int i = 0;i<ldishes.size();i++){
        ui->tableWidget_ordermenu->setItem(i,0,new QTableWidgetItem(ldishes[i].name));
        ui->tableWidget_ordermenu->setItem(i,1,new QTableWidgetItem(QString::number(ldishes[i].price)));
        ui->tableWidget_ordermenu->setItem(i,2,new QTableWidgetItem(ldishes[i].type));
    }
}
void MainWindow::update_ordertable(){
    ui->tableWidget_order_table->clear();
    ui->tableWidget_order_table->setColumnCount(3);
    QStringList l;
    l<<"桌号"<<"容量"<<"状态";
    ui->tableWidget_order_table->setHorizontalHeaderLabels(l);
    ui->tableWidget_order_table->setColumnWidth(0, ui->tableWidget_order_table->width()/3);
    ui->tableWidget_order_table->setColumnWidth(1, ui->tableWidget_order_table->width()/3);
    ui->tableWidget_order_table->setColumnWidth(2, ui->tableWidget_order_table->width()/3-20);

    ui->tableWidget_order_table->setSelectionBehavior(QAbstractItemView::SelectRows); // 只选中行
    ui->tableWidget_order_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //显示表格内容
    QList<tableInfo> ltables = m_ptrmenusql->getUsedTable();
    ui ->tableWidget_order_table->setRowCount(ltables.size());
    for(int i = 0;i<ltables.size();i++){
        ui->tableWidget_order_table->setItem(i,0,new QTableWidgetItem(ltables[i].id ));
        ui->tableWidget_order_table->setItem(i,1,new QTableWidgetItem(QString::number(ltables[i].capacity)));
        ui->tableWidget_order_table->setItem(i,2,new QTableWidgetItem(ltables[i].status ));
    }
}

void MainWindow::on_btn_order_menu_clicked()
{
    update_ordermenu();
    update_ordertable();
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_btn_new_order_clicked()
{
    int row_dish = ui->tableWidget_ordermenu->currentRow();
    int row_table = ui->tableWidget_order_table->currentRow();
    if(row_dish>=0&&row_table>=0){
        QString dishname=ui->tableWidget_ordermenu->item(row_dish,0)->text();
        QString tableid=ui->tableWidget_order_table->item(row_table,0)->text();
        auto reply = QMessageBox::question(
            this, "点菜确认", QString("桌号%1 确定要点 %2 吗？").arg(tableid).arg(dishname), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
        if(reply!=QMessageBox::Yes)return;
        m_ptrmenusql->newOrder(dishname,tableid);
        QMessageBox::information(nullptr,"信息","点菜成功");
    }
}

