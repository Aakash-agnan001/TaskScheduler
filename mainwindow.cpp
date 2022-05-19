#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Number.h"
 Number num;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->battery->setRange(0, 100);

    ui->display->setText("50");

    num.setNumber(67);

    ui->battery->setValue(num.getNumber());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_increase_clicked()
{
    if(num.getNumber() > 0 && num.getNumber() < 100) {
        num.setNumber(num.getNumber() + 1);
        ui->battery->setValue(num.getNumber());
        ui->display->setText(QString::number(num.getNumber()));
    }
}

