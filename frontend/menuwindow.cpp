#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "qdebug.h"

MenuWindow::MenuWindow(QString cardNumber, QString accountNumber, QString cardType, QWidget *parent) :
    QDialog(parent), ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
    myCardNumber = cardNumber;
    myAccountNumber = accountNumber;
    myCardType = cardType;
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
    this->close();
    delete this;
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
    objectBalanceWindow = new BalanceWindow(webToken);
    objectBalanceWindow->show();
}

void MenuWindow::on_killCardButton_clicked()
{
    objectKillCardWindow = new KillCardWindow(webToken, myCardNumber);
    objectKillCardWindow->show();
}
