#include "childwindow.h"
#include "mainwindow.h"

ChildWindow::ChildWindow()
{
    mainWindow = nullptr;
}

void ChildWindow::setMainWindow(MainWindow *mainWindow)
{
    this->mainWindow = mainWindow;
}

MainWindow *ChildWindow::getMainWindow()
{
    return mainWindow;
}
