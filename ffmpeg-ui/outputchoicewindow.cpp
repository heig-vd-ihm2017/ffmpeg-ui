/**
    file: outputchoicewindow.cpp
    authors: Ludovic Delafontaine, Sathiya Kirushnapillai, Mathieu Monteverde
*/

#include "mainwindow.h"
#include "outputchoicewindow.h"
#include "ui_outputchoicewindow.h"

#include <QFileDialog>
#include <QMessageBox>

OutputChoiceWindow::OutputChoiceWindow(QWidget *parent) :
    QWidget(parent),
    ChildWindow(),
    ui(new Ui::OutputChoiceWindow)
{
    ui->setupUi(this);

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

void OutputChoiceWindow::initWindow()
{
    resetErrors();

    // Set data
    ui->inputFileValue->setText(getSettingsContainer()->getInputFilePath());
    ui->startTimeValue->setText(getSettingsContainer()->getStartTime());
    ui->totalTimeValue->setText(getSettingsContainer()->getTotalTime());
    ui->endTimeValue->setText(getSettingsContainer()->getEndTime());
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

    QString input = getSettingsContainer()->getInputFilePath();
    QFileInfo infi(input);
    QString inext = infi.suffix();


    QFileInfo outfi(outputFilePath);
    QString outext = outfi.suffix();

    if(outfi.exists()) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Confirmation", "Are you sure that you want to override this file?",
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            // Check if the output file is valid
            if (inext == outext) {
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
    }
}

void OutputChoiceWindow::on_outputFileButton_clicked() {

    // Get input ext
    QString input = getSettingsContainer()->getInputFilePath();
    QFileInfo fi(input);
    QString ext = fi.suffix();

    // Allows to select file
    QString filename = QFileDialog::getSaveFileName(this, tr("Save File"),
                                "/home",
                                tr(QString("Videos (*.%1)").arg(ext).toStdString().c_str()));

    // Set the plain text edit
    ui->outputFileText->document()->setPlainText(filename);
}
