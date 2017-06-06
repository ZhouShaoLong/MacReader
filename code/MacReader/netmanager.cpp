#include "netmanager.h"

NetManager::NetManager(QObject *parent)
    : QObject(parent){
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
    case net_saveBook:
        m_url.setPath("/MacReader/upload");
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
    QNetworkReply *reply = manager->post(*request,data);
    QEventLoop eventLoop;
    QObject::connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
    eventLoop.exec(QEventLoop::ExcludeUserInputEvents);
    if(reply->error()==QNetworkReply::NoError){
        QTextCodec * codec = QTextCodec::codecForName("UTF-8");
        result = codec->toUnicode(reply->readAll());
    }
    reply->deleteLater();
    reply=NULL;
}

QString NetManager::getResult(){
    return result;
}

