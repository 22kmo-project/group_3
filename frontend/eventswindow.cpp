#include "eventswindow.h"
#include "ui_eventswindow.h"

EventsWindow::EventsWindow(QByteArray token, QString cardNumber, QString accountNumber, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EventsWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint & ~Qt::WindowSystemMenuHint & ~Qt::WindowCloseButtonHint);

    myCardNumber = cardNumber;
    myAccountNumber = accountNumber;
    webToken = token;
    ui->noEventsLabel->setVisible(false);

    closeWindowTimer = new QTimer(this);
    connect(closeWindowTimer, SIGNAL(timeout()), this, SLOT(CloseWindow()));
    connect(this, SIGNAL(destroyed()), parent, SLOT(resetForceLogoutTimer()));
    closeWindowTimer->start(1000 * 10);

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
    siteUrl = Url::getBaseUrl() + "/card-log/"+myCardNumber+"/"+myAccountNumber;
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
            QDateTime dateTime = jsonObj["datetime"].toVariant().toDateTime();
            QDateTime localDateTime = dateTime.toLocalTime();
            ui->eventLogTableWidget->setItem(column, 2, new QTableWidgetItem(localDateTime.toString("yyyy-MM-dd hh:mm:ss")));
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

void EventsWindow::CloseWindow()
{
    this->close();
    delete this;
}
