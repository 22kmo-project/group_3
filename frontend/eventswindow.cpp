#include "eventswindow.h"
#include "ui_eventswindow.h"

EventsWindow::EventsWindow(QByteArray token, QString cardNumber, QString accountNumber, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EventsWindow)
{
    ui->setupUi(this);
    myCardNumber = cardNumber;
    myAccountNumber = accountNumber;
    webToken = token;
    ui->noEventsLabel->setVisible(false);
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
    int rowCount = jsonArray.count();
    if (rowCount > 0) {
        this->configureEventLogTable(rowCount);
        int column = 0;
        foreach (const QJsonValue &value, jsonArray) {
            QJsonObject jsonObj = value.toObject();
            QString event = jsonObj["event"].toString();
            if (event == "Withdraw") {
                event = "Nosto";
            }
            ui->eventLogTableWidget->setItem(column, 0, new QTableWidgetItem(event));
            ui->eventLogTableWidget->setItem(column, 1, new QTableWidgetItem(QString::number(jsonObj["amount"].toDouble())));
            QString datetime = jsonObj["datetime"].toString();
            datetime.replace("T", " ").replace(".000Z", "");
            ui->eventLogTableWidget->setItem(column, 2, new QTableWidgetItem(datetime));
            ++column;
        }
    } else {
        // Ei tapahtumalogeja.
        ui->noEventsLabel->setVisible(true);
    }
    reply->deleteLater();
    eventManager->deleteLater();
}

void EventsWindow::configureEventLogTable(int rowCount)
{
    ui->eventLogTableWidget->setRowCount(rowCount);
    ui->eventLogTableWidget->setColumnCount(3);
    ui->eventLogTableWidget->verticalHeader()->setVisible(false);
    ui->eventLogTableWidget->setHorizontalHeaderLabels(QStringList({"Tapahtuma", "Määrä", "Päiväys"}));
    ui->eventLogTableWidget->setColumnWidth(0, 100);
    ui->eventLogTableWidget->setColumnWidth(1, 100);
    ui->eventLogTableWidget->setColumnWidth(2, 200);
    ui->eventLogTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

