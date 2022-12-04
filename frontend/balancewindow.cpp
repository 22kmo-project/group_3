#include "balancewindow.h"
#include "ui_balancewindow.h"

BalanceWindow::BalanceWindow(QByteArray token, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BalanceWindow)
{
    ui->setupUi(this);
    webToken = token;
}

BalanceWindow::~BalanceWindow()
{
    delete ui;
}

void BalanceWindow::on_backButton_clicked()
{
    this->close();
    delete this;
}

