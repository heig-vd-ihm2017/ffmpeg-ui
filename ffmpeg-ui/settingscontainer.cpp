#include "settingscontainer.h"

SettingsContainer::SettingsContainer() :
    inputFilePath(""),
    startTime(""),
    endTime(""),
    outputFilePath("")
{

}

QString SettingsContainer::getInputFilePath() const
{
    return inputFilePath;
}

void SettingsContainer::setInputFilePath(const QString& inputFilePath)
{
    this->inputFilePath = inputFilePath;
}

QString SettingsContainer::getStartTime() const
{
    return startTime;
}

void SettingsContainer::setStartTime(const QString& startTime)
{
    this->startTime = startTime;
}

QString SettingsContainer::getEndTime() const
{
    return endTime;
}

void SettingsContainer::setEndTime(const QString& endTime)
{
    this->endTime = endTime;
}

QString SettingsContainer::getOutputFilePath() const
{
    return outputFilePath;
}

void SettingsContainer::setOutputFilePath(const QString& outputFilePath)
{
    this->outputFilePath = outputFilePath;
}

QString SettingsContainer::getTotalTime() const
{
    return totalTime;
}

void SettingsContainer::setTotalTime(const QString &totalTime)
{
    this->totalTime = totalTime;
}

void SettingsContainer::reset() {
    inputFilePath = "";
    startTime = "";
    endTime = "";
    outputFilePath = "";
}
