#include "ControlWidget.h"



ControlWidget::ControlWidget(QWidget *parent)
    : QFrame(parent)
{
    createPushButton();
    createStyleSheet();
}

ControlWidget::~ControlWidget()
{

}

void ControlWidget::resizeEvent(QResizeEvent *e)
{
}

void ControlWidget::createPushButton()
{

    m_musicProgress = new QSlider(Qt::Horizontal, this);
    m_musicProgress->setMinimumWidth(150);

    m_musicTitle = new QLabel("Radiohead - creep", this);


    m_musicTimeElapsed = new QLabel("0:30 / 3:45", this);


    m_Play = new QPushButton(this);
    m_Play->setFixedSize(65, 65);

    m_Next = new QPushButton(this);
    m_Next->setFixedSize(75, 37);

    m_Stop = new QPushButton(this);
    m_Stop->setFixedSize(37, 37);

    m_Prev = new QPushButton(this);
    m_Prev->setFixedSize(75, 37);

    m_Stop->move(200, 40);
    m_Prev->move(250, 40);
    m_Play->move(350, 20);
    m_Next->move(450, 40);
    m_musicTimeElapsed->move(20, 60);
    m_musicTitle->move(10, 25);
    m_musicProgress->move(10, 40);
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
}
