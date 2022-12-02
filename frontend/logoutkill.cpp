#include "logoutkill.h"
#include "ui_logoutkill.h"

logoutkill::logoutkill(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logoutkill)
{
    ui->setupUi(this);
}

logoutkill::~logoutkill()
{
    delete ui;
}
