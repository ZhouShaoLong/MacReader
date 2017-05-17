#ifndef REGISTDIALOG_H
#define REGISTDIALOG_H

#include <QDialog>
#include <QGridLayout>
#include <QRegExp>
#include <QValidator>
#include <QByteArray>

#include "netmanager.h"


namespace Ui {
class RegistDialog;
}

class RegistDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegistDialog(QWidget *parent = 0);
    ~RegistDialog();

private slots:
    void on_btn_Exit_clicked();
    void on_btn_Regist_clicked();

private:
    Ui::RegistDialog *ui;
    NetManager netManager;
    bool check();
};

#endif // REGISTDIALOG_H
