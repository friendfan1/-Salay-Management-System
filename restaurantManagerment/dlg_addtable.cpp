#include "dlg_addtable.h"
#include "ui_dlg_addtable.h"
#include "menusql.h"
#include "QMessageBox"
dlg_addTable::dlg_addTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlg_addTable)
{
    ui->setupUi(this);
}

dlg_addTable::~dlg_addTable()
{
    delete ui;
}

void dlg_addTable::setType(bool isAdd, tableInfo info)
{
    m_isAdd = isAdd;
    m_info = info;
    ui->lineEdit_id->setText(info.id);
    cap=-1;
    isbusy=false;
    ui->btn_table_free->setEnabled(false);
    ui->btn_table_free->setStyleSheet("background-color: green; color: black;");
    ui->btn_table_busy->setEnabled(true);
    ui->btn_tablecap_2->setEnabled(true);
    ui->btn_tablecap_2->setStyleSheet("");
    ui->btn_tablecap_4->setEnabled(true);
    ui->btn_tablecap_4->setStyleSheet("");
    ui->btn_tablecap_8->setEnabled(true);
    ui->btn_tablecap_8->setStyleSheet("");
}

void dlg_addTable::on_btn_save_clicked()
{
    tableInfo info;
    auto ptr = menusql::getinstance();
    info.id = ui->lineEdit_id->text();
    if(info.id==""){
        QMessageBox::warning(nullptr,"错误","桌号不能为空");
        this->hide();
        return;
    }
    info.capacity = cap;
    if(info.capacity<=0){
        QMessageBox::warning(nullptr,"错误","餐桌容量错误");
        this->hide();
        return;
    }
    info.status = isbusy?"忙碌":"空闲";
    bool ok=false;
    if(m_isAdd){
        ok=ptr->addTable(info);
    }
    else{
        ok=ptr ->updateTable(info,m_info.id);
    }

    if(ok)QMessageBox::information(nullptr,"信息","存储成功");
    else QMessageBox::warning(nullptr,"错误","存储失败");
    this->hide();
}


void dlg_addTable::on_btn_cancel_clicked()
{
    this->hide();
}


void dlg_addTable::on_btn_table_free_clicked()
{
    isbusy=false;
    ui->btn_table_free->setEnabled(false);
    ui->btn_table_free->setStyleSheet("background-color: green; color: black;");
    ui->btn_table_busy->setEnabled(true);
    ui->btn_table_busy->setStyleSheet("");
}


void dlg_addTable::on_btn_table_busy_clicked()
{
    isbusy=true;
    ui->btn_table_free->setEnabled(true);
    ui->btn_table_free->setStyleSheet("");
    ui->btn_table_busy->setStyleSheet("background-color: red; color: black;");
    ui->btn_table_busy->setEnabled(false);
}


void dlg_addTable::on_btn_tablecap_2_clicked()
{
    cap=2;
    ui->btn_tablecap_4->setEnabled(true);
    ui->btn_tablecap_4->setStyleSheet("");
    ui->btn_tablecap_8->setEnabled(true);
    ui->btn_tablecap_8->setStyleSheet("");
    ui->btn_tablecap_2->setStyleSheet("background-color: yellow; color: black;");
    ui->btn_tablecap_2->setEnabled(false);
}


void dlg_addTable::on_btn_tablecap_4_clicked()
{
    cap=4;
    ui->btn_tablecap_2->setEnabled(true);
    ui->btn_tablecap_2->setStyleSheet("");
    ui->btn_tablecap_8->setEnabled(true);
    ui->btn_tablecap_8->setStyleSheet("");
    ui->btn_tablecap_4->setStyleSheet("background-color: yellow; color: black;");
    ui->btn_tablecap_4->setEnabled(false);
}


void dlg_addTable::on_btn_tablecap_8_clicked()
{
    cap=8;
    ui->btn_tablecap_2->setEnabled(true);
    ui->btn_tablecap_2->setStyleSheet("");
    ui->btn_tablecap_4->setEnabled(true);
    ui->btn_tablecap_4->setStyleSheet("");
    ui->btn_tablecap_8->setStyleSheet("background-color: yellow; color: black;");
    ui->btn_tablecap_8->setEnabled(false);
}

