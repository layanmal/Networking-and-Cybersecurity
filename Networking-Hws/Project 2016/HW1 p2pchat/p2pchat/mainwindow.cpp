#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"iostream"
#include "stdio.h"
#include <QUdpSocket>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   udpSocket=new QUdpSocket(this);

    ui->setupUi(this);

}


MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_send_clicked()
{

    QString sntmsg=ui->sentmessage->toPlainText();

    if(!sntmsg.isEmpty()){
        QByteArray message;
        message.append(sntmsg);//msg

        QHostAddress destIP;
        destIP.setAddress(ui->dstip->text());//ipaddress

        quint16 destport = ui->dstport->text().toInt();//portaddress

        udpSocket->writeDatagram( message, destIP,destport);

    }

}


void MainWindow::readPendingDatagrams()
{
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        QHostAddress senderip;
        quint16 senderPort;

        udpSocket->readDatagram(datagram.data(), datagram.size(),
                                &senderip, &senderPort);




        QString rcvdmsg=datagram.data();



        ui->recievedmessage->append(rcvdmsg);
        rcvdmsg.append("\n");

    }
}



void MainWindow::on_initial_clicked()
{
    QHostAddress srcip;
    srcip.setAddress(ui->srcip->text());//ipaddress

    quint16 srcport = ui->srcport->text().toInt();//portaddress

    udpSocket->bind(srcip,srcport);
    connect(udpSocket, SIGNAL(readyRead()),this, SLOT(readPendingDatagrams()));

}
