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

    QRegExp rx("^[A-Za-z0-9]+([-_.][A-Za-z0-9]+)*@([A-Za-z0-9]+[-.])+[A-Za-z0-9]{2,5}$");
    QValidator * valid = new QRegExpValidator(rx,this);
    ui->lineEdit_email->setValidator(valid);

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
        QString name,passwd1,passwd2,email;
        name = ui->lineEdit_name->text();
        passwd1 = ui->lineEdit_passwd1->text();
        passwd2 = ui->lineEdit_passwd2->text();
        email = ui->lineEdit_email->text();

        data.append("name=");
        data.append(name);
        data.append("&");
        data.append("passwd=");
        data.append(passwd1);
        data.append("&");
        data.append("email=");
        data.append(email);

        netManager.setHostPort("127.0.0.1",8080);
        netManager.setPattern(net_regist);
        netManager.post(data);
        qDebug()<<netManager.getResult();
    }
}

void RegistDialog::on_btn_Exit_clicked()
{
    this->close();
}


