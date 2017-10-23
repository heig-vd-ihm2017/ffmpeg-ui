#include "choosefilewindow.h"
#include "ui_choosefilewindow.h"
#include <mainwindow.h>

ChooseFileWindow::ChooseFileWindow(QWidget *parent) :
    QWidget(parent),
    ChildWindow(),
    ui(new Ui::ChooseFileWindow)
{
    ui->setupUi(this);
}

ChooseFileWindow::~ChooseFileWindow()
{
    delete ui;
}

void ChooseFileWindow::on_back_clicked()
{
    getMainWindow()->setCurrentWindow(MainWindow::MAIN_WINDOW);
}
