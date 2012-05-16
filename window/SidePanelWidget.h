#ifndef SIDEPANELWIDGET_H
#define SIDEPANELWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QTreeView>
#include <QResizeEvent>

class SidePanelWidget : public QWidget
{
    Q_OBJECT
public:
    SidePanelWidget(QWidget *parent = 0);
    ~SidePanelWidget();
    void resizeEvent(QResizeEvent *e);
private:
    QTreeView                   *m_View;
};


#endif // SIDEPANELWIDGET_H
