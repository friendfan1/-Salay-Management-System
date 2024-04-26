#include "dlg_checkout.h"
#include "ui_dlg_checkout.h"

dlg_checkout::dlg_checkout(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dlg_checkout)
{
    ui->setupUi(this);
    m_ptrmenusql=menusql::getinstance();
}

dlg_checkout::~dlg_checkout()
{
    delete ui;
}

void dlg_checkout::getBill(QString tno){
    m_tno=tno;
    ui->tablewidget->clear();
    ui->tablewidget->setColumnCount(3);
    QStringList l;
    l<<"菜名"<<"价格"<<"折扣";
    ui->tablewidget->setHorizontalHeaderLabels(l);

    ui->tablewidget->setSelectionMode(QAbstractItemView::NoSelection); // 只选中行
    ui->tablewidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //显示表格内容
    QList<dishInfo> ldishes = m_ptrmenusql->getOrderedDish(m_tno);
    ui ->tablewidget ->setRowCount(ldishes.size());
    total=0;
    for(int i = 0;i<ldishes.size();i++){
        ui->tablewidget->setItem(i,0,new QTableWidgetItem(ldishes[i].name ));
        ui->tablewidget->setItem(i,1,new QTableWidgetItem(QString::number(ldishes[i].price)));
        ui->tablewidget->setItem(i,2,new QTableWidgetItem(QString::number(ldishes[i].discount)));
        total+=ldishes[i].price*ldishes[i].discount;
    }
    ui->label->setText(QString("账单总计: %1元").arg(QString::number(total,'f',1)));
}


