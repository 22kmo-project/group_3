#include "withdrawwindow.h"
#include "ui_withdrawwindow.h"
#include <QTimer>

WithdrawWindow::WithdrawWindow(QByteArray token, QString cardNumber, QString accountNumber, QString cardType, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WithdrawWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint & ~Qt::WindowSystemMenuHint & ~Qt::WindowCloseButtonHint);

    webToken = token;
    myCardNumber = cardNumber;
    myAccountNumber = accountNumber;
    myCardType = cardType;

    ui->nosto2LineEdit->setValidator(new QIntValidator(10, 1000, this));
    ui->infoLabel2->setText("");
    ui->stackedWidget->setCurrentIndex(2);

    closeWindowTimer = new QTimer(this);
    connect(closeWindowTimer, SIGNAL(timeout()), this, SLOT(CloseWindow()));
    connect(this, SIGNAL(destroyed()), parent, SLOT(resetForceLogoutTimer()));
    closeWindowTimer->start(1000 * 10);
}

WithdrawWindow::~WithdrawWindow()
{
    delete ui;
}

void WithdrawWindow::on_backButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


int WithdrawWindow::GetBalance()
{
    int balance = 0;
    QString siteUrl = Url::getBaseUrl() + "/account/balance/" + myAccountNumber;

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
        balance = jsonObj["credit_limit"].toVariant().toInt();
    } else {
        balance = jsonObj["balance"].toVariant().toInt();
    }

    balanceReply->deleteLater();
    balanceManager->deleteLater();

    return balance;
}

void WithdrawWindow::Withdraw()
{
    closeWindowTimer->stop();
    QString siteUrl = Url::getBaseUrl() + "/account/withdraw/" + myAccountNumber;

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
    closeWindowTimer->start(1000 * 10);
}

void WithdrawWindow::LogWithdraw()
{
    QString siteUrl = Url::getBaseUrl() + "/log/";

    QNetworkRequest request((siteUrl));

    request.setRawHeader(QByteArray("Authorization"),(webToken));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject jsonObj;
    jsonObj.insert("account_number", myAccountNumber);
    jsonObj.insert("card_number", myCardNumber);
    jsonObj.insert("event", "Withdraw");
    jsonObj.insert("amount", withdrawAmount);
    jsonObj.insert("datetime", QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));

    logManager = new QNetworkAccessManager(this);

    logReply = logManager->post(request, QJsonDocument(jsonObj).toJson());

    // Synchronous connect, waits for response
    QEventLoop loop;
    connect(logReply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    logReply->deleteLater();
    logManager->deleteLater();
}

void WithdrawWindow::on_withdrawButton_clicked()
{
    closeWindowTimer->start(1000 * 10);
    ui->infoLabel->setText("");
    QString withdrawAmountString = ui->nosto2LineEdit->text();
    withdrawAmount = withdrawAmountString.toInt();
    if (withdrawAmount > 1000) {
        ui->infoLabel->setText("Noston enimmäismäärä on 1000 euroa");
        return;
    }
    if (withdrawAmount < 10) {
        ui->infoLabel->setText("Noston vähimmäismäärä on 10 euroa");
        return;
    }
    if (withdrawAmount % 10 != 0) {
        ui->infoLabel->setText("Syötä määrä 10 euron nousuilla");
        return;
    }
    int balance = this->GetBalance();
    if (balance >= withdrawAmount) {
        this->Withdraw();
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(Logout()));
        timer->start(3000);
        ui->stackedWidget->setCurrentIndex(1);
    } else {
        ui->infoLabel->setText("Tilin saldo ei ole riittävä");
    }
}

void WithdrawWindow::Logout()
{
    this->done(QDialog::Accepted);
}

void WithdrawWindow::on_pushButton_2_clicked()
{
    closeWindowTimer->start(1000 * 10);
    withdrawAmount = 20;
    int balance = this->GetBalance();
    if (balance >= withdrawAmount) {
        this->Withdraw();
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(Logout()));
        timer->start(3000);
        ui->stackedWidget->setCurrentIndex(1);
    } else {
        ui->infoLabel2->setText("Tilin saldo ei ole riittävä");
    }
}


void WithdrawWindow::on_pushButton_3_clicked()
{
    closeWindowTimer->start(1000 * 10);
    withdrawAmount = 40;
    int balance = this->GetBalance();
    if (balance >= withdrawAmount) {
        this->Withdraw();
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(Logout()));
        timer->start(3000);
        ui->stackedWidget->setCurrentIndex(1);
    } else {
        ui->infoLabel2->setText("Tilin saldo ei ole riittävä");
    }
}


void WithdrawWindow::on_pushButton_4_clicked()
{
    closeWindowTimer->start(1000 * 10);
    withdrawAmount = 50;
    int balance = this->GetBalance();
    if (balance >= withdrawAmount) {
        this->Withdraw();
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(Logout()));
        timer->start(3000);
        ui->stackedWidget->setCurrentIndex(1);
    } else {
        ui->infoLabel2->setText("Tilin saldo ei ole riittävä");
    }
}


void WithdrawWindow::on_pushButton_5_clicked()
{
    closeWindowTimer->start(1000 * 10);
    withdrawAmount = 100;
    int balance = this->GetBalance();
    if (balance >= withdrawAmount) {
        this->Withdraw();
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(Logout()));
        timer->start(3000);
        ui->stackedWidget->setCurrentIndex(1);
    } else {
        ui->infoLabel2->setText("Tilin saldo ei ole riittävä");
    }
}


void WithdrawWindow::on_pushButton_6_clicked()
{
    closeWindowTimer->start(1000 * 10);
    ui->stackedWidget->setCurrentIndex(0);
}


void WithdrawWindow::on_pushButton_7_clicked()
{
    this->close();
    delete this;
}

void WithdrawWindow::CloseWindow()
{
    this->close();
    delete this;
}
