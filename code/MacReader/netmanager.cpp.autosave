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
    QTextCodec * codec = QTextCodec::codecForName("UTF-8");
    result = codec->toUnicode(replay->readAll());
    qDebug()<<result;
    replay->deleteLater();
}

QString NetManager::getResult(){
    QString a;
    a = result;
    result = "";
    return a;
}

