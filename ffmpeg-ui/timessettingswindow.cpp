#include "mainwindow.h"
#include "timessettingswindow.h"
#include "ui_timessettingswindow.h"

TimesSettingsWindow::TimesSettingsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TimesSettingsWindow)
{
    ui->setupUi(this);
}

TimesSettingsWindow::~TimesSettingsWindow()
{
    delete ui;
}

void TimesSettingsWindow::on_back_clicked()
{
    getMainWindow()->setCurrentWindow(MainWindow::INPUT_CHOICE_WINDOW);
}

void TimesSettingsWindow::on_next_clicked()
{
    getMainWindow()->setCurrentWindow(MainWindow::OUTPUT_CHOICE_WINDOW);
}
