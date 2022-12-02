#ifndef LOGOUTKILL_H
#define LOGOUTKILL_H

#include <QDialog>

namespace Ui {
class logoutkill;
}

class logoutkill : public QDialog
{
    Q_OBJECT

public:
    explicit logoutkill(QWidget *parent = nullptr);
    ~logoutkill();

private:
    Ui::logoutkill *ui;
};

#endif // LOGOUTKILL_H
