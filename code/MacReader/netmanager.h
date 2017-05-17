#ifndef NETMANAGER_H
#define NETMANAGER_H

#include <QDebug>
#include <QUrl>
#include <QMessageBox>
#include <QTextCodec>
#include <QNetworkReply>
#include <QNetworkAccessManager>

#define net_regist 1
#define net_login 2


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

private slots:
    void replyFinished(QNetworkReply *);

};

#endif // NETMANAGER_H
