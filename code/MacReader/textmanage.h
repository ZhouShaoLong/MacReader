#ifndef TEXTMANAGE_H
#define TEXTMANAGE_H

#include <QDebug>
#include <QObject>
#include <QString>
#include <QFile>
#include <QTextCodec>

class TextManage : public QObject
{
    Q_OBJECT
public:
    explicit TextManage(QObject *parent = 0);
    bool openFile(QString filename);
    bool conversion(QString filename);

private:
    QString file;



};

#endif // TEXTMANAGE_H
