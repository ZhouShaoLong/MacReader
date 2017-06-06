#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QList>
#include <QTextCodec>
#include <QMainWindow>
#include <QFileDialog>
#include <QPushButton>
#include <QToolButton>
#include <QListIterator>
#include <QProgressDialog>
#include <Python.h>

#include <QDebug>

#include "logindialog.h"
#include "registdialog.h"
#include "textmanage.h"
#include "displaydialog.h"
#include "ftpmanager.h"
#include "usermessage.h"
#include "mybutton.h"


namespace Ui {
class MainWindow;
}

struct Book{
    QString name;
    QString path;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    UserMessage user;
    DisplayDialog *dis;

public slots:
    void openSlots();
    void deleteSlots();
    void renameSlots();

private slots:
    //按钮的槽函数
    void on_ac_login_triggered();
    void on_ac_register_triggered();
    void on_ac_logout_triggered();
    void on_fi_open_triggered();
    void on_actionupload_triggered();
    void on_actiondownload_triggered();
    void showBook();
    void CreatButton(QString name,QString path);

    void listBook();

    void uploadProgress(qint64 bytesSent, qint64 bytesTotal);
    void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);
    void error(QNetworkReply::NetworkError error);

private:
    Ui::MainWindow *ui;

//    QList<QPushButton*> ButtonGroup;
    QList<MyButton*> ButtonGroup;

    QList<Book> Books;

    LoginDialog *login;
    RegistDialog *regist;

    QProgressDialog * pro;

    FtpManager m_ftp;
    NetManager FtpFinfo;

    QString path;

    void initIni();

signals:
    void sendPath(QString);




};

#endif // MAINWINDOW_H
