#ifndef DLG_PAYMENT_H
#define DLG_PAYMENT_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class dlg_payment;
}

class dlg_payment : public QDialog
{
    Q_OBJECT

public:
    explicit dlg_payment(QWidget *parent = nullptr);
    ~dlg_payment();
    void setTotal(float total);
    QString method="";

private slots:
    void on_btn_cash_clicked();

    void on_btn_weixin_clicked();

    void on_btn_alipay_clicked();

    void on_btn_ysf_clicked();

    void on_buttonBox_accepted();

private:
    Ui::dlg_payment *ui;
};

#endif // DLG_PAYMENT_H
