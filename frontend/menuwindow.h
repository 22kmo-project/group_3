#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include "balancewindow.h"
#include "eventswindow.h"
#include "killcardwindow.h"
#include "withdrawwindow.h"

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui { class MenuWindow; }

class MenuWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MenuWindow(QString cardNumber, QString accountNumber, QString cardType, QWidget *parent = nullptr);
    ~MenuWindow();

    const QString &getWebToken() const;

    void setWebToken(const QByteArray &newWebToken);

public slots:
    void logout();
    void resetForceLogoutTimer();

private slots:
    void on_logoutButton_clicked();
    void on_eventsButton_clicked();
    void on_withdrawButton_clicked();
    void on_balanceButton_clicked();
    void on_killCardButton_clicked();
    void checkLogoutTimer();

private:
    Ui::MenuWindow *ui;

    WithdrawWindow *objectWithdrawWindow;
    BalanceWindow *objectBalanceWindow;
    KillCardWindow *objectKillCardWindow;
    EventsWindow *objectEventsWindow;

    QByteArray webToken;
    QString myCardNumber;
    QString myAccountNumber;
    QString myCardType;

    QNetworkAccessManager *dataManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QTimer * timer;
    QTimer * forceLogoutTimer;
    int logoutSeconds;
};

#endif // MENUWINDOW_H
