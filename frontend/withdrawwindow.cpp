#include "withdrawwindow.h"
#include "ui_withdrawwindow.h"

WithdrawWindow::WithdrawWindow(QByteArray token, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WithdrawWindow)
{
    ui->setupUi(this);
    webToken = token;
}

WithdrawWindow::~WithdrawWindow()
{
    delete ui;
}

void WithdrawWindow::on_backButton_clicked()
{
    this->close();
    delete this;
}

