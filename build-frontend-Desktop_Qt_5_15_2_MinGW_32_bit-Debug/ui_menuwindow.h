/********************************************************************************
** Form generated from reading UI file 'menuwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUWINDOW_H
#define UI_MENUWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MenuWindow
{
public:
    QPushButton *withdrawButton;
    QPushButton *balanceButton;
    QPushButton *killCardButton;
    QPushButton *eventsButton;
    QLabel *label_1;
    QLabel *label_2;
    QPushButton *logoutButton;

    void setupUi(QDialog *MenuWindow)
    {
        if (MenuWindow->objectName().isEmpty())
            MenuWindow->setObjectName(QString::fromUtf8("MenuWindow"));
        MenuWindow->resize(600, 400);
        withdrawButton = new QPushButton(MenuWindow);
        withdrawButton->setObjectName(QString::fromUtf8("withdrawButton"));
        withdrawButton->setGeometry(QRect(430, 110, 131, 31));
        withdrawButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,0);border: 0px;"));
        balanceButton = new QPushButton(MenuWindow);
        balanceButton->setObjectName(QString::fromUtf8("balanceButton"));
        balanceButton->setGeometry(QRect(430, 180, 131, 41));
        balanceButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,0);border: 0px;"));
        killCardButton = new QPushButton(MenuWindow);
        killCardButton->setObjectName(QString::fromUtf8("killCardButton"));
        killCardButton->setGeometry(QRect(20, 170, 241, 41));
        killCardButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,0);border: 0px;"));
        eventsButton = new QPushButton(MenuWindow);
        eventsButton->setObjectName(QString::fromUtf8("eventsButton"));
        eventsButton->setGeometry(QRect(350, 250, 211, 41));
        eventsButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,0);border: 0px;"));
        label_1 = new QLabel(MenuWindow);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(0, 0, 571, 91));
        label_1->setStyleSheet(QString::fromUtf8("image: url(:/images/otti2.png);"));
        label_2 = new QLabel(MenuWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 80, 571, 241));
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/images/backgroup.png);"));
        logoutButton = new QPushButton(MenuWindow);
        logoutButton->setObjectName(QString::fromUtf8("logoutButton"));
        logoutButton->setGeometry(QRect(20, 250, 241, 41));
        logoutButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,0);border: 0px;"));
        label_1->raise();
        label_2->raise();
        logoutButton->raise();
        killCardButton->raise();
        withdrawButton->raise();
        balanceButton->raise();
        eventsButton->raise();

        retranslateUi(MenuWindow);

        QMetaObject::connectSlotsByName(MenuWindow);
    } // setupUi

    void retranslateUi(QDialog *MenuWindow)
    {
        MenuWindow->setWindowTitle(QCoreApplication::translate("MenuWindow", "Dialog", nullptr));
        withdrawButton->setText(QString());
        balanceButton->setText(QString());
        killCardButton->setText(QString());
        eventsButton->setText(QString());
        label_1->setText(QString());
        label_2->setText(QString());
        logoutButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MenuWindow: public Ui_MenuWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWINDOW_H
