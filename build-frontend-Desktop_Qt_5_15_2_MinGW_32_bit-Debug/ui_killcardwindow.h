/********************************************************************************
** Form generated from reading UI file 'killcardwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KILLCARDWINDOW_H
#define UI_KILLCARDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KillCardWindow
{
public:
    QStackedWidget *stackedWidget;
    QWidget *killCardConfirmPage;
    QPushButton *confirmYesButton;
    QLabel *label_2;
    QLabel *label_1;
    QPushButton *confirmNoButton;
    QLabel *label_3;
    QWidget *killCardPinPage;
    QLabel *label_4;
    QPushButton *confirmKillCard;
    QPushButton *cancelKillCard;
    QPlainTextEdit *pinText;
    QLabel *label_5;
    QLabel *label_pin;

    void setupUi(QDialog *KillCardWindow)
    {
        if (KillCardWindow->objectName().isEmpty())
            KillCardWindow->setObjectName(QString::fromUtf8("KillCardWindow"));
        KillCardWindow->resize(600, 400);
        stackedWidget = new QStackedWidget(KillCardWindow);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 600, 400));
        killCardConfirmPage = new QWidget();
        killCardConfirmPage->setObjectName(QString::fromUtf8("killCardConfirmPage"));
        confirmYesButton = new QPushButton(killCardConfirmPage);
        confirmYesButton->setObjectName(QString::fromUtf8("confirmYesButton"));
        confirmYesButton->setGeometry(QRect(170, 240, 80, 24));
        label_2 = new QLabel(killCardConfirmPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 85, 571, 231));
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/images/default.png);"));
        label_1 = new QLabel(killCardConfirmPage);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(0, 0, 571, 91));
        label_1->setStyleSheet(QString::fromUtf8("image: url(:/images/otti2.png);"));
        confirmNoButton = new QPushButton(killCardConfirmPage);
        confirmNoButton->setObjectName(QString::fromUtf8("confirmNoButton"));
        confirmNoButton->setGeometry(QRect(330, 240, 80, 24));
        label_3 = new QLabel(killCardConfirmPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(100, 140, 381, 61));
        label_3->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe UI\";"));
        stackedWidget->addWidget(killCardConfirmPage);
        label_1->raise();
        label_2->raise();
        confirmNoButton->raise();
        label_3->raise();
        confirmYesButton->raise();
        killCardPinPage = new QWidget();
        killCardPinPage->setObjectName(QString::fromUtf8("killCardPinPage"));
        label_4 = new QLabel(killCardPinPage);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 0, 571, 91));
        label_4->setStyleSheet(QString::fromUtf8("image: url(:/images/otti2.png);"));
        confirmKillCard = new QPushButton(killCardPinPage);
        confirmKillCard->setObjectName(QString::fromUtf8("confirmKillCard"));
        confirmKillCard->setGeometry(QRect(349, 260, 131, 24));
        cancelKillCard = new QPushButton(killCardPinPage);
        cancelKillCard->setObjectName(QString::fromUtf8("cancelKillCard"));
        cancelKillCard->setGeometry(QRect(70, 260, 221, 24));
        pinText = new QPlainTextEdit(killCardPinPage);
        pinText->setObjectName(QString::fromUtf8("pinText"));
        pinText->setGeometry(QRect(153, 170, 321, 70));
        label_5 = new QLabel(killCardPinPage);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 85, 571, 241));
        label_5->setStyleSheet(QString::fromUtf8("image: url(:/images/default.png);"));
        label_pin = new QLabel(killCardPinPage);
        label_pin->setObjectName(QString::fromUtf8("label_pin"));
        label_pin->setGeometry(QRect(150, 120, 111, 41));
        label_pin->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe UI\";"));
        stackedWidget->addWidget(killCardPinPage);
        label_4->raise();
        label_5->raise();
        cancelKillCard->raise();
        confirmKillCard->raise();
        pinText->raise();
        label_pin->raise();

        retranslateUi(KillCardWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(KillCardWindow);
    } // setupUi

    void retranslateUi(QDialog *KillCardWindow)
    {
        KillCardWindow->setWindowTitle(QCoreApplication::translate("KillCardWindow", "Dialog", nullptr));
        confirmYesButton->setText(QCoreApplication::translate("KillCardWindow", "Kyll\303\244", nullptr));
        label_2->setText(QString());
        label_1->setText(QString());
        confirmNoButton->setText(QCoreApplication::translate("KillCardWindow", "Ei", nullptr));
        label_3->setText(QCoreApplication::translate("KillCardWindow", "Haluatko varmasti sulkea kortin", nullptr));
        label_4->setText(QString());
        confirmKillCard->setText(QCoreApplication::translate("KillCardWindow", "Poista kortti", nullptr));
        cancelKillCard->setText(QCoreApplication::translate("KillCardWindow", "En haluakaan kuolettaa korttia", nullptr));
        label_5->setText(QString());
        label_pin->setText(QCoreApplication::translate("KillCardWindow", "Sy\303\266n Pin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KillCardWindow: public Ui_KillCardWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KILLCARDWINDOW_H
