#ifndef DISPLAYDIALOG_H
#define DISPLAYDIALOG_H

#include <QDebug>
#include <QKeyEvent>
#include <QTextEdit>
#include <QDialog>
#include <QTimer>
#include <QCloseEvent>
#include <QGridLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextBlock>
#include <QPlainTextEdit>

#include <QMenuBar>
#include <QVBoxLayout>


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

    QString Path;
    QTextEdit * left;
    QTextEdit * right;

    int line,page;
    QString filePath,context;
    QFileInfo finfo;

    int pages[10000];

    int displayText();
    void NextPage();
    void PreviousPage();

public slots:
    void receivePath(QString path);



protected:
    void keyPressEvent(QKeyEvent *k);

};

#endif // DISPLAYDIALOG_H
