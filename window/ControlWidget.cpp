#include "ControlWidget.h"



ControlWidget::ControlWidget(QWidget *parent)
    : QFrame(parent)
{
    isPlaying = false;
    m_musicSliderPressed = false;
    createPushButton();
    createSlider();
    createStyleSheet();
    createConnexionBtwSignalsSlots();
}

ControlWidget::~ControlWidget()
{

}

void ControlWidget::resizeEvent(QResizeEvent *e)
{
    int width = e->size().width();
    m_Stop->move(width / 2.7, 40);
    m_Prev->move((width / 2.7) + 42, 40);
    m_Play->move((width / 2.7) + 122, 25);
    m_Next->move((width / 2.7) + 192, 40);
    m_volume->move(width - 95, 40);
    m_volumeLabel->move(width - 72, 25);
    m_volumeMore->move(width - 10, 40);
    m_volumeLess->move(width- 101, 40);
    m_musicProgress->resize(m_Stop->pos().x() - 25 , 25);
}

void ControlWidget::createPushButton()
{
    m_musicTitle = new QLabel(this);
    m_musicTitle->setFixedWidth(200);

    m_musicTimeElapsed = new QLabel(this);
    m_musicTimeElapsed->setFixedWidth(200);

    m_Play = new QPushButton(this);
    m_Play->setFixedSize(65, 65);

    m_Next = new QPushButton(this);
    m_Next->setFixedSize(75, 37);

    m_Stop = new QPushButton(this);
    m_Stop->setFixedSize(37, 37);

    m_Prev = new QPushButton(this);
    m_Prev->setFixedSize(75, 37);

    m_volumeLabel = new QLabel(tr("Volume"), this);

    m_volumeMore = new QLabel(tr("+"), this);

    m_volumeLess = new QLabel(tr("-"), this);

    m_musicTimeElapsed->move(20, 60);
    m_musicTitle->move(10, 25);

}

void ControlWidget::createSlider()
{
    m_musicProgress = new QSlider(Qt::Horizontal, this);
    m_musicProgress->setRange(0, 100);
    m_musicProgress->move(10, 40);

    m_volume = new QSlider(Qt::Horizontal, this);
    m_volume->setRange(0, 100);
    m_volume->setValue(100);
}

void ControlWidget::createStyleSheet()
{
    m_Play->setStyleSheet("QPushButton{"
                          "background-image:url(:/icones/img/play.png);"
                          "margin:-1px;"
                          "border:none;"
                          "}"
                          "QPushButton:hover{"
                          "background-image:url(:/icones/img/play_h.png);"
                          "margin:-1px;"
                          "border:none;"
                          "}"
                          "QPushButton:pressed{"
                          "background-image:url(:/icones/img/play_c.png);"
                          "margin:-1px;"
                          "border:none;"
                          "}");

    m_Prev->setStyleSheet("QPushButton{"
                          "background-image:url(:/icones/img/prev.png);"
                          "margin:-1px;"
                          "border:none;"
                          "}"
                          "QPushButton:hover{"
                          "background-image:url(:/icones/img/prev_h.png);"
                          "margin:-1px;"
                          "border:none;"
                          "}"
                          "QPushButton:pressed{"
                          "background-image:url(:/icones/img/prev_c.png);"
                          "margin:-1px;"
                          "border:none;"
                          "}");

    m_Next->setStyleSheet("QPushButton{"
                          "background-image:url(:/icones/img/next.png);"
                          "margin:-1px;"
                          "border:none;"
                          "}"
                          "QPushButton:hover{"
                          "background-image:url(:/icones/img/next_h.png);"
                          "margin:-1px;"
                          "border:none;"
                          "}"
                          "QPushButton:pressed{"
                          "background-image:url(:/icones/img/next_c.png);"
                          "margin:-1px;"
                          "border:none;"
                          "}");

    m_Stop->setStyleSheet("QPushButton{"
                            "background-image:url(:/icones/img/stop.png);"
                            "margin:-1px;"
                            "border:none;"
                            "}"
                            "QPushButton:hover{"
                            "background-image:url(:/icones/img/stop_h.png);"
                            "margin:-1px;"
                            "border:none;"
                            "}"
                            "QPushButton:pressed{"
                            "background-image:url(:/icones/img/stop_c.png);"
                            "margin:-1px;"
                            "border:none;"
                            "}");

    m_musicProgress->setStyleSheet("QSlider::groove:horizontal{"
                                   "height:4px;"
                                   "background-color: #b0b0b0;"
                                   "border: 1px solid #848484;"
                                   "position:absolute;"
                                   "}"
                                   "QSlider::handle:horizontal{"
                                   "height:18px;"
                                   "width:18px;"
                                   "margin:-7px 0px;"
                                   "background-image:url(:/icones/img/cur.png);"
                                   "}");

    m_musicTitle->setFont(QFont("Arial", 10));
    m_musicTitle->setStyleSheet("color:#666666;");

    m_musicTimeElapsed->setFont(QFont("Arial", 10));
    m_musicTimeElapsed->setStyleSheet("color:#666666;");

    m_volumeLabel->setFont(QFont("Arial", 10));
    m_volumeLabel->setStyleSheet("color:#666666;");

    m_volumeMore->setFont(QFont("Arial", 10));
    m_volumeMore->setStyleSheet("color:#666666;");

    m_volumeLess->setFont(QFont("Arial", 10));
    m_volumeLess->setStyleSheet("color:#666666;");

    m_volume->setStyleSheet("QSlider::groove:horizontal{"
                            "height:4px;"
                            "background-color: #b0b0b0;"
                            "border: 1px solid #848484;"
                            "position:absolute;"
                            "}"
                            "QSlider::handle:horizontal{"
                            "height:18px;"
                            "width:18px;"
                            "margin:-7px 0px;"
                            "background-image:url(:/icones/img/cur.png);"
                            "}");
}

