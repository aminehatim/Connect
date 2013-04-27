#include "setupconnectiondialog.h"
#include "ui_setupconnectiondialog.h"

setupConnectionDialog::setupConnectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setupConnectionDialog)
{
    ui->setupUi(this);
    setFixedSize(478,190);
    ui->ipAddresslineEdit->setInputMask("000.000.000.000");
    ui->PortlineEdit->setInputMask("99999");
    ui->consolTextEdit->setOverwriteMode(false);
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

}
