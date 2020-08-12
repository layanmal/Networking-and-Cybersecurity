#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include "stdio.h"

#include <QtNetwork/QUdpSocket>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    udpSocket = new QUdpSocket(this);
    ui->setupUi(this);
}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow:: initSocket(){
    int port = ui->myPort->text().toInt();

    udpSocket->bind(QHostAddress(ui->myIP->text()),port);

}

void MainWindow::onConnectClick(){
connect(udpSocket, SIGNAL(readyRead()),
          this, SLOT(readPendingDatagrams()));
}

void MainWindow::readPendingDatagrams(){
    while (udpSocket->hasPendingDatagrams()) {
           QByteArray datagram;
           datagram.resize(udpSocket->pendingDatagramSize());
           QHostAddress senderip;
           quint16 senderPort;

           udpSocket->readDatagram(datagram.data(), datagram.size(),
                                   &senderip, &senderPort);

           QString rcvdm=datagram.data();

          QString sender = "Ghadir: ";
         ui->Chat->append(sender);

           ui->Chat->append(rcvdm);
           rcvdm.append("\n");

}

 }
void MainWindow::onSendClick(){
    printf("let that shit go");
    QString  me = "You: ";
     ui->Chat->append(me);
   QString sendm = ui ->input->toPlainText();
    if(!sendm.isEmpty()){
        QByteArray msg;

        msg.append(sendm);//msg

  QHostAddress dstIP;
        dstIP.setAddress(ui->yourIP->text());//ipaddress

        quint16   dstport = ui->yourPort->text().toInt();//portaddress

        udpSocket->writeDatagram( msg, dstIP,dstport);

        ui->Chat->append(me);
        ui->Chat->append(sendm);
       sendm.append("\n");

    }
}
