#include "mainwindow.h"
#include "resultwindow.h"
#include "ui_resultwindow.h"

ResultWindow::ResultWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResultWindow)
{
    ui->setupUi(this);
}

ResultWindow::~ResultWindow()
{
    delete ui;
}

void ResultWindow::on_restart_clicked()
{
    getMainWindow()->setCurrentWindow(MainWindow::MAIN_WINDOW);
}

void ResultWindow::on_exit_clicked()
{
    exit(EXIT_SUCCESS);
}
