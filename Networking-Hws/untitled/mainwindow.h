
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QUdpSocket>
#include <QTextEdit>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);


    ~MainWindow();

private slots:
    void initSocket();
     void readPendingDatagrams();
    void onConnectClick();

    void onSendClick();


private:
    Ui::MainWindow *ui;
    QUdpSocket *udpSocket;



};

// MAINWINDOW_H
