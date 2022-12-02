#include "logout.h"
#include "ui_logout.h"

logout::logout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logout)
{
    ui->setupUi(this);
}

logout::~logout()
{
    delete ui;
}
