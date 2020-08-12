/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Server
{
public:
    QLabel *statusLabel;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *portLabel;
    QLineEdit *PortLineEdit;
    QComboBox *interfacesComboBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *listeningPushButton;
    QPushButton *stoplisteningPushButton;
    QListWidget *onlineUsersListWidget;
    QLabel *onlineUsersLabel;

    void setupUi(QWidget *Server)
    {
        if (Server->objectName().isEmpty())
            Server->setObjectName(QStringLiteral("Server"));
        Server->resize(349, 323);
        statusLabel = new QLabel(Server);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setGeometry(QRect(10, 300, 391, 16));
        layoutWidget = new QWidget(Server);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 331, 82));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        portLabel = new QLabel(layoutWidget);
        portLabel->setObjectName(QStringLiteral("portLabel"));

        horizontalLayout->addWidget(portLabel);

        PortLineEdit = new QLineEdit(layoutWidget);
        PortLineEdit->setObjectName(QStringLiteral("PortLineEdit"));

        horizontalLayout->addWidget(PortLineEdit);

        interfacesComboBox = new QComboBox(layoutWidget);
        interfacesComboBox->setObjectName(QStringLiteral("interfacesComboBox"));

        horizontalLayout->addWidget(interfacesComboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        listeningPushButton = new QPushButton(layoutWidget);
        listeningPushButton->setObjectName(QStringLiteral("listeningPushButton"));

        horizontalLayout_2->addWidget(listeningPushButton);

        stoplisteningPushButton = new QPushButton(layoutWidget);
        stoplisteningPushButton->setObjectName(QStringLiteral("stoplisteningPushButton"));

        horizontalLayout_2->addWidget(stoplisteningPushButton);


        verticalLayout->addLayout(horizontalLayout_2);

        onlineUsersListWidget = new QListWidget(Server);
        onlineUsersListWidget->setObjectName(QStringLiteral("onlineUsersListWidget"));
        onlineUsersListWidget->setGeometry(QRect(10, 100, 331, 191));
        onlineUsersLabel = new QLabel(Server);
        onlineUsersLabel->setObjectName(QStringLiteral("onlineUsersLabel"));
        onlineUsersLabel->setGeometry(QRect(10, 80, 229, 16));
#ifndef QT_NO_SHORTCUT
        portLabel->setBuddy(PortLineEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(Server);

        QMetaObject::connectSlotsByName(Server);
    } // setupUi

    void retranslateUi(QWidget *Server)
    {
        Server->setWindowTitle(QApplication::translate("Server", "Server", 0));
        statusLabel->setText(QApplication::translate("Server", "offline", 0));
        portLabel->setText(QApplication::translate("Server", "Port:", 0));
        listeningPushButton->setText(QApplication::translate("Server", "Start Listening", 0));
        stoplisteningPushButton->setText(QApplication::translate("Server", "Stop Listening", 0));
        onlineUsersLabel->setText(QApplication::translate("Server", "Online Users", 0));
    } // retranslateUi

};

namespace Ui {
    class Server: public Ui_Server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
