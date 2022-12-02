/********************************************************************************
** Form generated from reading UI file 'withdrawwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WITHDRAWWINDOW_H
#define UI_WITHDRAWWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_WithdrawWindow
{
public:
    QLabel *label_1;
    QLabel *label_2;
    QPushButton *backButton;

    void setupUi(QDialog *WithdrawWindow)
    {
        if (WithdrawWindow->objectName().isEmpty())
            WithdrawWindow->setObjectName(QString::fromUtf8("WithdrawWindow"));
        WithdrawWindow->resize(600, 400);
        label_1 = new QLabel(WithdrawWindow);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(0, 0, 571, 91));
        label_1->setStyleSheet(QString::fromUtf8("image: url(:/images/otti2.png);"));
        label_2 = new QLabel(WithdrawWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 85, 571, 231));
        QFont font;
        font.setPointSize(28);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/images/default.png);"));
        backButton = new QPushButton(WithdrawWindow);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(10, 280, 75, 24));

        retranslateUi(WithdrawWindow);

        QMetaObject::connectSlotsByName(WithdrawWindow);
    } // setupUi

    void retranslateUi(QDialog *WithdrawWindow)
    {
        WithdrawWindow->setWindowTitle(QCoreApplication::translate("WithdrawWindow", "Dialog", nullptr));
        label_1->setText(QString());
        label_2->setText(QCoreApplication::translate("WithdrawWindow", "    NOSTO", nullptr));
        backButton->setText(QCoreApplication::translate("WithdrawWindow", "Takaisin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WithdrawWindow: public Ui_WithdrawWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WITHDRAWWINDOW_H
