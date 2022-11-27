#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

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
    void on_Tapahtumat_clicked();
    void on_Nosto_clicked();
    void on_Saldo_clicked();
    void on_KirjauduUlos_clicked();
    void loginSlot(QNetworkReply *reply);

    void on_Kirjaudu_clicked();

    void on_LukitseKortti_clicked();

    void on_TakaisinN_clicked();

    void on_TakaisinT_clicked();

    void on_TakaisinS_clicked();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString card_number;
    QByteArray webToken;
};
#endif // MAINWINDOW_H
