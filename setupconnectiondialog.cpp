#include "setupconnectiondialog.h"
#include "ui_setupconnectiondialog.h"
#include <QTimer>
#include "mainwindow.h"
#include <QStatusBar>


setupConnectionDialog::setupConnectionDialog(QWidget *parent, MainWindow *pMainwindow) :
    QDialog(parent),
    ui(new Ui::setupConnectionDialog)
{
    // Initialization
    ui->setupUi(this);
    this->pMainwindow = pMainwindow;
    // Form
    setFixedSize(478,190);
    ui->ipAddresslineEdit->setInputMask("000.000.000.000");
    ui->PortlineEdit->setInputMask("99999");
    ui->consolTextEdit->setOverwriteMode(false);
    // Udp Connection
    pSendSocket = new QUdpSocket(this);
    pRecieveSocket = new QUdpSocket(this);
    QHostAddress adr;
    adr.setAddress("169.254.210.210");
    pRecieveSocket->bind(adr, 45454, QUdpSocket::ShareAddress);
    connect(pRecieveSocket, SIGNAL(readyRead()),this, SLOT(processPendingDatagrams()));
    // SLOT & SIGNAL Connection
    connect(ui->connectButton, SIGNAL(clicked()), this, SLOT(tryConnect()));
}

setupConnectionDialog::~setupConnectionDialog()
{
    delete ui;
}

//public slots

////////////////////////////////////////////////////////////////
// connect() : check if inputs are correct and start connection
////////////////////////////////////////////////////////////////
void setupConnectionDialog::tryConnect(){
    bool isEmpty;
    isEmpty = false;
    ipAddress = ui->ipAddresslineEdit->text();
    portNumber = ui->PortlineEdit->text();
    ui->consolTextEdit->setTextColor(QColor("red"));
    if(ipAddress == "..."){
        ui->consolTextEdit->append("Ip Address is empty");
        isEmpty =  true;
    }
    if(portNumber == ""){
        ui->consolTextEdit->append("Port number is empty");
        isEmpty =  true;
    }
    if(isEmpty){
        ui->consolTextEdit->append("Connection failed!");
        return;
    }
    ui->consolTextEdit->setTextColor(QColor("black"));
    ui->consolTextEdit->append("Port Number :"+portNumber);
    ui->consolTextEdit->append("Ip Address  :"+ipAddress);
    ui->consolTextEdit->append("Trying connect ...");
    // send a hello packet
    QByteArray datagram = "Hello";
    QHostAddress adr;
    adr.setAddress("169.254.46.31");
    pSendSocket->writeDatagram(datagram.data(), datagram.size(),adr, 45454);
    ui->consolTextEdit->append("Hello packet sent ...");
    ui->consolTextEdit->append("Waiting for responce ...");
    QTimer::singleShot(3000, this, SLOT(connectionTimedOut()));

}

void setupConnectionDialog ::processPendingDatagrams(){

       while (pRecieveSocket->hasPendingDatagrams()) {
            QByteArray datagram;
            datagram.resize(pRecieveSocket->pendingDatagramSize());
           pRecieveSocket->readDatagram(datagram.data(), datagram.size());
           if(datagram == "Hi!"){
                ui->consolTextEdit->append("OK!");
                 pMainwindow->pStatusLabel->setText("<font color='red'>Not Connected :-(</font>");

                break;
           }
       }
}
////////////////////////////////////////////////////////////////
// connectionTimedouT() : when the board doesn't respond after 3000ms
//                        connection is canceled
////////////////////////////////////////////////////////////////
void setupConnectionDialog::connectionTimedOut(){
    ui->consolTextEdit->setTextColor(QColor("red"));
    ui->consolTextEdit->append("The board doesn't responce");
    ui->consolTextEdit->append("Connection Failed!!");
    ui->consolTextEdit->setTextColor(QColor("black"));


}
