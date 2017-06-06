#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include <QAction>
#include <QDebug>

class MyButton : public QPushButton
{
    Q_OBJECT
public:
    MyButton(QWidget *parent = 0);
    ~MyButton();
    QAction *m_actionOne;
    QAction *m_actionTwo;
    QAction *m_actionThree;

protected slots:
    void actionOneSlot();
    void actionTwoSlot();
    void actionThreeSlot();



};

#endif // MYBUTTON_H
