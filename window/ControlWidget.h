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

public slots:
    void playPauseSlot();

signals:
    void playPause(bool play);

private:
    void createPushButton();
    void createStyleSheet();
    void createConnexionBtwSignalsSlots();

private:
    QSlider                 *m_musicProgress;
    QSlider                 *m_volume;
    QLabel                  *m_volumeLabel;
    QLabel                  *m_volumeMore;
    QLabel                  *m_volumeLess;
    QLabel                  *m_musicTitle;
    QLabel                  *m_musicTimeElapsed;
    QPushButton             *m_Stop;
    QPushButton             *m_Play;
    QPushButton             *m_Next;
    QPushButton             *m_Prev;
    bool                    isPlaying;
};


#endif // CONTROLWIDGET_H
