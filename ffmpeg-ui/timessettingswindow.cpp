#include "mainwindow.h"
#include "timessettingswindow.h"
#include "ui_timessettingswindow.h"

TimesSettingsWindow::TimesSettingsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TimesSettingsWindow)
{
    ui->setupUi(this);

    resetErrors();
}

TimesSettingsWindow::~TimesSettingsWindow()
{
    delete ui;
}

void TimesSettingsWindow::resetErrors()
{
    setNumberOfTriesToNextStep();

    ui->errorStartTime->setHidden(true);
    ui->errorEndTime->setHidden(true);
    ui->tooltip->setHidden(true);
}

void TimesSettingsWindow::on_back_clicked()
{
    resetErrors();

    getMainWindow()->setCurrentWindow(MainWindow::INPUT_CHOICE_WINDOW);
}

void TimesSettingsWindow::on_next_clicked()
{
    // Get the inputs
    QString startTime = ui->startTimeInput->toPlainText();
    QString endTime = ui->endTimeInput->toPlainText();

    // Errors if the start time is not in the range
    if (false) {
        ui->errorStartTime->setHidden(false);

        if (getNumberOfTriesToNextStep() >= 2) {
            ui->tooltip->setHidden(false);
        }
    }
    // Errors if the end time is not in the range
    else if (false) {
        ui->errorEndTime->setHidden(false);

        if (getNumberOfTriesToNextStep() >= 2) {
            ui->tooltip->setHidden(false);
        }
    }
    // Errors if the start and end times overlap
    else if (false) {
        ui->errorStartTime->setHidden(false);
        ui->errorEndTime->setHidden(false);

        if (getNumberOfTriesToNextStep() >= 2) {
            ui->tooltip->setHidden(false);
        }
    }
    // Everything is ok
    else {

        // Save settings
        getSettingsContainer()->setStartTime(startTime);
        getSettingsContainer()->setEndTime(endTime);

        // Go to next window
        getMainWindow()->setCurrentWindow(MainWindow::OUTPUT_CHOICE_WINDOW);
    }
}
