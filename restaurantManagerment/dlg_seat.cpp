#include "dlg_seat.h"
#include "ui_dlg_seat.h"

dlg_seat::dlg_seat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlg_seat)
{
    ui->setupUi(this);
    m_ptrmenusql = menusql::getinstance();
    //updateTable();
}

dlg_seat::~dlg_seat()
{
    delete ui;
}

void dlg_seat::updateTable()
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(3);
    QStringList l;
    l<<"桌号"<<"容量"<<"状态";
    ui->tableWidget->setHorizontalHeaderLabels(l);
    ui->tableWidget->setColumnWidth(0, ui->tableWidget->width()/3);
    ui->tableWidget->setColumnWidth(1, ui->tableWidget->width()/3);
    ui->tableWidget->setColumnWidth(2, ui->tableWidget->width()/3-20);

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); // 只选中行
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //显示表格内容
    QList<tableInfo> ltables = m_ptrmenusql->getFreeTable();
    ui ->tableWidget ->setRowCount(ltables.size());
    int cap=0;
    if(!quickMode)cap=m_ptrmenusql->getCapNeed(selectedCno);
    for(int i = 0,index=0;i<ltables.size();i++){
        if(!quickMode && ltables[i].capacity<cap){
            ui->tableWidget->removeRow(ui->tableWidget->rowCount()-1);
            continue;
        }
        ui->tableWidget->setItem(index,0,new QTableWidgetItem(ltables[i].id ));
        ui->tableWidget->setItem(index,1,new QTableWidgetItem(QString::number(ltables[i].capacity)));
        ui->tableWidget->setItem(index,2,new QTableWidgetItem(ltables[i].status ));
        ++index;
    }
}

void dlg_seat::on_btn_exit_clicked()
{
    this->hide();  //隐藏添加菜品界面
}

void dlg_seat::on_btn_enter_clicked()
{
    int r=ui->tableWidget->currentRow();
    if(r>=0){
        QString tno = ui->tableWidget->item(r,0)->text();
        QString cap = ui->tableWidget->item(r,1)->text();
        if(quickMode)m_ptrmenusql->quickTakeSeat(tno,cap);
        else m_ptrmenusql->takeSeat(selectedCno,tno);
        update_queue();
        updateTable();
        if(!quickMode)this->hide();

    }else{
        QMessageBox::warning(nullptr,"错误","请选择一个餐桌。");
    }
}


