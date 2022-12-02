#ifndef EVENTSWINDOW_H
#define EVENTSWINDOW_H

#include "eventlogmodel.h"

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class EventsWindow;
}

class EventsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EventsWindow(QString cardNumber, QString accountNumber, QWidget *parent = nullptr);
    ~EventsWindow();

    void setWebToken(const QByteArray &newWebToken);

private slots:
    void on_BackButton_clicked();
    void eventsSlot(QNetworkReply *reply);
    void getEventsLog();

private:
    Ui::EventsWindow *ui;
    QNetworkAccessManager *eventManager;
    QNetworkReply *reply;
    QString myCardNumber;
    QString myAccountNumber;
    QByteArray webToken;
};

#endif // EVENTSWINDOW_H
