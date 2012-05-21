#ifndef SIDEPANELWIDGET_H
#define SIDEPANELWIDGET_H

#include <QDebug>
#include <QWidget>
#include <QPushButton>
#include <QTreeView>
#include <QResizeEvent>
#include <QStandardItemModel>
#include <QStandardItem>

class SidePanelWidget : public QWidget
{
    Q_OBJECT
public:
    SidePanelWidget(QWidget *parent = 0);
    ~SidePanelWidget();
    void resizeEvent(QResizeEvent *e);
signals:
    void showView(QString view);
public slots:
    void itemChangedSlot(QModelIndex index);
private:
    void createModelView();
    void createConnexionBtwSignalsSlots();
private:
    QTreeView                   *m_View;
    QStandardItemModel          *m_Model;
};


#endif // SIDEPANELWIDGET_H
