#ifndef DISPLAYDIALOG_H
#define DISPLAYDIALOG_H

#include <QDebug>
#include <QTextEdit>
#include <QDialog>
#include <QCloseEvent>
#include <QGridLayout>


namespace Ui {
class DisplayDialog;
}

class DisplayDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DisplayDialog(QWidget *parent = 0);
    ~DisplayDialog();

private:
    Ui::DisplayDialog *ui;
    QTextEdit * left;
    QTextEdit * right;

    int displayText();

};

#endif // DISPLAYDIALOG_H
