#include "MainProcess.h"


MainProcess::MainProcess(QObject *parent)
    : QObject(parent)
{
    mainWnd = NULL;
}

MainProcess::~MainProcess()
{
    if(mainWnd != NULL)
        delete mainWnd;
}

void MainProcess::run()
{
    mainWnd = new MainWindow();
    mainWnd->show();
}
