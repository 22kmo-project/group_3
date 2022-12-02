#ifndef EVENTSWINDOW_H
#define EVENTSWINDOW_H

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
    explicit EventsWindow(QWidget *parent = nullptr);
    ~EventsWindow();

private slots:
    void on_BackButton_clicked();
    void eventsSlot(QNetworkReply *reply);

private:
    Ui::EventsWindow *ui;
};

#endif // EVENTSWINDOW_H
