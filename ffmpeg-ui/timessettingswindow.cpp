/**
    file: timessettingswindow.cpp
    authors: Ludovic Delafontaine, Sathiya Kirushnapillai, Mathieu Monteverde
*/

#include <qfiledialog.h>
#include <qprocess.h>

#include "mainwindow.h"
#include "timessettingswindow.h"
#include "ui_timessettingswindow.h"
#include "video.h"

QRegularExpression TimesSettingsWindow::PATTERN("^[0-5][0-9]\\:[0-5][0-9]\\:[0-5][0-9]\\.[0-9][0-9]$");

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

void TimesSettingsWindow::initWindow()
{
    // Set the input file path label
    QString filePath = getSettingsContainer()->getInputFilePath();
    ui->inputFileValue->setText(filePath);

    // Set the input file duration
    Video video(getSettingsContainer()->getInputFilePath().toStdString().c_str());
    ui->lengthValue->setText(video.duration());

    // Set default values
    if (getSettingsContainer()->getStartTime().length() == 0) {
        ui->startTimeInput->setPlainText("00:00:00.00");
    }
    if (getSettingsContainer()->getEndTime().length() == 0) {
        ui->endTimeInput->setPlainText(video.duration());
    }

    resetErrors();
}

void TimesSettingsWindow::on_back_clicked()
{
    resetErrors();

    getMainWindow()->setCurrentWindow(MainWindow::INPUT_CHOICE_WINDOW);
}

void TimesSettingsWindow::on_next_clicked()
{
    const QString videoStartTime = "00:00:00.00";
    const QString videoEndTime = ui->lengthValue->text();

    // Get the inputs
    QString startTime = ui->startTimeInput->toPlainText();
    QString endTime = ui->endTimeInput->toPlainText();

    bool startTimeError = !isValidTime(startTime, videoStartTime, videoEndTime);
    bool endTimeError = !isValidTime(endTime, videoStartTime, videoEndTime)
                || timeStringToInt(endTime) <= timeStringToInt(startTime);

    // Errors if the start time is not in the range
    if (startTimeError) {
        ui->errorStartTime->setHidden(false);

        if (getNumberOfTriesToNextStep() >= 2) {
            ui->tooltip->setHidden(false);
        }
    } else {
        ui->errorStartTime->setHidden(true);
    }

    // Errors if the end time is not in the range or it is smaller than start time
    if (endTimeError) {
        ui->errorEndTime->setHidden(false);

        if (getNumberOfTriesToNextStep() >= 2) {
            ui->tooltip->setHidden(false);
        }
    } else {
        ui->errorEndTime->setHidden(true);
    }

    // Everything is ok
    if (!startTimeError && !endTimeError) {

        // Save settings
        getSettingsContainer()->setStartTime(startTime);
        getSettingsContainer()->setEndTime(endTime);

        int totalTime = timeStringToInt(endTime) - timeStringToInt(startTime);
        QString strTotalTime = timeIntToString(totalTime);
        getSettingsContainer()->setTotalTime(strTotalTime);

        // Go to next window
        getMainWindow()->setCurrentWindow(MainWindow::OUTPUT_CHOICE_WINDOW);
    }
}

bool TimesSettingsWindow::isValidTime(const QString &time, const QString &min, const QString &max)
{
    if (!PATTERN.match(time).hasMatch()) {
        return false;
    }

    // Convert to integer time in seconds
    int timeCent = timeStringToInt(time);

    if (timeCent == -1) {
        return false;
    }

    int minCent = timeStringToInt(min);
    int maxCent = timeStringToInt(max);

    // return the truth
    return (timeCent >= minCent && timeCent <= maxCent);
}

int TimesSettingsWindow::timeStringToInt(const QString &string)
{
    // hours, minutes, seconds and centiseconds
    int h, m, s, c;

    // The time in cents
    int cents = -1;

    // Try to read the time
    if (sscanf(string.toLatin1().data(), "%d:%d:%d.%d", &h, &m, &s, &c) >= 4)
    {
      cents = h *3600 * 100 + m * 60 * 100 + s * 100 + c;
    }

    // If any value is wrong return -1
    if (h < 0 || h > 59 || m < 0 || m > 59 || s < 0 || s > 59 || c < 0 || c > 99) {
        return -1;
    }

    // Return the read sum of tim or -1 if not every value could be read
    return cents;
}

QString TimesSettingsWindow::timeIntToString(int time)
{
    int h, m, s, c;
    s = time / 100;
    c = time % 100;
    m = s / 60;
    s = s % 60;
    h = m / 60;
    m = m % 60;

    return QString().sprintf("%02d:%02d:%02d.%02d", h, m, s, c);
}
