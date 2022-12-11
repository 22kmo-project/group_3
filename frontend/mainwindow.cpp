#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowMinMaxButtonsHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loginSlot(QNetworkReply *reply)
{
    responseData = reply->readAll();
    int test = QString::compare(responseData, "false");
    if (responseData.length() == 0){
        ui->labelInfo->setText("Palvelin ei vastaa");
    } else {
        if (QString::compare(responseData, "-4078") == 0) {
            ui->labelInfo->setText("Virhe tietokanta yhteydessä");
        } else {
            if (test == 0) {
                resetTextFields();
                ui->labelInfo->setText("Tunnus ja salasana eivät täsmää tai kortti on lukittu");
            } else {
                // Login successful, do your thing.
                ui->labelInfo->setText("Syötä kortin numero ja pin koodi");
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

void MainWindow::resetTextFields()
{
    ui->lineEditCard->clear();
    ui->lineEditPin->clear();
}

void MainWindow::openMenuWindow()
{
    objectMenuWindow = new MenuWindow(cardNumber, accountNumber, cardType, this);
    connect(objectMenuWindow, SIGNAL(rejected()), this, SLOT(showMainWindowSlot()));
    objectMenuWindow->setWebToken("Bearer " + webToken);
    objectMenuWindow->show();
    this->hide();
}

QString MainWindow::getCardType()
{
    QString cardType = "unknown";
    QString siteUrl = Url::getBaseUrl() + "/card/type/" + cardNumber;
    QNetworkRequest request((siteUrl));

    request.setRawHeader(QByteArray("Authorization"),("Bearer " + webToken));
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
        siteUrl = Url::getBaseUrl() + "/card-account/"+cardNumber+"/1";
    } else {
        siteUrl = Url::getBaseUrl() + "/card-account/"+cardNumber+"/0";
    }
    QNetworkRequest request((siteUrl));

    request.setRawHeader(QByteArray("Authorization"),("Bearer " + webToken));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    accountNumberManager = new QNetworkAccessManager(this);
    reply = accountNumberManager->get(request);

    // Synchronous connect, waits for response
    QEventLoop loop;
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(reply->readAll());
    QJsonObject jsonObj = jsonDoc.object();
    accountNumber = jsonObj["account_number"].toVariant().toString();
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
    cardNumber = ui->lineEditCard->text();
    QString pin = ui->lineEditPin->text();
    if (!this->isValidInput(pin)) {
        ui->labelInfo->setText("Virhe kortti tai pin tiedoissa.");
        return;
    }
    QJsonObject jsonObj;
    jsonObj.insert("card_number", cardNumber);
    jsonObj.insert("pin", pin);

    QString site_url = Url::getBaseUrl() + "/login";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

    reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());
}

bool MainWindow::isValidInput(QString pin)
{
    if (cardNumber.isEmpty() || pin.length() != 4)
    {
        return false;
    }
    return true;
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
