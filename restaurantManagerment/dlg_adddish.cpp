#include "dlg_adddish.h"
#include "ui_dlg_adddish.h"
#include "menusql.h"
#include "QMessageBox"
Dlg_addDish::Dlg_addDish(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_addDish)
{
    ui->setupUi(this);
}

Dlg_addDish::~Dlg_addDish()
{
    delete ui;
}
//修改菜单用 使修改时显示原信息
void Dlg_addDish::setType(bool isAdd,dishInfo info)
{
    m_isAdd = isAdd;
    m_info = info;
    ui->le_name->setText(info.name);
    ui->le_type->setText(info.type);
    ui->le_mat->setText(info.material);
    ui->le_price->setText(QString::number(info.price));
    ui->le_dis->setText(QString::number(info.discount));
}

void Dlg_addDish::on_pushButton_clicked()
{
    dishInfo info;
    auto ptr = menusql::getinstance();
    info.name = ui->le_name->text();
    info.type = ui->le_type->text();
    info.material = ui->le_mat->text();
    info.price = ui->le_price->text().toUInt();
    info.discount = ui ->le_dis->text().toFloat();
    bool ok=false;
    if(m_isAdd){
        ok=ptr->addDish(info);
    }
    else{
        ok=ptr ->updateDish(info,m_info.name);
    }
    if(ok)QMessageBox::information(nullptr,"信息","存储成功");
    else QMessageBox::warning(nullptr,"错误","存储失败");
    this->hide(); //隐藏添加菜品界面
}

void Dlg_addDish::on_pushButton_2_clicked()
{
    this->hide();  //隐藏添加菜品界面
}




