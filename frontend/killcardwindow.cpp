#include "killcardwindow.h"
#include "ui_killcardwindow.h"
#include <QTimer>


KillCardWindow::KillCardWindow(QByteArray token, QString cardNumber, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KillCardWindow)
{
    ui->setupUi(this);
    myCardNumber = cardNumber;
    webToken = token;
    ui->stackedWidget->setCurrentIndex(0);
}

KillCardWindow::~KillCardWindow()
{
    delete ui;
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

    QString pin = ui->pinText->toPlainText();

    QJsonObject jsonObj;
    jsonObj.insert("card_number", myCardNumber);
    jsonObj.insert("pin", pin);
    jsonObj.insert("is_active", is_active);

    QString site_url="http://localhost:3000/card/killcard/"+myCardNumber+"";
    QNetworkRequest request((site_url));

    request.setRawHeader(QByteArray("Authorization"),(webToken));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    lukitaManager = new QNetworkAccessManager(this);
    connect(lukitaManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(lukitaSlot(QNetworkReply*)));
    reply = lukitaManager->put(request, QJsonDocument(jsonObj).toJson());


}

void KillCardWindow::lukitaSlot(QNetworkReply *reply)
{
    if(reply->error()==QNetworkReply::NoError)
    {
    response_data = reply->readAll();
    ui->stackedWidget->setCurrentIndex(2); // korttiLukittu

    ui->label_8->setText("Sivu sulkeutuu: 5");
    Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()), this, SLOT(KillCardKilled()));
    Timer->start(1000);

    qInfo() << "Kortti lukitaan!";
    }
    else{
        ui->label_pin->setText("PIN väärin");
        qInfo() << "PIN väärin";
    }
}

void KillCardWindow::KillCardKilled()
{
    sec--;
    if(sec==-1)
    {
        qDebug()<< "Ok";
        Timer->stop();
        this->close();
        delete this;
    }
    else
    ui->label_8->setText(QString("Sivu sulkeutuu: %1").arg(sec));
}
