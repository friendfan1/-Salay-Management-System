#include "dlg_payment.h"
#include "ui_dlg_payment.h"

dlg_payment::dlg_payment(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dlg_payment)
{
    ui->setupUi(this);
}

dlg_payment::~dlg_payment()
{
    delete ui;
}

void dlg_payment::setTotal(float total){
    ui->label_total->setText(QString("%1元").arg(QString::number(total,'f',1)));
    method="";
    ui->btn_cash->setEnabled(true);
    ui->btn_cash->setStyleSheet("");
    ui->btn_weixin->setEnabled(true);
    ui->btn_weixin->setStyleSheet("");
    ui->btn_alipay->setEnabled(true);
    ui->btn_alipay->setStyleSheet("");
    ui->btn_ysf->setEnabled(true);
    ui->btn_ysf->setStyleSheet("");
}

void dlg_payment::on_btn_cash_clicked()
{
    method="现金";
    ui->btn_cash->setEnabled(false);
    ui->btn_cash->setStyleSheet("background-color: pink; color: black;");
    ui->btn_weixin->setEnabled(true);
    ui->btn_weixin->setStyleSheet("");
    ui->btn_alipay->setEnabled(true);
    ui->btn_alipay->setStyleSheet("");
    ui->btn_ysf->setEnabled(true);
    ui->btn_ysf->setStyleSheet("");
}


void dlg_payment::on_btn_weixin_clicked()
{
    method="微信支付";
    ui->btn_weixin->setEnabled(false);
    ui->btn_weixin->setStyleSheet("background-color: green; color: black;");
    ui->btn_cash->setEnabled(true);
    ui->btn_cash->setStyleSheet("");
    ui->btn_alipay->setEnabled(true);
    ui->btn_alipay->setStyleSheet("");
    ui->btn_ysf->setEnabled(true);
    ui->btn_ysf->setStyleSheet("");
}


void dlg_payment::on_btn_alipay_clicked()
{
    method="支付宝";
    ui->btn_alipay->setEnabled(false);
    ui->btn_alipay->setStyleSheet("background-color: #00A0E9; color: black;");
    ui->btn_cash->setEnabled(true);
    ui->btn_cash->setStyleSheet("");
    ui->btn_weixin->setEnabled(true);
    ui->btn_weixin->setStyleSheet("");
    ui->btn_ysf->setEnabled(true);
    ui->btn_ysf->setStyleSheet("");
}


void dlg_payment::on_btn_ysf_clicked()
{
    method="云闪付";
    ui->btn_ysf->setEnabled(false);
    ui->btn_ysf->setStyleSheet("background-color: red; color: black;");
    ui->btn_cash->setEnabled(true);
    ui->btn_cash->setStyleSheet("");
    ui->btn_weixin->setEnabled(true);
    ui->btn_weixin->setStyleSheet("");
    ui->btn_alipay->setEnabled(true);
    ui->btn_alipay->setStyleSheet("");
}


void dlg_payment::on_buttonBox_accepted()
{
    if(method==""){
        QMessageBox::warning(nullptr,"错误","请选择支付方式");
    }else accept();
}
