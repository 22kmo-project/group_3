#include "mainwindow.h"
#include "ui_mainwindow.h"

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




void MainWindow::on_pushButton_8_clicked()
{
   ui->stackedWidget->setCurrentIndex(2);//tapahtumat 4
}


void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0); //nosto on nolla
}


void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(4); // 4 on saldo
}



void MainWindow::on_pushButton_3_clicked()
{
     ui->stackedWidget->setCurrentIndex(3); // mainmenu/login
}

