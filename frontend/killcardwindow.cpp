#include "killcardwindow.h"
#include "ui_killcardwindow.h"
#include <QTimer>


KillCardWindow::KillCardWindow(QByteArray token, QString cardNumber, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KillCardWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint & ~Qt::WindowSystemMenuHint & ~Qt::WindowCloseButtonHint);

    myCardNumber = cardNumber;
    webToken = token;
    ui->stackedWidget->setCurrentIndex(0);

    closeWindowTimer = new QTimer(this);
    connect(closeWindowTimer, SIGNAL(timeout()), this, SLOT(CloseWindow()));
    connect(this, SIGNAL(destroyed()), parent, SLOT(resetForceLogoutTimer()));
    closeWindowTimer->start(1000 * 10);
}

KillCardWindow::~KillCardWindow()
{
    delete ui;
}

void KillCardWindow::on_confirmYesButton_clicked()
{
    closeWindowTimer->start(1000 * 10);
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
    closeWindowTimer->start(1000 * 10);
    //Kortin lukitus
    int is_active = 0;

    QString pin = ui->lineEditPin->text();

    QJsonObject jsonObj;
    jsonObj.insert("card_number", myCardNumber);
    jsonObj.insert("pin", pin);
    jsonObj.insert("is_active", is_active);

    QString site_url = Url::getBaseUrl() + "/card/killcard/"+myCardNumber+"";
    QNetworkRequest request((site_url));

    request.setRawHeader(QByteArray("Authorization"),(webToken));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    lukitaManager = new QNetworkAccessManager(this);
    connect(lukitaManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(lukitaSlot(QNetworkReply*)));
    reply = lukitaManager->put(request, QJsonDocument(jsonObj).toJson());


}

void KillCardWindow::lukitaSlot(QNetworkReply *reply)
{
    closeWindowTimer->stop();
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
    closeWindowTimer->start(1000 * 10);
}

void KillCardWindow::KillCardKilled()
{
    closeWindowTimer->stop();
    sec--;
    if(sec==-1)
    {
        qDebug()<< "Ok";
        Timer->stop();
        this->done(QDialog::Accepted);
    }
    else
    ui->label_8->setText(QString("Sivu sulkeutuu: %1").arg(sec));
}

void KillCardWindow::CloseWindow()
{
    this->close();
    delete this;
}
