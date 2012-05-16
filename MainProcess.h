#ifndef MAINPROCESS_H
#define MAINPROCESS_H

#include <QObject>

#include "window/MainWindow.h"

class MainProcess : public QObject
{
    Q_OBJECT
public:
    MainProcess(QObject *parent = 0);
    ~MainProcess();
    void run();
private:
    MainWindow *mainWnd;
};


#endif // MAINPROCESS_H
