#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <setupconnectiondialog.h>
#include <aboutdialog.h>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QStatusBar *pStatusBar;
    QLabel *pStatusLabel;
private:
    Ui::MainWindow *ui;
    setupConnectionDialog *pSetupConnectionDialog;
    aboutDialog *pAboutDialog;

public slots:
    void setupConnection();
    void about();

};

#endif // MAINWINDOW_H
