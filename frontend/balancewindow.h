#ifndef BALANCEWINDOW_H
#define BALANCEWINDOW_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

#include "url.h"

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
    void CloseWindow();

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

    QTimer * closeWindowTimer;
};

#endif // BALANCEWINDOW_H
