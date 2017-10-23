#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>
#include <childwindow.h>

namespace Ui {
class SettingsWindow;
}

/**
 * @brief The SettingsWindow class is the controller
 * for the Settings window where the user can view the
 * settings of the file he has chosen and can decide the length
 * of the video and other settings.
 *
 * It is a ChildWindow as well.
 */
class SettingsWindow : public QWidget, public ChildWindow
{
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = 0);
    ~SettingsWindow();

private:
    Ui::SettingsWindow *ui;
};

#endif // SETTINGSWINDOW_H
