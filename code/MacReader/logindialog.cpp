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

    layout->addWidget(ui->label_name,0,0,1,1);
    layout->addWidget(ui->lineEdit_name,0,1,1,3);
    layout->addWidget(ui->label_passwd,1,0,1,1);
    layout->addWidget(ui->lineEdit_passwd,1,1,1,3);
    layout->addWidget(ui->check_Reme,2,1,1,1);
    layout->addWidget(ui->check_Auto,2,2,1,1);
    layout->addWidget(ui->btn_login,3,1,1,1);
    layout->addWidget(ui->btn_exit,3,2,1,1);

    setLayout(layout);

}

LoginDialog::~LoginDialog()
{
    delete ui;
}

bool LoginDialog::resolve(QString result)
{
    int code;
    QString dec;

    QJsonParseError json_error;
    QJsonDocument parse_doucment = QJsonDocument::fromJson(result.toUtf8(), &json_error);
    QJsonValue value;
    if(json_error.error==QJsonParseError::NoError){
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

    json.insert("name",name);
    json.insert("passwd",passwd);

    document.setObject(json);

    data = document.toJson(QJsonDocument::Compact);

    netManager.setHostPort("127.0.0.1",8080);
    netManager.setPattern(net_login);
    netManager.post(data);

    result = netManager.getResult();
    qDebug()<<result;
    resolve(result);
}
