#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QResizeEvent>

#include "SidePanelWidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void resizeEvent(QResizeEvent *e);

private:
    void createMenuBar();
    void createSidePanelWidget();
    void createConnexionBtwSignalsSlots();
private:
    SidePanelWidget         *m_SidePanel;


    QMenu                   *m_FileMenu;
    QMenu                   *m_EditMenu;
    QMenu                   *m_ControlMenu;
    QMenu                   *m_HelpMenu;


    QAction                 *m_OpenAction;
    QAction                 *m_OpenUrlAction;
    QAction                 *m_CreateSelectionAction;
    QAction                 *m_SettingAction;
    QAction                 *m_ExitAction;
    QAction                 *m_PlayAction;
    QAction                 *m_NextMediaAction;
    QAction                 *m_PreviousMediaAction;
    QAction                 *m_StopAction;
    QAction                 *m_VolumeUpAction;
    QAction                 *m_VolumeDownAction;
    QAction                 *m_OpenAboutAction;
    QAction                 *m_OpenHelpAction;
};


#endif // MAINWINDOW_H
