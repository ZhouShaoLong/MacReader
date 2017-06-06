#include "mybutton.h"


MyButton::MyButton(QWidget *parent)
    : QPushButton(parent)
{
    setContextMenuPolicy(Qt::ActionsContextMenu);

    m_actionOne = new QAction(this);
    m_actionTwo = new QAction(this);

    m_actionOne->setText("打开");
    m_actionTwo->setText("删除");

    addAction(m_actionOne);
    addAction(m_actionTwo);

}

MyButton::~MyButton()
{

}
