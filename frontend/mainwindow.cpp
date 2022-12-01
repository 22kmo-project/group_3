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

void MainWindow::logSlot(QNetworkReply *reply)
{
    QByteArray responseData=reply->readAll();
    qDebug()<<responseData;
    QJsonDocument json_doc = QJsonDocument::fromJson(responseData);
    QJsonObject json_obj = json_doc.object();
    qDebug()<<json_doc;
    reply->deleteLater();
    eventsManager->deleteLater();
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
                ui->textCardNumber->clear();
                ui->textPin->clear();
                ui->labelInfo->setText("Tunnus ja salasana eivät täsmää");
                qInfo() << "Tunnus ja salasana eivät täsmää";
            } else {
                objectMenuWindow = new MenuWindow(cardNumber, "123123");
                connect(objectMenuWindow, SIGNAL(rejected()), this, SLOT(showMainWindowSlot()));
                objectMenuWindow->setWebToken("Bearer " + responseData);
                objectMenuWindow->show();
                this->hide();
            }
        }
    }
    reply->deleteLater();
    loginManager->deleteLater();
}

void MainWindow::showMainWindowSlot()
{
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

