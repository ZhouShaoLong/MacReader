/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QLabel *label_name;
    QLabel *label_passwd;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_passwd;
    QPushButton *btn_login;
    QPushButton *btn_exit;
    QCheckBox *check_Reme;
    QCheckBox *check_Auto;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(433, 233);
        label_name = new QLabel(LoginDialog);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setGeometry(QRect(80, 50, 60, 16));
        label_passwd = new QLabel(LoginDialog);
        label_passwd->setObjectName(QStringLiteral("label_passwd"));
        label_passwd->setGeometry(QRect(80, 90, 60, 16));
        lineEdit_name = new QLineEdit(LoginDialog);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(190, 40, 113, 21));
        lineEdit_passwd = new QLineEdit(LoginDialog);
        lineEdit_passwd->setObjectName(QStringLiteral("lineEdit_passwd"));
        lineEdit_passwd->setGeometry(QRect(190, 90, 113, 21));
        btn_login = new QPushButton(LoginDialog);
        btn_login->setObjectName(QStringLiteral("btn_login"));
        btn_login->setGeometry(QRect(60, 170, 113, 32));
        btn_exit = new QPushButton(LoginDialog);
        btn_exit->setObjectName(QStringLiteral("btn_exit"));
        btn_exit->setGeometry(QRect(220, 180, 113, 32));
        check_Reme = new QCheckBox(LoginDialog);
        check_Reme->setObjectName(QStringLiteral("check_Reme"));
        check_Reme->setGeometry(QRect(90, 130, 87, 20));
        check_Auto = new QCheckBox(LoginDialog);
        check_Auto->setObjectName(QStringLiteral("check_Auto"));
        check_Auto->setGeometry(QRect(210, 140, 87, 20));

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Dialog", Q_NULLPTR));
        label_name->setText(QApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215:", Q_NULLPTR));
        label_passwd->setText(QApplication::translate("LoginDialog", "\345\257\206\347\240\201:", Q_NULLPTR));
        btn_login->setText(QApplication::translate("LoginDialog", "\347\231\273\345\275\225", Q_NULLPTR));
        btn_exit->setText(QApplication::translate("LoginDialog", "\350\277\224\345\233\236", Q_NULLPTR));
        check_Reme->setText(QApplication::translate("LoginDialog", "\350\256\260\344\275\217\345\257\206\347\240\201", Q_NULLPTR));
        check_Auto->setText(QApplication::translate("LoginDialog", "\350\207\252\345\212\250\347\231\273\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
