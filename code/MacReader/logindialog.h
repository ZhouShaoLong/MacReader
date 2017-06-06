#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

/*
 *登录模块头文件
 *验证登录信息
 *
*/

#include <QDialog>
#include <QGridLayout>
#include <QByteArray>
#include <QJsonObject>
#include <QMessageBox>
#include <QJsonDocument>
#include <QSettings>
#include <QCoreApplication>
#include <QRegExp>
#include <QTimer>

#include <QDebug>

#include "netmanager.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();
    bool resolve(QString);
    void refresh();
    void saveUser();
    void changeStatus();

private slots:
    void on_btn_exit_clicked();
    void on_btn_login_clicked();

private:
    Ui::LoginDialog *ui;
    NetManager netManager;
};

#endif // LOGINDIALOG_H
