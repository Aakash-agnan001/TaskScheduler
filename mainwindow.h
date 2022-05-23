#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QMainWindow"
#include <QTextEdit>

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

private:
    Ui::MainWindow *ui;

    QTextEdit taskTitle;
    QTextEdit taskDescription;
    QTextEdit taskClassification;
    QTextEdit taskPriority;
    QTextEdit taskDate;
    QTextEdit taskDuration;
};
#endif // MAINWINDOW_H
