#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_increase_clicked()
{
}

