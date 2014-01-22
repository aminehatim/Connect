#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <setupconnectiondialog.h>
#include <aboutdialog.h>
#include <QLabel>
#include <QComboBox>
#include <QCheckBox>
#include <QMdiArea>
#include "qcustomplot.h"
#include "plotbox.h"
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
    QAction *pInputAction;
    QAction *pTclConsole;
    //plotBox *pInputPlotBox;
    QMdiArea *mdiArea;



public slots:
    void setupConnection();
    void about();
    void AddNewPlotBox();
    void resizeInputSigPlot(QSize newSize);
    void updateMdiArea();

};

#endif // MAINWINDOW_H
