#include "mybutton.h"


MyButton::MyButton(QWidget *parent)
    : QPushButton(parent)
{
    setContextMenuPolicy(Qt::ActionsContextMenu);

    m_actionOne = new QAction(this);
    m_actionTwo = new QAction(this);
    m_actionThree = new QAction(this);

    m_actionOne->setText("打开");
    m_actionTwo->setText("删除");
    m_actionThree->setText("重命名");

    addAction(m_actionOne);
    addAction(m_actionTwo);
    addAction(m_actionThree);

    connect(m_actionOne, SIGNAL(triggered()), this, SLOT(actionOneSlot()));
    connect(m_actionTwo, SIGNAL(triggered()), this, SLOT(actionTwoSlot()));
    connect(m_actionThree, SIGNAL(triggered()), this, SLOT(actionThreeSlot()));
}

MyButton::~MyButton()
{

}

void MyButton::actionOneSlot()
{
    qDebug()<<tr("one action");
}

void MyButton::actionTwoSlot()
{
    qDebug()<<tr("two action");
}

void MyButton::actionThreeSlot()
{
    qDebug()<<tr("three action");
}


