#ifndef SETUPCONNECTIONDIALOG_H
#define SETUPCONNECTIONDIALOG_H

#include <QDialog>
#include <QtNetwork>

class MainWindow;
namespace Ui {
class setupConnectionDialog;
}

class setupConnectionDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit setupConnectionDialog(QWidget *parent = 0, MainWindow *pMainwindow = 0);
    ~setupConnectionDialog();
    
private:
    Ui::setupConnectionDialog *ui;
    QString portNumber;
    QString ipAddress;
    QUdpSocket *pSendSocket;
    QUdpSocket *pRecieveSocket;
    MainWindow *pMainwindow;
public slots:
    void tryConnect();
    void processPendingDatagrams();
    void connectionTimedOut();
};

#endif // SETUPCONNECTIONDIALOG_H
