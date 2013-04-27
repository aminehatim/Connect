#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // File menu
    ui->menu_File->addAction(tr("&Setup Connection"),this,SLOT(setupConnection()),QKeySequence(tr("Ctrl+s")));
    // Help menu
    ui->menu_Help->addAction(tr("&About"), this, SLOT(about()));

}

MainWindow::~MainWindow()
{
    delete ui;

}


//public slots

//////////////////////////////////////////////////////
// setupConnection() : open setupConnection window
//////////////////////////////////////////////////////

void MainWindow::setupConnection(){
    pSetupConnectionDialog = new setupConnectionDialog;
    pSetupConnectionDialog->show();
}
//////////////////////////////////////////////////////
// about() : open about window
//////////////////////////////////////////////////////
void MainWindow::about(){
    pAboutDialog = new aboutDialog;
    pAboutDialog->show();
}
