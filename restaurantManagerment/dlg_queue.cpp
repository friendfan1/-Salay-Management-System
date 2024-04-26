#include "dlg_queue.h"
#include "ui_dlg_queue.h"
#include "QMessageBox"
#include<QSqlQuery> //sql查询语句
#include<QCloseEvent>
dlg_queue::dlg_queue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlg_queue),
    m_dlgSeat(selectedCustomer,this),
    selectedCustomer()
{
    ui->setupUi(this);
    //
    m_ptrmenusq = menusql::getinstance();
    m_dlgSeat.update_queue=[this](){
        updateTable1();
        updateTable2();
        updateTable3();
    };
    // updateTable1();
    // updateTable2();
    // updateTable3();

    // ui->btn_seat->setEnabled(false);
}

dlg_queue::~dlg_queue()
{
    delete ui;
}

void dlg_queue::updateTable1()
{
    ui->tableWidget_1->clear();
    ui->tableWidget_1->setColumnCount(3);
    QStringList l;
    l<<"排队编号"<<"人数"<<"排队时间";
    ui->tableWidget_1->setHorizontalHeaderLabels(l);

    ui->tableWidget_1->setSelectionBehavior(QAbstractItemView::SelectRows); // 只选中行
    ui->tableWidget_1->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //显示表格内容
    QList<queInfo> lq = m_ptrmenusq->getq1();
    ui ->tableWidget_1 ->setRowCount(lq.size());
    for(int i = 0;i<lq.size();i++){
        ui->tableWidget_1->setItem(i,0,new QTableWidgetItem(lq[i].qno));
        ui->tableWidget_1->setItem(i,1,new QTableWidgetItem(lq[i].qnum ));
        ui->tableWidget_1->setItem(i,2,new QTableWidgetItem(lq[i].qreachtime));
    }
}

void dlg_queue::updateTable2()
{
    ui->tableWidget_2->clear();
    ui->tableWidget_2->setColumnCount(3);
    QStringList l;
    l<<"排队编号"<<"人数"<<"排队时间";
    ui->tableWidget_2->setHorizontalHeaderLabels(l);

    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows); // 只选中行
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //显示表格内容
    QList<queInfo> lq = m_ptrmenusq->getq2();
    ui ->tableWidget_2 ->setRowCount(lq.size());
    for(int i = 0;i<lq.size();i++){
        ui->tableWidget_2->setItem(i,0,new QTableWidgetItem(lq[i].qno));
        ui->tableWidget_2->setItem(i,1,new QTableWidgetItem(lq[i].qnum ));
        ui->tableWidget_2->setItem(i,2,new QTableWidgetItem(lq[i].qreachtime));
    }
}

void dlg_queue::updateTable3()
{
    ui->tableWidget_3->clear();
    ui->tableWidget_3->setColumnCount(3);
    QStringList l;
    l<<"排队编号"<<"人数"<<"排队时间";
    ui->tableWidget_3->setHorizontalHeaderLabels(l);

    ui->tableWidget_3->setSelectionBehavior(QAbstractItemView::SelectRows); // 只选中行
    ui->tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //显示表格内容
    QList<queInfo> lq = m_ptrmenusq->getq3();
    ui ->tableWidget_3 ->setRowCount(lq.size());
    for(int i = 0;i<lq.size();i++){
        ui->tableWidget_3->setItem(i,0,new QTableWidgetItem(lq[i].qno));
        ui->tableWidget_3->setItem(i,1,new QTableWidgetItem(lq[i].qnum ));
        ui->tableWidget_3->setItem(i,2,new QTableWidgetItem(lq[i].qreachtime));
    }
}






void dlg_queue::on_pushButton_clicked()
{
    m_dlgLine.refreshDlg();
    m_dlgLine.exec();
    updateTable1();
    updateTable2();
    updateTable3();
}


void dlg_queue::on_pushButton_3_clicked()
{
    int i = ui->tableWidget_3->currentRow();
    // qDebug()<<i;
    if(i >= 0){
        QString qno = ui->tableWidget_3->item(i,0)->text();
        //int id=i+1;
        qDebug()<<qno;
        m_ptrmenusq->delLine(qno); //直接用行号代替了id  要求id务必和行号相同
        updateTable3();
        QMessageBox::information(nullptr,"信息","删除成功");
    }
}


