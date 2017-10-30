/**
    file: inputchoicewindow.cpp
    authors: Ludovic Delafontaine, Sathiya Kirushnapillai, Mathieu Monteverde
*/

#include <QFileDialog>
#include <QProcess>
#include <stdexcept>

#include "mainwindow.h"
#include "inputchoicewindow.h"
#include "ui_inputchoicewindow.h"
#include "video.h"

InputChoiceWindow::InputChoiceWindow(QWidget *parent) :
    QWidget(parent),
    ChildWindow(),
    ui(new Ui::InputChoiceWindow)
{
    ui->setupUi(this);

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

void InputChoiceWindow::initWindow() {
    resetErrors();

    ui->inputFileText->setPlainText(getSettingsContainer()->getInputFilePath());
}

void InputChoiceWindow::on_back_clicked()
{
    resetErrors();

    getMainWindow()->setCurrentWindow(MainWindow::MAIN_WINDOW);
}

void InputChoiceWindow::on_next_clicked()
{
    // Get the filename
    QString filename = ui->inputFileText->document()->toPlainText();

    // Try to open the file
    try {
        Video video(filename.toStdString().c_str());

        resetErrors();

        // Save the settings
        getSettingsContainer()->setInputFilePath(filename);

        // Go to next window
        getMainWindow()->setCurrentWindow(MainWindow::TIMES_SETTINGS_WINDOW);

    } catch (const std::runtime_error& e) {
        // Show errors
        ui->error->setHidden(false);

        if (getNumberOfTriesToNextStep() >= 2) {
            ui->tooltip->setHidden(false);
        }
    }
}

void InputChoiceWindow::on_inputFileButton_clicked() {

    // Allows to select file
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), "/home", tr("All Files (*.*)"));

    // Set the plain text edit
    ui->inputFileText->document()->setPlainText(filename);
}

