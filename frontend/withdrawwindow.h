#ifndef WITHDRAWWINDOW_H
#define WITHDRAWWINDOW_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QValidator>

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
    void on_nosto2Button_clicked();
     void KirjauduUlos2();

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
      QTimer * laskuri;
        int sec = 5;

    int withdrawAmount;
};

#endif // WITHDRAWWINDOW_H
