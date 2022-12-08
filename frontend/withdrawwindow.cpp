#include "withdrawwindow.h"
#include "ui_withdrawwindow.h"

WithdrawWindow::WithdrawWindow(QByteArray token, QString cardNumber, QString accountNumber, QString cardType, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WithdrawWindow)
{
    ui->setupUi(this);

    webToken = token;
    myCardNumber = cardNumber;
    myAccountNumber = accountNumber;
    myCardType = cardType;

    ui->withdrawLineEdit->setValidator(new QIntValidator(10, 1000, this));
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


void WithdrawWindow::on_withdrawButton_clicked()
{
    ui->infoLabel->setText("");
    QString withdrawAmountString = ui->withdrawLineEdit->text();
    withdrawAmount = withdrawAmountString.toInt();
    if (withdrawAmount % 10 != 0) {
        ui->infoLabel->setText("Syötä määrä 10 euron nousuilla");
        return;
    }
    if (withdrawAmount > 1000) {
        ui->infoLabel->setText("Noston enimmäismäärä on 1000 euroa");
        return;
    }
    int balance = this->GetBalance();
    if (balance >= withdrawAmount) {
        this->Withdraw();
        this->close();
    } else {
        ui->infoLabel->setText("Tilin saldo ei ole riittävä");
    }
}

int WithdrawWindow::GetBalance()
{
    int balance = 0;
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
        balance = QString::number(jsonObj["credit_limit"].toDouble()).toInt();
    } else {
        balance = QString::number(jsonObj["balance"].toDouble(), 'f', 0).toInt();
    }

    balanceReply->deleteLater();
    balanceManager->deleteLater();

    return balance;
}

void WithdrawWindow::Withdraw()
{
    QString siteUrl = "http://localhost:3000/account/withdraw/" + myAccountNumber;

    bool useCredit;
    if (myCardType == "credit") {
        useCredit = true;
    } else {
        useCredit = false;
    }

    QNetworkRequest request((siteUrl));

    request.setRawHeader(QByteArray("Authorization"),(webToken));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    withdrawManager = new QNetworkAccessManager(this);

    QJsonObject jsonObj;
    jsonObj.insert("withdrawAmount", withdrawAmount);
    jsonObj.insert("useCredit", useCredit);

    withdrawReply = withdrawManager->put(request, QJsonDocument(jsonObj).toJson());

    // Synchronous connect, waits for response
    QEventLoop loop;
    connect(withdrawReply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    withdrawReply->deleteLater();
    withdrawManager->deleteLater();
    LogWithdraw();
}

void WithdrawWindow::LogWithdraw()
{
    QString siteUrl = "http://localhost:3000/log/";

    QNetworkRequest request((siteUrl));

    request.setRawHeader(QByteArray("Authorization"),(webToken));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject jsonObj;
    jsonObj.insert("account_number", myAccountNumber);
    jsonObj.insert("card_number", myCardNumber);
    jsonObj.insert("event", "Withdraw");
    jsonObj.insert("amount", withdrawAmount);
    jsonObj.insert("datetime", QDateTime::currentDateTimeUtc().toString("yyyy-MM-dd HH:mm:ss"));

    logManager = new QNetworkAccessManager(this);

    logReply = logManager->post(request, QJsonDocument(jsonObj).toJson());

    // Synchronous connect, waits for response
    QEventLoop loop;
    connect(logReply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    logReply->deleteLater();
    logManager->deleteLater();
}
