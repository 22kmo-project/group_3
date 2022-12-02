#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete objectMenuWindow;
    objectMenuWindow = nullptr;
}

void MainWindow::loginSlot(QNetworkReply *reply)
{
    responseData = reply->readAll();
    int test = QString::compare(responseData, "false");
    if (responseData.length() == 0){
        qInfo() << "Palvelin ei vastaa";
        ui->labelInfo->setText("Palvelin ei vastaa");
    } else {
        if (QString::compare(responseData, "-4078") == 0) {
            ui->labelInfo->setText("Virhe tietokanta yhteydessä");
            qInfo() << "Virhe tietokanta yhteydessä";
        } else {
            if (test == 0) {
                resetTextFields();
                ui->labelInfo->setText("Tunnus ja salasana eivät täsmää");
                qInfo() << "Tunnus ja salasana eivät täsmää";
            } else {

                objectMenuWindow = new MenuWindow(cardNumber, "123123");
                connect(objectMenuWindow, SIGNAL(rejected()), this, SLOT(showMainWindowSlot()));
                objectMenuWindow->setWebToken("Bearer " + responseData);
                objectMenuWindow->show();
                this->hide();

                // Login successful, do your thing.
                resetTextFields();
                webToken = responseData;
                cardType = this->getCardType();
                if (cardType == "credit/debit") {
                    ui->stackedWidget->setCurrentIndex(1);
                } else {
                    this->getAccountNumber();
                    this->openMenuWindow();
                }
            }
        }
    }
    reply->deleteLater();
    loginManager->deleteLater();
}


void MainWindow::showMainWindowSlot()
{
    qDebug()<<"showMainWindowSlot";
    this->show();
}

void MainWindow::on_loginButton_clicked()
{
    cardNumber = ui->textCardNumber->toPlainText();
    QString pin = ui->textPin->toPlainText();
    QJsonObject jsonObj;
    jsonObj.insert("card_number", cardNumber);
    jsonObj.insert("pin", pin);

    QString site_url="http://localhost:3000/login";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

    reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());

}

void MainWindow::resetTextFields()
{
    ui->textCardNumber->clear();
    ui->textPin->clear();
}

void MainWindow::openMenuWindow()
{
    objectMenuWindow = new MenuWindow(cardNumber, accountNumber);
    connect(objectMenuWindow, SIGNAL(rejected()), this, SLOT(showMainWindowSlot()));
    objectMenuWindow->setWebToken("Bearer " + webToken);
    objectMenuWindow->show();
    this->hide();
}

QString MainWindow::getCardType()
{
    QString cardType = "unknown";
    QString siteUrl="http://localhost:3000/card/type/"+cardNumber;
    QNetworkRequest request((siteUrl));

    request.setRawHeader(QByteArray("Authorization"),(webToken));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    cardTypeManager = new QNetworkAccessManager(this);
    reply = cardTypeManager->get(request);

    // Synchronous connect, waits for response
    QEventLoop loop;
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(reply->readAll());
    QJsonObject jsonObj = jsonDoc.object();
    cardType = jsonObj.value("type").toString();
    reply->deleteLater();
    cardTypeManager->deleteLater();

    return cardType;
}

void MainWindow::getAccountNumber()
{
    QString siteUrl = "";
    if (cardType == "debit") {
        siteUrl="http://localhost:3000/card-account/"+cardNumber+"/1";
    } else {
        siteUrl="http://localhost:3000/card-account/"+cardNumber+"/0";
    }
    QNetworkRequest request((siteUrl));

    request.setRawHeader(QByteArray("Authorization"),(webToken));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    accountNumberManager = new QNetworkAccessManager(this);
    reply = accountNumberManager->get(request);

    // Synchronous connect, waits for response
    QEventLoop loop;
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(reply->readAll());
    QJsonObject jsonObj = jsonDoc.object();
    accountNumber = QString::number(jsonObj["account_number"].toDouble());
    reply->deleteLater();
    accountNumberManager->deleteLater();
}

void MainWindow::showMainWindowSlot()
{
    ui->stackedWidget->setCurrentIndex(0);
    this->show();
}

void MainWindow::on_loginButton_clicked()
{
    cardNumber = ui->textCardNumber->toPlainText();
    QString pin = ui->textPin->toPlainText();
    QJsonObject jsonObj;
    jsonObj.insert("card_number", cardNumber);
    jsonObj.insert("pin", pin);

    QString site_url="http://localhost:3000/login";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

    reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());
}

void MainWindow::on_creditButton_clicked()
{
    cardType = "credit";
    this->getAccountNumber();
    this->openMenuWindow();
}


void MainWindow::on_debitButton_clicked()
{
    cardType = "debit";
    this->getAccountNumber();
    this->openMenuWindow();
}
