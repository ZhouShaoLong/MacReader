#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    QGridLayout *layout = new QGridLayout;

    this->setWindowTitle(tr("登录"));

    ui->label_name->setAlignment(Qt::AlignRight);
    ui->label_passwd->setAlignment(Qt::AlignRight);

    ui->lineEdit_passwd->setEchoMode(QLineEdit::Password);
    ui->lineEdit_passwd->setPlaceholderText(QStringLiteral("请输入密码"));
    ui->lineEdit_passwd->setMaxLength(16);

    QRegExp rx1("[_a-zA-Z0-9]{3,12}");
    QValidator * valid1 = new QRegExpValidator(rx1,this);
    ui->lineEdit_name->setValidator(valid1);

    layout->addWidget(ui->label_name,0,0,1,1);
    layout->addWidget(ui->lineEdit_name,0,1,1,3);
    layout->addWidget(ui->label_passwd,1,0,1,1);
    layout->addWidget(ui->lineEdit_passwd,1,1,1,3);
    layout->addWidget(ui->check_Reme,2,1,1,1);
    layout->addWidget(ui->check_Auto,2,2,1,1);
    layout->addWidget(ui->btn_login,3,1,1,1);
    layout->addWidget(ui->btn_exit,3,2,1,1);

    setLayout(layout);

    refresh();


}

LoginDialog::~LoginDialog()
{
    delete ui;
}

bool LoginDialog::resolve(QString result)
{
    int code = 0;
    QString dec = "";

    int id=0;
    QString name="";
    QString email="";

    QJsonParseError json_error;
    QJsonDocument parse_doucment = QJsonDocument::fromJson(result.toUtf8(), &json_error);
    QJsonValue value;
    if(!parse_doucment.isNull() &&json_error.error==QJsonParseError::NoError){
        if(parse_doucment.isObject()){
            QJsonObject json = parse_doucment.object();
            if(json.contains("code")){
                value = json.take("code");
                if(value.isDouble()){
                    code = value.toVariant().toInt();
                }
            }
            if(json.contains("dec")){
                value = json.take("dec");
                if(value.isString()){
                    dec = value.toString();
                }
            }
        }
        qDebug()<<tr("code:")<<code<<endl<<tr("dec:")<<dec;
        if(code==1){

            if(parse_doucment.isObject()){
                QJsonObject object = parse_doucment.object();
                if(object.contains("userInfo")){
                    QJsonValue value = object.value("userInfo");
                    if(value.isObject()){
                        QJsonObject obj = value.toObject();
                        if(obj.contains("id")){
                            QJsonValue value = obj.value("id");
                            if(value.isDouble()){
                                id = value.toInt();
                            }
                        }
                        if(obj.contains("name")){
                            QJsonValue value = obj.value("name");
                            if(value.isString()){
                                name = value.toString();
                            }
                        }
                        if(obj.contains("email")){
                            QJsonValue value = obj.value("email");
                            if(value.isString()){
                                email = value.toString();
                            }
                        }
                    }
                }
            }

            qDebug()<<tr("登录成功")<<endl<<tr("name:")<<name<<endl<<tr("email:")<<email<<endl<<tr("id:")<<id;
            QCoreApplication::setApplicationName("MacReader");
            QCoreApplication::setOrganizationName("zhou");

            QSettings settings(QSettings::IniFormat, QSettings::UserScope, QCoreApplication::organizationName(), QCoreApplication::applicationName());

            settings.beginGroup("LogStatus");
            settings.setValue("Status",1);
            settings.setValue("id",id);
            settings.setValue("name",name);
            settings.setValue("email",email);
            settings.endGroup();


            if(ui->check_Reme->checkState()==Qt::Checked){
                saveUser();
            }

            QMessageBox::information(NULL,tr("登录"),dec,QMessageBox::Ok);

            this->close();
        }else if(code<0) {
            QMessageBox::information(NULL,tr("登录"),dec,QMessageBox::Ok);
        }
    }else {
        return false;
    }

    return true;
}

void LoginDialog::refresh()
{
    QCoreApplication::setApplicationName("MacReader");
    QCoreApplication::setOrganizationName("zhou");

    QSettings settings(QSettings::IniFormat, QSettings::UserScope, QCoreApplication::organizationName(), QCoreApplication::applicationName());

    int statusRemember = 0;
    int statusAuto = 0;

    settings.beginGroup("Login");
    statusRemember = settings.value("Remember").toInt();
    statusAuto = settings.value("Auto").toInt();
    settings.endGroup();


    if(statusRemember==1){
        ui->check_Reme->setChecked(true);
        settings.beginGroup("User");
        ui->lineEdit_name->setText(settings.value("Name").toString());
        ui->lineEdit_passwd->setText(settings.value("Passwd").toString());
        settings.endGroup();
    }
    if(statusAuto==1){
        QTimer::singleShot(1000, this, SLOT(on_btn_login_clicked()));
        this->close();
    }




}

void LoginDialog::saveUser()
{
    QCoreApplication::setApplicationName("MacReader");
    QCoreApplication::setOrganizationName("zhou");

    QSettings settings(QSettings::IniFormat, QSettings::UserScope, QCoreApplication::organizationName(), QCoreApplication::applicationName());

    settings.beginGroup("User");
    settings.setValue("Name",ui->lineEdit_name->text());
    settings.setValue("Passwd",ui->lineEdit_passwd->text());
    settings.endGroup();

    settings.beginGroup("Login");
    settings.setValue("Remember",1);
    settings.endGroup();
}

void LoginDialog::changeStatus()
{
    QCoreApplication::setApplicationName("MacReader");
    QCoreApplication::setOrganizationName("zhou");

    QSettings settings(QSettings::IniFormat, QSettings::UserScope, QCoreApplication::organizationName(), QCoreApplication::applicationName());

    int reStatus,auStatus;

    if(ui->check_Reme->checkState()==Qt::Unchecked){
        reStatus = 0;
    }else if (ui->check_Reme->checkState()==Qt::Checked) {
        reStatus = 1;
    }
    if(ui->check_Auto->checkState()==Qt::Unchecked){
        auStatus = 0;
    }else if (ui->check_Auto->checkState()==Qt::Checked) {
        auStatus = 1;
    }

    settings.beginGroup("Login");
    settings.setValue("Remember",reStatus);
    settings.setValue("Auto",auStatus);
    settings.endGroup();
}

void LoginDialog::on_btn_exit_clicked()
{
    this->close();
}

void LoginDialog::on_btn_login_clicked()
{
    QByteArray data;
    QJsonObject json;
    QJsonDocument document;
    QString name,passwd,result;

    name = ui->lineEdit_name->text();
    passwd = ui->lineEdit_passwd->text();

    changeStatus();

    json.insert("name",name);
    json.insert("passwd",passwd);

    document.setObject(json);

    data = document.toJson(QJsonDocument::Compact);

    netManager.setHostPort("120.25.60.217",8080);
    netManager.setPattern(net_login);
    netManager.post(data);

    result = netManager.getResult();
    qDebug()<<result;
    resolve(result);
}
