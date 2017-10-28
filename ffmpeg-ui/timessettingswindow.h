#ifndef TIMESSETTINGSWINDOW_H
#define TIMESSETTINGSWINDOW_H

#include <QWidget>

#include <childwindow.h>

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
};

#endif // TIMESSETTINGSWINDOW_H
