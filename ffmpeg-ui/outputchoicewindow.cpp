#include "mainwindow.h"
#include "outputchoicewindow.h"
#include "ui_outputchoicewindow.h"

OutputChoiceWindow::OutputChoiceWindow(QWidget *parent) :
    QWidget(parent),
    ChildWindow(),
    ui(new Ui::OutputChoiceWindow)
{
    ui->setupUi(this);

    // Fais crasher le programme car SettingsContainer n'est pas encore initialisé je crois...
    /*
    ui->inputFileValue->setPlainText(getSettingsContainer()->getInputFilePath());
    ui->startTimeValue->setPlainText(getSettingsContainer()->getStartTime());
    ui->endTimeValue->setPlainText(getSettingsContainer()->getEndTime());
    // Le calcul ici est totalement faux
    ui->totalTimeValue->setPlainText(getSettingsContainer()->getEndTime() - getSettingsContainer()->getStartTime());
    ui->outputFileText->setPlainText(getSettingsContainer()->getOutputFilePath());
    */

    resetErrors();
}

OutputChoiceWindow::~OutputChoiceWindow()
{
    delete ui;
}

void OutputChoiceWindow::resetErrors()
{
    setNumberOfTriesToNextStep();

    // Hide the errors
    ui->error->setHidden(true);
    ui->tooltip->setHidden(true);
}


void OutputChoiceWindow::on_back_clicked()
{
    resetErrors();

    getMainWindow()->setCurrentWindow(MainWindow::TIMES_SETTINGS_WINDOW);
}

void OutputChoiceWindow::on_next_clicked()
{
    // Get the inputs
    QString outputFilePath = ui->outputFileText->toPlainText();

    // Check if the output file is valid
    if (true) {

        resetErrors();

        // Save the settings
        getSettingsContainer()->setOutputFilePath(outputFilePath);

        // Go to next window
        getMainWindow()->setCurrentWindow(MainWindow::SUMMARY_WINDOW);
    }
    else {

        // Show errors
        ui->error->setHidden(false);

        if (getNumberOfTriesToNextStep() >= 2) {
            ui->tooltip->setHidden(false);
        }
    }
}
