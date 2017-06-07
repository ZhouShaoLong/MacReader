#ifndef USERMESSAGE_H
#define USERMESSAGE_H

#include <QObject>
#include <QString>


class UserMessage
{

public:
    UserMessage();
    UserMessage(QString name,QString email,int id);

    QString getName();
    QString getEmail();
    int getId();

    void setName(QString name);
    void setEmail(QString email);
    void setId(int id);


private:
    QString Name;
    QString Email;
    int Id;


};

#endif // USERMESSAGE_H
