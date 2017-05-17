/********************************************************************************
** Form generated from reading UI file 'registdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTDIALOG_H
#define UI_REGISTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RegistDialog
{
public:
    QLabel *label_name;
    QLabel *label_passwd1;
    QLabel *label_passwd2;
    QLabel *label_email;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_passwd1;
    QLineEdit *lineEdit_passwd2;
    QLineEdit *lineEdit_email;
    QPushButton *btn_Regist;
    QPushButton *btn_Exit;

    void setupUi(QDialog *RegistDialog)
    {
        if (RegistDialog->objectName().isEmpty())
            RegistDialog->setObjectName(QStringLiteral("RegistDialog"));
        RegistDialog->resize(377, 231);
        label_name = new QLabel(RegistDialog);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setGeometry(QRect(70, 40, 60, 16));
        label_passwd1 = new QLabel(RegistDialog);
        label_passwd1->setObjectName(QStringLiteral("label_passwd1"));
        label_passwd1->setGeometry(QRect(60, 70, 60, 16));
        label_passwd2 = new QLabel(RegistDialog);
        label_passwd2->setObjectName(QStringLiteral("label_passwd2"));
        label_passwd2->setGeometry(QRect(60, 100, 60, 16));
        label_email = new QLabel(RegistDialog);
        label_email->setObjectName(QStringLiteral("label_email"));
        label_email->setGeometry(QRect(60, 140, 60, 16));
        lineEdit_name = new QLineEdit(RegistDialog);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(150, 30, 113, 21));
        lineEdit_passwd1 = new QLineEdit(RegistDialog);
        lineEdit_passwd1->setObjectName(QStringLiteral("lineEdit_passwd1"));
        lineEdit_passwd1->setGeometry(QRect(140, 70, 113, 21));
        lineEdit_passwd2 = new QLineEdit(RegistDialog);
        lineEdit_passwd2->setObjectName(QStringLiteral("lineEdit_passwd2"));
        lineEdit_passwd2->setGeometry(QRect(140, 100, 113, 21));
        lineEdit_email = new QLineEdit(RegistDialog);
        lineEdit_email->setObjectName(QStringLiteral("lineEdit_email"));
        lineEdit_email->setGeometry(QRect(150, 140, 113, 21));
        btn_Regist = new QPushButton(RegistDialog);
        btn_Regist->setObjectName(QStringLiteral("btn_Regist"));
        btn_Regist->setGeometry(QRect(30, 190, 113, 32));
        btn_Exit = new QPushButton(RegistDialog);
        btn_Exit->setObjectName(QStringLiteral("btn_Exit"));
        btn_Exit->setGeometry(QRect(160, 190, 113, 32));

        retranslateUi(RegistDialog);

        QMetaObject::connectSlotsByName(RegistDialog);
    } // setupUi

    void retranslateUi(QDialog *RegistDialog)
    {
        RegistDialog->setWindowTitle(QApplication::translate("RegistDialog", "Dialog", Q_NULLPTR));
        label_name->setText(QApplication::translate("RegistDialog", "\347\224\250\346\210\267\345\220\215:", Q_NULLPTR));
        label_passwd1->setText(QApplication::translate("RegistDialog", "\345\257\206\347\240\201:", Q_NULLPTR));
        label_passwd2->setText(QApplication::translate("RegistDialog", "\347\241\256\350\256\244\345\257\206\347\240\201:", Q_NULLPTR));
        label_email->setText(QApplication::translate("RegistDialog", "\351\202\256\347\256\261:", Q_NULLPTR));
        btn_Regist->setText(QApplication::translate("RegistDialog", "\346\263\250\345\206\214", Q_NULLPTR));
        btn_Exit->setText(QApplication::translate("RegistDialog", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RegistDialog: public Ui_RegistDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTDIALOG_H
