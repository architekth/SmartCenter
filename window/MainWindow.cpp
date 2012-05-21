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
}


void MainWindow::createMenuBar()
{
    m_FileMenu = menuBar()->addMenu(tr("Fichier"));
    m_EditMenu = menuBar()->addMenu(tr("Edition"));
    m_ControlMenu = menuBar()->addMenu(tr("Contr�le"));
    m_HelpMenu = menuBar()->addMenu(tr("Aide"));


    m_OpenAction = m_FileMenu->addAction(tr("Ouvrir"));
    m_OpenUrlAction = m_FileMenu->addAction(tr("Ouvrir une URL"));
    m_CreateSelectionAction = m_FileMenu->addAction(tr("Cr�er une s�lection"));
    m_FileMenu->addSeparator();
    m_SettingAction = m_FileMenu->addAction(tr("Options"));
    m_FileMenu->addSeparator();
    m_ExitAction = m_FileMenu->addAction(tr("Quitter"));

    m_PlayAction = m_ControlMenu->addAction(tr("Lecture"));
    m_NextMediaAction = m_ControlMenu->addAction(tr("Suivant"));
    m_PreviousMediaAction = m_ControlMenu->addAction(tr("Pr�c�dent"));
    m_StopAction = m_ControlMenu->addAction(tr("Arr�ter"));
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
                              // "font-size:13px;"
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
}
