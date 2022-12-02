/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *loginPage;
    QLabel *label_4;
    QLabel *labelInfo;
    QLabel *label_17;
    QLabel *label_8;
    QLabel *label_18;
    QPushButton *loginButton;
    QPlainTextEdit *textCardNumber;
    QPlainTextEdit *textPin;
    QWidget *accountPage;
    QLabel *label_5;
    QLabel *label_9;
    QPushButton *creditButton;
    QPushButton *debitButton;
    QLabel *label;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 400);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 701, 471));
        loginPage = new QWidget();
        loginPage->setObjectName(QString::fromUtf8("loginPage"));
        label_4 = new QLabel(loginPage);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 0, 600, 91));
        label_4->setStyleSheet(QString::fromUtf8("image: url(:/images/otti2.png);"));
        labelInfo = new QLabel(loginPage);
        labelInfo->setObjectName(QString::fromUtf8("labelInfo"));
        labelInfo->setGeometry(QRect(70, 90, 441, 41));
        QFont font;
        font.setPointSize(22);
        labelInfo->setFont(font);
        label_17 = new QLabel(loginPage);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(120, 160, 81, 31));
        label_17->setFont(font);
        label_8 = new QLabel(loginPage);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(0, 80, 600, 251));
        label_8->setStyleSheet(QString::fromUtf8("image: url(:/images/default.png);"));
        label_18 = new QLabel(loginPage);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(140, 240, 51, 51));
        label_18->setFont(font);
        loginButton = new QPushButton(loginPage);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(20, 280, 80, 24));
        textCardNumber = new QPlainTextEdit(loginPage);
        textCardNumber->setObjectName(QString::fromUtf8("textCardNumber"));
        textCardNumber->setGeometry(QRect(210, 140, 371, 70));
        QFont font1;
        font1.setPointSize(32);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setKerning(false);
        textCardNumber->setFont(font1);
        textCardNumber->setAcceptDrops(true);
        textCardNumber->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textCardNumber->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textPin = new QPlainTextEdit(loginPage);
        textPin->setObjectName(QString::fromUtf8("textPin"));
        textPin->setGeometry(QRect(210, 230, 271, 70));
        textPin->setFont(font1);
        textPin->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textPin->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        stackedWidget->addWidget(loginPage);
        label_4->raise();
        label_8->raise();
        label_18->raise();
        loginButton->raise();
        textCardNumber->raise();
        textPin->raise();
        labelInfo->raise();
        label_17->raise();
        accountPage = new QWidget();
        accountPage->setObjectName(QString::fromUtf8("accountPage"));
        label_5 = new QLabel(accountPage);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 0, 600, 91));
        label_5->setStyleSheet(QString::fromUtf8("image: url(:/images/otti2.png);"));
        label_9 = new QLabel(accountPage);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(0, 80, 600, 251));
        label_9->setStyleSheet(QString::fromUtf8("image: url(:/images/default.png);"));
        creditButton = new QPushButton(accountPage);
        creditButton->setObjectName(QString::fromUtf8("creditButton"));
        creditButton->setGeometry(QRect(370, 200, 80, 24));
        debitButton = new QPushButton(accountPage);
        debitButton->setObjectName(QString::fromUtf8("debitButton"));
        debitButton->setGeometry(QRect(170, 200, 80, 24));
        QFont font2;
        font2.setPointSize(9);
        debitButton->setFont(font2);
        label = new QLabel(accountPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(230, 130, 141, 41));
        QFont font3;
        font3.setPointSize(24);
        label->setFont(font3);
        stackedWidget->addWidget(accountPage);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_4->setText(QString());
        labelInfo->setText(QCoreApplication::translate("MainWindow", "Sy\303\266t\303\244 kortin numero ja pin koodi", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Kortti", nullptr));
        label_8->setText(QString());
        label_18->setText(QCoreApplication::translate("MainWindow", "PIN", nullptr));
        loginButton->setText(QCoreApplication::translate("MainWindow", "Kirjaudu", nullptr));
        textCardNumber->setPlainText(QString());
        textPin->setPlainText(QString());
        label_5->setText(QString());
        label_9->setText(QString());
        creditButton->setText(QCoreApplication::translate("MainWindow", "Credit", nullptr));
        debitButton->setText(QCoreApplication::translate("MainWindow", "Debit", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Valitse tili", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
