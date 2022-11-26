#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Tapahtumat_clicked()
{
   ui->stackedWidget->setCurrentIndex(2);//tapahtumat 2
}


void MainWindow::on_Nosto_clicked()
{
    ui->stackedWidget->setCurrentIndex(0); //nosto on nolla
}


void MainWindow::on_Saldo_clicked()
{
    ui->stackedWidget->setCurrentIndex(4); // 4 on saldo
}

void MainWindow::on_KirjauduUlos_clicked()
{

}

void MainWindow::loginSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();
    int test = QString::compare(response_data, "false");
    if (response_data.length() == 0){
        qInfo() << "Palvelin ei vastaa";
        ui->labelInfo->setText("Palvelin ei vastaa");
    } else {
        if (QString::compare(response_data, "-4078") == 0) {
            ui->labelInfo->setText("Virhe tietokanta yhteydessä");
            qInfo() << "Virhe tietokanta yhteydessä";
        } else {
            if (test == 0) {
                ui->textCardNumber->clear();
                ui->textPin->clear();
                ui->labelInfo->setText("Tunnus ja salasana eivät täsmää");
                qInfo() << "Tunnus ja salasana eivät täsmää";
            } else {
                webToken = ("Bearer " + response_data);
                ui->stackedWidget->setCurrentIndex(3); // mainmenu
            }
        }
    }

}


void MainWindow::on_Kirjaudu_clicked()
{
    //Login
    qInfo() << "Logging in";

    card_number = ui->textCardNumber->toPlainText();
    QString pin = ui->textPin->toPlainText();

    QJsonObject jsonObj;
    jsonObj.insert("card_number", card_number);
    jsonObj.insert("pin", pin);

    QString site_url="http://localhost:3000/login";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

    reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());
}


void MainWindow::on_LukitseKortti_clicked()
{

}

