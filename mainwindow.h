#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <setupconnectiondialog.h>
#include <aboutdialog.h>
#include <QLabel>
#include <QComboBox>
#include <QCheckBox>
#include "qcustomplot.h"
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
    QCheckBox *pEditCheckBox;
    QAction *newAction;

public slots:
    void setupConnection();
    void about();
    void hideInputSig();

};

#endif // MAINWINDOW_H
