#include "netmanager.h"

NetManager::NetManager(QObject *parent) : QObject(parent){
    m_url.setScheme("http");
}

void NetManager::setHostPort(const QString &host, int port){
    m_url.setHost(host);
    m_url.setPort(port);
}

void NetManager::setPattern(int a){
    switch (a) {
    case net_regist:
        m_url.setPath("/MacReader/reg");
        break;
    case net_login:
        m_url.setPath("/MacReader/login");
        break;
    default:
        break;
    }
}

void NetManager::post(QByteArray data){
    qDebug()<<m_url.toString()<<data;
    request = new QNetworkRequest;
    request->setUrl(m_url);
    manager = new QNetworkAccessManager(this);
    request->setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply*)));
    manager->post(*request,data);
}

void NetManager::replyFinished(QNetworkReply * replay){
    QJsonParseError jsonError;
    QJsonDocument document;
    QJsonValue value;
    double code;
    QString dec;
    QTextCodec * codec = QTextCodec::codecForName("UTF-8");
    result = codec->toUnicode(replay->readAll());
    qDebug()<<result;
    document = QJsonDocument::fromJson(result.toUtf8(),&jsonError);

    //解析服务器返回信息
    if (!document.isNull() && (jsonError.error == QJsonParseError::NoError)) {  // 解析未发生错误
        if (document.isObject()) { // JSON 文档为对象
            QJsonObject json = document.object();
            if(json.contains("code")){
                value = json.value("code");
                if(value.isDouble()){
                    code = value.toDouble();
                }
            }
            if(json.contains("dec")){
                value = json.value("dec");
                if(value.isString()){
                    dec = value.toString();
                }
            }
        }
    }

    if(code==1){
        QMessageBox::information(NULL,tr("登录"),dec,QMessageBox::Ok);
    }else {
        QMessageBox::warning(NULL,tr("警告"),dec,QMessageBox::Ok);
    }


    replay->deleteLater();
}

QString NetManager::getResult(){
    QString a;
    a = result;
    result = "";
    return a;
}

