#include "childwindow.h"
#include "mainwindow.h"
#include "settingscontainer.h"

ChildWindow::ChildWindow() : numberOfTriesToNextStep(0)
{
    mainWindow = nullptr;
    settingsContainer = nullptr;
}

void ChildWindow::setMainWindow(MainWindow *mainWindow)
{
    this->mainWindow = mainWindow;
}

MainWindow *ChildWindow::getMainWindow()
{
    return mainWindow;
}

void ChildWindow::setSettingsContainer(SettingsContainer *settingsContainer)
{
    this->settingsContainer = settingsContainer;
}

SettingsContainer *ChildWindow::getSettingsContainer()
{
    return settingsContainer;
}

int ChildWindow::getNumberOfTriesToNextStep() {
    numberOfTriesToNextStep++;

    return numberOfTriesToNextStep;
}

void ChildWindow::setNumberOfTriesToNextStep(int numberOfTrisToNextStep)
{
    this->numberOfTriesToNextStep = numberOfTrisToNextStep;
}
