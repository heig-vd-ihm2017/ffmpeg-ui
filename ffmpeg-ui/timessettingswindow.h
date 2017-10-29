#ifndef TIMESSETTINGSWINDOW_H
#define TIMESSETTINGSWINDOW_H

#include <QWidget>

#include <childwindow.h>
#include <QRegularExpression>

namespace Ui
{
    class TimesSettingsWindow;
}

/**
 * @brief The TimesSettingsWindow class is the controller
 * for the Times Settings window where the user can view the
 * settings of the file he has chosen and can decide the length
 * of the video and other settings.
 *
 * It is a ChildWindow as well.
 */
class TimesSettingsWindow : public QWidget, public ChildWindow
{
    Q_OBJECT

public:
    /**
     * @brief TimesSettingsWindow
     * @param parent The parent of the current window.
     */
    explicit TimesSettingsWindow(QWidget *parent = 0);

    /**
     * Destructor.
     */
    ~TimesSettingsWindow();

    /**
     * @brief resetErrors Reset the errors on the window.
     */
    void resetErrors();

    /**
     * @override
     * @brief initWindow init the content of the window
     */
    void initWindow();

private slots:
    /**
     * @brief on_back_clicked Go to the previous step.
     */
    void on_back_clicked();

    /**
     * @brief on_next_clicked Go to the next step.
     */
    void on_next_clicked();

private:
    Ui::TimesSettingsWindow *ui;

    /**
     * @brief isValidTime validate if the given time QString is in the given range.
     * @param time the time to validate
     * @param min the range min value
     * @param max the range max value
     * @return
     */
    bool isValidTime(const QString& time, const QString& min, const QString& max);

    /**
     * @brief timeStringToInt converts given formatted string time to seconds.
     * @param string the formatted time (hh:mm:ss)
     * @return the number of the seconds
     */
    int timeStringToInt(const QString& string);
};

#endif // TIMESSETTINGSWINDOW_H
