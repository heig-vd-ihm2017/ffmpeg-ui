#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set main window to children
    chooseFileWindow.setMainWindow(this);
    settingsWindow.setMainWindow(this);

    // Insert the widget windows in order
    ui->stackedWidget->addWidget(&chooseFileWindow);
    ui->stackedWidget->addWidget(&settingsWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setCurrentWindow(MainWindow::WidgetWindow windowEnum)
{
    ui->stackedWidget->setCurrentIndex(windowEnum);
}

void MainWindow::on_getStarted_clicked()
{
    setCurrentWindow(CHOOSE_FILE_WINDOW);
}
