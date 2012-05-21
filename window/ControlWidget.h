#ifndef CONTROLWIDGET_H
#define CONTROLWIDGET_H

#include <QWidget>
#include <QResizeEvent>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QSlider>

class ControlWidget : public QFrame
{
    Q_OBJECT
public:
    ControlWidget(QWidget *parent = 0);
    ~ControlWidget();
    void resizeEvent(QResizeEvent *e);
    void createPushButton();
    void createStyleSheet();
private:
    QSlider                 *m_musicProgress;
    QLabel                  *m_musicTitle;
    QLabel                  *m_musicTimeElapsed;
    QPushButton             *m_Stop;
    QPushButton             *m_Play;
    QPushButton             *m_Next;
    QPushButton             *m_Prev;
};


#endif // CONTROLWIDGET_H
