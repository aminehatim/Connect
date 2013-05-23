#ifndef GRAPHICSETTINGSDIALOG_H
#define GRAPHICSETTINGSDIALOG_H

#include <QDialog>

class  plotBox;
namespace Ui {
class graphicSettingsDialog;
}

class graphicSettingsDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit graphicSettingsDialog(plotBox *parent = 0);
    ~graphicSettingsDialog();
    
private:
    Ui::graphicSettingsDialog *ui;
    plotBox *pPlotBox;

public slots:
    void updateGraphicSettings();
};

#endif // GRAPHICSETTINGSDIALOG_H
