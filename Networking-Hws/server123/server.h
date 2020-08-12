#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include <QtCore>
#include <QList>
#include <QtNetwork>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMessageBox>
#include <QString>

namespace Ui {
class Server;
}

class Server : public QWidget
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = 0);
    ~Server();

    QList<QHostAddress> interfacesIPs;
    QTcpServer * serverSocket;
    void interfaces();

    QHostAddress serverIP;
    quint16 serverPort;

    QList<QTcpSocket *> clientsUserSockets;

    QList<QString>clientsUsernames;
    QList<QHostAddress> clientsAddresses;
    QList<quint16> clientsPorts;


public slots:
    void newConnection();
    void disconnected();
    void readyRead();


private slots:
    void on_listeningPushButton_clicked();
    void on_stoplisteningPushButton_clicked();

private:
    Ui::Server *ui;
    void updateOnlineUsersListWidget();
};

#endif // SERVER_H
