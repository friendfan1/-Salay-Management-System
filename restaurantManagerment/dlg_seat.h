#ifndef DLG_SEAT_H
#define DLG_SEAT_H

#include <QDialog>
#include "menusql.h"
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
private slots:
    void on_btn_exit_clicked();

    void on_tableWidget_cellClicked(int row, int column);

    void on_btn_enter_clicked();

private:
    QString& cno;
    Ui::dlg_seat *ui;
    int num_selectedTable;
    menusql *m_ptrmenusq;
};

#endif // DLG_SEAT_H
