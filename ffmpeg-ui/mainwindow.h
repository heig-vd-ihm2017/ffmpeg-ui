/**
    file: mainwindow.h
    authors: Ludovic Delafontaine, Sathiya Kirushnapillai, Mathieu Monteverde
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "inputchoicewindow.h"
#include "outputchoicewindow.h"
#include "resultwindow.h"
#include "settingscontainer.h"
#include "summarywindow.h"
#include "timessettingswindow.h"

namespace Ui
{
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
    enum WidgetWindow {MAIN_WINDOW, INPUT_CHOICE_WINDOW, TIMES_SETTINGS_WINDOW, OUTPUT_CHOICE_WINDOW, SUMMARY_WINDOW, RESULT_WINDOW };

    /**
     * @brief MainWindow Constructor.
     * @param parent The parent of the current window.
     */
    explicit MainWindow(QWidget *parent = 0);

    /**
     * Destructor.
     */
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
     * @brief on_back_clicked Go to the previous step.
     */
    void on_next_clicked();

    /**
     * @brief on_actionExit_triggered Exit the program.
     */
    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;

    SettingsContainer *settingsContainer;

    // Children windows
    InputChoiceWindow inputChoiceWindow;
    TimesSettingsWindow timessettingsWindow;
    OutputChoiceWindow outputChoiceWindow;
    SummaryWindow summaryWindow;
    ResultWindow resultWindow;
};

#endif // MAINWINDOW_H
