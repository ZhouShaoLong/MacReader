#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QProgressBar>
#include <QDebug>

#include "logindialog.h"
#include "registdialog.h"
#include "textmanage.h"
#include "displaydialog.h"
#include "ftpmanager.h"
#include "usermessage.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    UserMessage user;


private slots:
    //按钮的槽函数
    void on_ac_login_triggered();
    void on_ac_register_triggered();
    void on_ac_logout_triggered();
    void on_fi_open_triggered();
    void on_actionupload_triggered();
    void on_actiondownload_triggered();
    void on_book1_clicked();
    void showBook();

    void uploadProgress(qint64 bytesSent, qint64 bytesTotal);
    void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);
    void error(QNetworkReply::NetworkError error);



private:
    Ui::MainWindow *ui;
    LoginDialog *login;
    RegistDialog *regist;

    QProgressBar *m_pUploadBar;
    QProgressBar *m_pDownloadBar;
    FtpManager m_ftp;
    NetManager FtpFinfo;

};

#endif // MAINWINDOW_H
