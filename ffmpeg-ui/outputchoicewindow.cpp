#include "mainwindow.h"
#include "outputchoicewindow.h"
#include "ui_outputchoicewindow.h"

OutputChoiceWindow::OutputChoiceWindow(QWidget *parent) :
    QWidget(parent),
    ChildWindow(),
    ui(new Ui::OutputChoiceWindow)
{
    ui->setupUi(this);
}

OutputChoiceWindow::~OutputChoiceWindow()
{
    delete ui;
}

void OutputChoiceWindow::on_back_clicked()
{
    getMainWindow()->setCurrentWindow(MainWindow::TIMES_SETTINGS_WINDOW);
}

void OutputChoiceWindow::on_next_clicked()
{
    getMainWindow()->setCurrentWindow(MainWindow::SUMMARY_WINDOW);
}
