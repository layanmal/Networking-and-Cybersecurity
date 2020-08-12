#include "client.h"
#include "ui_client.h"
#include <QFileDialog>
#include<iostream>
int count=0;
unsigned short base64comm_crc(unsigned short crc, unsigned char rx) {
    const unsigned short base64comm_crc16_table[256] = {   0x0000, 0x1189, 0x2312, 0x329b, 0x4624, 0x57ad, 0x6536, 0x74bf,
                                                           0x8c48, 0x9dc1, 0xaf5a, 0xbed3, 0xca6c, 0xdbe5, 0xe97e, 0xf8f7,
                                                           0x1081, 0x0108, 0x3393, 0x221a, 0x56a5, 0x472c, 0x75b7, 0x643e,
                                                           0x9cc9, 0x8d40, 0xbfdb, 0xae52, 0xdaed, 0xcb64, 0xf9ff, 0xe876,
                                                           0x2102, 0x308b, 0x0210, 0x1399, 0x6726, 0x76af, 0x4434, 0x55bd,
                                                           0xad4a, 0xbcc3, 0x8e58, 0x9fd1, 0xeb6e, 0xfae7, 0xc87c, 0xd9f5,
                                                           0x3183, 0x200a, 0x1291, 0x0318, 0x77a7, 0x662e, 0x54b5, 0x453c,
                                                           0xbdcb, 0xac42, 0x9ed9, 0x8f50, 0xfbef, 0xea66, 0xd8fd, 0xc974,
                                                           0x4204, 0x538d, 0x6116, 0x709f, 0x0420, 0x15a9, 0x2732, 0x36bb,
                                                           0xce4c, 0xdfc5, 0xed5e, 0xfcd7, 0x8868, 0x99e1, 0xab7a, 0xbaf3,
                                                           0x5285, 0x430c, 0x7197, 0x601e, 0x14a1, 0x0528, 0x37b3, 0x263a,
                                                           0xdecd, 0xcf44, 0xfddf, 0xec56, 0x98e9, 0x8960, 0xbbfb, 0xaa72,
                                                           0x6306, 0x728f, 0x4014, 0x519d, 0x2522, 0x34ab, 0x0630, 0x17b9,
                                                           0xef4e, 0xfec7, 0xcc5c, 0xddd5, 0xa96a, 0xb8e3, 0x8a78, 0x9bf1,
                                                           0x7387, 0x620e, 0x5095, 0x411c, 0x35a3, 0x242a, 0x16b1, 0x0738,
                                                           0xffcf, 0xee46, 0xdcdd, 0xcd54, 0xb9eb, 0xa862, 0x9af9, 0x8b70,
                                                           0x8408, 0x9581, 0xa71a, 0xb693, 0xc22c, 0xd3a5, 0xe13e, 0xf0b7,
                                                           0x0840, 0x19c9, 0x2b52, 0x3adb, 0x4e64, 0x5fed, 0x6d76, 0x7cff,
                                                           0x9489, 0x8500, 0xb79b, 0xa612, 0xd2ad, 0xc324, 0xf1bf, 0xe036,
                                                           0x18c1, 0x0948, 0x3bd3, 0x2a5a, 0x5ee5, 0x4f6c, 0x7df7, 0x6c7e,
                                                           0xa50a, 0xb483, 0x8618, 0x9791, 0xe32e, 0xf2a7, 0xc03c, 0xd1b5,
                                                           0x2942, 0x38cb, 0x0a50, 0x1bd9, 0x6f66, 0x7eef, 0x4c74, 0x5dfd,
                                                           0xb58b, 0xa402, 0x9699, 0x8710, 0xf3af, 0xe226, 0xd0bd, 0xc134,
                                                           0x39c3, 0x284a, 0x1ad1, 0x0b58, 0x7fe7, 0x6e6e, 0x5cf5, 0x4d7c,
                                                           0xc60c, 0xd785, 0xe51e, 0xf497, 0x8028, 0x91a1, 0xa33a, 0xb2b3,
                                                           0x4a44, 0x5bcd, 0x6956, 0x78df, 0x0c60, 0x1de9, 0x2f72, 0x3efb,
                                                           0xd68d, 0xc704, 0xf59f, 0xe416, 0x90a9, 0x8120, 0xb3bb, 0xa232,
                                                           0x5ac5, 0x4b4c, 0x79d7, 0x685e, 0x1ce1, 0x0d68, 0x3ff3, 0x2e7a,
                                                           0xe70e, 0xf687, 0xc41c, 0xd595, 0xa12a, 0xb0a3, 0x8238, 0x93b1,
                                                           0x6b46, 0x7acf, 0x4854, 0x59dd, 0x2d62, 0x3ceb, 0x0e70, 0x1ff9,
                                                           0xf78f, 0xe606, 0xd49d, 0xc514, 0xb1ab, 0xa022, 0x92b9, 0x8330,
                                                           0x7bc7, 0x6a4e, 0x58d5, 0x495c, 0x3de3, 0x2c6a, 0x1ef1, 0x0f78};
    return ((crc >> 8) ^ base64comm_crc16_table[rx ^ (crc & 0xff)]);
}
unsigned short ComputeCRC(unsigned char *Buffer, int Len)   {
    unsigned short crc=0x43A6;
    unsigned short i;
    for( i = 0 ; i < Len ; i++)     {
        crc=base64comm_crc(crc,Buffer[i]);
    }
    return crc;
}

