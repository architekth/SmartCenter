#include "MainWindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_SidePanel = NULL;
    m_Control = NULL;
    m_libraryBar = NULL;

    createMenuBar();
    createSidePanelWidget();
    createControlWidget();
    createLibraryBar();
    createConnexionBtwSignalsSlots();
    createStyleSheet();

    setWindowTitle("Smart Center");
    resize(800, 600);
    setMinimumSize(800, 200);
}

MainWindow::~MainWindow()
{
    if(m_SidePanel != NULL)
        delete m_SidePanel;
    if(m_Control != NULL)
        delete m_Control;
    if(m_libraryBar != NULL)
        delete m_libraryBar;
}


void MainWindow::createMenuBar()
{
    m_FileMenu = menuBar()->addMenu(tr("Fichier"));
    m_EditMenu = menuBar()->addMenu(tr("Edition"));
    m_ControlMenu = menuBar()->addMenu(tr("Contrôle"));
    m_HelpMenu = menuBar()->addMenu(tr("Aide"));


    m_OpenAction = m_FileMenu->addAction(tr("Ouvrir"));
    m_OpenUrlAction = m_FileMenu->addAction(tr("Ouvrir une URL"));
    m_CreateSelectionAction = m_FileMenu->addAction(tr("Créer une sélection"));
    m_FileMenu->addSeparator();
    m_SettingAction = m_FileMenu->addAction(tr("Options"));
    m_FileMenu->addSeparator();
    m_ExitAction = m_FileMenu->addAction(tr("Quitter"));

    m_PlayAction = m_ControlMenu->addAction(tr("Lecture"));
    m_PauseAction = m_ControlMenu->addAction(tr("Pause"));
    m_NextMediaAction = m_ControlMenu->addAction(tr("Suivant"));
    m_PreviousMediaAction = m_ControlMenu->addAction(tr("Précédent"));
    m_StopAction = m_ControlMenu->addAction(tr("Arrêter"));
    m_ControlMenu->addSeparator();
    m_VolumeUpAction = m_ControlMenu->addAction(tr("Augmenter le volume"));
    m_VolumeDownAction = m_ControlMenu->addAction(tr("Diminuer le volume"));

    m_OpenAboutAction = m_HelpMenu->addAction(tr("A Propos"));
    m_OpenHelpAction = m_HelpMenu->addAction(tr("Aide"));
}

void MainWindow::createConnexionBtwSignalsSlots()
{
    connect(m_SidePanel, SIGNAL(showView(QString)), this, SLOT(showViewSlot(QString)));

    connect(m_Control, SIGNAL(play()), this, SLOT(playFile()));
    connect(m_Control, SIGNAL(pause()), this, SLOT(pauseFile()));
    connect(m_Control, SIGNAL(stop()), this, SLOT(stopFile()));

    connect(m_OpenAction, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(m_ExitAction, SIGNAL(triggered()), this, SLOT(close()));

    connect(m_PlayAction, SIGNAL(triggered()), this, SLOT(playFile()));
    connect(m_PauseAction, SIGNAL(triggered()), this, SLOT(pauseFile()));
    connect(m_StopAction, SIGNAL(triggered()), this, SLOT(stopFile()));
}


void MainWindow::resizeEvent(QResizeEvent *e)
{
    if(m_SidePanel != NULL)
        m_SidePanel->resize(200, e->size().height() - 20);
    if(m_Control != NULL)
    {
        m_Control->move(200, height() - 100);
        m_Control->resize(width() - 200, 100);
    }
    if(m_libraryBar != NULL)
    {
        m_libraryBar->resize(width() - 200, 25);
    }
}

void MainWindow::createSidePanelWidget()
{
    m_SidePanel = new SidePanelWidget(this);
    m_SidePanel->move(0, 20);
}

void MainWindow::createControlWidget()
{
    m_Control = new ControlWidget(this);
    m_Control->move(200, height());
}

void MainWindow::createLibraryBar()
{
    m_libraryBar = new LibraryBar(this);
    m_libraryBar->move(200, 20);
    m_libraryBar->resize(width() - 200, 25);
    m_libraryBar->hide();
}

void MainWindow::showViewSlot(QString view)
{
    if(view == tr("Musique"))
    {
        m_libraryBar->createMusicBar();
        m_libraryBar->setVisible(true);
    }
    else
    {
        m_libraryBar->setVisible(false);
    }
}

void MainWindow::createStyleSheet()
{
    setStyleSheet("QMenuBar{"
                  "background-color:#ececec;"
                  "border-right:none;"
                  "border-left:none;"
                  "border-bottom:1px solid #b0b0b0;"
                  "border-top:none;"
                  "}"
                  "QMenuBar::item{"
                  "background-color:#ececec;"
                  "}"
                  "QMenuBar::item:selected{"
                  "background-color:#68c1fd;"
                  "margin: 2px;"
                  "color: white;"
                  "}"
                  "QMenu{"
                  "background-color:#ececec;"
                  "}"
                  "QMenu::item:selected{"
                  "background-color:#68c1fd;"
                  "}"
                  "QMenu::separator{"
                  "background:#cbcbcb;"
                  "height:1px;"
                  "margin-left:10px;"
                  "margin-right:10px;"
                  "}"
                  "QMainWindow{"
                  "background-color:#ececec;"
                  "}"
                  "QWidget{"
                  "font-family:Arial;"
                  "}");
    m_SidePanel->setStyleSheet("QTreeView{"
                               "background-color:#cbcbcb;"
                               "border-right:1px solid #b0b0b0;"
                               "border-left:none;"
                               "border-bottom:none;"
                               "border-top:1px solid #b0b0b0;"
                               "font-size:12px;"
                               "}"
                               "QTreeView::item:hover{"
                               "margin-right:10px;"
                               "background-color:#68c1fd;"
                               "color:#ffffff;"
                               "}"
                               "QTreeView::item:selected:active{"
                               "background-color:#68c1fd;"
                               "color:#ffffff;"
                               "border:none;"
                               "margin-right:10px;"
                               "}"
                               "QTreeView::item:selected:!active{"
                               "background-color:#68c1fd;"
                               "color:#ffffff;"
                               "border:none;"
                               "margin-right:10px;"
                               "}");
    m_Control->setStyleSheet("QFrame{"
                             "background-color:#ececec;"
                             "border-right:none;"
                             "border-left:none;"
                             "border-bottom:none;"
                             "border-top:1px solid #b0b0b0;"
                             "}"
                             "QLabel{"
                             "border:none;"
                             "font-family:Arial;"
                             "}");

    m_libraryBar->setStyleSheet("QFrame{"
                                "background-color:#cbcbcb;"
                                "border-right:none;"
                                "border-left:none;"
                                "border-bottom:1px solid #b0b0b0;"
                                "border-top:1px solid #b0b0b0;"
                                "}");
}

void MainWindow::openFile()
{
    // FOR MULTI FILES
    //QStringList filesName = QFileDialog::getOpenFileNames(this, tr("Ouvrir un ou des médias"));
    QString fileName = QFileDialog::getOpenFileName(this, "Ouvrir un média", QString(), "*.mp3 *.wma");
    MusicManager::getInstance()->setMusicPath(fileName);
    m_Control->showStopState();
    m_Control->playPauseSlot();
}

void MainWindow::playFile()
{
    MusicManager::getInstance()->Play();
    m_Control->showPauseButton();
}

void MainWindow::pauseFile()
{
    MusicManager::getInstance()->Pause();
    m_Control->showPlayButton();
}

void MainWindow::stopFile()
{
    MusicManager::getInstance()->Stop();
    m_Control->showStopState();
}
