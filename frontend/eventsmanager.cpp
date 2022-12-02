#include "eventsmanager.h"

EventsManager::EventsManager()
{

}

void EventsManager::tapahtumatSlot(QNetworkReply* reply)
{
    qDebug()<<"TEST";
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    //account_number = QString::number(json_obj["account_number"].toDouble());
    reply->deleteLater();
    //tapahtumatManager->deleteLater();
}
