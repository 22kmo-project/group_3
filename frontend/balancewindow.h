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
    explicit BalanceWindow(QByteArray token, QWidget *parent = nullptr);
    ~BalanceWindow();

private slots:
    void on_backButton_clicked();

private:
    Ui::BalanceWindow *ui;
    QByteArray webToken;
};

#endif // BALANCEWINDOW_H
