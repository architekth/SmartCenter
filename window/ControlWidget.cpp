#include "ControlWidget.h"



ControlWidget::ControlWidget(QWidget *parent)
    : QWidget(parent)
{

    createPushButton();

}

ControlWidget::~ControlWidget()
{

}

void ControlWidget::resizeEvent(QResizeEvent *e)
{
    h_layout->setGeometry(QRect(0, 0, width(), height()));
}

void ControlWidget::createPushButton()
{
    h_layout = new QHBoxLayout(this);
    /*QWidget *container = new QWidget;
    m_Play = new QPushButton(container);
    m_Play->setFixedSize(65, 65);

    m_Next = new QPushButton(container);
    m_Next->setFixedSize(75, 37);

    m_Stop = new QPushButton(container);
    m_Stop->setFixedSize(37, 37);

    m_Prev = new QPushButton(container);
    m_Prev->setFixedSize(75, 37);*/

    m_Play = new QPushButton;
    m_Play->setFixedSize(65, 65);

    m_Next = new QPushButton;
    m_Next->setFixedSize(75, 37);

    m_Stop = new QPushButton;
    m_Stop->setFixedSize(37, 37);

    m_Prev = new QPushButton;
    m_Prev->setFixedSize(75, 37);

    h_layout->addWidget(m_Stop);
    h_layout->addWidget(m_Prev);
    h_layout->addWidget(m_Play);
    h_layout->addWidget(m_Next);


    /*m_Stop->move(10, 20);
    m_Prev->move(50, 20);
    m_Play->move(150, 0);
    m_Next->move(250, 20);

    h_layout->addWidget(container, 0, Qt::AlignCenter);*/

}