void dlg_queue::on_pushButton_5_clicked()
{
    int i = ui->tableWidget_1->currentRow();
    // qDebug()<<i;
    if(i >= 0){
        QString qno = ui->tableWidget_1->item(i,0)->text();
        //int id=i+1;
        qDebug()<<qno;
        m_ptrmenusq->delLine(qno); //直接用行号代替了id  要求id务必和行号相同
        updateTable1();
        QMessageBox::information(nullptr,"信息","删除成功");
    }
}


void dlg_queue::on_btn_del2_clicked()
{
    int i = ui->tableWidget_2->currentRow();
    // qDebug()<<i;
    if(i >= 0){
        QString qno = ui->tableWidget_2->item(i,0)->text();
        //int id=i+1;
        qDebug()<<qno;
        m_ptrmenusq->delLine(qno); //直接用行号代替了id  要求id务必和行号相同
        updateTable2();
        QMessageBox::information(nullptr,"信息","删除成功");
    }
}


void dlg_queue::on_btn_seat_clicked()
{

    QString title="安排入座";
    m_dlgSeat.setWindowTitle(title);
    m_dlgSeat.quickMode=true;
    m_dlgSeat.updateTable();
    m_dlgSeat.exec();
    updateTable1();
    updateTable2();
    updateTable3();
}


// void dlg_queue::on_tableWidget_1_cellClicked(int row, int column)
// {

//     ui->tableWidget_2->setCurrentItem(NULL);
//     ui->tableWidget_3->setCurrentItem(NULL);
//     selectedCustomer = ui->tableWidget_1->item(row,0)->text();//获取客户编号
//     ui->btn_seat->setEnabled(true);
// }


// void dlg_queue::on_tableWidget_2_cellClicked(int row, int column)
// {
//     ui->tableWidget_1->setCurrentItem(NULL);
//     ui->tableWidget_3->setCurrentItem(NULL);
//     selectedCustomer = ui->tableWidget_2->item(row,0)->text();//获取客户编号
//     ui->btn_seat->setEnabled(true);
// }


// void dlg_queue::on_tableWidget_3_cellClicked(int row, int column)
// {
//     ui->tableWidget_1->setCurrentItem(NULL);
//     ui->tableWidget_2->setCurrentItem(NULL);
//     selectedCustomer = ui->tableWidget_3->item(row,0)->text();//获取客户编号
//     ui->btn_seat->setEnabled(true);
// }
void dlg_queue::closeEvent(QCloseEvent *event)
{
    ui->tableWidget_1->setCurrentItem(NULL);
    ui->tableWidget_2->setCurrentItem(NULL);
    ui->tableWidget_3->setCurrentItem(NULL);
    selectedCustomer={};
    event->accept();
}


void dlg_queue::on_btn_q1seat_clicked()
{
    int r=ui->tableWidget_1->currentRow();
    if(r>=0){
        QString cno=ui->tableWidget_1->item(r,0)->text();
        m_dlgSeat.quickMode=false;
        m_dlgSeat.selectedCno=cno;
        QString title=QString("安排%1号客人入座").arg(cno);
        m_dlgSeat.setWindowTitle(title);
        m_dlgSeat.updateTable();
        m_dlgSeat.exec();

        updateTable1();
        updateTable2();
        updateTable3();
    }
}


void dlg_queue::on_btn_q2seat_clicked()
{
    int r=ui->tableWidget_2->currentRow();
    if(r>=0){
        QString cno=ui->tableWidget_2->item(r,0)->text();
        m_dlgSeat.quickMode=false;
        m_dlgSeat.selectedCno=cno;
        QString title=QString("安排%1号客人入座").arg(cno);
        m_dlgSeat.setWindowTitle(title);
        m_dlgSeat.updateTable();
        m_dlgSeat.exec();

        updateTable1();
        updateTable2();
        updateTable3();
    }
}


void dlg_queue::on_btn_q3seat_clicked()
{
    int r=ui->tableWidget_3->currentRow();
    if(r>=0){
        QString cno=ui->tableWidget_3->item(r,0)->text();
        m_dlgSeat.quickMode=false;
        m_dlgSeat.selectedCno=cno;
        QString title=QString("安排%1号客人入座").arg(cno);
        m_dlgSeat.setWindowTitle(title);
        m_dlgSeat.updateTable();
        m_dlgSeat.exec();

        updateTable1();
        updateTable2();
        updateTable3();
    }
}

