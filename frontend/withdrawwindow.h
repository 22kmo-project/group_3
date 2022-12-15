#ifndef WITHDRAWWINDOW_H
#define WITHDRAWWINDOW_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QValidator>

#include "url.h"

namespace Ui {
class WithdrawWindow;
}

class WithdrawWindow : public QDialog
{
    Q_OBJECT

public:
    explicit WithdrawWindow(QByteArray token, QString cardNumber, QString accountNumber, QString cardType, QWidget *parent = nullptr);
    ~WithdrawWindow();

private slots:
    void on_backButton_clicked();
    int GetBalance();
    void Withdraw();
    void LogWithdraw();
    void on_withdrawButton_clicked();
    void Logout();
    void CloseWindow();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::WithdrawWindow *ui;
    QByteArray webToken;

    QString myAccountNumber;
    QString myCardNumber;
    QString myCardType;

    QNetworkAccessManager *balanceManager;
    QNetworkAccessManager *withdrawManager;
    QNetworkAccessManager *logManager;
    QNetworkReply *balanceReply;
    QNetworkReply *withdrawReply;
    QNetworkReply *logReply;
    QByteArray withdrawResponse;
    QTimer *timer;
    QTimer * closeWindowTimer;

    int withdrawAmount;
};

#endif // WITHDRAWWINDOW_H
