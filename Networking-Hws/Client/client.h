#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QtCore>
#include <QList>
#include <QtNetwork>
#include <QUdpSocket>
#include <QTcpSocket>
#include <QMessageBox>

 enum Type{text,fileRequest,fileResponse,ack,file};
#pragma pack(1);
class datagram{
public:
    Type type;
    char  data[1026];
    unsigned int size=0;
    unsigned int seq=0;
    unsigned short checksum=0;


};
namespace Ui {
class Client;
}

class Client : public QWidget
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);
    ~Client();


    QList<QHostAddress> interfacesIPs;

    QTcpSocket * clientSocket;
    QUdpSocket * udpSocket;

        QMessageBox msgBox;
    QString username;

    QHostAddress serverIP;
    quint16 serverPort;

    QHostAddress peerIP;
    quint16 peerPort;

    QHostAddress peerFileIP;
    quint16 peerFilePort;

    QHostAddress peerRemoteIP;
    quint16 peerRemotePort;

    bool interfacesIPsQListInitialized;
    void interfaces();

    QList<QString>clientsUsernames;
    QList<QHostAddress> clientsAddresses;
    QList<quint16> clientsPorts;

    QList<datagram> window;
    QList<datagram> sent;
    int windowSize=5;
    int left=0;
    int ackCounter=0;
    unsigned int currentSeq=0;
    unsigned int recvSeq=0;
    QByteArray recvFile;
    QString recvFileName;
    unsigned int recvSize=0;
    QFile  File;
    QTimer * timer;
    int timeout=500;

void saveFile();
    void setSequance(datagram & d);
void sendAck(QHostAddress address,int port);
void sendPrevAck(QHostAddress address,int port);
void moveLeft(int steps);
public slots:
    void connected();
    void disconnected();
    void readyReadQTcpSocket();
    void readyReadQUdpSocket();

bool isInRange(int seq);
void sendFile();
private slots:
void sendFileResponse(QAbstractButton *);
void resend();
    void on_loginPushButton_clicked();

    void on_interfacesComboBox_currentIndexChanged(int index);

    void on_onlineUsersListWidget_clicked(const QModelIndex &index);

    void on_logoutPushButton_clicked();

    void on_sendPushButton_clicked();

    void on_msgLineEdit_returnPressed();

    void on_sendFile_button_clicked();
    void rdt_send();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::Client *ui;
    void updateOnlineUsersListWidget(QStringList clientsOnlineInformationQStringList);
    void clear();
};

#endif // CLIENT_H
