#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QLabel>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pStatusBar = new QStatusBar;
    pStatusLabel = new QLabel;

    this->setStatusBar(pStatusBar);
    pStatusLabel->setText("<font color='red'>Not Connected :-(</font>");
    pStatusBar->addPermanentWidget(pStatusLabel);

    // File menu
    ui->menu_File->addAction(tr("&Setup Connection"),this,SLOT(setupConnection()),QKeySequence(tr("Ctrl+s")));
    // Help menu
    ui->menu_Help->addAction(tr("&About"), this, SLOT(about()));
    // Status Bar



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
    pSetupConnectionDialog = new setupConnectionDialog(this ,this);
    pSetupConnectionDialog->show();
}
//////////////////////////////////////////////////////
// about() : open about window
//////////////////////////////////////////////////////
void MainWindow::about(){
    pAboutDialog = new aboutDialog(this);
    pAboutDialog->show();
}