void ControlWidget::createConnexionBtwSignalsSlots()
{
    connect(m_Play, SIGNAL(clicked()), this, SLOT(playPauseSlot()));
    connect(m_Stop, SIGNAL(clicked()), this, SLOT(stopSlot()));
    connect(m_volume, SIGNAL(valueChanged(int)), MusicManager::getInstance(), SLOT(changeVolume(int)));
    connect(MusicManager::getInstance(), SIGNAL(currentSourceChanged(QString)), this, SLOT(currentSourceChangedSlot(QString)));
    connect(MusicManager::getInstance(), SIGNAL(totalTimeChanged()), this, SLOT(currentSourceTotalTimeChangedSlot()));
    connect(MusicManager::getInstance(), SIGNAL(timeChanged(QString)), this, SLOT(currentSourceTimeChangedSlot(QString)));
    connect(m_musicProgress, SIGNAL(sliderReleased()), this, SLOT(musicSliderReleasedSlot()));
    connect(m_musicProgress, SIGNAL(sliderPressed()), this, SLOT(musicSliderPressedSlot()));
}

void ControlWidget::playPauseSlot()
{
    isPlaying = !isPlaying;
    if(isPlaying)
    {
        m_Play->setStyleSheet("QPushButton{"
                              "background-image:url(:/icones/img/pause.png);"
                              "margin:-1px;"
                              "border:none;"
                              "}"
                              "QPushButton:hover{"
                              "background-image:url(:/icones/img/pause_h.png);"
                              "margin:-1px;"
                              "border:none;"
                              "}"
                              "QPushButton:pressed{"
                              "background-image:url(:/icones/img/pause_c.png);"
                              "margin:-1px;"
                              "border:none;"
                              "}");
    }
    else
    {
        m_Play->setStyleSheet("QPushButton{"
                              "background-image:url(:/icones/img/play.png);"
                              "margin:-1px;"
                              "border:none;"
                              "}"
                              "QPushButton:hover{"
                              "background-image:url(:/icones/img/play_h.png);"
                              "margin:-1px;"
                              "border:none;"
                              "}"
                              "QPushButton:pressed{"
                              "background-image:url(:/icones/img/play_c.png);"
                              "margin:-1px;"
                              "border:none;"
                              "}");
    }

    if(isPlaying)
        emit play();
    else
        emit pause();
}

void ControlWidget::stopSlot()
{
    isPlaying = false;
    showPlayButton();
    emit stop();
}

void ControlWidget::showPlayButton()
{
    isPlaying = false;
    m_Play->setStyleSheet("QPushButton{"
                          "background-image:url(:/icones/img/play.png);"
                          "margin:-1px;"
                          "border:none;"
                          "}"
                          "QPushButton:hover{"
                          "background-image:url(:/icones/img/play_h.png);"
                          "margin:-1px;"
                          "border:none;"
                          "}"
                          "QPushButton:pressed{"
                          "background-image:url(:/icones/img/play_c.png);"
                          "margin:-1px;"
                          "border:none;"
                          "}");
}

void ControlWidget::showPauseButton()
{
    isPlaying = true;
    m_Play->setStyleSheet("QPushButton{"
                          "background-image:url(:/icones/img/pause.png);"
                          "margin:-1px;"
                          "border:none;"
                          "}"
                          "QPushButton:hover{"
                          "background-image:url(:/icones/img/pause_h.png);"
                          "margin:-1px;"
                          "border:none;"
                          "}"
                          "QPushButton:pressed{"
                          "background-image:url(:/icones/img/pause_c.png);"
                          "margin:-1px;"
                          "border:none;"
                          "}");
}

void ControlWidget::showStopState()
{
    isPlaying = false;
    m_Play->setStyleSheet("QPushButton{"
                          "background-image:url(:/icones/img/play.png);"
                          "margin:-1px;"
                          "border:none;"
                          "}"
                          "QPushButton:hover{"
                          "background-image:url(:/icones/img/play_h.png);"
                          "margin:-1px;"
                          "border:none;"
                          "}"
                          "QPushButton:pressed{"
                          "background-image:url(:/icones/img/play_c.png);"
                          "margin:-1px;"
                          "border:none;"
                          "}");
}

void ControlWidget::currentSourceChangedSlot(QString name)
{
    m_musicTitle->setText(name.right(name.length() - (name.lastIndexOf("/") + 1)));
}

void ControlWidget::currentSourceTotalTimeChangedSlot()
{
    QString qstr_seconde = "";
    MusicManager::getInstance()->getTotalMusicDuration(&qstr_seconde);
    m_musicTimeElapsed->setText("0:00 / " + qstr_seconde);
    qint64 duration = 0;
    MusicManager::getInstance()->getTotalMusicDuration(&duration);
    m_musicProgress->setRange(0, duration);
    m_musicProgress->setValue(0);
}

void ControlWidget::currentSourceTimeChangedSlot(QString time)
{
    QString qstr_seconde = "";
    MusicManager::getInstance()->getTotalMusicDuration(&qstr_seconde);
    m_musicTimeElapsed->setText(time + " / " + qstr_seconde);

    if(!m_musicSliderPressed)
        m_musicProgress->setValue(MusicManager::getInstance()->getTimeElapsed());
}

void ControlWidget::musicSliderReleasedSlot()
{
    MusicManager::getInstance()->changePositionMusic(m_musicProgress->value());
    m_musicSliderPressed = false;
}

void ControlWidget::musicSliderPressedSlot()
{
    m_musicSliderPressed = true;
}
