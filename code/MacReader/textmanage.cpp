#include "textmanage.h"

TextManage::TextManage(QObject *parent): QObject(parent){

}

bool TextManage::conversion(QString filename){
    QTextCodec *codec = QTextCodec::codecForName("gbk");
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        return false;
    }

    while(!file.atEnd()){
        QByteArray line = file.readLine();
        QString str = codec->toUnicode(line);
        qDebug()<<str;


    }


    return true;
}
