#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

#include "menuwindow.h"
#include "url.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void loginSlot(QNetworkReply *reply);
    void showMainWindowSlot();
    void on_loginButton_clicked();
    void getAccountNumber();
    QString getCardType();
    void openMenuWindow();
    void resetTextFields();
    bool isValidInput(QString pin);

    void on_creditButton_clicked();
    void on_debitButton_clicked();

private:
    Ui::MainWindow *ui;
    MenuWindow *objectMenuWindow;
    QNetworkAccessManager *loginManager;
    QNetworkAccessManager *cardTypeManager;
    QNetworkAccessManager *accountNumberManager;
    QNetworkReply *reply;
    QByteArray responseData;
    QByteArray webToken;
    QString cardNumber;
    QString accountNumber;
    QString cardType;
};
#endif // MAINWINDOW_H
