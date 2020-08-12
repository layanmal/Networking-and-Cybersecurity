#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QUdpSocket>
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

    void readPendingDatagrams();
    void on_send_clicked();




    void on_initial_clicked();

private:
    Ui::MainWindow *ui;
    QUdpSocket *udpSocket ;
};

#endif // MAINWINDOW_H
