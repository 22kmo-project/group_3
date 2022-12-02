#include "killcardwindow.h"
#include "ui_killcardwindow.h"
#include "mainwindow.h"

KillCardWindow::KillCardWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KillCardWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

KillCardWindow::~KillCardWindow()
{
    delete ui;
}

void KillCardWindow::on_confirmYesButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void KillCardWindow::on_confirmNoButton_clicked()
{
    this->close();
    delete this;
}

void KillCardWindow::on_cancelKillCard_clicked()
{
    this->close();
    delete this;
}

void KillCardWindow::on_confirmKillCard_clicked()
{
    //Kortin lukitus
    int is_active = 0;
    qInfo() << "Kortti lukitaan!";
    QString pin = ui->pinText->toPlainText();

    QJsonObject jsonObj;
    jsonObj.insert("pin", pin);
    jsonObj.insert("is_active", is_active);

    QString site_url="http://localhost:3000/card/3";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    lukitaManager = new QNetworkAccessManager(this);
    connect(lukitaManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(lukitaSlot(QNetworkReply*)));

    reply = lukitaManager->put(request, QJsonDocument(jsonObj).toJson());
}


void KillCardWindow::lukitaSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();
    int test = QString::compare(response_data, "false");
    if (response_data.length() == 0){
        qInfo() << "Palvelin ei vastaa";
        //ui->labelInfo->setText("Palvelin ei vastaa");
    } else {
        if (QString::compare(response_data, "-4078") == 0) {
            //ui->labelInfo->setText("Virhe tietokanta yhteydessä");
            qInfo() << "Virhe tietokanta yhteydessä";
        } else {
            if (test == 0) {
                //ui->textCardNumber->clear();
                ui->pinText->clear();
                //ui->labelInfo->setText("PIN väärin");
                qInfo() << "PIN väärin";
            } else {
                //webToken = ("Bearer " + response_data);
                ui->stackedWidget->setCurrentIndex(7); // korttiLukittu
            }
        }
    }

}

