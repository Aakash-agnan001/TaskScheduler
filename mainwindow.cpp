#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextEdit>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include "Headers/TaskList.h"
#include <iterator>
#include <list>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    this->setStyleSheet("QMainWindow {background: 'black';}");
    this->show();
    ui->setupUi(this);
    QFile file("../../../data.txt");
    if (!file.open(QIODevice::ReadWrite))
    {
        return;
    }

    QTextStream stream(&file);

    QString line;
    while (!stream.atEnd())
    {
        line = stream.readLine();
        if (line == "START")
            continue;
        else if (line == "END")
            break;
        else if (line == "")
            continue;
        else
        {
            QStringList pieces = line.split(",");

            this->user.tasks.addTask(pieces.at(0).toStdString(), pieces.at(1).toStdString(), pieces.at(2).toInt(), pieces.at(3).toInt(), pieces.at(4).toStdString(), pieces.at(5).toInt());

            QListWidgetItem *newItem = new QListWidgetItem;
            newItem->setText(pieces.at(0));
            ui->tasklist->insertItem(0, newItem);
        }
    }

    file.close();
}

MainWindow::~MainWindow()
{
    QFile file("../../../data.txt");
    if (!file.open(QIODevice::ReadWrite))
    {
        return;
    }

    file.resize(0);
    QTextStream stream(&file);

    std::list<Task>::iterator ptr;

    stream << "START"
           << "\n\n";

    for (ptr = user.tasks.tasks.begin(); ptr != user.tasks.tasks.end(); ++ptr)
    {

        stream << QString::fromStdString((*ptr).title.getInfo("")) << "," << QString::fromStdString((*ptr).description.getInfo("")) << "," << QString::number((*ptr).classification.getInfo(1)) << "," << QString::number((*ptr).priority.getInfo(1)) << "," << QString::fromStdString((*ptr).date.getInfo("")) << "," << QString::number((*ptr).duration.getInfo(1)) << "\n";
    }

    stream << "\n"
           << "END";

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
    QListWidgetItem *newItem = new QListWidgetItem;
    newItem->setText(ui->addTaskInputTitle->toPlainText());
    ui->tasklist->insertItem(0, newItem);
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

void MainWindow::on_tasklist_itemClicked(QListWidgetItem *item)
{
    std::list<Task>::iterator ptr;
    for (ptr = user.tasks.tasks.begin(); ptr != user.tasks.tasks.end(); ++ptr)
    {
        if ((*ptr).title.getInfo("") == item->text().toStdString())
        {
            ui->addTaskInputTitle->setText(QString::fromStdString((*ptr).title.getInfo("")));
            ui->addTaskInputDescription->setText(QString::fromStdString((*ptr).description.getInfo("")));
            ui->addTaskInputClassification->setText(QString::number((*ptr).classification.getInfo(1)));
            ui->addTaskInputPriority->setText(QString::number((*ptr).priority.getInfo(1)));
            ui->addTaskInputDuration->setText(QString::number((*ptr).duration.getInfo(1)));
            ui->addTaskInputDuedate->setText(QString::fromStdString((*ptr).date.getInfo("")));
        }
    }
}

void MainWindow::on_addNew_clicked()
{
    ui->addTaskInputTitle->setText("");
    ui->addTaskInputDescription->setText("");
    ui->addTaskInputClassification->setText("");
    ui->addTaskInputPriority->setText("");
    ui->addTaskInputDuration->setText("");
    ui->addTaskInputDuedate->setText("");

    QList<QListWidgetItem *> selected_items = ui->tasklist->selectedItems();
    for (int i = 0; i < selected_items.count(); ++i)
    {
        selected_items.at(i)->setSelected(false);
    }
}
