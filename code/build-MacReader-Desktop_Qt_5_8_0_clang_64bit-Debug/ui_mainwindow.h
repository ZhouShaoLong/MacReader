/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *ac_login;
    QAction *ac_register;
    QAction *ac_logout;
    QAction *fi_open;
    QAction *actionclose;
    QAction *fi_file1;
    QAction *fi_file2;
    QAction *fi_file3;
    QAction *fi_file4;
    QAction *fi_clean;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *fi_recent;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(605, 416);
        ac_login = new QAction(MainWindow);
        ac_login->setObjectName(QStringLiteral("ac_login"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/icon/count.png"), QSize(), QIcon::Normal, QIcon::Off);
        ac_login->setIcon(icon);
        ac_register = new QAction(MainWindow);
        ac_register->setObjectName(QStringLiteral("ac_register"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/icon/sign_up.png"), QSize(), QIcon::Normal, QIcon::Off);
        ac_register->setIcon(icon1);
        ac_logout = new QAction(MainWindow);
        ac_logout->setObjectName(QStringLiteral("ac_logout"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/icon/out.png"), QSize(), QIcon::Normal, QIcon::Off);
        ac_logout->setIcon(icon2);
        fi_open = new QAction(MainWindow);
        fi_open->setObjectName(QStringLiteral("fi_open"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/icon/openfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        fi_open->setIcon(icon3);
        actionclose = new QAction(MainWindow);
        actionclose->setObjectName(QStringLiteral("actionclose"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/icon/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionclose->setIcon(icon4);
        fi_file1 = new QAction(MainWindow);
        fi_file1->setObjectName(QStringLiteral("fi_file1"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/image/icon/file.png"), QSize(), QIcon::Normal, QIcon::Off);
        fi_file1->setIcon(icon5);
        fi_file2 = new QAction(MainWindow);
        fi_file2->setObjectName(QStringLiteral("fi_file2"));
        fi_file2->setIcon(icon5);
        fi_file3 = new QAction(MainWindow);
        fi_file3->setObjectName(QStringLiteral("fi_file3"));
        fi_file3->setIcon(icon5);
        fi_file4 = new QAction(MainWindow);
        fi_file4->setObjectName(QStringLiteral("fi_file4"));
        fi_file4->setIcon(icon5);
        fi_clean = new QAction(MainWindow);
        fi_clean->setObjectName(QStringLiteral("fi_clean"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/image/icon/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        fi_clean->setIcon(icon6);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 605, 22));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        fi_recent = new QMenu(menu_2);
        fi_recent->setObjectName(QStringLiteral("fi_recent"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/image/icon/files.png"), QSize(), QIcon::Normal, QIcon::Off);
        fi_recent->setIcon(icon7);
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(ac_login);
        menu->addAction(ac_register);
        menu->addAction(ac_logout);
        menu_2->addAction(fi_open);
        menu_2->addAction(fi_recent->menuAction());
        menu_2->addAction(actionclose);
        fi_recent->addAction(fi_file1);
        fi_recent->addAction(fi_file2);
        fi_recent->addAction(fi_file3);
        fi_recent->addAction(fi_file4);
        fi_recent->addSeparator();
        fi_recent->addAction(fi_clean);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        ac_login->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225", Q_NULLPTR));
        ac_register->setText(QApplication::translate("MainWindow", "\346\263\250\345\206\214", Q_NULLPTR));
        ac_logout->setText(QApplication::translate("MainWindow", "\346\263\250\351\224\200", Q_NULLPTR));
        fi_open->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
        actionclose->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\347\252\227\345\217\243", Q_NULLPTR));
        fi_file1->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\2661", Q_NULLPTR));
        fi_file2->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\2662", Q_NULLPTR));
        fi_file3->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\2663", Q_NULLPTR));
        fi_file4->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\2664", Q_NULLPTR));
        fi_clean->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\350\264\246\346\210\267", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", Q_NULLPTR));
        fi_recent->setTitle(QApplication::translate("MainWindow", "\346\234\200\350\277\221\344\275\277\347\224\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
