#include "mainwindow.h"
#include "inputchoicewindow.h"
#include "ui_inputchoicewindow.h"

InputChoiceWindow::InputChoiceWindow(QWidget *parent) :
    QWidget(parent),
    ChildWindow(),
    ui(new Ui::InputChoiceWindow)
{
    ui->setupUi(this);

    ui->error->setHidden(true);
    ui->tooltip->setHidden(true);
}

InputChoiceWindow::~InputChoiceWindow()
{
    delete ui;
}

void InputChoiceWindow::on_back_clicked()
{
    getMainWindow()->setCurrentWindow(MainWindow::MAIN_WINDOW);
}

void InputChoiceWindow::on_next_clicked()
{
    getMainWindow()->setCurrentWindow(MainWindow::TIMES_SETTINGS_WINDOW);
}
