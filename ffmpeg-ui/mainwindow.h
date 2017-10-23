#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <choosefilewindow.h>
#include <settingswindow.h>

namespace Ui {
class MainWindow;
}

/**
 * @brief The MainWindow class is the main window controller
 * of the application. It has other windows as children and
 * displays them.
 * It specifies a WidgetWindow enum that list all of its children
 * position codes in the ui StackedWidget stack.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // enum to list windows
    enum WidgetWindow {MAIN_WINDOW, CHOOSE_FILE_WINDOW, SETTINGS_WINDOW };

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    /**
     * @brief setCurrentWindow sets the current window according to its
     * WidgetWindow enum code.
     *
     * @param windowEnum the WidgetWindow enum code of the windoe to set
     */
    void setCurrentWindow(MainWindow::WidgetWindow windowEnum);

private slots:
    /**
     * @brief on_getStarted_clicked action executed when the button getStarted
     * is clicked.
     */
    void on_getStarted_clicked();

private:
    Ui::MainWindow *ui;

    // Children windows
    ChooseFileWindow chooseFileWindow;
    SettingsWindow settingsWindow;
};

#endif // MAINWINDOW_H
