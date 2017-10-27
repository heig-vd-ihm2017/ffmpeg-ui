#ifndef SUMMARYWINDOW_H
#define SUMMARYWINDOW_H

#include <QWidget>

#include <childwindow.h>

namespace Ui
{
    class SummaryWindow;
}

/**
 * @brief The SummaryWindow class is the controller
 * for the Summary window where the user can view the
 * summary of the whole process before confirming the
 * encoding.
 *
 * It is a ChildWindow as well.
 */
class SummaryWindow : public QWidget, public ChildWindow
{
    Q_OBJECT

public:
    /**
     * @brief SummaryWindow
     * @param parent The parent of the current window.
     */
    explicit SummaryWindow(QWidget *parent = 0);

    /**
     * Destructor.
     */
    ~SummaryWindow();

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
    Ui::SummaryWindow *ui;
};

#endif // SUMMARYWINDOW_H
