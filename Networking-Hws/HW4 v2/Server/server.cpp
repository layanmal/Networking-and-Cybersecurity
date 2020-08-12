#include "server.h"
#include "ui_server.h"
#include <QDebug>

Server::Server(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);

    serverSocket = new QTcpServer();

    this->clientsUsernames = QList<QString>();
    this->clientsAddresses = QList<QHostAddress>();
    this->clientsPorts = QList<quint16>();

    connect(this->serverSocket,SIGNAL(newConnection()),this,SLOT(newConnection()));
    this->interfaces();


}

Server::~Server()
{
    delete ui;
}

void Server::on_listeningPushButton_clicked()
{
    this->serverIP = this->interfacesIPs.at(ui->interfacesComboBox->currentIndex());
    qDebug()<<ui->interfacesComboBox->currentText();
    QString serverPortString = ui->PortLineEdit->text();
    if(!serverPortString.isEmpty()){
    this->serverPort = serverPortString.toUShort();
       bool x = this->serverSocket->listen(serverIP,serverPort);
    if(x){
        ui->statusLabel->setText("online on address:"+this->serverIP.toString()+" and port:"+serverPortString);
    }else{
        QMessageBox msgBox;
          msgBox.setText("try to use another port number");
          int ret = msgBox.exec();
          switch (ret) {
            case QMessageBox::Ok:
              //exit(0);
              break;}
        //ui->statusLabel->setText("offline try to use another port number");
    }
    }else{
        QMessageBox msgBox;
          msgBox.setText("entr the port number");
          msgBox.exec();

    }
}

void Server::on_stoplisteningPushButton_clicked(){
    serverSocket->close();
    ui->statusLabel->setText("offline");
    this->clientsUserSockets.clear();
    this->clientsUsernames.clear();
    this->clientsAddresses.clear();
    this->clientsPorts.clear();
    updateOnlineUsersListWidget();
}

void Server::newConnection()
{

         QTcpSocket *clientSocket = this->serverSocket->nextPendingConnection();

         this->clientsUserSockets.append(clientSocket);

         connect(clientSocket, SIGNAL(readyRead()),this,SLOT(readyRead()));
         connect(clientSocket, SIGNAL(disconnected()),this,SLOT(disconnected()));
}

void Server::disconnected()
{

    QTcpSocket *socket = static_cast<QTcpSocket*>(sender());

    int index = this->clientsUserSockets.indexOf(socket);

    this->clientsUserSockets.removeOne(socket);

    this->clientsUsernames.removeAt(index);
    this->clientsAddresses.removeAt(index);
    this->clientsPorts.removeAt(index);

    updateOnlineUsersListWidget();

}

void Server::readyRead()
{
    QTcpSocket *socket = static_cast<QTcpSocket*>(sender());

    QString clientInformation = socket->readAll();
    QStringList clientInformationList = clientInformation.split(',');

    this->clientsUsernames.append(clientInformationList[0]);
    this->clientsAddresses.append(QHostAddress(clientInformationList[1]));
    this->clientsPorts.append(clientInformationList[2].toUShort());

    updateOnlineUsersListWidget();

}

void Server::interfaces(){

    QList<QNetworkInterface> networkInterfaces = QNetworkInterface::allInterfaces();

    bool hasAddressEntry = false;
    QString interfaceName;

    foreach(QNetworkInterface interface,networkInterfaces)
    {

        QList<QNetworkAddressEntry> addressEntry = interface.addressEntries();

        QNetworkAddressEntry entry=addressEntry.last();

                interfaceName = interface.humanReadableName();

                    ui->interfacesComboBox->addItem(interfaceName);

                hasAddressEntry = true;


            QHostAddress address = entry.ip();


                   this->interfacesIPs.append(address);


    }
}

void Server::updateOnlineUsersListWidget()
{

    QByteArray clientsUsersOnline;

    ui->onlineUsersListWidget->clear();

    for(int i=0;i<this->clientsUsernames.length();i++)
    {
        clientsUsersOnline.append(this->clientsUsernames.at(i));
        ui->onlineUsersListWidget->addItem(this->clientsUsernames.at(i));
        clientsUsersOnline.append(",");
        clientsUsersOnline.append(this->clientsAddresses.at(i).toString());
        clientsUsersOnline.append(",");
        clientsUsersOnline.append(QString::number(this->clientsPorts.at(i)));
        clientsUsersOnline.append(",");
    }



    foreach (QTcpSocket * clientSocket, clientsUserSockets)
    {
        clientSocket->write(clientsUsersOnline);

        clientSocket->flush();

        clientSocket->waitForBytesWritten(3000);
    }
}




