#ifndef WITHDRAWWINDOW_H
#define WITHDRAWWINDOW_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class WithdrawWindow;
}

class WithdrawWindow : public QDialog
{
    Q_OBJECT

public:
    explicit WithdrawWindow(QWidget *parent = nullptr);
    ~WithdrawWindow();

private slots:
    void on_backButton_clicked();

private:
    Ui::WithdrawWindow *ui;
};

#endif // WITHDRAWWINDOW_H
