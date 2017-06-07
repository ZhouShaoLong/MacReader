#include "usermessage.h"


UserMessage::UserMessage()
{

}

UserMessage::UserMessage(QString name, QString email, int id)
{
    this->Name = name;
    this->Email = email;
    this->Id = id;
}

QString UserMessage::getName()
{
    return this->Name;
}

QString UserMessage::getEmail()
{
    return this->Email;
}

int UserMessage::getId()
{
    return this->Id;
}

void UserMessage::setName(QString name)
{
    this->Name = name;
}

void UserMessage::setEmail(QString email)
{
    this->Email = email;
}

void UserMessage::setId(int id)
{
    this->Id = id;
}
