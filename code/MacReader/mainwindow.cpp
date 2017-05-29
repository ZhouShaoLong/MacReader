#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("书架"));

    m_pUploadBar = ui->m_pUploadBar;
    m_pDownloadBar = ui->m_pDownloadBar;

    m_pUploadBar->setValue(0);
    m_pDownloadBar->setValue(0);

    m_ftp.setHostPort("120.25.60.217", 21);
    m_ftp.setUserInfo("test", "123123");
}

MainWindow::~MainWindow()
{
    delete ui;
}

//自定义槽函数

void MainWindow::showBook()
{
    DisplayDialog *showBook = new DisplayDialog(this);
    this->hide();
    showBook->exec();
    this->show();

}


//菜单栏函数实现

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

//菜单栏打开文件按钮槽函数
void MainWindow::on_fi_open_triggered()
{
    QString file = "";
    file = QFileDialog::getOpenFileName(this,tr("文件对话框"),"/Users/zhou/Desktop/我的文档/小说",tr("文本文件(*txt)"));
    qDebug()<<file;
    TextManage tex(this);
    tex.conversion(file);
}

//文件上传
void MainWindow::on_actionupload_triggered()
{
    QString fname = QFileDialog::getOpenFileName(this,tr("选择上传文件"),"/Users/zhou/Desktop/我的文档/小说",tr("文本文件(*.txt)"));
    QFileInfo finfo = QFileInfo(fname);
    QString FtpPath = "/home/test/"+finfo.fileName();
    m_ftp.put(fname, FtpPath);
    connect(&m_ftp, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(error(QNetworkReply::NetworkError)));
    connect(&m_ftp, SIGNAL(uploadProgress(qint64, qint64)), this, SLOT(uploadProgress(qint64, qint64)));
}

//文件下载
void MainWindow::on_actiondownload_triggered()
{
    m_ftp.get("/home/test/jx.txt", "/Users/zhou/Desktop/jx2.txt");
    connect(&m_ftp, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(error(QNetworkReply::NetworkError)));
    connect(&m_ftp, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(downloadProgress(qint64, qint64)));
}

// 更新上传进度
void MainWindow::uploadProgress(qint64 bytesSent, qint64 bytesTotal)
{
    m_pUploadBar->setMaximum(bytesTotal);
    m_pUploadBar->setValue(bytesSent);
    if(bytesSent==bytesTotal){
        qDebug()<<tr("上传完成");
    }
}

// 更新下载进度
void MainWindow::downloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    m_pDownloadBar->setMaximum(bytesTotal);
    m_pDownloadBar->setValue(bytesReceived);
    if(bytesReceived==bytesTotal){
        qDebug()<<tr("下载完成");
    }
}

// 错误处理
void MainWindow::error(QNetworkReply::NetworkError error)
{
    switch (error) {
    case QNetworkReply::HostNotFoundError :
        qDebug() << QString::fromLocal8Bit("主机没有找到");
        break;
        // 其他错误处理
    default:
        break;
    }
}


//主界面函数实现

void MainWindow::on_book1_clicked()
{
    showBook();
}


