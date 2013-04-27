#ifndef SETUPCONNECTIONDIALOG_H
#define SETUPCONNECTIONDIALOG_H

#include <QDialog>

namespace Ui {
class setupConnectionDialog;
}

class setupConnectionDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit setupConnectionDialog(QWidget *parent = 0);
    ~setupConnectionDialog();
    
private:
    Ui::setupConnectionDialog *ui;
    QString portNumber;
    QString ipAddress;
public slots:
    void tryConnect();
};

#endif // SETUPCONNECTIONDIALOG_H
