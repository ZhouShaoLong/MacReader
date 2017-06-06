#include "registdialog.h"
#include "ui_registdialog.h"

RegistDialog::RegistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistDialog)
{
    ui->setupUi(this);
    QGridLayout *layout = new QGridLayout;
    this->setWindowTitle(tr("注册"));

    ui->label_name->setAlignment(Qt::AlignRight);
    ui->label_passwd1->setAlignment(Qt::AlignRight);
    ui->label_passwd2->setAlignment(Qt::AlignRight);
    ui->label_email->setAlignment(Qt::AlignRight);

    ui->lineEdit_passwd1->setEchoMode(QLineEdit::Password);
    ui->lineEdit_passwd2->setEchoMode(QLineEdit::Password);

    QRegExp rx1("^[A-Za-z0-9]+([-_.][A-Za-z0-9]+)*@([A-Za-z0-9]+[-.])+[A-Za-z0-9]{2,5}$");
    QValidator * valid1 = new QRegExpValidator(rx1,this);
    ui->lineEdit_email->setValidator(valid1);

    QRegExp rx2("[_a-zA-Z0-9]{3,12}");
    QValidator * valid2 = new QRegExpValidator(rx2,this);
    ui->lineEdit_name->setValidator(valid2);

    layout->addWidget(ui->label_name,0,0,1,1);
    layout->addWidget(ui->lineEdit_name,0,1,1,3);
    layout->addWidget(ui->label_passwd1,1,0,1,1);
    layout->addWidget(ui->lineEdit_passwd1,1,1,1,3);
    layout->addWidget(ui->label_passwd2,2,0,1,1);
    layout->addWidget(ui->lineEdit_passwd2,2,1,1,3);
    layout->addWidget(ui->label_email,3,0,1,1);
    layout->addWidget(ui->lineEdit_email,3,1,1,3);
    layout->addWidget(ui->btn_Regist,4,1,1,1);
    layout->addWidget(ui->btn_Exit,4,2,1,1);

    setLayout(layout);

}

RegistDialog::~RegistDialog()
{
    delete ui;
}

bool RegistDialog::check(){
    QString name,passwd1,passwd2,email;
    bool result = true;
    name = ui->lineEdit_name->text();
    passwd1 = ui->lineEdit_passwd1->text();
    passwd2 = ui->lineEdit_passwd2->text();
    email = ui->lineEdit_email->text();

    //检查用户名
    if(name.length()<4||name.length()>12){
        result = false;
    }

    //检查密码
    if(passwd1!=passwd2){
        result = false;
    }

    if(passwd1.length()<6||passwd1.length()>18){
        result = false;
    }


    //检查email
    if(email.length()<4||email.length()>15){
        result = false;
    }

    return result;
}

void RegistDialog::on_btn_Regist_clicked()
{
    if(check()){
        QByteArray data;
        QJsonObject json;
        QJsonDocument document;
        QString name,passwd1,passwd2,email,result;
        name = ui->lineEdit_name->text();
        passwd1 = ui->lineEdit_passwd1->text();
        passwd2 = ui->lineEdit_passwd2->text();
        email = ui->lineEdit_email->text();

        json.insert("name",name);
        json.insert("passwd",passwd1);
        json.insert("email",email);

        document.setObject(json);

        data = document.toJson(QJsonDocument::Compact);

        netManager.setHostPort("127.0.0.1",8080);
        netManager.setPattern(net_regist);
        netManager.post(data);

        result = netManager.getResult();
        qDebug()<<result;
        resolve(result);

    }else{
        QMessageBox::information(NULL,tr("注册"),tr("用户信息验证不合法"),QMessageBox::Ok);
    }
}

bool RegistDialog::resolve(QString result)
{
    int code = 0;
    QString dec = "";

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
            QMessageBox::information(NULL,tr("注册"),dec,QMessageBox::Ok);
            this->close();
        }else if(code<=0) {
            QMessageBox::information(NULL,tr("注册"),dec,QMessageBox::Ok);
        }
    }else {

        return false;
    }

    return true;
}

void RegistDialog::on_btn_Exit_clicked()
{
    this->close();
}


