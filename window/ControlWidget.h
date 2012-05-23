#ifndef CONTROLWIDGET_H
#define CONTROLWIDGET_H

#include <QWidget>
#include <QResizeEvent>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QSlider>
#include <Phonon/Phonon>

#include "../manager/MusicManager.h"

class ControlWidget : public QFrame
{
    Q_OBJECT
public:
    ControlWidget(QWidget *parent = 0);
    ~ControlWidget();
    void resizeEvent(QResizeEvent *e);
    void showPlayButton();
    void showPauseButton();
    void showStopState();
public slots:
    void playPauseSlot();
    void stopSlot();
    void currentSourceChangedSlot(QString name);
    void currentSourceTotalTimeChangedSlot();
    void currentSourceTimeChangedSlot(QString time);
    void musicSliderReleasedSlot();
    void musicSliderPressedSlot();
signals:
    void play();
    void pause();
    void stop();

private:
    void createPushButton();
    void createSlider();
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

    bool                    m_musicSliderPressed;
};


#endif // CONTROLWIDGET_H
