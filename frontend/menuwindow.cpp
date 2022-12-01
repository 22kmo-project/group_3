#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "qdebug.h"

MenuWindow::MenuWindow(QString cardNumber, QString accountNumber, QWidget *parent) :
    QDialog(parent), ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
    myCardNumber = cardNumber;
    myAccountNumber = accountNumber;
}

MenuWindow::~MenuWindow()
{
    qDebug() << "MenuWindow Dekonstruktori";
    delete ui;
    delete objectEventsWindow;
    delete objectWithdrawWindow;
    delete objectBalanceWindow;
    delete objectKillCardWindow;
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
{/*
    ui->stackedWidget->setCurrentIndex(2);//tapahtumat 2
    QString site_url="http://localhost:3000/card-account/12345678/1";
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(webToken));
    //WEBTOKEN LOPPU
    tapahtumatManager = new QNetworkAccessManager(this);

    connect(tapahtumatManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(tapahtumatSlot(QNetworkReply*)));

    reply = tapahtumatManager->get(request);

    site_url="http://localhost:3000/card-log/"+cardNumber+"/"+accountNumber;
    QNetworkRequest eventsRequest((site_url));
    eventsRequest.setRawHeader(QByteArray("Authorization"),(webToken));
    eventsManager = new QNetworkAccessManager(this);
    connect(eventsManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(logSlot(QNetworkReply*)));
    reply = eventsManager->get(eventsRequest);
    */
    objectEventsWindow = new EventsWindow();
    objectEventsWindow->show();
}

void MenuWindow::on_withdrawButton_clicked()
{
    objectWithdrawWindow = new WithdrawWindow();
    objectWithdrawWindow->show();
}

void MenuWindow::on_balanceButton_clicked()
{
    objectBalanceWindow = new BalanceWindow();
    objectBalanceWindow->show();
}

void MenuWindow::on_killCardButton_clicked()
{
    objectKillCardWindow = new KillCardWindow();
    objectKillCardWindow->show();
}
