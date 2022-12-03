#include "killcardwindow.h"
#include "ui_killcardwindow.h"

#include "ui_menuwindow.h"


KillCardWindow::KillCardWindow(QString cardNumber, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KillCardWindow)
{
    ui->setupUi(this);
    myCardNumber = cardNumber;
    ui->stackedWidget->setCurrentIndex(0);
}

KillCardWindow::~KillCardWindow()
{
    delete ui;
}

void KillCardWindow::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
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
    jsonObj.insert("card_number", myCardNumber);
    jsonObj.insert("pin", pin);
    jsonObj.insert("is_active", is_active);

    QString site_url="http://localhost:3000/card/"+myCardNumber+"";
    QNetworkRequest request((site_url));

    request.setRawHeader(QByteArray("Authorization"),(webToken));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    lukitaManager = new QNetworkAccessManager(this);
    connect(lukitaManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(lukitaSlot(QNetworkReply*)));

    reply = lukitaManager->put(request, QJsonDocument(jsonObj).toJson());

    QTimer::singleShot(3000, this, SLOT(KillCardKilled()));
}



void KillCardWindow::lukitaSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();
    ui->stackedWidget->setCurrentIndex(2); // korttiLukittu
}

void KillCardWindow::KillCardKilled()
{
    this->close();
    delete this;
}
