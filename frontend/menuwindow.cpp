#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "qdebug.h"
#include <QTimer>

MenuWindow::MenuWindow(QString cardNumber, QString accountNumber, QString cardType, QWidget *parent) :
    QDialog(parent), ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
    myCardNumber = cardNumber;
    myAccountNumber = accountNumber;
    myCardType = cardType;
    ui->stackedWidget->setCurrentIndex(0);
}

MenuWindow::~MenuWindow()
{
    delete ui;
    webToken = nullptr;
    objectEventsWindow = nullptr;
    objectWithdrawWindow = nullptr;
    objectBalanceWindow = nullptr;
    objectKillCardWindow = nullptr;
}

void MenuWindow::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
}

void MenuWindow::on_logoutButton_clicked()
{
    ui->label_5->setText("Sivu sulkeutuu: 5");
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(KirjauduUlos()));
    timer->start(1000);
    ui->stackedWidget->setCurrentIndex(1);
}

void MenuWindow::on_eventsButton_clicked()
{
    objectEventsWindow = new EventsWindow(webToken, myCardNumber, myAccountNumber);
    objectEventsWindow->show();
}

void MenuWindow::on_withdrawButton_clicked()
{
    objectWithdrawWindow = new WithdrawWindow(webToken, myCardNumber, myAccountNumber, myCardType);
    objectWithdrawWindow->show();
}

void MenuWindow::on_balanceButton_clicked()
{
    objectBalanceWindow = new BalanceWindow(webToken, myAccountNumber, myCardType);
    objectBalanceWindow->show();
}

void MenuWindow::on_killCardButton_clicked()
{
    objectKillCardWindow = new KillCardWindow(webToken, myCardNumber);
    objectKillCardWindow->show();
}

void MenuWindow::KirjauduUlos()
{
    sec--;
    if(sec==-1)
    {
        qDebug()<< "Ok";
        timer->stop();
        this->close();
        delete this;
    }
    else
    ui->label_5->setText(QString("Sivu sulkeutuu: %1").arg(sec));
}
