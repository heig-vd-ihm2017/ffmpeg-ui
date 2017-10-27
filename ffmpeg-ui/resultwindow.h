#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <QWidget>

#include <childwindow.h>

namespace Ui
{
    class ResultWindow;
}

/**
 * @brief The ResultWindow class is the controller
 * for the Result window where the user view the results
 * of the whole process. In our case, it only shows the
 * ffmpeg command the user should use to put the wanted
 * input file to the output file with the time settings
 * he wanted.
 *
 * It is a ChildWindow as well.
 */
class ResultWindow : public QWidget, public ChildWindow
{
    Q_OBJECT

public:
    explicit ResultWindow(QWidget *parent = 0);
    ~ResultWindow();

private slots:
    void on_restart_clicked();

    void on_exit_clicked();

private:
    Ui::ResultWindow *ui;
};

#endif // RESULTWINDOW_H
