#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QUdpSocket>

#include <QFile>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QUdpSocket * udpSocket;

    QHostAddress serverIP;
    quint16 serverPort;

    QHostAddress peerRemoteIP;
    quint16 peerRemotePort;

    QStringList filesNames;
    QString fileName;
    void getFilesNames();
    //MainWindow * MW;

    quint16 base;
    quint16 nextSequenceNumber;
    int theNumberOfSequenceNumber;

    QList<int> sentNotYetAckedSequenceNumbers;
    QList<QByteArray> sentNotYetAckedBuffers;

    quint16 checksum(QByteArray);

private slots:
    void on_connect_clicked();

    void on_recvB_clicked();

    void on_pushStartTimer_clicked();

    void on_pushStartTimer_2_clicked();

    void on_createFile_clicked();

    void on_readFile_clicked();

    void on_readChunck_clicked();

    void on_clearText_clicked();

public slots:
    void readyRead();
    void timeout();

signals:
    void stopTheTimer();
    void sendAllTheWindow();



private:
    Ui::MainWindow *ui;
    void timerEvent(QTimerEvent *event);
    int timerId;
    int count;
    QString toHex(QByteArray& qba);//, QString& qsout);
    QFile *mFile;
    bool isFileOpen;
    bool isDone;
    int bytesRead;
    Server * server;
};

#endif // MAINWINDOW_H
