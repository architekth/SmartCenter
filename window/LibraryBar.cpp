#include "LibraryBar.h"


LibraryBar::LibraryBar(QWidget *parent)
    : QFrame(parent)
{
    m_Artist = NULL;
    m_Album = NULL;
    m_Genre = NULL;
    m_2DViewButton = NULL;
    m_3DViewButton = NULL;
}

LibraryBar::~LibraryBar()
{
}

void LibraryBar::resizeEvent(QResizeEvent *e)
{
    if(m_Artist != NULL)
    {
        m_Artist->move((width() / 2) - 90, 1);
        m_Album->move((width() / 2) -30 , 1);
        m_Genre->move((width() / 2) + 30, 1);
        m_2DViewButton->move(width() - 25, 5);
        m_3DViewButton->move(width() - 46, 5);
    }
}

void LibraryBar::createMusicBar()
{
    deleteButton();

    m_Artist = new QPushButton(tr("Artiste"), this);
    m_Artist->setFixedSize(60, 23);
    m_Artist->setCheckable(true);
    m_Artist->setChecked(true);
    m_Album = new QPushButton(tr("Album"), this);
    m_Album->setFixedSize(60, 23);
    m_Album->setCheckable(true);
    m_Album->setChecked(false);
    m_Genre = new QPushButton(tr("Genre"), this);
    m_Genre->setFixedSize(60, 23);
    m_Genre->setCheckable(true);
    m_Genre->setChecked(false);

    m_2DViewButton = new QPushButton(this);
    m_2DViewButton->setCheckable(true);
    m_2DViewButton->setChecked(true);
    m_2DViewButton->setFixedSize(16, 16);
    m_3DViewButton = new QPushButton(this);
    m_3DViewButton->setCheckable(true);
    m_3DViewButton->setChecked(false);
    m_3DViewButton->setEnabled(false);
    m_3DViewButton->setFixedSize(16, 16);

    m_Artist->move((width() / 2) - 90, 1);
    m_Album->move((width() / 2) -30 , 1);
    m_Genre->move((width() / 2) + 30, 1);
    m_2DViewButton->move(width() - 25, 5);
    m_3DViewButton->move(width() - 46, 5);


    //######## CREATE THE STYLE SHEET ########
    m_Artist->setStyleSheet("QPushButton{"
                            "border:none;"
                            "}"
                            "QPushButton:hover{"
                            "background-color:#68c1fd;"
                            "color:white;"
                            "}"
                            "QPushButton:checked{"
                            "background-color:#68c1fd;"
                            "color:white;"
                            "}");
    m_Album->setStyleSheet("QPushButton{"
                           "border:none;"
                           "}"
                           "QPushButton:hover{"
                           "background-color:#68c1fd;"
                           "color:white;"
                           "}"
                           "QPushButton:checked{"
                           "background-color:#68c1fd;"
                           "color:white;"
                           "}");
    m_Genre->setStyleSheet("QPushButton{"
                           "border:none;"
                           "}"
                           "QPushButton:hover{"
                           "background-color:#68c1fd;"
                           "color:white;"
                           "}"
                           "QPushButton:checked{"
                           "background-color:#68c1fd;"
                           "color:white;"
                           "}");
    m_2DViewButton->setStyleSheet("QPushButton{"
                                  "border:none;"
                                  "background-image:url(:icones/img/2DSelected.png);"
                                  "}"
                                  "QPushButton:hover{"
                                  "background-image:url(:icones/img/2DSelected_h.png);"
                                  "}"
                                  "QPushButton:checked{"
                                  "background-image:url(:icones/img/2DSelected_h.png);"
                                  "}");
    m_3DViewButton->setStyleSheet("QPushButton{"
                                  "border:none;"
                                  "background-image:url(:icones/img/3DSelected.png);"
                                  "}"
                                  "QPushButton:hover{"
                                  "background-image:url(:icones/img/3DSelected_h.png);"
                                  "}"
                                  "QPushButton:checked{"
                                  "background-image:url(:icones/img/3DSelected_h.png);"
                                  "}");

    createConnexionBtwSignalSlot();
}

void LibraryBar::deleteButton()
{
    if(m_Artist != NULL)
        delete m_Artist;
    if(m_Album != NULL)
        delete m_Album;
    if(m_Genre != NULL)
        delete m_Genre;
    if(m_2DViewButton != NULL)
        delete m_2DViewButton;
    if(m_3DViewButton != NULL)
        delete m_3DViewButton;
}

void LibraryBar::createConnexionBtwSignalSlot()
{
    connect(m_Artist, SIGNAL(clicked()), this, SLOT(musicBarItemSelectedSlot()));
    connect(m_Album, SIGNAL(clicked()), this, SLOT(musicBarItemSelectedSlot()));
    connect(m_Genre, SIGNAL(clicked()), this, SLOT(musicBarItemSelectedSlot()));
    connect(m_2DViewButton, SIGNAL(clicked()), this, SLOT(show2DViewSlot()));
    connect(m_3DViewButton, SIGNAL(clicked()), this, SLOT(show3DViewSlot()));
}

void LibraryBar::musicBarItemSelectedSlot()
{
    QString objName = ((QPushButton*)sender())->text();
    if(objName == tr("Artiste"))
    {
        m_Artist->setChecked(true);
        m_Album->setChecked(false);
        m_Genre->setChecked(false);

    }
    else if(objName == tr("Album"))
    {
        m_Artist->setChecked(false);
        m_Album->setChecked(true);
        m_Genre->setChecked(false);
    }
    else if(objName == tr("Genre"))
    {
        m_Artist->setChecked(false);
        m_Album->setChecked(false);
        m_Genre->setChecked(true);
    }
    else
    {
    }

    emit musicBarItemSelected(objName);
}

void LibraryBar::show2DViewSlot()
{
    m_2DViewButton->setChecked(true);
    m_3DViewButton->setChecked(false);
}

void LibraryBar::show3DViewSlot()
{
    m_2DViewButton->setChecked(false);
    m_3DViewButton->setChecked(true);
}
