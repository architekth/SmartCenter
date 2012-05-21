#ifndef CONTROLWIDGET_H
#define CONTROLWIDGET_H

#include <QWidget>
#include <QResizeEvent>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QSpacerItem>

class ControlWidget : public QWidget
{
    Q_OBJECT
public:
    ControlWidget(QWidget *parent = 0);
    ~ControlWidget();
    void resizeEvent(QResizeEvent *e);
    void createPushButton();
private:
    QPushButton             *m_Stop;
    QPushButton             *m_Play;
    QPushButton             *m_Next;
    QPushButton             *m_Prev;

    QHBoxLayout *h_layout;
};


#endif // CONTROLWIDGET_H
