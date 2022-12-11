#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "qdebug.h"
#include <QTimer>

MenuWindow::MenuWindow(QString cardNumber, QString accountNumber, QString cardType, QWidget *parent) :
    QDialog(parent), ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint & ~Qt::WindowSystemMenuHint & ~Qt::WindowCloseButtonHint);

    myCardNumber = cardNumber;
    myAccountNumber = accountNumber;
    myCardType = cardType;
    ui->stackedWidget->setCurrentIndex(0);
    logoutSeconds = 5;
}

MenuWindow::~MenuWindow()
{
    delete ui;
    webToken = nullptr;
}

void MenuWindow::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
}

void MenuWindow::logout()
{
    ui->label_5->setText("Sivu sulkeutuu: 5");
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(checkLogoutTimer()));
    timer->start(1000);
    ui->stackedWidget->setCurrentIndex(1);
}

void MenuWindow::on_logoutButton_clicked()
{
    this->logout();
}

void MenuWindow::on_eventsButton_clicked()
{
    objectEventsWindow = new EventsWindow(webToken, myCardNumber, myAccountNumber, this);
    objectEventsWindow->exec();
}

void MenuWindow::on_withdrawButton_clicked()
{
    objectWithdrawWindow = new WithdrawWindow(webToken, myCardNumber, myAccountNumber, myCardType, this);
    connect(objectWithdrawWindow, SIGNAL(accepted()), this, SLOT(logout()));
    objectWithdrawWindow->exec();
}

void MenuWindow::on_balanceButton_clicked()
{
    objectBalanceWindow = new BalanceWindow(webToken, myAccountNumber, myCardType, this);
    objectBalanceWindow->exec();
}

void MenuWindow::on_killCardButton_clicked()
{
    objectKillCardWindow = new KillCardWindow(webToken, myCardNumber, this);
    connect(objectKillCardWindow, SIGNAL(accepted()), this, SLOT(logout()));
    objectKillCardWindow->exec();
}

void MenuWindow::checkLogoutTimer()
{
    --logoutSeconds;
    if(logoutSeconds < 0)
    {
        timer->stop();
        this->close();
        delete this;
    } else {
        ui->label_5->setText(QString("Sivu sulkeutuu: %1").arg(logoutSeconds));
    }
}
