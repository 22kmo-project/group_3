/********************************************************************************
** Form generated from reading UI file 'eventswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTSWINDOW_H
#define UI_EVENTSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EventsWindow
{
public:
    QLabel *label_13;
    QPushButton *BackButton;
    QLabel *label_14;

    void setupUi(QDialog *EventsWindow)
    {
        if (EventsWindow->objectName().isEmpty())
            EventsWindow->setObjectName(QString::fromUtf8("EventsWindow"));
        EventsWindow->resize(600, 400);
        label_13 = new QLabel(EventsWindow);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(0, 0, 571, 91));
        label_13->setStyleSheet(QString::fromUtf8("image: url(:/images/otti2.png);"));
        BackButton = new QPushButton(EventsWindow);
        BackButton->setObjectName(QString::fromUtf8("BackButton"));
        BackButton->setGeometry(QRect(10, 280, 75, 24));
        label_14 = new QLabel(EventsWindow);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(0, 85, 571, 231));
        QFont font;
        font.setPointSize(28);
        label_14->setFont(font);
        label_14->setStyleSheet(QString::fromUtf8("image: url(:/images/default.png);"));
        label_13->raise();
        label_14->raise();
        BackButton->raise();

        retranslateUi(EventsWindow);

        QMetaObject::connectSlotsByName(EventsWindow);
    } // setupUi

    void retranslateUi(QDialog *EventsWindow)
    {
        EventsWindow->setWindowTitle(QCoreApplication::translate("EventsWindow", "Dialog", nullptr));
        label_13->setText(QString());
        BackButton->setText(QCoreApplication::translate("EventsWindow", "Takaisin", nullptr));
        label_14->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EventsWindow: public Ui_EventsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTSWINDOW_H
