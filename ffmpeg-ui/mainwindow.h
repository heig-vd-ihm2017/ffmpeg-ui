#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <inputchoicewindow.h>
#include <timessettingswindow.h>
#include <outputchoicewindow.h>
#include <summarywindow.h>
#include <resultwindow.h>

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
     * @brief on_back_clicked Go to the previous step.
     */
    void on_next_clicked();

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;

    // Children windows
    InputChoiceWindow inputChoiceWindow;
    TimesSettingsWindow timessettingsWindow;
    OutputChoiceWindow outputChoiceWindow;
    SummaryWindow summaryWindow;
    ResultWindow resultWindow;
};

#endif // MAINWINDOW_H
