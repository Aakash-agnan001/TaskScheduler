#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QMainWindow"
#include <QTextEdit>
#include <QListWidgetItem>

#include "Headers/User.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addTask_clicked();

    void on_deleteTask_clicked();

    void on_tasklist_itemClicked(QListWidgetItem *item);

    void on_addNew_clicked();

    void on_group_1_itemClicked(QListWidgetItem *item);

    void on_group_2_itemClicked(QListWidgetItem *item);

    void on_group_3_itemClicked(QListWidgetItem *item);

    void on_group_4_itemClicked(QListWidgetItem *item);

    void on_Login_clicked();

private:
    Ui::MainWindow *ui;
    User user;
    void autofill(QListWidgetItems *);

};
#endif // MAINWINDOW_H
