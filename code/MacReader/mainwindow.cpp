#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("书架"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//菜单栏登录按钮槽函数
void MainWindow::on_ac_login_triggered()
{
    login = new LoginDialog(this);
    login->exec();
}

//菜单栏注册按钮槽函数
void MainWindow::on_ac_register_triggered()
{
    regist = new RegistDialog(this);
    regist->exec();
}

//菜单栏注销按钮槽函数
void MainWindow::on_ac_logout_triggered()
{

}
