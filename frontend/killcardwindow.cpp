#include "killcardwindow.h"
#include "ui_killcardwindow.h"

#include "ui_menuwindow.h"


KillCardWindow::KillCardWindow(QByteArray token, QString cardNumber, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KillCardWindow)
{
    ui->setupUi(this);
    myCardNumber = cardNumber;
    webToken = token;
    ui->stackedWidget->setCurrentIndex(0);
    short a = 10;
    QString t = "Syötä PIN";
    pinCodeText(t,a);
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
    QTimer::singleShot(3000, this, SLOT(KillCardKilled()));
    qInfo() << "Kortti lukitaan!";
    }
    else{
        short a = 10;
        QString t = "Väärä PIN";
        pinCodeText(t,a);
        qInfo() << "PIN väärin";
    }
}

void KillCardWindow::KillCardKilled()
{
    this->close();
    delete this;
}

void KillCardWindow::pinCodeText(QString pincode, short luku)
{
    ui->label_pin->setText(pincode);
    QFont font = ui->label_pin->font();
    font.setPointSize(luku);
    font.setBold(true);
    ui->label_pin->setFont(font);
}
