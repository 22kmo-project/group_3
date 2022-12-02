#include "eventswindow.h"
#include "ui_eventswindow.h"

EventsWindow::EventsWindow(QString cardNumber, QString accountNumber, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EventsWindow)
{
    ui->setupUi(this);
    myCardNumber = cardNumber;
    myAccountNumber = accountNumber;
    this->getEventsLog();
}

EventsWindow::~EventsWindow()
{
    delete ui;
}

void EventsWindow::on_BackButton_clicked()
{
    this->close();
    delete this;
}

void EventsWindow::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
}

void EventsWindow::getEventsLog()
{
    QString siteUrl = "";
    siteUrl = "http://localhost:3000/card-log/"+myCardNumber+"/"+myAccountNumber;
    QNetworkRequest request((siteUrl));

    request.setRawHeader(QByteArray("Authorization"),(webToken));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    eventManager = new QNetworkAccessManager(this);

    connect(eventManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(eventsSlot(QNetworkReply*)));

    eventManager->get(request);
}

void EventsWindow::eventsSlot(QNetworkReply *reply)
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(reply->readAll());
    QJsonArray jsonArray = jsonDoc.array();
    QString eventslog = "";
    foreach (const QJsonValue &value, jsonArray) {
        QJsonObject jsonObj = value.toObject();
        eventslog+=jsonObj["event"].toString()+", " + QString::number(jsonObj["amount"].toInt())+" , "+
        jsonObj["datetime"].toString()+"\r\n";
    }
    reply->deleteLater();
    eventManager->deleteLater();
}

