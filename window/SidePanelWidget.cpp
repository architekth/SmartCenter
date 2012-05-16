#include "SidePanelWidget.h"

SidePanelWidget::SidePanelWidget(QWidget *parent)
    : QWidget(parent)
{
    m_View = new QTreeView(this);
}

SidePanelWidget::~SidePanelWidget()
{

}

void SidePanelWidget::resizeEvent(QResizeEvent *e)
{
    m_View->resize(e->size());
}
