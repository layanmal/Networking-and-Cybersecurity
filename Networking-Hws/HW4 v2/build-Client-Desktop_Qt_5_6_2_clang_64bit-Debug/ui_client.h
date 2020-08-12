/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTextBrowser *chatTextBrowser;
    QLineEdit *msgLineEdit;
    QPushButton *sendPushButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *usernameLabel;
    QLineEdit *usernameLineEdit;
    QPushButton *loginPushButton;
    QPushButton *logoutPushButton;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_3;
    QLabel *serverPortLabel;
    QLineEdit *serverPortLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *serverIPLabel;
    QLineEdit *serverIPLineEdit;
    QComboBox *interfacesComboBox;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_5;
    QLabel *localPortLabel;
    QLineEdit *localPortLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *localIPLabel;
    QLineEdit *localIPLineEdit;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout_7;
    QLabel *remotePortLabel;
    QLineEdit *remotePortLineEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *remoteIPLabel;
    QLineEdit *remoteIPLineEdit;
    QLabel *statusLabel;
    QListWidget *onlineUsersListWidget;
    QLabel *onlineUsersLabel;
    QPushButton *pushButton;

    void setupUi(QWidget *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QStringLiteral("Client"));
        Client->resize(838, 462);
        layoutWidget = new QWidget(Client);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 371, 431));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(layoutWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 357, 361));
        chatTextBrowser = new QTextBrowser(scrollAreaWidgetContents);
        chatTextBrowser->setObjectName(QStringLiteral("chatTextBrowser"));
        chatTextBrowser->setGeometry(QRect(0, 0, 361, 371));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        msgLineEdit = new QLineEdit(layoutWidget);
        msgLineEdit->setObjectName(QStringLiteral("msgLineEdit"));

        verticalLayout->addWidget(msgLineEdit);

        sendPushButton = new QPushButton(layoutWidget);
        sendPushButton->setObjectName(QStringLiteral("sendPushButton"));

        verticalLayout->addWidget(sendPushButton);

        layoutWidget1 = new QWidget(Client);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(390, 0, 431, 170));
        verticalLayout_4 = new QVBoxLayout(layoutWidget1);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        usernameLabel = new QLabel(layoutWidget1);
        usernameLabel->setObjectName(QStringLiteral("usernameLabel"));

        horizontalLayout->addWidget(usernameLabel);

        usernameLineEdit = new QLineEdit(layoutWidget1);
        usernameLineEdit->setObjectName(QStringLiteral("usernameLineEdit"));

        horizontalLayout->addWidget(usernameLineEdit);

        loginPushButton = new QPushButton(layoutWidget1);
        loginPushButton->setObjectName(QStringLiteral("loginPushButton"));

        horizontalLayout->addWidget(loginPushButton);

        logoutPushButton = new QPushButton(layoutWidget1);
        logoutPushButton->setObjectName(QStringLiteral("logoutPushButton"));

        horizontalLayout->addWidget(logoutPushButton);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        serverPortLabel = new QLabel(layoutWidget1);
        serverPortLabel->setObjectName(QStringLiteral("serverPortLabel"));

        horizontalLayout_3->addWidget(serverPortLabel);

        serverPortLineEdit = new QLineEdit(layoutWidget1);
        serverPortLineEdit->setObjectName(QStringLiteral("serverPortLineEdit"));

        horizontalLayout_3->addWidget(serverPortLineEdit);


        horizontalLayout_8->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        serverIPLabel = new QLabel(layoutWidget1);
        serverIPLabel->setObjectName(QStringLiteral("serverIPLabel"));

        horizontalLayout_2->addWidget(serverIPLabel);

        serverIPLineEdit = new QLineEdit(layoutWidget1);
        serverIPLineEdit->setObjectName(QStringLiteral("serverIPLineEdit"));

        horizontalLayout_2->addWidget(serverIPLineEdit);


        horizontalLayout_8->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout_8);

        interfacesComboBox = new QComboBox(layoutWidget1);
        interfacesComboBox->setObjectName(QStringLiteral("interfacesComboBox"));

        verticalLayout_4->addWidget(interfacesComboBox);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        localPortLabel = new QLabel(layoutWidget1);
        localPortLabel->setObjectName(QStringLiteral("localPortLabel"));

        horizontalLayout_5->addWidget(localPortLabel);

        localPortLineEdit = new QLineEdit(layoutWidget1);
        localPortLineEdit->setObjectName(QStringLiteral("localPortLineEdit"));

        horizontalLayout_5->addWidget(localPortLineEdit);


        horizontalLayout_9->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        localIPLabel = new QLabel(layoutWidget1);
        localIPLabel->setObjectName(QStringLiteral("localIPLabel"));

        horizontalLayout_4->addWidget(localIPLabel);

        localIPLineEdit = new QLineEdit(layoutWidget1);
        localIPLineEdit->setObjectName(QStringLiteral("localIPLineEdit"));

        horizontalLayout_4->addWidget(localIPLineEdit);


        horizontalLayout_9->addLayout(horizontalLayout_4);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        remotePortLabel = new QLabel(layoutWidget1);
        remotePortLabel->setObjectName(QStringLiteral("remotePortLabel"));

        horizontalLayout_7->addWidget(remotePortLabel);

        remotePortLineEdit = new QLineEdit(layoutWidget1);
        remotePortLineEdit->setObjectName(QStringLiteral("remotePortLineEdit"));

        horizontalLayout_7->addWidget(remotePortLineEdit);


        horizontalLayout_10->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        remoteIPLabel = new QLabel(layoutWidget1);
        remoteIPLabel->setObjectName(QStringLiteral("remoteIPLabel"));

        horizontalLayout_6->addWidget(remoteIPLabel);

        remoteIPLineEdit = new QLineEdit(layoutWidget1);
        remoteIPLineEdit->setObjectName(QStringLiteral("remoteIPLineEdit"));

        horizontalLayout_6->addWidget(remoteIPLineEdit);


        horizontalLayout_10->addLayout(horizontalLayout_6);


        verticalLayout_4->addLayout(horizontalLayout_10);

        statusLabel = new QLabel(Client);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setGeometry(QRect(20, 440, 43, 21));
        onlineUsersListWidget = new QListWidget(Client);
        onlineUsersListWidget->setObjectName(QStringLiteral("onlineUsersListWidget"));
        onlineUsersListWidget->setGeometry(QRect(390, 194, 191, 241));
        onlineUsersLabel = new QLabel(Client);
        onlineUsersLabel->setObjectName(QStringLiteral("onlineUsersLabel"));
        onlineUsersLabel->setGeometry(QRect(390, 170, 81, 31));
        pushButton = new QPushButton(Client);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(582, 191, 251, 251));
#ifndef QT_NO_SHORTCUT
        usernameLabel->setBuddy(usernameLineEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QWidget *Client)
    {
        Client->setWindowTitle(QApplication::translate("Client", "Client", 0));
        sendPushButton->setText(QApplication::translate("Client", "Send", 0));
        usernameLabel->setText(QApplication::translate("Client", "Username:", 0));
        loginPushButton->setText(QApplication::translate("Client", "Login", 0));
        logoutPushButton->setText(QApplication::translate("Client", "Logout", 0));
        serverPortLabel->setText(QApplication::translate("Client", "Server Port: ", 0));
        serverIPLabel->setText(QApplication::translate("Client", "Server IP:   ", 0));
        localPortLabel->setText(QApplication::translate("Client", "My Port:       ", 0));
        localIPLabel->setText(QApplication::translate("Client", "My IP:       ", 0));
        remotePortLabel->setText(QApplication::translate("Client", "Reciver Port:", 0));
        remoteIPLabel->setText(QApplication::translate("Client", "Reciver IP:", 0));
        statusLabel->setText(QString());
        onlineUsersLabel->setText(QApplication::translate("Client", "Online Users:", 0));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
