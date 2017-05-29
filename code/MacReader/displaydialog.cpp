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

    BookLayout->addWidget(left,0,0,4,2);
    BookLayout->addWidget(right,0,2,4,2);

    setLayout(BookLayout);



}

DisplayDialog::~DisplayDialog()
{
    delete ui;
}

int DisplayDialog::displayText(){
}

