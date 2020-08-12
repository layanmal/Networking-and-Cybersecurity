/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_server
{
public:
    QWidget *centralWidget;
    QTextEdit *textEdit;
    QPushButton *Connect;
    QPushButton *send;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *server)
    {
        if (server->objectName().isEmpty())
            server->setObjectName(QStringLiteral("server"));
        server->resize(638, 334);
        centralWidget = new QWidget(server);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 20, 431, 261));
        Connect = new QPushButton(centralWidget);
        Connect->setObjectName(QStringLiteral("Connect"));
        Connect->setGeometry(QRect(490, 60, 75, 23));
        send = new QPushButton(centralWidget);
        send->setObjectName(QStringLiteral("send"));
        send->setGeometry(QRect(490, 130, 75, 23));
        server->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(server);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 638, 21));
        server->setMenuBar(menuBar);
        mainToolBar = new QToolBar(server);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        server->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(server);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        server->setStatusBar(statusBar);

        retranslateUi(server);

        QMetaObject::connectSlotsByName(server);
    } // setupUi

    void retranslateUi(QMainWindow *server)
    {
        server->setWindowTitle(QApplication::translate("server", "server", 0));
        Connect->setText(QApplication::translate("server", "Connect", 0));
        send->setText(QApplication::translate("server", "Send", 0));
    } // retranslateUi

};

namespace Ui {
    class server: public Ui_server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
