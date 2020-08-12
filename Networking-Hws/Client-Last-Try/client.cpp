#include "client.h"
#include "ui_client.h"

client::client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);
    clientSocket = new QTcpSocket(0);
     clientSocket->connectToHost(QHostAddress::LocalHost,8888);
     if(clientSocket->waitForConnected(1000))
     {
    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(onReceiveFromServer()));
     }
}

client::~client()
{
    delete ui;
}

MainWindow::sendData(PACKET *pkt)
{
clientSocket->write((const char *)pkt, sizeof(pkt));
}

void MainWindow:: onReceiveFromServer ()
{
 char buffer[2048] = {0}; // make it bigger than your packet
 qDebug() << "receiving ..";
 int bytesReceived = clientSocket ->bytesAvailable();
 cl->read(buffer, bytesReceived);
 PACKET *pkt = (PACKET *)buffer; // use tis to access the fields of your PACKET
 // for example pkt->type ... packet->data ..etc
}
