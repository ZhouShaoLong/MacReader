 #include "displaydialog.h"
#include "ui_displaydialog.h"

DisplayDialog::DisplayDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisplayDialog)
{
    ui->setupUi(this);
    this->setFixedSize(900,600);

    QGridLayout * BookLayout = new QGridLayout;
    left = ui->leftBook;
    right = ui->rightBook;

    QPalette pleft = left->palette();
    QPalette pright = right->palette();

    pleft.setBrush(QPalette::Base,QBrush(QColor(255,0,0,0)));
    pright.setBrush(QPalette::Base,QBrush(QColor(255,0,0,0)));

    left->setPalette(pleft);
    right->setPalette(pright);

    left->setReadOnly(true);
    right->setReadOnly(true);

    left->copyAvailable(false);
    right->copyAvailable(false);

//    left->setStyleSheet("QTextEdit{font-color:color;}");


    BookLayout->addWidget(left,0,0,4,2);
    BookLayout->addWidget(right,0,2,4,2);

    BookLayout->setSpacing(70);
    BookLayout->setContentsMargins(30,20,30,20);

    setLayout(BookLayout);

    this->setFocusPolicy(Qt::StrongFocus);
}

DisplayDialog::~DisplayDialog()
{
    delete ui;
    delete right;
    delete left;
    qDebug()<<tr("~DisplayDialog()");
}

int DisplayDialog::displayText(){
//    filePath = QFileDialog::getOpenFileName(this,tr("文件对话框"),"/Users/zhou/Desktop/我的文档/小说",tr("文本文件(*txt)"));
    QFile file(filePath);
    finfo = QFileInfo(filePath);
    this->setWindowTitle(finfo.baseName());

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
       QMessageBox::warning(this,"Warnning","can't open",QMessageBox::Yes);
       return 0;
    }
    QTextStream in(&file);
    pages[page] = 0;
    in.seek(pages[page]);
    left->setText(in.read(530));
    right->setText(in.read(530));
    pages[++page] = in.pos();
    file.close();
    return 0;
}

void DisplayDialog::NextPage()
{
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
       QMessageBox::warning(this,"Warnning","can't open",QMessageBox::Yes);

    }
    QTextStream in(&file);
    in.seek(pages[page]);
    if(in.atEnd()){
        return;
    }
    left->setText(in.read(530));
    right->setText(in.read(530));
    pages[++page] = in.pos();
    file.close();
    qDebug()<<tr("next");
}

void DisplayDialog::PreviousPage()
{
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
       QMessageBox::warning(this,"Warnning","can't open",QMessageBox::Yes);

    }
    QTextStream in(&file);
    page-=2;
    if(page<0){
        page+=2;

        return;
    }
    in.seek(pages[page]);
    left->setText(in.read(530));
    right->setText(in.read(530));
    pages[++page] = in.pos();
    file.close();
    qDebug()<<tr("previous");
}

void DisplayDialog::receivePath(QString path)
{
    filePath = path;
    displayText();
}


//键盘相应函数
void DisplayDialog::keyPressEvent(QKeyEvent *k)
{
    if(k->key()==Qt::Key_Down||k->key()==Qt::Key_Right){
        NextPage();
    }
    if(k->key()==Qt::Key_Up||k->key()==Qt::Key_Left){
        PreviousPage();
    }
}




