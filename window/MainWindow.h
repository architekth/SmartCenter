#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QResizeEvent>
#include <QMessageBox>

#include "SidePanelWidget.h"
#include "ControlWidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void resizeEvent(QResizeEvent *e);
public slots:
    void showViewSlot(QString view);
private:
    void createMenuBar();
    void createSidePanelWidget();
    void createControlWidget();
    void createConnexionBtwSignalsSlots();
    void createStyleSheet();
private:
    SidePanelWidget         *m_SidePanel;
    ControlWidget           *m_Control;


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