unsigned short checksum( unsigned short * a,int size){
    unsigned long sum=0;
    for(int i=0;i<size;i++){
        sum+=a[i];
        sum+=(sum&0x00010000)>>16;
        sum=(sum&0x0000ffff);
    }
    return ~sum;
}
QString encode(QByteArray a){
   char base64[]= "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    int size=a.size()-a.size()%3;
    char e[4];
    char c[3];
    QString s;
    for (int i = 0; i < size; i+=3) {
        c[0]=a[i];
        c[1]=a[i+1];
        c[2]=a[i+2];

        e[0]=(c[0]&0xFC)>>2;
        e[1]=((c[0]&0x03)<<4)|((c[1]&0xF0)>>4);
        e[2]=((c[1]&0x0F)<<2)|((c[2]&0xC0)>>6);
        e[3]=((c[2]&0x3F));
    s.append(base64[e[0]]);
    s.append(base64[e[1]]);
    s.append(base64[e[2]]);
    s.append(base64[e[3]]);
    }
     size= a.size();
    if(size%3==1){
       c[0]=a[size-1] ;
       c[1]=0;

        e[0]=(c[0]&0xFC)>>2;
        e[1]=((c[0]&0x03)<<4)|((c[1]&0xF0)>>4);
        e[2]=((c[1]&0x0F)<<2)|((c[2]&0xC0)>>6);
        e[3]=((c[2]&0x3F));


    s.append(base64[e[0]]);
    s.append(base64[e[1]]);
    s.append("==");
    }
    else if(size%3==2){
       c[0]=a[size-2] ;
        c[1]=a[size-1];
        c[2]=0;

        e[0]=(c[0]&0xFC)>>2;
        e[1]=((c[0]&0x03)<<4)|((c[1]&0xF0)>>4);
        e[2]=((c[1]&0x0F)<<2)|((c[2]&0xC0)>>6);
        e[3]=((c[2]&0x3F));

    s.append(base64[e[0]]);
    s.append(base64[e[1]]);
    s.append(base64[e[2]]);
    s.append("=");
    }
    return s;
}
char asciToValue(char x){
    if(x>='A'&&x<='Z')
        return x-'A';
    else if(x>='a'&&x<='z')
        return x-'a'+26;
    else if(x>='0'&&x<='9')
        return x-'0'+52;
    else if(x=='+')
        return 62;
    else if(x=='-')
        return 63;
    else
        return -1;
}
QString decode(QByteArray a){
    int index=a.indexOf("=");
    if(index>0)
    a.truncate(index);
    QString s;
    int size=a.size()-a.size()%4;
    char c[4];
    char d[3];
    for (int i = 0; i < size; i+=4) {
       c[0]=asciToValue(a[i]) ;
       c[1]=asciToValue(a[i+1]) ;
       c[2]=asciToValue(a[i+2]) ;
       c[3]=asciToValue(a[i+3]) ;
       d[0]=(c[0]<<2)|(c[1]>>4);
       d[1]=(c[1]<<4)|(c[2]>>2);
       d[2]=(c[2]<<6)|(c[3]);

      s.append(d[0]);
      s.append(d[1]);
      s.append(d[2]);

    }
    size=a.size();

    if(size%4==2){
       c[0]=asciToValue(a[size-2]) ;
       c[1]=asciToValue(a[size-1]) ;
       c[2]=0;

       d[0]=(c[0]<<2)|(c[1]>>4);

       s.append(d[0]);
    }
    else if(size%4==3){
       c[0]=asciToValue(a[size-3]) ;
       c[1]=asciToValue(a[size-2]) ;
       c[2]=asciToValue(a[size-1]) ;
       c[3]=0;

       d[0]=(c[0]<<2)|(c[1]>>4);
       d[1]=(c[1]<<4)|(c[2]>>2);

       s.append(d[0]);
       s.append(d[1]);

    }
    return s;

}

