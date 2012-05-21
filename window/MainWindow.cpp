#include "MainWindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_SidePanel = NULL;
    m_Control = NULL;

    createMenuBar();
    createSidePanelWidget();
    createControlWidget();
    createConnexionBtwSignalsSlots();

    setWindowTitle("Smart Center");
    resize(800, 600);
}

MainWindow::~MainWindow()
{
    if(m_SidePanel != NULL)
        delete m_SidePanel;
    if(m_Control != NULL)
        delete m_Control;
}


void MainWindow::createMenuBar()
{
    m_FileMenu = menuBar()->addMenu(tr("Fichier"));
    //m_EditMenu = menuBar()->addMenu(tr("Edition"));
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
    m_NextMediaAction = m_ControlMenu->addAction(tr("Suivant"));
    m_PreviousMediaAction = m_ControlMenu->addAction(tr("Précédent"));
    m_StopAction = m_ControlMenu->addAction(tr("Arrêter"));
    m_ControlMenu->addSeparator();
    m_VolumeUpAction = m_ControlMenu->addAction(tr("Augmenter le volume"));
    m_VolumeDownAction = m_ControlMenu->addAction(tr("Diminuer le volume"));

    m_OpenAction = m_HelpMenu->addAction(tr("A Propos"));
    m_OpenHelpAction = m_HelpMenu->addAction(tr("Aide"));
}

void MainWindow::createConnexionBtwSignalsSlots()
{
    connect(m_SidePanel, SIGNAL(showView(QString)), this, SLOT(showViewSlot(QString)));
    connect(m_ExitAction, SIGNAL(triggered()), this, SLOT(close()));
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

void MainWindow::showViewSlot(QString view)
{
    qDebug() << "Requested view : " << view;
}
