#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    this->setStyleSheet("QMainWindow {background: 'black';}");
    this->show();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addTask_clicked()
{
    this->user.tasks.addTask(ui->addTaskInputTitle->toPlainText().toStdString(), ui->addTaskInputDescription->toPlainText().toStdString(), ui->addTaskInputClassification->toPlainText().toInt(), ui->addTaskInputPriority->toPlainText().toInt(), ui->addTaskInputDuedate->toPlainText().toStdString(), ui->addTaskInputDuration->toPlainText().toInt());

    QListWidgetItem *newItem = new QListWidgetItem;
    newItem->setText(ui->addTaskInputTitle->toPlainText());
    ui->tasklist->insertItem(0, newItem);
}

void MainWindow::on_deleteTask_clicked()
{
    this->user.tasks.deleteTask(ui->deleteTaskInput->toPlainText().toStdString());

    for (int i = 0; i < ui->tasklist->count(); ++i)
    {
        if (ui->tasklist->item(i)->text() == ui->deleteTaskInput->toPlainText())
        {
            delete ui->tasklist->item(i);
        }
    }
}

void MainWindow::on_getTask_clicked()
{
    // storing getTask inside a Task Pointer so that it can be displayed later on
    // implementation of that will be done later on
    //    Task* get_the_task = this->user.tasks.getTask(ui->addTaskInputTitle->toPlainText().toStdString());
}
