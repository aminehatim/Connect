#ifndef PLOTBOX_H
#define PLOTBOX_H

#include <QtCore>
#include <QWidget>
#include "plotbox.h"
#include "qcustomplot.h"

namespace Ui {
class plotBox;
}

class plotBox : public QWidget
{
  Q_OBJECT

public:
  explicit plotBox(QWidget *parent = 0);
  ~plotBox();

private slots:
  void titleDoubleClick();
  void axisLabelDoubleClick(QCPAxis* axis, QCPAxis::SelectablePart part);
  void legendDoubleClick(QCPLegend* legend, QCPAbstractLegendItem* item);
  void selectionChanged();
  void mousePress();
  void mouseWheel();
  void addRandomGraph();
  void removeSelectedGraph();
  void removeAllGraphs();
  void contextMenuRequest(QPoint pos);
  void moveLegend();
  void graphClicked(QCPAbstractPlottable *plottable);

private:
  Ui::plotBox *ui;
};
//#include <QWidget>
//#include "qcustomplot.h"
//#include "graphicsettingsdialog.h"
//#include "QPair"

//namespace Ui {
//class plotBox;
//}

//class plotBox : public QWidget
//{
//    Q_OBJECT
    
//public:
//    explicit plotBox(QWidget *parent = 0);
//    ~plotBox();
//    void setAxisXlabel(QString newLabel);
//    void setAxisYlabel(QString newLabel);
//    void setAxisXRange(QPair<int,int> newRange);
//    void setAxisYRange(QPair<int,int> newRange);
//    void addSource();
    
//private:
//    Ui::plotBox *ui;
//    graphicSettingsDialog *pGraphicSettingsDialog;
//public slots:
//    void ShowContextMenu(const QPoint& pos);
//};

#endif // PLOTBOX_H
