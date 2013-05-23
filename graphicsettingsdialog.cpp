#include "graphicsettingsdialog.h"
#include "ui_graphicsettingsdialog.h"
#include "plotbox.h"

graphicSettingsDialog::graphicSettingsDialog(plotBox *parent) :
    QDialog(parent),
    ui(new Ui::graphicSettingsDialog)
{
    ui->setupUi(this);
    pPlotBox = parent;
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(updateGraphicSettings()));

}

graphicSettingsDialog::~graphicSettingsDialog()
{
    delete ui;
}

void graphicSettingsDialog::updateGraphicSettings(){
    if(ui->axisXLabellineEdit->text() != ""){
    //pPlotBox->setAxisXlabel(ui->axisXLabellineEdit->text());
    }
     if(ui->axisYLabellineEdit->text() != ""){
   // pPlotBox->setAxisYlabel(ui->axisYLabellineEdit->text());
     }


    close();

}
