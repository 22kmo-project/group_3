#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

#include "menuwindow.h"

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
    void logSlot(QNetworkReply *reply);
    void showMainWindowSlot();
    void on_loginButton_clicked();

private:
    Ui::MainWindow *ui;
    MenuWindow *objectMenuWindow;
    QNetworkAccessManager *loginManager;
    QNetworkAccessManager *tapahtumatManager;
    QNetworkAccessManager *eventsManager;
    QNetworkReply *reply;
    QByteArray responseData;
    QByteArray webToken;
    QString cardNumber;
    QString accountNumber;
};
#endif // MAINWINDOW_H
