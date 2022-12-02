/********************************************************************************
** Form generated from reading UI file 'balancewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BALANCEWINDOW_H
#define UI_BALANCEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_BalanceWindow
{
public:
    QLabel *label_12;
    QLabel *label_11;
    QPushButton *backButton;

    void setupUi(QDialog *BalanceWindow)
    {
        if (BalanceWindow->objectName().isEmpty())
            BalanceWindow->setObjectName(QString::fromUtf8("BalanceWindow"));
        BalanceWindow->resize(600, 400);
        label_12 = new QLabel(BalanceWindow);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(0, 0, 571, 91));
        label_12->setStyleSheet(QString::fromUtf8("image: url(:/images/otti2.png);"));
        label_11 = new QLabel(BalanceWindow);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(0, 85, 571, 231));
        QFont font;
        font.setPointSize(28);
        label_11->setFont(font);
        label_11->setStyleSheet(QString::fromUtf8("image: url(:/images/default.png);"));
        backButton = new QPushButton(BalanceWindow);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(20, 280, 75, 24));

        retranslateUi(BalanceWindow);

        QMetaObject::connectSlotsByName(BalanceWindow);
    } // setupUi

    void retranslateUi(QDialog *BalanceWindow)
    {
        BalanceWindow->setWindowTitle(QCoreApplication::translate("BalanceWindow", "Dialog", nullptr));
        label_12->setText(QString());
        label_11->setText(QCoreApplication::translate("BalanceWindow", "              SALDOOOOOOOO", nullptr));
        backButton->setText(QCoreApplication::translate("BalanceWindow", "Takaisin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BalanceWindow: public Ui_BalanceWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BALANCEWINDOW_H
