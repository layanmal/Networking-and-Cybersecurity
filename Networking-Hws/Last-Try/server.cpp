#include "server.h"
#include "ui_server.h"

server::server(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::server)
{
    ui->setupUi(this);
   serverr = new QTcpServer(8888);
     connect(serverr, SIGNAL(newConnection()), this, SLOT(acceptConnection()));

}

server::~server()
{
    delete ui;
}

void MainWindow::acceptConnection()
{
   startListening();
 clientSocket = serverr->nextPendingConnection();

 connect(clientSocket, SIGNAL(readyRead()), this, SLOT(readClientData()));

}
void MainWindow::readClientData()
{
 char buffer[2048] = {0};
 qDebug() << "receiving ..";
 //QTcpSocket* cl = qobject_cast<QTcpSocket*>(QObject::sender());

 File = ;
 QTcpSocket* cl = clientSocket;
 int bytesReceived = cl->bytesAvailable();
 cl->read(buffer, bytesReceived);
 PACKET *pkt = (PACKET *)buffer;
 pkt;
 // for example pkt->type ... packet->data ..etc
}

void MainWindow::Browse(){
    if (!File.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

    QString filePath = QFileDialog::getOpenFileName(this, "Select the file", "../");
    if(!filePath.isEmpty())
        {
            fileName.clear();
            fileSize = 0;
            QFileInfo info(filePath);
            fileName = info.fileName();
            fileSize = info.size();
            sendSize = 0;
            File.setFileName(filePath);

      }

        QTextStream in(&File);
        while (!in.atEnd()) {
            data = clientSocket-> readAll();
            temp.clear();
            temp = data.left(1000);
            data.remove(0,1000);
            emit dataArrive(temp);
        }



}

MainWindow::startListening()
{

 server->listen(QHostAddress(QHostAddress::Any, 8888);
}
// you need to read the data from a file of max 1k bytes and send it
 MainWindow::sendData(QString filename)
 {
     QFile sent(filename);
     int size=0;
     while(true){
     datagram d;
     size= File.read(pkt->data,pkt->length);
     if(size==0)break;
     d.type=file;
     d.size=size;

 }
     File.close();

 clientSocket->write((const char *)pkt, sizeof(pkt));
 }

 void MainWindow::on_Connect_clicked(){
     acceptConnection();
 }
