#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
#include <QFile>
#define MAX_DATA_SIZE 1024
enum PACKET_TYPES
{
 START,
 ACK,
 DONE,
 DATA,
 //all your types
 MAX_TYPE=0x0FFFF //forces to 16bit
};
struct PACKET {
 PACKET_TYPES type;
 unsigned short length; // number of data bytes not all
 //unsigned long checksum; // add this in the UDP code, to do a check sum
 // other fields

 // --
 unsigned char data[MAX_DATA_SIZE]; // when you compute checksum, add only the bytes
//specified by length
 // or initialize the data to zeros before you fill it and add all
};


namespace Ui {
class server;
}

class server : public QMainWindow
{
    Q_OBJECT

public:
    explicit server(QWidget *parent = 0);
    ~server();
signals:
    void dataArrive(QByteArray ba);

private:

    Ui::server *ui;
    QTcpServer *serverr;
     QTcpSocket* clientSocket;
     //QList <QTcpSocket*> clientList; // if you need multiple connections
     void startListening();
     sendData(PACKET *pkt);

     QFile File();
        QString fileName;// File name
        qint64 fileSize;//File size
        qint64 sendSize;
        QByteArray temp;
        QByteArray data;
    public slots:
       void on_Connect_clicked();
     void acceptConnection();
     void readClientData();

};

#endif // SERVER_H
