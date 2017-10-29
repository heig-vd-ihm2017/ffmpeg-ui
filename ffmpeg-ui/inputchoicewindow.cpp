/**
    file: inputchoicewindow.cpp
    authors: Ludovic Delafontaine, Sathiya Kirushnapillai, Mathieu Monteverde
*/

#include "mainwindow.h"
#include "inputchoicewindow.h"
#include "ui_inputchoicewindow.h"

InputChoiceWindow::InputChoiceWindow(QWidget *parent) :
    QWidget(parent),
    ChildWindow(),
    ui(new Ui::InputChoiceWindow)
{
    ui->setupUi(this);

    // Fais crasher le programme car SettingsContainer n'est pas encore initialisé je crois...
    /*
    ui->inputFileText->setPlainText(getSettingsContainer()->getInputFilePath());
    */

    resetErrors();
}

InputChoiceWindow::~InputChoiceWindow()
{
    delete ui;
}

void InputChoiceWindow::resetErrors()
{
    setNumberOfTriesToNextStep();

    // Hide the errors
    ui->error->setHidden(true);
    ui->tooltip->setHidden(true);
}

void InputChoiceWindow::on_back_clicked()
{
    resetErrors();

    getMainWindow()->setCurrentWindow(MainWindow::MAIN_WINDOW);
}

void InputChoiceWindow::on_next_clicked()
{
    // Get the inputs
    QString inputFilePath = ui->inputFileText->toPlainText();

    // Check if the file is valid
    if (true) {

        resetErrors();

        // Save the settings
        getSettingsContainer()->setInputFilePath(inputFilePath);

        // Go to next window
        getMainWindow()->setCurrentWindow(MainWindow::TIMES_SETTINGS_WINDOW);
    }
    else {

        // Show errors
        ui->error->setHidden(false);

        if (getNumberOfTriesToNextStep() >= 2) {
            ui->tooltip->setHidden(false);
        }
    }
}
