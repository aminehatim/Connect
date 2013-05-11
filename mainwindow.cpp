#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QLabel>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //setup
    ui->setupUi(this);
    pStatusBar = new QStatusBar;
    pStatusLabel = new QLabel;
    pEditCheckBox = new QCheckBox;
    // status bar
    this->setStatusBar(pStatusBar);
    pStatusLabel->setText("<font color='red'>Not Connected :-(</font>");
    pStatusBar->addPermanentWidget(pStatusLabel);
    // plot widget
    ui->inputWidget->addGraph();
    ui->inputWidget->xAxis->setLabel("x");
    ui->inputWidget->yAxis->setLabel("y");
    ui->inputWidget->setTitle("Inpit signal");
    // File menu
    ui->menu_File->addAction(tr("&Setup Connection"),this,SLOT(setupConnection()),QKeySequence(tr("Ctrl+s")));
    // Edit menu
    newAction = new QAction(  tr("&New"), this );
    newAction->setShortcut( tr("Ctrl+N") );
    newAction->setStatusTip( tr("Create a new document") );
    newAction->setCheckable(true);
   //connect( newAction, SIGNAL(triggered()), this, SLOT(fileNew()) );
    ui->menu_Edit->addAction(newAction);
    QLabel label;
    label.setText("sadas");
    ui->menu_Edit->addSeparator();
    // Help menu
    ui->menu_Help->addAction(tr("&About"), this, SLOT(about()));
    // slot - signals




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
//////////////////////////////////////////////////////
// hideInputSig : hide input signal plot
//////////////////////////////////////////////////////
void MainWindow::hideInputSig(){

    ui->inputWidget->hide();
}
