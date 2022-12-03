#ifndef KILLCARDWINDOW_H
#define KILLCARDWINDOW_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {

class KillCardWindow;

}

class KillCardWindow : public QDialog
{
    Q_OBJECT

public:
    explicit KillCardWindow(QString cardNumber, QWidget *parent = nullptr);
    ~KillCardWindow();

    void setWebToken(const QByteArray &newWebToken);

private slots:
    void on_confirmYesButton_clicked();
    void on_confirmNoButton_clicked();
    void on_confirmKillCard_clicked();
    void lukitaSlot(QNetworkReply *reply);
    void KillCardKilled();
    void on_cancelKillCard_clicked();

private:
    Ui::KillCardWindow *ui;
    QNetworkAccessManager *lukitaManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QByteArray webToken;
    QString myCardNumber;
};

#endif // KILLCARDWINDOW_H
