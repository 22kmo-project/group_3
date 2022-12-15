#ifndef EVENTSWINDOW_H
#define EVENTSWINDOW_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

#include "url.h"

namespace Ui {
class EventsWindow;
}

class EventsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EventsWindow(QByteArray token, QString cardNumber, QString accountNumber, QWidget *parent = nullptr);
    ~EventsWindow();

private slots:
    void on_BackButton_clicked();
    void eventsSlot(QNetworkReply *reply);
    void getEventsLog();
    void configureEventLogTable(int rowCount);
    void CloseWindow();

private:
    Ui::EventsWindow *ui;
    QNetworkAccessManager *eventManager;
    QNetworkReply *reply;
    QString myCardNumber;
    QString myAccountNumber;
    QByteArray webToken;
    QTimer * closeWindowTimer;
};

#endif // EVENTSWINDOW_H
