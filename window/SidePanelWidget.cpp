#include "SidePanelWidget.h"

SidePanelWidget::SidePanelWidget(QWidget *parent)
    : QWidget(parent)
{
    m_View = new QTreeView(this);
    m_Model = new QStandardItemModel;

    createModelView();
    createConnexionBtwSignalsSlots();
    initItemSelected();
}

SidePanelWidget::~SidePanelWidget()
{
}

void SidePanelWidget::resizeEvent(QResizeEvent *e)
{
    m_View->resize(e->size());
}

void SidePanelWidget::createModelView()
{
    QStandardItem *playItem = new QStandardItem(tr("Lecture en cours"));
    playItem->setEditable(false);
    QStandardItem *libraryItem = new QStandardItem(tr("Bibliothèque"));
    libraryItem->setEditable(false);
    QStandardItem *artistItem = new QStandardItem(tr("Musique"));
    artistItem->setEditable(false);
    QStandardItem *albumItem = new QStandardItem(tr("Film"));
    albumItem->setEditable(false);
    QStandardItem *genreItem = new QStandardItem(tr("Série TV"));
    genreItem->setEditable(false);
    QStandardItem *userListItem = new QStandardItem(tr("Listes de lecture"));
    userListItem->setEditable(false);


    m_Model->appendRow(playItem);
    m_Model->appendRow(libraryItem);
    libraryItem->appendRow(artistItem);
    libraryItem->appendRow(albumItem);
    libraryItem->appendRow(genreItem);
    m_Model->appendRow(userListItem);

    m_View->setModel(m_Model);
    m_View->setHeaderHidden(true);
    m_View->setAnimated(true);
    m_View->setExpanded(m_Model->indexFromItem(libraryItem), true);
}

void SidePanelWidget::createConnexionBtwSignalsSlots()
{
    connect(m_View, SIGNAL(clicked(QModelIndex)), this, SLOT(itemChangedSlot(QModelIndex)));
}

void SidePanelWidget::itemChangedSlot(QModelIndex index)
{
    emit showView(m_Model->itemFromIndex(index)->text());
}

void SidePanelWidget::initItemSelected()
{
    m_View->setCurrentIndex(m_Model->index(0, 0));
}
