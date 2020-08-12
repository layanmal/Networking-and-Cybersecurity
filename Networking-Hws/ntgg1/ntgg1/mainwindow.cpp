#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isDone = false;
    isFileOpen = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connect_clicked()
{

    this->udpSocket = new QUdpSocket();
    connect(this->udpSocket,SIGNAL(readyRead()),this,SLOT(readyRead()));

    //this->timer = new Timer(this);
    connect(this,SIGNAL(timeout()),this,SLOT(timeout()));
    connect(this,SIGNAL(stopTheTimer()),this->timer,SLOT(stopTheTimer()));

    //this->server = new Server(this);
    connect(this,SIGNAL(sendAllTheWindow()),this->sender,SLOT(sendAllTheWindow()));

    this->sentNotYetAckedSequenceNumbers = QList<int>();
    this->sentNotYetAckedBuffers = QList<QByteArray>();

    this->fileName = "";

    this->base=0;
    this->nextSequenceNumber=0;
    this->theNumberOfSequenceNumber = WINDOW_SIZE + 1;

    //this->getInterfaces();

}

void MainWindow::on_recvB_clicked()
{
    ui->recvB->setText("bb");
}

void MainWindow::on_pushStartTimer_clicked()
{
    timerId = startTimer(1000); //every 1000ms => 1sec
    count =0;

   // you can run several timers with different Ids
//    id1 = startTimer(50);     // 50-millisecond timer
//    id2 = startTimer(1000);   // 1-second timer
//    id2 = startTimer(60000);  // 1-minute timer
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    //qDebug() << "Timer ID:" << event->timerId();
    QString qs;
    qs.sprintf("Timer Id %d, event->timerId =%d, count =%d", timerId,event->timerId(), count++);

     ui->lineEdit->setText(qs);
     bytesRead = 0;
}

void MainWindow::on_pushStartTimer_2_clicked()
{
    killTimer(timerId);
}

void MainWindow::on_createFile_clicked()
{
    isDone = false;
    QFile file("a.bbb");
    if (!file.open(QIODevice::WriteOnly))
        return;
    QByteArray ba;
    int size = 1024;
    for (int j=0; j <1; j++)
    {
        ba.clear();
        for (int i =0;i <size; i++) ba[i]=0x0+i%256;
        file.write(ba,ba.size());

        //ba[10]='\n';
    }
    file.close();
}

// Writes a QByteArray bytes in hex to a QString
QString MainWindow::toHex(QByteArray& qba)//, QString& qsout)
{
    QString qsout;
    qsout.clear(); //empty
    for (int i = 0; i < qba.length(); i++)
    {
        //Add to the string just like java or javascript
        qsout += QString().sprintf("%02x ", (unsigned char)qba[i]);
    }
    return qsout;

}
void MainWindow::on_readFile_clicked()
{
    QFile file("a.bbb");
    if (!file.open(QIODevice::ReadOnly)){
        ui->textEdit->setText("Open file failed");
        return;
    }
    int n = file.size();
    QByteArray ba = file.read(n);

    QString qs= toHex(ba);
    //toHex(ba, qs);
    ui->textEdit->setText(qs);
    file.close();


}

void MainWindow::on_readChunck_clicked()
{
    if (isDone) return;
    if(!isFileOpen){
        mFile = new QFile("a.bbb");
        if (!mFile->open(QIODevice::ReadOnly)){
            ui->textEdit->setText("Open file failed");
            return;
        }
        isFileOpen = true;
        ui->textEdit->setText("");
        bytesRead = 0;
        ui->bytesReadEdit->setText(QString().sprintf("%d", bytesRead));
        ui->fileSizeEite->setText(QString().sprintf("%d", mFile->size()));
    }
    // file is Open

    int n = ui->lineEdit_2->text().toInt();
    if (n <=0) return;
    QByteArray ba = mFile->read(n);
    bytesRead += ba.length();
    ui->bytesReadEdit->setText(QString().sprintf("%d", bytesRead));
    QString qs= toHex(ba);
    ui->textEdit->append(qs);
    if(ba.length() < n){
        mFile->close();
        isFileOpen = false;
        ui->textEdit->append("---Done---");
        isDone = true;
        delete mFile;
    }
}

void MainWindow::on_clearText_clicked()
{
    ui->textEdit->setText("");
    isDone = false;
    if(isFileOpen){
        mFile->close();
        isFileOpen = false;
        bytesRead = 0;
    }
}
