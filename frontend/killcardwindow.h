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
    explicit KillCardWindow(QWidget *parent = nullptr);
    ~KillCardWindow();

private slots:
    void on_confirmYesButton_clicked();
    void on_confirmNoButton_clicked();
    void on_confirmKillCard_clicked();
    void lukitaSlot(QNetworkReply *reply);

    void on_cancelKillCard_clicked();

private:
    Ui::KillCardWindow *ui;
    QNetworkAccessManager *lukitaManager;
    QNetworkReply *reply;
    QByteArray response_data;
};

#endif // KILLCARDWINDOW_H
