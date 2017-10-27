#ifndef CHILDWINDOW_H
#define CHILDWINDOW_H

class MainWindow;

/**
 * @brief The ChildWindow class represents child windows of the
 * application. A child window is displayed inside a parent window
 * called the main window.
 */
class ChildWindow
{
public:
    /**
     * @brief ChildWindow Constructor.
     */
    ChildWindow();

    /**
     * @brief setMainWindow sets the MainWindow object.
     *
     * @param mainWindow the MainWindow object to set
     */
    void setMainWindow(MainWindow* mainWindow);

    /**
     * @brief getMainWindow gets the MainWindow object.
     *
     * @return the MainWindow object
     */
    MainWindow* getMainWindow();

private:
    // Pointer to the main window
    MainWindow* mainWindow;
};

#endif // CHILDWINDOW_H
