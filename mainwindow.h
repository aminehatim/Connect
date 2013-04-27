#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <setupconnectiondialog.h>
#include <aboutdialog.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    setupConnectionDialog *pSetupConnectionDialog;
    aboutDialog *pAboutDialog;
public slots:
    void setupConnection();
    void about();

};

#endif // MAINWINDOW_H
