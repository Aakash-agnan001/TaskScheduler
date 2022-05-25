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
    inputTask.addTask(ui->addTaskInputTitle->toPlainText().toStdString(), ui->addTaskInputDescription->toPlainText().toStdString(), ui->addTaskInputClassification->toPlainText().toInt(), ui->addTaskInputPriority->toPlainText().toInt(), ui->addTaskInputDuedate->toPlainText().toStdString(), ui->addTaskInputDuration->toPlainText().toInt());
}


void MainWindow::on_deleteTask_clicked()
{
    TaskList dltTask;
    dltTask.deleteTask(ui->addTaskInputTitle->toPlainText().toStdString());
}


void MainWindow::on_getTask_clicked()
{
    TaskList findTask;
    // storing getTask inside a Task Pointer so that it can be displayed later on
    //implementation of that will be done later on
    Task* get_the_task = findTask.getTask(ui->addTaskInputTitle->toPlainText().toStdString());
}

