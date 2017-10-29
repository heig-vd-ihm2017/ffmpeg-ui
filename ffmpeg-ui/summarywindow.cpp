/**
    file: summarywindow.cpp
    authors: Ludovic Delafontaine, Sathiya Kirushnapillai, Mathieu Monteverde
*/

#include "mainwindow.h"
#include "summarywindow.h"
#include "ui_summarywindow.h"

SummaryWindow::SummaryWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SummaryWindow)
{
    ui->setupUi(this);
}

SummaryWindow::~SummaryWindow()
{
    delete ui;
}

void SummaryWindow::initWindow()
{
    // Set all data
    ui->inputFileValue->setText(getSettingsContainer()->getInputFilePath());
    ui->startTimeValue->setText(getSettingsContainer()->getStartTime());
    ui->endTimeValue->setText(getSettingsContainer()->getEndTime());
    ui->totalTimeValue->setText(getSettingsContainer()->getTotalTime());
    ui->outputFileValue->setText(getSettingsContainer()->getOutputFilePath());
}

void SummaryWindow::on_back_clicked()
{
    getMainWindow()->setCurrentWindow(MainWindow::OUTPUT_CHOICE_WINDOW);
}

void SummaryWindow::on_next_clicked()
{
    getMainWindow()->setCurrentWindow(MainWindow::RESULT_WINDOW);
}
