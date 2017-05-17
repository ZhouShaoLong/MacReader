#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "logindialog.h"
#include "registdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_ac_login_triggered();

    void on_ac_register_triggered();

    void on_ac_logout_triggered();

private:
    Ui::MainWindow *ui;
    LoginDialog *login;
    RegistDialog *regist;

};

#endif // MAINWINDOW_H
