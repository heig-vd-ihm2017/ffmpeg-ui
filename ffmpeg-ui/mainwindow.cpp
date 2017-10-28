#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settingscontainer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    settingsContainer(new SettingsContainer)
{
    ui->setupUi(this);

    // Set main window to children
    inputChoiceWindow.setMainWindow(this);
    timessettingsWindow.setMainWindow(this);
    outputChoiceWindow.setMainWindow(this);
    summaryWindow.setMainWindow(this);
    resultWindow.setMainWindow(this);

    // Set settings container to children
    inputChoiceWindow.setSettingsContainer(settingsContainer);
    timessettingsWindow.setSettingsContainer(settingsContainer);
    outputChoiceWindow.setSettingsContainer(settingsContainer);
    summaryWindow.setSettingsContainer(settingsContainer);
    resultWindow.setSettingsContainer(settingsContainer);

    // Insert the widget windows in order
    ui->stackedWidget->addWidget(&inputChoiceWindow);
    ui->stackedWidget->addWidget(&timessettingsWindow);
    ui->stackedWidget->addWidget(&outputChoiceWindow);
    ui->stackedWidget->addWidget(&summaryWindow);
    ui->stackedWidget->addWidget(&resultWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete settingsContainer;
}

void MainWindow::setCurrentWindow(MainWindow::WidgetWindow windowEnum)
{
    ui->stackedWidget->setCurrentIndex(windowEnum);
}

void MainWindow::on_next_clicked()
{
    setCurrentWindow(INPUT_CHOICE_WINDOW);
}

void MainWindow::on_actionExit_triggered()
{
    exit(EXIT_SUCCESS);
}
