#ifndef SETTINGSCONTAINER_H
#define SETTINGSCONTAINER_H

#include <QString>

namespace Ui
{
    class SettingsContainer;
}

class SettingsContainer
{

public:
    SettingsContainer();

    QString getInputFilePath() const;

    void setInputFilePath(const QString& inputFilePath);

    QString getStartTime() const;

    void setStartTime(const QString& startTime);

    QString getEndTime() const;

    void setEndTime(const QString& endTime);

    QString getOutputFilePath() const;

    void setOutputFilePath(const QString& outputFilePath);

    void reset();

private:

    //! The input file
    QString inputFilePath;

    //! The start cut time
    QString startTime;

    //! The end cut time
    QString endTime;

    //! The output file
    QString outputFilePath;

};

#endif // SETTINGSCONTAINER_H
