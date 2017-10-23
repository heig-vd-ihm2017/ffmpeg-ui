#ifndef CHOOSEFILEWINDOW_H
#define CHOOSEFILEWINDOW_H

#include <QWidget>
#include <childwindow.h>

namespace Ui {
class ChooseFileWindow;
}

/**
 * @brief The ChooseFileWindow class is the controller
 * for the Choose File window where the user can select a file
 * to convert on his computer.
 * It is a ChildWindow as well.
 */
class ChooseFileWindow : public QWidget, public ChildWindow
{
    Q_OBJECT

public:
    explicit ChooseFileWindow(QWidget *parent = 0);
    ~ChooseFileWindow();

private slots:
    // Dummy button to test the interactivity between the windows
    void on_back_clicked();

private:
    Ui::ChooseFileWindow *ui;
};

#endif // CHOOSEFILEWINDOW_H
