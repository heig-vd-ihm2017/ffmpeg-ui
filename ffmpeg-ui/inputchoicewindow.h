/**
    file: inputchoicewindow.h
    authors: Ludovic Delafontaine, Sathiya Kirushnapillai, Mathieu Monteverde
*/

#ifndef INPUTCHOICEWINDOW_H
#define INPUTCHOICEWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QPlainTextEdit>

#include <childwindow.h>

namespace Ui
{
    class InputChoiceWindow;
}

/**
 * @brief The InputChoiceWindow class is the controller
 * for the Input Choice window where the user can select a file
 * to convert on his computer.
 * It is a ChildWindow as well.
 */
class InputChoiceWindow : public QWidget, public ChildWindow
{
    Q_OBJECT

public:
    /**
     * @brief InputChoiceWindow Constructor.
     * @param parent The parent of the current window.
     */
    explicit InputChoiceWindow(QWidget *parent = 0);

    /**
     * Destructor.
     */
    ~InputChoiceWindow();

    /**
     * @brief resetErrors Reset the errors on the window.
     */
    void resetErrors();

    void initWindow() override;

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
     * @brief on_inputFileButton_clicked Allows to choose a file
     */
    void on_inputFileButton_clicked();


private:
    Ui::InputChoiceWindow *ui;
};

#endif // INPUTCHOICEWINDOW_H
