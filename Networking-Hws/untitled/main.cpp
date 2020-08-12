#include "mainwindow.h"
#include <QApplication>
#include <QtNetwork/QUdpSocket>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
