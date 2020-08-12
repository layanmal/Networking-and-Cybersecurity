#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_select_clicked();

    void on_encode_clicked();

    void on_decode_clicked();

    void on_save_clicked();

private:
    Ui::MainWindow *ui;
    QByteArray fb;
};

#endif // MAINWINDOW_H
