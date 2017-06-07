#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle(tr("书架"));
    this->setFixedSize(960,600);

//    initIni();
    listBook();

//    QCoreApplication::setApplicationName("MacReader");
//    QCoreApplication::setOrganizationName("zhou");

//    QSettings settings(QSettings::IniFormat, QSettings::UserScope, QCoreApplication::organizationName(), QCoreApplication::applicationName());

//    settings.beginGroup("User");

//    settings.endGroup();

    //设置上传文件的ip地址、端口、用户名、密码
    m_ftp.setHostPort("120.25.60.217", 21);
    m_ftp.setUserInfo("test", "123123");

    dis = new DisplayDialog(this);
    connect(this,SIGNAL(sendPath(QString)),dis,SLOT(receivePath(QString)));
}

MainWindow::~MainWindow()
{
    //注销登录状态
    on_ac_logout_triggered();

    //释放按钮资源
    while(!ButtonGroup.isEmpty()){
        delete ButtonGroup.takeFirst();
    }

    //释放展示界面资源
    delete dis;
    delete ui;
}


//自定义槽函数

void MainWindow::showBook()
{
    //检查是哪一个按钮被点击, 即用户点击的是哪一本书
    MyButton *pt=qobject_cast <MyButton*>(sender());
    if(!pt){
        return;
    }
    QListIterator<Book> i(Books);
    while(i.hasNext()){
        Book book = i.next();
        QString name = pt->text();
        if(!QString::compare(book.name,name)){
            this->path = book.path;
            break;
        }
    }
    emit sendPath(path);


    this->hide();
    dis->exec();
    this->show();
}


//菜单栏函数实现

//菜单栏登录按钮槽函数
void MainWindow::on_ac_login_triggered()
{
    login = new LoginDialog(this);
    login->exec();
    delete login;
}

//菜单栏注册按钮槽函数
void MainWindow::on_ac_register_triggered()
{
    regist = new RegistDialog(this);
    regist->exec();
    delete regist;
}

//菜单栏注销按钮槽函数
void MainWindow::on_ac_logout_triggered()
{
    QCoreApplication::setApplicationName("MacReader");
    QCoreApplication::setOrganizationName("zhou");

    QSettings settings(QSettings::IniFormat, QSettings::UserScope, QCoreApplication::organizationName(), QCoreApplication::applicationName());

    settings.beginGroup("LogStatus");
    settings.remove("");
    settings.endGroup();
}

//菜单栏打开文件按钮槽函数
void MainWindow::on_fi_open_triggered()
{
    QString file = "";
    QFileInfo finfo;
    file = QFileDialog::getOpenFileName(this,tr("文件对话框"),"/Users/zhou/Desktop/我的文档/小说",tr("文本文件(*txt)"));
    finfo = QFileInfo(file);
    qDebug()<<file<<finfo.baseName();
    CreatButton(finfo.baseName(),file);


    Py_Initialize();
    if(!PyRun_SimpleString("execfile('Decode.py')"))
            qDebug()<<"execute python file program failed";


    Py_Finalize();


//    TextManage tex(this);
//    tex.conversion(file);
}

void MainWindow::CreatButton(QString name,QString path)
{
    QCoreApplication::setApplicationName("MacReader");
    QCoreApplication::setOrganizationName("zhou");

    QSettings settings(QSettings::IniFormat, QSettings::UserScope, QCoreApplication::organizationName(), QCoreApplication::applicationName());

    QFile qssFile(":/qss/button/BookButton.qss");
    qssFile.open(QFile::ReadOnly);

    ButtonGroup.append(new MyButton(this));
    ButtonGroup.last()->setText(name);
    ButtonGroup.last()->setGeometry(160*((ButtonGroup.length()-1)%4+1),10+180*((ButtonGroup.length()-1)/4),100,150);

    ButtonGroup.last()->setStyleSheet(qssFile.readAll());
    ButtonGroup.last()->show();
    connect(ButtonGroup.last(),SIGNAL(clicked(bool)),this,SLOT(showBook()));
    connect(ButtonGroup.last()->m_actionOne, SIGNAL(triggered()), this, SLOT(openSlots()));
    connect(ButtonGroup.last()->m_actionTwo, SIGNAL(triggered()), this, SLOT(deleteSlots()));

    Book book;
    book.name = name;
    book.path = path;
    Books.append(book);

    settings.beginWriteArray("BookList");
    settings.setArrayIndex(ButtonGroup.length()-1);
    settings.setValue("BookName",name);
    settings.setValue("BookPath",path);
    settings.endArray();
}

void MainWindow::openSlots()
{
    QAction *ac = qobject_cast <QAction*>(sender());
    if(!ac){
        return;
    }
    MyButton *pt =(MyButton*) ac->parentWidget();
    QListIterator<Book> i(Books);
    while(i.hasNext()){
        Book book = i.next();
        QString name = pt->text();
        if(!QString::compare(book.name,name)){
            this->path = book.path;
            break;
        }
        qDebug()<<name;
    }
    emit sendPath(path);
    this->hide();
    dis->exec();
    this->show();
}

