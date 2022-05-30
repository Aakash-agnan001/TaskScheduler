#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextEdit>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    this->setStyleSheet("QMainWindow {background: 'black';}");
    this->show();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    QFile file("../../../data.txt");
    if(!file.open(QIODevice::ReadWrite)) {
        return;
    }

    QTextStream stream(&file);
    for(int i = 0; i < 40; ++i ) {
        stream << QString::number(i) << "Hello World\n";
    }

    file.close();
    delete ui;
}

void MainWindow::on_addTask_clicked()
{
    QMessageBox Msgbox;

    for (int i = 0; i < ui->tasklist->count(); ++i)
    {
        if (ui->tasklist->item(i)->text() == ui->addTaskInputTitle->toPlainText())
        {
            this->user.tasks.updateTask(ui->addTaskInputTitle->toPlainText().toStdString(), ui->addTaskInputDescription->toPlainText().toStdString(), ui->addTaskInputClassification->toPlainText().toInt(), ui->addTaskInputPriority->toPlainText().toInt(), ui->addTaskInputDuedate->toPlainText().toStdString(), ui->addTaskInputDuration->toPlainText().toInt());
            Msgbox.setText("TASK UPDATED");
            Msgbox.exec();
            return;
        }
    }

    if (ui->addTaskInputTitle->toPlainText() == "" || ui->addTaskInputDescription->toPlainText() == "" || ui->addTaskInputClassification->toPlainText() == "" || ui->addTaskInputPriority->toPlainText() == "" || ui->addTaskInputDuedate->toPlainText() == "" || ui->addTaskInputDuration->toPlainText() == "")
    {
        Msgbox.setText("ERROR: 1 OR MORE EMPTY PARAMETERS");
        Msgbox.exec();
        return;
    }

    if (ui->addTaskInputClassification->toPlainText().toStdString().size() > 1 || ui->addTaskInputPriority->toPlainText().toStdString().size() > 1 || ui->addTaskInputClassification->toPlainText().toInt() < 0 || ui->addTaskInputClassification->toPlainText().toInt() > 10 || ui->addTaskInputPriority->toPlainText().toInt() < 0 || ui->addTaskInputPriority->toPlainText().toInt() > 10)
    {
        Msgbox.setText("ERROR: CLASSIFICATION AND PRIORITY MUST BE 1 - 9");
        Msgbox.exec();
        return;
    }

    for (char const &c : ui->addTaskInputDuration->toPlainText().toStdString())
    {
        if (std::isdigit(c) == 0)
        {
            Msgbox.setText("ERROR: DURATION MUST BE NUMBERS ONLY");
            Msgbox.exec();
            return;
        }
    }

    for (char const &c : ui->addTaskInputDuedate->toPlainText().toStdString())
    {
        if (std::isdigit(c) == 0)
        {
            Msgbox.setText("ERROR: DUEDATE MUST BE NUMBERS ONLY");
            Msgbox.exec();
            return;
        }
    }

    if (ui->addTaskInputDuedate->toPlainText().toStdString().size() != 8)
    {
        Msgbox.setText("ERROR: ENTER DUEDATE IN MMDDYYYY FORMAT");
        Msgbox.exec();
        return;
    }

    this->user.tasks.addTask(ui->addTaskInputTitle->toPlainText().toStdString(), ui->addTaskInputDescription->toPlainText().toStdString(), ui->addTaskInputClassification->toPlainText().toInt(), ui->addTaskInputPriority->toPlainText().toInt(), ui->addTaskInputDuedate->toPlainText().toStdString(), ui->addTaskInputDuration->toPlainText().toInt());

    // QListWidgetItem *newItem = new QListWidgetItem;
    QListWidgetItem* newItem = new QListWidgetItem;
    newItem->setText(ui->addTaskInputTitle->toPlainText());
    ui->tasklist->insertItem(0, newItem);
    user.writeCSV();
}

void MainWindow::on_deleteTask_clicked()
{
    QMessageBox Msgbox;

    if (ui->deleteTaskInput->toPlainText() == "")
    {
        Msgbox.setText("ERROR: EMPTY PARAMETER");
        Msgbox.exec();
        return;
    }

    for (int i = 0; i < ui->tasklist->count(); ++i)
    {
        if (ui->tasklist->item(i)->text() == ui->deleteTaskInput->toPlainText())
        {
            this->user.tasks.deleteTask(ui->deleteTaskInput->toPlainText().toStdString());
            delete ui->tasklist->item(i);
            return;
        }
    }

    Msgbox.setText("ERROR: NO TASK TO DELETE WITH GIVEN PARAMETER");
    Msgbox.exec();
}
