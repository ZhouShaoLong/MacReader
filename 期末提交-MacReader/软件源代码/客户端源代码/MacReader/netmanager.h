#ifndef NETMANAGER_H
#define NETMANAGER_H

/*
 *网路管理类
 *主要封装了发送网络请求的函数
 *
*/


#include <QUrl>
#include <QDebug>
#include <QTextCodec>
#include <QMessageBox>
#include <QNetworkReply>
#include <QEventLoop>
#include <QNetworkAccessManager>

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonParseError>

#include <QMainWindow>

#define net_regist 1
#define net_login 2
#define net_saveBook 3


class NetManager : public QObject
{
    Q_OBJECT
public:
    explicit NetManager(QObject *parent = 0);
    void setHostPort(const QString &host, int port = 8080);
    void setPattern(int a);
    void post(QByteArray data);
    QString getResult();

private:
    QUrl m_url;
    QNetworkAccessManager *manager;
    QNetworkRequest *request;
    QString result;


};

#endif // NETMANAGER_H
