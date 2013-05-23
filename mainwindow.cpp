#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QLabel>
#include <QVBoxLayout>
#include <QTimer>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //setup
    ui->setupUi(this);
    pStatusBar = new QStatusBar;
    pStatusLabel = new QLabel;

    //pInputPlotBox = new plotBox;
    // status bar
    // test mdi
    mdiArea = new QMdiArea;
    mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setCentralWidget(mdiArea);

    // end mdi test
    this->setStatusBar(pStatusBar);
    pStatusLabel->setText("<font color='red'>Not Connected :-(</font>");
    pStatusBar->addPermanentWidget(pStatusLabel);
    // plot widget

//    ui->inputSigWidget->addGraph();
//    ui->inputSigWidget->xAxis->setLabel("x");
//    ui->inputSigWidget->yAxis->setLabel("y");
//    ui->inputSigWidget->xAxis->setRange(-1.1, 1.1);
//    ui->inputSigWidget->yAxis->setRange(-1.1, 1.1);
//    ui->inputSigWidget->setTitle("Input Signal");
    // File menu
    ui->menu_File->addAction(tr("&Setup Connection"),this,SLOT(setupConnection()),QKeySequence(tr("Ctrl+s")));
    // Edit menu
        // input sig
    pInputAction = new QAction(  tr("&Add New PlotBox"), this );
    pInputAction->setShortcut( tr("Ctrl+a") );
    connect( pInputAction, SIGNAL(triggered()), this, SLOT(AddNewPlotBox()));
        // tcl console
    pTclConsole = new QAction(  tr("&Tcl conole"), this );
    pTclConsole->setShortcut( tr("Ctrl+t") );
    pTclConsole->setStatusTip( tr("Show Tcl console") );
    pTclConsole->setCheckable(true);
    pTclConsole->setChecked(false);
    // connect( pInputAction, SIGNAL(toggled(bool )), this, SLOT(showInputSig(bool )) ); will be done when tcl console is all set

    ui->menu_Edit->addAction(pInputAction);
    ui->menu_Edit->addSeparator();
    ui->menu_Edit->addAction(pTclConsole);
    // Help menu
    ui->menu_Help->addAction(tr("&About"), this, SLOT(about()));

    // slot - signals
    //connect(ui, SIGNAL(iconSizeChanged(QSize)), this, SLOT(resizeInputSigPlot(QSize)));
    // update mdi Area
    QTimer::singleShot(100, this, SLOT(updateMdiArea()));




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
    update();
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
// showInputSigPlot : hide/show input signal plot
//////////////////////////////////////////////////////
void MainWindow::AddNewPlotBox(){

    plotBox *pNewPlotBox;
    pNewPlotBox = new plotBox;
    mdiArea->addSubWindow(pNewPlotBox);
    pNewPlotBox->parentWidget()->setGeometry(10, 100, 400, 400);
    pNewPlotBox->show();




}
//////////////////////////////////////////////////////////////
// resizeInputSigPlot : resize input plot( 25% of main window)
//////////////////////////////////////////////////////////////
void MainWindow::resizeInputSigPlot(QSize newSize){
    int x, y;
    x = newSize.width()/4;
    y = newSize.height()/4;
    ui->centralWidget->resize(x,y);
}
///////////////////////////////////////////////////////////////////
// updateMidArea : repaint mdiarea due to diaplay problem #issue 6
//////////////////////////////////////////////////////////////////
void MainWindow::updateMdiArea(){
  update();


}
//////////////////////////////////
/////
//////////////////////////////////////////

