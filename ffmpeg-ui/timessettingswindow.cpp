#include "mainwindow.h"
#include "timessettingswindow.h"
#include "ui_timessettingswindow.h"
#include <qfiledialog.h>
#include <qprocess.h>
#include "video.h"

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
    ui->inputFileLabel->setText(filePath);

    Video video("/Users/mathieu/Desktop/testffmpeg/test2.mp4");
    printf("%d\n", video.duration());

    /*
    // Call the ffprobe command line tool to retrieve the duration
    QProcess process;

    process.start("/usr/local/bin/ffprobe", QStringList() << "/Users/mathieu/Desktop/testffmpeg/test2.mp4");
    process.waitForFinished();
    QString output(process.readAllStandardError());

    const QString videoStartTime = "00:00:00.00";
    const QString videoEndTime = QRegularExpression("(?<=Duration\: ).*(?=, start)").match(output).captured();

    ui->lengthValue->setText(videoEndTime);
    */
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

        // Go to next window
        getMainWindow()->setCurrentWindow(MainWindow::OUTPUT_CHOICE_WINDOW);
    }
}

bool TimesSettingsWindow::isValidTime(const QString &time, const QString &min, const QString &max)
{
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

    int cents = -1;

    if (sscanf(string.toLatin1().data(), "%d:%d:%d.%d", &h, &m, &s, &c) >= 4)
    {
      cents = h *3600 * 100 + m * 60 * 100 + s * 100 + c;
    }

    if (h < 0 || h > 59 || m < 0 || m > 59 || s < 0 || s > 59 || c < 0 || c > 99) {
        return -1;
    }

    return cents;
}
