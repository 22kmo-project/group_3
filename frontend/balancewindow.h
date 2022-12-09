#ifndef BALANCEWINDOW_H
#define BALANCEWINDOW_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class BalanceWindow;
}

class BalanceWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BalanceWindow(QByteArray token, QString accountNumber, QString cardType, QWidget *parent = nullptr);
    ~BalanceWindow();

private slots:
    void on_backButton_clicked();
    void GetBalance();


private:
    Ui::BalanceWindow *ui;
    QByteArray webToken;

    QString myAccountNumber;
    QString myCardType;

    QNetworkAccessManager *balanceManager;
    QNetworkAccessManager *logManager;
    QNetworkReply *balanceReply;
    QNetworkReply *logReply;
    QByteArray balanceResponse;

};

#endif // BALANCEWINDOW_H
