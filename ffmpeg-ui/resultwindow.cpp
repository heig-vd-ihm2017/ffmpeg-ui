#include "mainwindow.h"
#include "resultwindow.h"
#include "ui_resultwindow.h"

ResultWindow::ResultWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResultWindow)
{
    ui->setupUi(this);
}

ResultWindow::~ResultWindow()
{
    delete ui;
}

void ResultWindow::initWindow()
{
    ui->command->setText(
                "ffmpeg -ss "
                + getSettingsContainer()->getStartTime() + " -i "
                + getSettingsContainer()->getInputFilePath() + " -t "
                + getSettingsContainer()->getTotalTime() +" -c copy "
                + getSettingsContainer()->getOutputFilePath());
}

void ResultWindow::on_restart_clicked()
{
    getSettingsContainer()->reset();
    getMainWindow()->setCurrentWindow(MainWindow::MAIN_WINDOW);
}

void ResultWindow::on_exit_clicked()
{
    exit(EXIT_SUCCESS);
}