void Client::setSequance(datagram & d){
    d.seq=this->currentSeq;
    this->currentSeq++;
    if(currentSeq==windowSize+1)
        currentSeq=0;
}

Client::Client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client)
{
    timer=new QTimer(this);
    ui->setupUi(this);
    qsrand(1);
    qDebug()<<qrand();
        msgBox.setParent(this);
        msgBox.setWindowTitle("File Recived");
        msgBox.setStandardButtons(QMessageBox::Save);
        msgBox.addButton(QMessageBox::Discard);
        msgBox.setDefaultButton(QMessageBox::No);
        msgBox.setWindowModality(Qt::NonModal);
    this->clientSocket = new QTcpSocket();
    this->udpSocket = new QUdpSocket();

    this->interfacesIPsQListInitialized=false;

    this->clientsUsernames = QList<QString>();
    this->clientsAddresses = QList<QHostAddress>();
    this->clientsPorts = QList<quint16>();

    connect(&this->msgBox,SIGNAL(buttonClicked(QAbstractButton *)),this,SLOT(sendFileResponse(QAbstractButton *)));
    connect(this->timer,SIGNAL(timeout()),this,SLOT(resend()));
    connect(this->clientSocket,SIGNAL(connected()),this,SLOT(connected()));
    connect(this->clientSocket,SIGNAL(disconnected()),this,SLOT(disconnected()));

    connect(this->clientSocket,SIGNAL(readyRead()),this,SLOT(readyReadQTcpSocket()));

    connect(this->udpSocket,SIGNAL(readyRead()),this,SLOT(readyReadQUdpSocket()));

    this->interfaces();
    this->interfacesIPsQListInitialized=true;

}

void Client::sendFileResponse(QAbstractButton * b){
    datagram d;
    d.type=fileResponse;
    QString s;
    QString l=b->text();
    std::cout<<"was closed"<<msgBox.close();
    if(!QString::compare(b->text(),"Save")){
        s.append("yes");
          QString fileName = QFileDialog::getSaveFileName(this,
                                                          tr("Save the file "),this->recvFileName,"");
          if(fileName==NULL){
              s.clear();
              s.append("no");
              recvSize=0;
          }
          else{
              recvFileName=fileName;
          }

    }
       else{

        recvSize=0;
        s.append("no");
    }
    memcpy(d.data,s.toStdString().c_str(),s.size()+1);
        setSequance(d);
    d.checksum=checksum((unsigned short  *)&d,sizeof(d)/2);
        window.append(d);
        rdt_send();
}

