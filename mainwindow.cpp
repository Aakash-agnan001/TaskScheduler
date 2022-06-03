#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextEdit>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QScreen>
#include "Headers/TaskList.h"
#include <iterator>
#include <list>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    this->setStyleSheet("QMainWindow {background: 'black';}");
    this->show();
    ui->setupUi(this);
    this->move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());


    ui->tasklist->setSortingEnabled(true);
    ui->group_1->setSortingEnabled(true);
    ui->group_2->setSortingEnabled(true);
    ui->group_3->setSortingEnabled(true);
    ui->group_4->setSortingEnabled(true);

    if(user.getLoggedin()){



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
        else if(line.startsWith("USER")){
            continue;
        }
        else
        {
            QStringList pieces = line.split(",");

            this->user.tasks.addTask(pieces.at(0).toStdString(), pieces.at(1).toStdString(), pieces.at(2).toInt(), pieces.at(3).toInt(), pieces.at(4).toStdString(), pieces.at(5).toInt());

            QListWidgetItem *newItem = new QListWidgetItem;
             newItem->setText(pieces.at(3) + " - " + pieces.at(0));
//            newItem->setText(pieces.at(0));
            ui->tasklist->insertItem(0, newItem);

            QListWidgetItem *newItem_2 = new QListWidgetItem;
             newItem_2->setText(pieces.at(3) + " - " + pieces.at(0));
//            newItem_2->setText(pieces.at(0));

            switch (pieces.at(2).toInt())
            {
            case 1:
                ui->group_1->insertItem(0, newItem_2);
                break;
            case 2:
                ui->group_2->insertItem(0, newItem_2);
                break;
            case 3:
                ui->group_3->insertItem(0, newItem_2);
                break;
            case 4:
                ui->group_4->insertItem(0, newItem_2);
                break;
            }
        }
    }

    file.close();
    } else {
        ui->stackedWidget->setCurrentIndex(1);
    }
}

MainWindow::~MainWindow()
{

    if(user.getLoggedin()){


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

    stream << "USER," << QString::fromStdString(user.getName()) << "," << QString::fromStdString(user.getPassword()) << "\n\n";

    for (ptr = user.tasks.tasks.begin(); ptr != user.tasks.tasks.end(); ++ptr)
    {

        stream << QString::fromStdString((*ptr).title.getInfo("")) << "," << QString::fromStdString((*ptr).description.getInfo("")) << "," << QString::number((*ptr).classification.getInfo(1)) << "," << QString::number((*ptr).priority.getInfo(1)) << "," << QString::fromStdString((*ptr).date.getInfo("")) << "," << QString::number((*ptr).duration.getInfo(1)) << "\n";
    }

    stream << "\n"
           << "END";

    file.close();
    } else {
        ui->stackedWidget->setCurrentIndex(1);
    }

    user.setLoggedin(false);
    delete ui->login;
    delete ui->WolcomeLabel;
    delete ui->WolcomeLabel_3;
    delete ui->WolcomeLabel_2;

    // Delete variables inside taskList and classification widgets
    for(int i = 0; i < ui->tasklist->count(); ++i) {
        delete ui->tasklist->item(i);
    }
    for(int i = 0; i < ui->group_1->count(); i++) {
        delete ui->group_1->item(i);
    }
    for(int i = 0; i < ui->group_2->count(); i++) {
        delete ui->group_2->item(i);
    }
    for(int i = 0; i < ui->group_3->count(); i++) {
        delete ui->group_3->item(i);
    }
    for(int i = 0; i < ui->group_4->count(); i++) {
        delete ui->group_4->item(i);
    }

    delete ui->tasklist;
    delete ui->group_1;
    delete ui->group_2;
    delete ui->group_3;
    delete ui->group_4;
    delete ui->addNew;
    delete ui->addTaskInputTitle;
    delete ui->addTaskInputDescription;
    delete ui->addTaskInputPriority;
    delete ui->addTaskInputDuration;
    delete ui->addTaskInputClassification;
    delete ui->addTaskInputDuedate;
    delete ui->addTask;
    delete ui->WolcomeLabel_4;
    delete ui->deleteTaskInput;
    delete ui->deleteTask;
    delete ui->WolcomeLabel_5;
    delete ui->WolcomeLabel_6;
    delete ui->WolcomeLabel_7;
    delete ui->WolcomeLabel_8;
    delete ui->main;
    delete ui->username;
    delete ui->password;
    delete ui->n;
    delete ui->e;
    delete ui->WolcomeLabel_9;
    delete ui->menubar;
    delete ui->statusbar;
    delete ui->Login;
    delete ui->stackedWidget;
    delete ui->centralwidget;
    delete ui;
}

