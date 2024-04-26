#include "dlg_line.h"
#include "ui_dlg_line.h"
#include "menusql.h"
#include "QMessageBox"
#include<QTime>
dlg_line::dlg_line(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlg_line)
{
    ui->setupUi(this);
}

dlg_line::~dlg_line()
{
    delete ui;
}

void dlg_line::refreshDlg(){
    ui->tableWidget_tablelist->clear();
    ui->tableWidget_tablelist->setColumnCount(1);
    ui->tableWidget_tablelist->setColumnWidth(0, ui->tableWidget_tablelist->width()-10);

    ui->tableWidget_tablelist->horizontalHeader()->setVisible(false); //隐藏水平表头
    ui->tableWidget_tablelist->verticalHeader()->setVisible(false);

    ui->tableWidget_tablelist->setSelectionBehavior(QAbstractItemView::SelectRows); // 只选中行
    ui->tableWidget_tablelist->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //显示表格内容
    auto ptr = menusql::getinstance();
    auto ltypes = ptr->getAllTableType();
    ui ->tableWidget_tablelist ->setRowCount(ltypes.size());
    for(int i = 0;i<ltypes.size();i++){
        ui->tableWidget_tablelist->setItem(i,0,new QTableWidgetItem(QString::number(ltypes[i])));
    }
    ui->lineEdit_qnum->clear();
}

void dlg_line::on_btn_exit_clicked()
{
    this->hide();
}


void dlg_line::on_btn_save_clicked()
{
    auto ptr = menusql::getinstance();
    int r = ui->tableWidget_tablelist->currentRow();
    bool ok;
    int num=ui->lineEdit_qnum->text().toInt(&ok);
    if(!ok){
        QMessageBox::critical(this,"错误","人数输入有误!");
        refreshDlg();
    }
    else if(r<0){
        QMessageBox::critical(this,"错误","请选择餐桌类型!");
    }
    else{
        int cap=ui->tableWidget_tablelist->item(r,0)->text().toInt();
        ptr->addLine(num,cap);
        QMessageBox::information(nullptr,"信息","排队成功");
        this->hide();
    }
}

