#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Headers/Task.h"
#include "Headers/TaskList.h"
#include <QTextEdit>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addTask_clicked()
{
    TaskList inputTask;
    inputTask.addTask(taskTitle.toPlainText().toStdString(), taskDescription.toPlainText().toStdString(), taskClassification.toPlainText().toInt(), taskPriority.toPlainText().toInt(), taskDate.toPlainText().toStdString(), taskDuration.toPlainText().toInt());
}

