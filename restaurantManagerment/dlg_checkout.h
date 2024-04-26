#ifndef DLG_CHECKOUT_H
#define DLG_CHECKOUT_H

#include <QDialog>
#include <QString>
#include "menusql.h"

namespace Ui {
class dlg_checkout;
}

class dlg_checkout : public QDialog
{
    Q_OBJECT

public:
    explicit dlg_checkout(QWidget *parent = nullptr);
    ~dlg_checkout();
    QString m_tno;
    void getBill(QString tno);
    float total=0;

private:
    Ui::dlg_checkout *ui;
    menusql* m_ptrmenusql;
};

#endif // DLG_CHECKOUT_H
