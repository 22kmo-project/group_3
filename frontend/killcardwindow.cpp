#include "killcardwindow.h"
#include "ui_killcardwindow.h"

KillCardWindow::KillCardWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KillCardWindow)
{
    ui->setupUi(this);
}

KillCardWindow::~KillCardWindow()
{
    delete ui;
}

void KillCardWindow::on_confirmYesButton_clicked()
{

}


void KillCardWindow::on_confirmNoButton_clicked()
{
    this->close();
    delete this;
}

