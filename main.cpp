#include <QApplication>
#include "MainProcess.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainProcess mainProc;
    mainProc.run();
    return app.exec();
}
