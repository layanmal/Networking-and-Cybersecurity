#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QByteArray encode(QByteArray a){
   char base64[]= "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    int size=a.size()-a.size()%3;
    char e[4];
    char c[3];
    QByteArray s;
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
    else if(x=='/')
        return 63;
    else
        return -1;
}
void check(){
   char base64[]= "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
   for (int i = 0; i < 64; ++i) {
       if (base64[asciToValue(base64[i])]!=base64[i]) {
   qDebug()<<"not equal: "<<i<<" "<<base64[i]<<" "<<QString(asciToValue(base64[i]));
       }

   }
}

QByteArray decode(QByteArray a){
    int index=a.indexOf("=");
    QByteArray b;
    if(index>0)
    a.truncate(index);
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

      b.append(d[0]);
      b.append(d[1]);
      b.append(d[2]);

    }
    size=a.size();

    if(size%4==2){
       c[0]=asciToValue(a[size-2]) ;
       c[1]=asciToValue(a[size-1]) ;
       c[2]=0;

       d[0]=(c[0]<<2)|(c[1]>>4);

       b.append(d[0]);
    }
    else if(size%4==3){
       c[0]=asciToValue(a[size-3]) ;
       c[1]=asciToValue(a[size-2]) ;
       c[2]=asciToValue(a[size-1]) ;
       c[3]=0;

       d[0]=(c[0]<<2)|(c[1]>>4);
       d[1]=(c[1]<<4)|(c[2]>>2);

       b.append(d[0]);
       b.append(d[1]);

    }
    return b;

}

void MainWindow::on_encode_clicked()
{
    QByteArray a;
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Any File"), ".","");
          if(fileName==NULL)return;
          else{
             QFile File(fileName) ;
        File.open(QFile::ReadOnly);
        a=File.readAll();
        ui->textBrowser->setText(QString(a.toHex()));
        QByteArray s=encode(a);

        fb=s;
        ui->textBrowser_2->setText(QString(s));


          }


}

void MainWindow::on_decode_clicked()
{
    check();
    QByteArray a;
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Any File"), ".","");
          if(fileName==NULL)return;
          else{
             QFile File(fileName) ;
        File.open(QFile::ReadOnly);
        a=File.readAll();
        ui->textBrowser->setText(QString(a.toHex()));
        QByteArray s=decode(a);
        fb=s;
        ui->textBrowser_2->setText(QString(s));


          }

}

void MainWindow::on_save_clicked()
{

          QString fileName = QFileDialog::getSaveFileName(this,
                                                          tr("Save the file "),"","");
          if(fileName==NULL)return;
          else{
              QFile File(fileName);
              File.open(QFile::WriteOnly);
              File.write(fb);
          }
}
