#include "eventswindow.h"
#include "ui_eventswindow.h"

EventsWindow::EventsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EventsWindow)
{
    ui->setupUi(this);
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

void EventsWindow::eventsSlot(QNetworkReply *reply)
{
    /*
    QByteArray responseData=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(responseData);
    QJsonObject json_obj = json_doc.object();
    accountNumber = QString::number(json_obj["accountNumber"].toDouble());
    reply->deleteLater();
    tapahtumatManager->deleteLater();
    */
}