void Client::interfaces(){
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

Client::~Client()
{
    this->clientSocket->close();
    delete ui;
}

void Client::on_loginPushButton_clicked()
{
    this->username = ui->usernameLineEdit->text();
    if(!username.isEmpty()){
    this->peerIP = QHostAddress(ui->localIPLineEdit->text());

    QString peerPortString = ui->localPortLineEdit->text();
    if(peerPortString.isEmpty()){
        QMessageBox msgBox;
          msgBox.setText("entr your port");
          msgBox.exec();
    }else{
    this->peerPort = peerPortString.toUShort();


    serverIP = QHostAddress(ui->serverIPLineEdit->text());

    QString serverPortString = ui->serverPortLineEdit->text();
    this->serverPort = serverPortString.toUShort();

    if(this->udpSocket->bind(this->peerIP,this->peerPort))
    {
        this->clientSocket->connectToHost(this->serverIP,this->serverPort);

        if(!clientSocket->waitForConnected(3000))
        {
            QMessageBox msgBox;
              msgBox.setText("entr the right server");
              msgBox.exec();
              username.clear();
              udpSocket->close();
            //qDebug()<<"Error:"<<clientSocket->error();
        }

    }
    else
    {
        QMessageBox msgBox;
          msgBox.setText("you are already signed");
          msgBox.exec();
        //qDebug()<<"Local port is reserved!";
    }
    }
    }
    else{
        QMessageBox msgBox;
          msgBox.setText("entr the username");
          msgBox.exec();
    }

}

void Client::on_interfacesComboBox_currentIndexChanged(int index)
{
    if(this->interfacesIPsQListInitialized)
    {
        this->peerIP = this->interfacesIPs.at(index);
    }
    else
    {
        this->peerIP=QHostAddress::LocalHost;
    }

    ui->localIPLineEdit->setText(this->peerIP.toString());

}

void Client::connected()
{

    QByteArray clientInformation;
    clientInformation.append(this->username);
    clientInformation.append(",");
    clientInformation.append(this->peerIP.toString());
    clientInformation.append(",");
    clientInformation.append(QString::number(this->peerPort));
    clientInformation.append(",");


    this->clientSocket->write(clientInformation);

    this->clientSocket->waitForBytesWritten(3000);

}

void Client::disconnected()
{
    clear();
}


void Client::readyReadQTcpSocket()
{
      QByteArray clientsUsersOnlineQByteArray = QByteArray(this->clientSocket->readAll());

      QString clientsUsersOnlineQString = QString(clientsUsersOnlineQByteArray);

      QStringList clientsOnlineInformationQStringList = clientsUsersOnlineQString.split(',');
      clientsOnlineInformationQStringList.removeLast();

      updateOnlineUsersListWidget(clientsOnlineInformationQStringList);

}

void Client::updateOnlineUsersListWidget(QStringList clientsOnlineInformation)
{
    this->clear();

    for(int i=0;i<clientsOnlineInformation.length();i+=3)
    {

        this->clientsUsernames.append(clientsOnlineInformation[i]);
        this->clientsAddresses.append(QHostAddress(clientsOnlineInformation[i+1]));
        this->clientsPorts.append(clientsOnlineInformation[i+2].toUShort());
    }

    foreach(QString username,this->clientsUsernames)
    {
        ui->onlineUsersListWidget->addItem(username);

    }

}

void Client::on_onlineUsersListWidget_clicked(const QModelIndex &index)
{
   this->peerRemoteIP = this->clientsAddresses.at(index.row());
   this->peerRemotePort = this->clientsPorts.at(index.row());

   ui->remoteIPLineEdit->setText(this->peerRemoteIP.toString());
   ui->remotePortLineEdit->setText(QString::number(this->peerRemotePort));

}

void Client::on_logoutPushButton_clicked()
{
    this->clientSocket->close();
    this->udpSocket->close();
}

void Client::clear()
{
    this->clientsUsernames.clear();
    this->clientsAddresses.clear();
    this->clientsPorts.clear();
    ui->onlineUsersListWidget->clear();
}

void Client::on_sendPushButton_clicked()
{
    QList <QListWidgetItem*>l=ui->onlineUsersListWidget->selectedItems();

    if(ui->remotePortLineEdit->text().isEmpty()){
        QMessageBox msgBox;
          msgBox.setText("entr the reciver port number");
          msgBox.exec();
    }else if(ui->remoteIPLineEdit->text().isEmpty()){
        QMessageBox msgBox;
          msgBox.setText("entr the reciver IP number");
          msgBox.exec();
    }else if(ui->localPortLineEdit->text().isEmpty()){
        QMessageBox msgBox;
          msgBox.setText("entr your port number");
          msgBox.exec();
    }else if(ui->localIPLineEdit->text().isEmpty()){
        QMessageBox msgBox;
          msgBox.setText("entr your IP number");
          msgBox.exec();
    }else if(ui->msgLineEdit->text().isEmpty()){
        QMessageBox msgBox;
          msgBox.setText("entre a message");
          msgBox.exec();
    }
    else if(l.size()==0){

        QMessageBox msgBox;
          msgBox.setText("select a user to send to");
          msgBox.exec();
    }
    else{
        datagram d;
        d.type=text;
        d.checksum=0;
        QString s;
        s.append("<");
        s.append(encode(this->ui->msgLineEdit->text().toUtf8()));
        s.append(">");
        memcpy(d.data,s.toStdString().c_str(),s.size()+1);
   unsigned short  sum= ComputeCRC((unsigned char *) &d,sizeof(d)-sizeof(d.checksum));
   d.checksum=sum;
    QByteArray bufferSent((char *)&d,sizeof(d));
    this->udpSocket->writeDatagram(bufferSent,this->peerRemoteIP,this->peerRemotePort);
    ui->chatTextBrowser->append("Me: " + ui->msgLineEdit->text());
    ui->msgLineEdit->setText("");
    this->clientSocket->waitForBytesWritten(3000);
    }
}
bool Client::isInRange(int seq){
    if (sent.isEmpty()){
        return false;
    }
  if(((this->sent.first().seq+5)%6)==seq) {
       return false;
   }
   return true;
}

void Client::resend(){
    this->ui->resend->setText(QString::number(this->ui->resend->text().toInt()+sent.size()));
    /*if(!sent.isEmpty()){

        window.push_front(sent.last());
        std::cout<<"resend : "<<std::endl;
        qDebug()<<sent.last().seq;
        sent.removeLast();
    }*/
    while(!sent.isEmpty()){
        window.push_front(sent.last());
        std::cout<<"resend : "<<std::endl;
        qDebug()<<sent.last().seq;
        sent.removeLast();
    }
    rdt_send();
}
void Client::readyReadQUdpSocket()
{
    QByteArray bufferRecieved;
    bufferRecieved.resize(udpSocket->pendingDatagramSize());

    QHostAddress senderAddress;
    quint16 senderPort;

    this->ui->recv->setText(QString::number(this->ui->recv->text().toInt()+1));
    udpSocket->readDatagram(bufferRecieved.data(),bufferRecieved.size(),&senderAddress,&senderPort);
    datagram * d=(datagram *)bufferRecieved.data();
   unsigned short  sum= checksum((unsigned short *) d,sizeof(*d)/2);
   int x=qrand()%100;
        if(x<this->ui->errorEdit->text().toInt()){

        count++;
        std::cout<<"corrupted: "<<count<<std::endl;
        std::cout<<"with seq: "<<d->seq<<std::endl;
        std::cout<<"left: "<<left<<std::endl;
            sum=1;
        }
   if(sum!=0&&d->type!=text){
    this->ui->errorRec->setText(QString::number(this->ui->errorRec->text().toInt()+1));
       return;
   }
   else if(d->type==text){
   unsigned short  sum= ComputeCRC((unsigned char *) d,sizeof(*d));
   qDebug()<<"sum2: "<< sum;

    int index = this->clientsPorts.indexOf(senderPort);
    QString s;
    s.append(d->data);
    s.remove(0,1);
    s.truncate(s.size()-1);
    qDebug()<<s;
    s=decode(s.toUtf8());
    qDebug()<<s;
    ui->chatTextBrowser->append(this->clientsUsernames.at(index) + ": " + s);
    ui->statusLabel->setText("Received From IP:" + senderAddress.toString() + ", Port:" + QString::number(senderPort) );
   }
   else if(d->type==ack){
    if(isInRange(d->seq)){
        moveLeft(d->seq);
    }
    else{
        ackCounter++;
        if(ackCounter==3){
            this->timer->stop();
            resend();
            ackCounter=0;
        }
    }
   }
   else if(d->seq!=recvSeq){
    sendPrevAck(senderAddress,senderPort);
   }
   else if(d->type==fileRequest){
       recvFile.clear();
       QString s(d->data);
       QStringList dataList=s.split(',');
       recvFileName=dataList.at(0);
       this->recvSize=dataList.at(1).toInt();
        sendAck(senderAddress,senderPort);
        datagram * data=new datagram();
        data->type=fileResponse;
        QMessageBox::StandardButton reply;

        s.clear();
    int index = this->clientsPorts.indexOf(senderPort);
        QString senderName(this->clientsUsernames.at(index));
        msgBox.setText(QString("you have recived file from %1 with size %2 kb do you want to keep it ? ").arg(
                           senderName,QString::number(recvSize/1024.0)));
        if(!msgBox.isVisible()){
        msgBox.show();
        QCoreApplication::processEvents();
      peerFileIP=senderAddress;
      peerFilePort=senderPort;
        }
   }
   else if(d->type==fileResponse){
        sendAck(senderAddress,senderPort);
        QString answer(d->data);
        if(!answer.compare("yes")){

            this->sendFile();
            rdt_send();
        }
   }
   else if(d->type==file){
        sendAck(senderAddress,senderPort);

        recvFile.append(d->data,d->size);
        recvSize-=d->size;
        if(recvSize==0){

            saveFile();
        QMessageBox msgBox;
          msgBox.setText("download completed");
          msgBox.exec();
        }

   }
}


void Client::on_msgLineEdit_returnPressed()
{

    QList <QListWidgetItem*>l=ui->onlineUsersListWidget->selectedItems();
    if(ui->remotePortLineEdit->text().isEmpty()){
        QMessageBox msgBox;
          msgBox.setText("entr the reciver port number");
          msgBox.exec();
    }else if(ui->remoteIPLineEdit->text().isEmpty()){
        QMessageBox msgBox;
          msgBox.setText("entr the reciver IP number");
          msgBox.exec();
    }else if(ui->localPortLineEdit->text().isEmpty()){
        QMessageBox msgBox;
          msgBox.setText("entr your port number");
          msgBox.exec();
    }else if(ui->localIPLineEdit->text().isEmpty()){
        QMessageBox msgBox;
          msgBox.setText("entr your IP number");
          msgBox.exec();
    }else if(ui->msgLineEdit->text().isEmpty()){
        QMessageBox msgBox;
          msgBox.setText("entre a message");
          msgBox.exec();

    }
    else if(l.size()==0){

        QMessageBox msgBox;
          msgBox.setText("select a user to send to");
          msgBox.exec();
    }
            else{
        datagram d;
        d.type=text;
        QString s;
        s.append(this->ui->msgLineEdit->text());
        memcpy(d.data,s.toStdString().c_str(),s.size()+1);
    QByteArray bufferSent((char *)&d,sizeof(d));
    this->udpSocket->writeDatagram(bufferSent,this->peerRemoteIP,this->peerRemotePort);
    ui->chatTextBrowser->append("Me: " + ui->msgLineEdit->text());
    ui->msgLineEdit->setText("");
    this->clientSocket->waitForBytesWritten(3000);
    }
}

void Client::on_sendFile_button_clicked()
{
    QList <QListWidgetItem*>l=ui->onlineUsersListWidget->selectedItems();
    if(l.size()==0){

        QMessageBox msgBox;
          msgBox.setText("select a user to send to");
          msgBox.exec();
          return;
    }
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Any File"), ".","");
    if(fileName==NULL)return;
    this->File.setFileName(fileName);
    File.open(QFile::ReadOnly);
    datagram d;
    d.type=fileRequest;
    QString string;
    int size=File.size();
    string.append(fileName+",");
    string.append(QString::number(size)+",");
    memcpy(d.data,string.toStdString().c_str(),string.size()+1);
    this->setSequance(d);
    d.checksum=checksum((unsigned short  *)&d,sizeof(d)/2);
     QByteArray newData;
    window.append(d);
    rdt_send();
}
void Client::sendFile(){
    int size=0;
    while(true){
    datagram d;
    size=File.read(d.data,sizeof(d.data));
    if(size==0)break;
    d.type=file;
    d.size=size;
    setSequance(d);
    d.checksum=checksum((unsigned short  *)&d,sizeof(d)/2);
    window.append(d);
    //this->udpSocket->writeDatagram(newData,this->peerRemoteIP,this->peerRemotePort);
}
    File.close();
                }
void Client::rdt_send(){
    bool first=true;
    if(sent.size()==0&&window.size()!=0){

    timer->start(timeout);
    }
    for(int i=0;sent.size()<windowSize&&!window.isEmpty();i++){
        datagram d=window.first();
        sent.append(d);
        std::cout<<"sent :";
        std::cout<<d.seq<<std::endl;
        window.removeFirst();
        QByteArray newData;
        newData.setRawData((char *)&d,sizeof(d));
    this->ui->sent->setText(QString::number(this->ui->sent->text().toInt()+1));
        if(recvSize==0)
        this->udpSocket->writeDatagram(newData,this->peerRemoteIP,this->peerRemotePort);
        else
        this->udpSocket->writeDatagram(newData,this->peerFileIP,this->peerFilePort);


    }
}
void Client::sendAck(QHostAddress address,int port){
   datagram d;
   d.type=ack;
   d.seq=recvSeq;
   recvSeq++;
   if(recvSeq==windowSize+1)
       recvSeq=0;
   QByteArray newData;
    d.checksum=checksum((unsigned short  *)&d,sizeof(d)/2);
   newData.setRawData((char *)&d,sizeof(d));
   this->udpSocket->writeDatagram(newData,address,port);
}
void Client::sendPrevAck(QHostAddress address,int port){
    datagram d;
    d.type=ack;
    d.seq=(recvSeq+5)%6;
    QByteArray newData;
    d.checksum=checksum((unsigned short  *)&d,sizeof(d)/2);
    newData.setRawData((char *)&d,sizeof(d));
    this->udpSocket->writeDatagram(newData,address,port);
}
void Client::moveLeft(int seq){
    datagram d;
    int i=0;
    bool found=false;
    this->timer->stop();
    for (i = 0;! sent.isEmpty(); ++i) {
       d=sent.first();
       if(d.seq==seq){
           found=true;
           break;
       }
       sent.removeFirst();
    }
    if(found){
    sent.removeFirst();
        if(sent.size()!=0){
        this->timer->start(timeout);
        }
        rdt_send();
    }
}
void Client::saveFile(){

   QFile f;
   f.setFileName(recvFileName);
   f.open(QFile::WriteOnly);
   f.write(recvFile);
   f.close();
}

void Client::on_lineEdit_textChanged(const QString &arg1)
{
    QByteArray a;
    a.append(arg1);
   QString s=encode(a);
   qDebug()<<"enc "<<s;
   a.clear();
   a.append(s);
    qDebug()<<"dec "<<decode(a);
}
