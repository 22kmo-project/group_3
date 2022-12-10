#include "balancewindow.h"
#include "ui_balancewindow.h"

BalanceWindow::BalanceWindow(QByteArray token, QString accountNumber, QString cardType, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BalanceWindow)
{
    ui->setupUi(this);

    webToken = token;
    myAccountNumber = accountNumber;
    myCardType = cardType;
    this->GetBalance();
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

void BalanceWindow::GetBalance()
{
    QString balance = "0";
    QString siteUrl = "http://localhost:3000/account/balance/" + myAccountNumber;

    if (myCardType == "credit") {
        siteUrl += "/1";
    } else {
        siteUrl += "/0";
    }

    QNetworkRequest request((siteUrl));

    request.setRawHeader(QByteArray("Authorization"),(webToken));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    balanceManager = new QNetworkAccessManager(this);

    balanceReply = balanceManager->get(request);

    // Synchronous connect, waits for response
    QEventLoop loop;
    connect(balanceReply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(balanceReply->readAll());
    QJsonObject jsonObj = jsonDoc.object();

    if (myCardType == "credit") {
        ui->label->setText("Luotto");
        balance = jsonObj["credit_limit"].toVariant().toString();
    } else {
        ui->label->setText("Valuutta");
        balance = jsonObj["balance"].toVariant().toString();
    }

    balanceReply->deleteLater();
    balanceManager->deleteLater();

    ui->lineEdit->setText(balance);
}



