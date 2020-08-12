/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *Connect;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *myPort;
    QLineEdit *myIP;
    QLabel *label_3;
    QLineEdit *yourIP;
    QLabel *label_4;
    QLineEdit *yourPort;
    QPushButton *Send;
    QTextEdit *Chat;
    QTextEdit *input;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(754, 354);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Connect = new QPushButton(centralWidget);
        Connect->setObjectName(QStringLiteral("Connect"));
        Connect->setGeometry(QRect(550, 0, 161, 61));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(540, 70, 151, 21));
        label->setTextFormat(Qt::AutoText);
        label->setScaledContents(false);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(540, 120, 171, 16));
        myPort = new QLineEdit(centralWidget);
        myPort->setObjectName(QStringLiteral("myPort"));
        myPort->setGeometry(QRect(540, 140, 191, 21));
        myIP = new QLineEdit(centralWidget);
        myIP->setObjectName(QStringLiteral("myIP"));
        myIP->setGeometry(QRect(540, 90, 191, 21));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(540, 170, 181, 16));
        yourIP = new QLineEdit(centralWidget);
        yourIP->setObjectName(QStringLiteral("yourIP"));
        yourIP->setGeometry(QRect(540, 190, 191, 20));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(540, 220, 161, 16));
        yourPort = new QLineEdit(centralWidget);
        yourPort->setObjectName(QStringLiteral("yourPort"));
        yourPort->setGeometry(QRect(540, 240, 191, 20));
        Send = new QPushButton(centralWidget);
        Send->setObjectName(QStringLiteral("Send"));
        Send->setGeometry(QRect(394, 270, 111, 31));
        Chat = new QTextEdit(centralWidget);
        Chat->setObjectName(QStringLiteral("Chat"));
        Chat->setGeometry(QRect(10, 10, 511, 201));
        input = new QTextEdit(centralWidget);
        input->setObjectName(QStringLiteral("input"));
        input->setGeometry(QRect(10, 220, 511, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 754, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        Connect->setText(QApplication::translate("MainWindow", "Connect", 0));
        label->setText(QApplication::translate("MainWindow", "Enter your IP Address: ", 0));
        label_2->setText(QApplication::translate("MainWindow", "Choose an available port number:", 0));
        label_3->setText(QApplication::translate("MainWindow", "Your friend IP address", 0));
        label_4->setText(QApplication::translate("MainWindow", "Your friend's port  number:", 0));
        Send->setText(QApplication::translate("MainWindow", "Send !", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
