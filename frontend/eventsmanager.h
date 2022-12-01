#ifndef EVENTSMANAGER_H
#define EVENTSMANAGER_H

#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include "mainwindow.h"

class EventsManager : public QObject
{
    Q_OBJECT

public:
    EventsManager();

public slots:
    void tapahtumatSlot(QNetworkReply*);
};

#endif // EVENTSMANAGER_H