void MainWindow::on_addTask_clicked()
{
    QMessageBox Msgbox;

    if (ui->addTaskInputTitle->toPlainText() == "" || ui->addTaskInputDescription->toPlainText() == "" || ui->addTaskInputClassification->toPlainText() == "" || ui->addTaskInputPriority->toPlainText() == "" || ui->addTaskInputDuedate->toPlainText() == "" || ui->addTaskInputDuration->toPlainText() == "")
    {
        Msgbox.setText("ERROR: 1 OR MORE EMPTY PARAMETERS");
        Msgbox.exec();
        return;
    }

    if (ui->addTaskInputPriority->toPlainText().toStdString().size() > 1 || ui->addTaskInputPriority->toPlainText().toInt() < 1 || ui->addTaskInputPriority->toPlainText().toInt() > 9)
    {
        Msgbox.setText("ERROR: PRIORITY MUST BE 1 - 9");
        Msgbox.exec();
        return;
    }

    if (ui->addTaskInputClassification->toPlainText().toStdString().size() > 1 || ui->addTaskInputClassification->toPlainText().toInt() < 1 || ui->addTaskInputClassification->toPlainText().toInt() > 4)
    {
        Msgbox.setText("ERROR: CLASSIFICATION MUST BE 1 - 4");
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

    for (int i = 0; i < ui->tasklist->count(); ++i)
    {
        // CHECKS IF UPDATE IS HAPPENING
        if (ui->tasklist->item(i)->text().split(" - ").at(1) == ui->addTaskInputTitle->toPlainText())
        {

            std::list<Task>::iterator ptr;

            for (ptr = user.tasks.tasks.begin(); ptr != user.tasks.tasks.end(); ++ptr)
            {
                if ((*ptr).title.getInfo("") == ui->addTaskInputTitle->toPlainText().toStdString())
                {
                    switch ((*ptr).classification.getInfo(1))
                    {
                    case 1:
                        for (int i = 0; i < ui->group_1->count(); ++i)
                        {
                            if (ui->group_1->item(i)->text().split(" - ").at(1).toStdString() == (*ptr).title.getInfo(""))
                            {
                                delete ui->group_1->item(i);
                            }
                        }

                        break;
                    case 2:
                        for (int i = 0; i < ui->group_2->count(); ++i)
                        {
                            if (ui->group_2->item(i)->text().split(" - ").at(1).toStdString() == (*ptr).title.getInfo(""))
                            {
                                delete ui->group_2->item(i);
                            }
                        }
                        break;
                    case 3:
                        for (int i = 0; i < ui->group_3->count(); ++i)
                        {
                            if (ui->group_3->item(i)->text().split(" - ").at(1).toStdString() == (*ptr).title.getInfo(""))
                            {
                                delete ui->group_3->item(i);
                            }
                        }
                        break;
                    case 4:
                        for (int i = 0; i < ui->group_4->count(); ++i)
                        {
                            if (ui->group_4->item(i)->text().split(" - ").at(1).toStdString() == (*ptr).title.getInfo(""))
                            {
                                delete ui->group_4->item(i);
                            }
                        }
                        break;
                    }
                }
            }

            this->user.tasks.updateTask(ui->addTaskInputTitle->toPlainText().toStdString(), ui->addTaskInputDescription->toPlainText().toStdString(), ui->addTaskInputClassification->toPlainText().toInt(), ui->addTaskInputPriority->toPlainText().toInt(), ui->addTaskInputDuedate->toPlainText().toStdString(), ui->addTaskInputDuration->toPlainText().toInt());
            // TODO: REMOVE FROM CURRENT LIST

            QListWidgetItem *newItem = new QListWidgetItem;
            newItem->setText(ui->addTaskInputPriority->toPlainText() + " - " + ui->tasklist->item(i)->text().split(" - ").at(1));

            switch (ui->addTaskInputClassification->toPlainText().toInt())
            {
            case 1:
                ui->group_1->insertItem(0, newItem);
                break;
            case 2:
                ui->group_2->insertItem(0, newItem);
                break;
            case 3:
                ui->group_3->insertItem(0, newItem);
                break;
            case 4:
                ui->group_4->insertItem(0, newItem);
                break;
            }

            for(int i = 0; i < ui->tasklist->count(); ++i) {
                if(ui->tasklist->item(i)->text().split(" - ").at(1) == ui->addTaskInputTitle->toPlainText()) {
                    ui->tasklist->item(i)->setText(ui->addTaskInputPriority->toPlainText() + " - " + ui->tasklist->item(i)->text().split(" - ").at(1));
                }
            }


            Msgbox.setText("TASK UPDATED");
            Msgbox.exec();
            return;
        }
    }

    this->user.tasks.addTask(ui->addTaskInputTitle->toPlainText().toStdString(), ui->addTaskInputDescription->toPlainText().toStdString(), ui->addTaskInputClassification->toPlainText().toInt(), ui->addTaskInputPriority->toPlainText().toInt(), ui->addTaskInputDuedate->toPlainText().toStdString(), ui->addTaskInputDuration->toPlainText().toInt());

    // QListWidgetItem *newItem = new QListWidgetItem;
    QListWidgetItem *newItem = new QListWidgetItem;
    QListWidgetItem *newItem_2 = new QListWidgetItem;

    newItem->setText(ui->addTaskInputPriority->toPlainText() + " - " +ui->addTaskInputTitle->toPlainText());
    newItem_2->setText(ui->addTaskInputPriority->toPlainText() + " - " +ui->addTaskInputTitle->toPlainText());
    ui->tasklist->insertItem(0, newItem);

    switch (ui->addTaskInputClassification->toPlainText().toInt())
    {
    case 1:
        ui->group_1->insertItem(0, newItem_2);
        break;
    case 2:
        ui->group_2->insertItem(0, newItem_2);
        break;
    case 3:
        ui->group_3->insertItem(0, newItem_2);
        break;
    case 4:
        ui->group_4->insertItem(0, newItem_2);
        break;
    }
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
        if (ui->tasklist->item(i)->text().split(" - ").at(1) == ui->deleteTaskInput->toPlainText())
        {

            this->user.tasks.deleteTask(ui->deleteTaskInput->toPlainText().toStdString());
            delete ui->tasklist->item(i);
        }
    }

    for(int i = 0; i < ui->group_1->count(); ++i){
        if (ui->group_1->item(i)->text().split(" - ").at(1) == ui->deleteTaskInput->toPlainText()){
            delete ui->group_1->item(i);
            return;
        }
    }

    for(int i = 0; i < ui->group_2->count(); ++i){
        if (ui->group_2->item(i)->text().split(" - ").at(1) == ui->deleteTaskInput->toPlainText()){
            delete ui->group_2->item(i);
            return;
        }
    }

    for(int i = 0; i < ui->group_3->count(); ++i){
        if (ui->group_3->item(i)->text().split(" - ").at(1) == ui->deleteTaskInput->toPlainText()){
            delete ui->group_3->item(i);
            return;
        }
    }

    for(int i = 0; i < ui->group_4->count(); ++i){
        if (ui->group_4->item(i)->text().split(" - ").at(1) == ui->deleteTaskInput->toPlainText()){
            delete ui->group_4->item(i);
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
        if ((*ptr).title.getInfo("") == item->text().split(" - ").at(1).toStdString())
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

    QList<QListWidgetItem *> selected_items_1 = ui->group_1->selectedItems();
    for (int i = 0; i < selected_items_1.count(); ++i)
    {
        selected_items_1.at(i)->setSelected(false);
    }

    QList<QListWidgetItem *> selected_items_2 = ui->group_2->selectedItems();
    for (int i = 0; i < selected_items_2.count(); ++i)
    {
        selected_items_2.at(i)->setSelected(false);
    }

    QList<QListWidgetItem *> selected_items_3 = ui->group_3->selectedItems();
    for (int i = 0; i < selected_items_3.count(); ++i)
    {
        selected_items_3.at(i)->setSelected(false);
    }

    QList<QListWidgetItem *> selected_items_4 = ui->group_4->selectedItems();
    for (int i = 0; i < selected_items_4.count(); ++i)
    {
        selected_items_4.at(i)->setSelected(false);
    }
}

void MainWindow::on_group_1_itemClicked(QListWidgetItem *item)
{
    std::list<Task>::iterator ptr;
    for (ptr = user.tasks.tasks.begin(); ptr != user.tasks.tasks.end(); ++ptr)
    {
        if ((*ptr).title.getInfo("") == item->text().split(" - ").at(1).toStdString())
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

void MainWindow::on_group_2_itemClicked(QListWidgetItem *item)
{
    std::list<Task>::iterator ptr;
    for (ptr = user.tasks.tasks.begin(); ptr != user.tasks.tasks.end(); ++ptr)
    {
        if ((*ptr).title.getInfo("") == item->text().split(" - ").at(1).toStdString())
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

void MainWindow::on_group_3_itemClicked(QListWidgetItem *item)
{
    std::list<Task>::iterator ptr;
    for (ptr = user.tasks.tasks.begin(); ptr != user.tasks.tasks.end(); ++ptr)
    {
        if ((*ptr).title.getInfo("") == item->text().split(" - ").at(1).toStdString())
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

void MainWindow::on_group_4_itemClicked(QListWidgetItem *item)
{
    std::list<Task>::iterator ptr;
    for (ptr = user.tasks.tasks.begin(); ptr != user.tasks.tasks.end(); ++ptr)
    {
        if ((*ptr).title.getInfo("") == item->text().split(" - ").at(1).toStdString())
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

void MainWindow::on_Login_clicked()
{
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
        if (line == "START" || line == "")
            continue;
        else if(line.startsWith("USER")){
            user.setName(line.split(",").at(1).toStdString());

            std::string encryption = line.split(",").at(2).toStdString();

            user.setPassword(encryption);
            break;
        }
    }

    //e = 5, n = 1649
    std::vector<int> numbers = user.encrypt(ui->password->toPlainText().toStdString(), ui->e->toPlainText().toInt(), ui->n->toPlainText().toInt());
    std::string password = "";

    for(unsigned int i = 0 ; i < numbers.size(); ++i) {
        password += std::to_string(numbers.at(i)) + " ";
    }

    if(user.getName() == ui->username->toPlainText().toStdString() && password == user.getPassword()) {
        user.setLoggedin(true);
        ui->stackedWidget->setCurrentIndex(0);

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
            else if(line.startsWith("USER")){
                continue;
            }
            else
            {
                QStringList pieces = line.split(",");

                this->user.tasks.addTask(pieces.at(0).toStdString(), pieces.at(1).toStdString(), pieces.at(2).toInt(), pieces.at(3).toInt(), pieces.at(4).toStdString(), pieces.at(5).toInt());

                QListWidgetItem *newItem = new QListWidgetItem;
                 newItem->setText(pieces.at(3) + " - " + pieces.at(0));
    //            newItem->setText(pieces.at(0));
                ui->tasklist->insertItem(0, newItem);

                QListWidgetItem *newItem_2 = new QListWidgetItem;
                 newItem_2->setText(pieces.at(3) + " - " + pieces.at(0));
    //            newItem_2->setText(pieces.at(0));

                switch (pieces.at(2).toInt())
                {
                case 1:
                    ui->group_1->insertItem(0, newItem_2);
                    break;
                case 2:
                    ui->group_2->insertItem(0, newItem_2);
                    break;
                case 3:
                    ui->group_3->insertItem(0, newItem_2);
                    break;
                case 4:
                    ui->group_4->insertItem(0, newItem_2);
                    break;
                }
            }
        }

        file.close();
    }
}