void MainWindow::deleteSlots()
{
    QAction *ac = qobject_cast <QAction*>(sender());
    if(!ac){
        return;
    }
    MyButton *pt =(MyButton*) ac->parentWidget();
    QListIterator<MyButton*> i(ButtonGroup);
    int index = 0;
    while(i.hasNext()){
        MyButton * btn = i.next();
        QString name = pt->text();
        QString name_btn = btn->text();
        if(!QString::compare(name_btn,name)){
            delete ButtonGroup.takeAt(index);
        }
        index++;
    }
    qDebug()<<tr("2");
}


void MainWindow::listBook()
{
    QCoreApplication::setApplicationName("MacReader");
    QCoreApplication::setOrganizationName("zhou");

    QSettings settings(QSettings::IniFormat, QSettings::UserScope, QCoreApplication::organizationName(), QCoreApplication::applicationName());

    int size = 0;
    size = settings.beginReadArray("BookList");

    for(int i = 0;i<size;i++){
        settings.setArrayIndex(i);
        Book book;
        book.name = settings.value("BookName").toString();
        book.path = settings.value("BookPath").toString();
        Books.append(book);
        CreatButton(book.name,book.path);
    }
    settings.endArray();
}


//文件上传
void MainWindow::on_actionupload_triggered()
{
    QByteArray data;
    QJsonObject json;
    QJsonDocument document;
    QString name,path,UserName,FileHash;
    int status,UserID,size;

    QCoreApplication::setApplicationName("MacReader");
    QCoreApplication::setOrganizationName("zhou");

    QSettings settings(QSettings::IniFormat, QSettings::UserScope, QCoreApplication::organizationName(), QCoreApplication::applicationName());

    settings.beginGroup("LogStatus");
    status = settings.value("Status").toInt();
    UserName = settings.value("name").toString();
    UserID = settings.value("id").toInt();
    settings.endGroup();

    if(status==0){
        QMessageBox::information(NULL,tr("上传文件"),tr("请先登录后再上传文件"),QMessageBox::Ok);
        return;
    }

    QString fname = QFileDialog::getOpenFileName(this,tr("选择上传文件"),"/Users/zhou/Desktop/我的文档/小说",tr("文本文件(*.txt)"));
    QFileInfo finfo = QFileInfo(fname);
    if(!finfo.isFile()){
        qDebug()<<tr("a");
        return;
    }

    //获取文件的Hash值
    QFile file(fname);
    if(file.open(QIODevice::ReadOnly)){
        QByteArray bArray = QCryptographicHash::hash(file.readAll(),QCryptographicHash::Md5);
        FileHash = QString(bArray.toHex()).toUpper();
    }
    file.close();
    qDebug()<<FileHash;


    QString FtpPath = "/home/test/"+finfo.fileName();

    name = finfo.baseName();
    path = FtpPath;
    size = finfo.size();

    pro = new QProgressDialog("《"+finfo.baseName()+"》正在上传中，请稍后","取消",0,size,this);

    json.insert("BookName",name);
    json.insert("OwnID",UserID);
    json.insert("Path",FtpPath);
    json.insert("Hash",FileHash);
    json.insert("Size",size);

    document.setObject(json);

    data = document.toJson(QJsonDocument::Compact);

    FtpFinfo.setHostPort("120.25.60.217",8080);
    FtpFinfo.setPattern(net_saveBook);
    FtpFinfo.post(data);

    m_ftp.put(fname, FtpPath);
    connect(&m_ftp, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(error(QNetworkReply::NetworkError)));
    connect(&m_ftp, SIGNAL(uploadProgress(qint64, qint64)), this, SLOT(uploadProgress(qint64, qint64)));
}

//文件下载
void MainWindow::on_actiondownload_triggered()
{
    m_ftp.get("/home/test/破灭时空.txt", "/Users/zhou/Desktop/jx.txt");
    connect(&m_ftp, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(error(QNetworkReply::NetworkError)));
    connect(&m_ftp, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(downloadProgress(qint64, qint64)));
}

// 更新上传进度
void MainWindow::uploadProgress(qint64 bytesSent, qint64 bytesTotal)
{
    pro->setValue((int)bytesSent);
    if(bytesSent==bytesTotal){
        QMessageBox::information(NULL,tr("上传文件"),tr("文件上传成功"),QMessageBox::Ok);
        return;
    }
}

// 更新下载进度
void MainWindow::downloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    pro->setValue((int)bytesReceived);
    if(bytesReceived==bytesTotal){
        QMessageBox::information(NULL,tr("下载文件"),tr("文件下载成功"),QMessageBox::Ok);
        return;
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

void MainWindow::initIni()
{
    QCoreApplication::setApplicationName("MacReader");
    QCoreApplication::setOrganizationName("zhou");

    QSettings settings(QSettings::IniFormat, QSettings::UserScope, QCoreApplication::organizationName(), QCoreApplication::applicationName());

    settings.beginGroup("User");
    settings.setValue("Name", "zhou");
    settings.setValue("Passwd", "zhou123123");
    settings.endGroup();

    settings.beginGroup("Login");
    settings.setValue("Remember",0);
    settings.setValue("AutoLogin",0);
    settings.endGroup();

    settings.beginGroup("Display");
    settings.setValue("FontSize",10);
    settings.setValue("FontColor","black");
    settings.setValue("BackGround",0);
    settings.endGroup();
}




void MainWindow::on_actionclose_triggered()
{
    while(!ButtonGroup.isEmpty()){
        delete ButtonGroup.takeFirst();
    }
}
