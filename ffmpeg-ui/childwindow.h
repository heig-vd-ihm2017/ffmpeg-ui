#ifndef CHILDWINDOW_H
#define CHILDWINDOW_H

class MainWindow;
class SettingsContainer;

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
     * @param mainWindow the MainWindow object to set.
     */
    void setMainWindow(MainWindow* mainWindow);

    /**
     * @brief getMainWindow gets the MainWindow object.
     *
     * @return the MainWindow object.
     */
    MainWindow* getMainWindow();

    /**
     * @brief setSettingsContainer sets the SettingsContainer object.
     *
     * @param settingsContainer the settingsContainer object to set.
     */
    void setSettingsContainer(SettingsContainer* settingsContainer);

    /**
     * @brief getSettingsContainer gets the SettingsContainer object.
     *
     * @return the SettingsContainer object.
     */
    SettingsContainer* getSettingsContainer();

    /**
     * @brief getNumberOfTriesToNextStep gets the number of tries to go
     * to the next step.
     *
     * @return the number of tries.
     */
    int getNumberOfTriesToNextStep();

    /**
     * @brief setNumberOfTriesToNextStep sets the number of tries to go
     * to the next step.
     */
    void setNumberOfTriesToNextStep(int numberOfTriesToNextStep = 0);

    /**
     * @brief initWindow method called after each window change to allow it
     * to initialize its view
     */
    virtual void initWindow();

private:
    // Pointer to the main window
    MainWindow* mainWindow;

    // Pointer to the settings container
    SettingsContainer* settingsContainer;

    // The number of tries for the error tooltip
    int numberOfTriesToNextStep;
};

#endif // CHILDWINDOW_H
