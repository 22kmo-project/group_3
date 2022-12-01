#ifndef KILLCARDWINDOW_H
#define KILLCARDWINDOW_H

#include <QDialog>

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

private:
    Ui::KillCardWindow *ui;
};

#endif // KILLCARDWINDOW_H
