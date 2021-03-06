/**
    file: outputchoicewindow.h
    authors: Ludovic Delafontaine, Sathiya Kirushnapillai, Mathieu Monteverde
*/

#ifndef OUTPUTCHOICEWINDOW_H
#define OUTPUTCHOICEWINDOW_H

#include <QWidget>
/**
    file: outputchoicewindow.h
    authors: Ludovic Delafontaine, Sathiya Kirushnapillai, Mathieu Monteverde
*/

#include <childwindow.h>

namespace Ui
{
    class OutputChoiceWindow;
}

/**
 * @brief The OutputChoiceWindow class is the controller
 * for the Output Choice window where the user can select an
 * output file to store the converted file.
 * It is a ChildWindow as well.
 */
class OutputChoiceWindow : public QWidget, public ChildWindow
{
    Q_OBJECT

public:
    /**
     * @brief OutputChoiceWindow
     * @param parent The parent of the current window.
     */
    explicit OutputChoiceWindow(QWidget *parent = 0);

    /**
     * Destructor.
     */
    ~OutputChoiceWindow();

    /**
     * @brief resetErrors Reset the errors on the window.
     */
    void resetErrors();

    /**
     * @brief initWindow init the window
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

    /**
     * @brief on_outputFileButton_clicked Allows to choose a path
     */
    void on_outputFileButton_clicked();

private:
    Ui::OutputChoiceWindow *ui;
};

#endif // OUTPUTCHOICEWINDOW_H
