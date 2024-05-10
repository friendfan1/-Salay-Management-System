#ifndef DLG_SEAT_H
#define DLG_SEAT_H

#include <QDialog>
#include <QMessageBox>
#include "menusql.h"
#
namespace Ui {
class dlg_seat;
}

class dlg_seat : public QDialog
{
    Q_OBJECT

public:
    explicit dlg_seat(QString& _cno,QWidget *parent = nullptr);
    ~dlg_seat();
    void updateTable();
    QString selectedCno="-1";
    bool quickMode=true;
    std::function<void()> update_queue;
private slots:
    void on_btn_exit_clicked();

    void on_btn_enter_clicked();

private:
    QString& cno;
    Ui::dlg_seat *ui;
    menusql *m_ptrmenusq;
};

#endif // DLG_SEAT_H
