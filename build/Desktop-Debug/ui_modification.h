/********************************************************************************
** Form generated from reading UI file 'modification.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFICATION_H
#define UI_MODIFICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Modification
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLineEdit *nom;
    QLineEdit *passwd;
    QLabel *label_inscription;
    QLabel *label;
    QLabel *label_2;
    QPushButton *modifier;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Modification)
    {
        if (Modification->objectName().isEmpty())
            Modification->setObjectName(QString::fromUtf8("Modification"));
        Modification->resize(800, 600);
        centralwidget = new QWidget(Modification);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(180, 70, 401, 441));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(191, 248, 80);\n"
"border-radius: 40px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        nom = new QLineEdit(frame);
        nom->setObjectName(QString::fromUtf8("nom"));
        nom->setGeometry(QRect(50, 140, 301, 41));
        nom->setStyleSheet(QString::fromUtf8("background-color: rgb(246, 245, 244);\n"
"border-color: rgb(0, 0, 0);\n"
"border-radius: 10px;"));
        passwd = new QLineEdit(frame);
        passwd->setObjectName(QString::fromUtf8("passwd"));
        passwd->setGeometry(QRect(50, 220, 301, 41));
        passwd->setStyleSheet(QString::fromUtf8("background-color: rgb(246, 245, 244);\n"
"border-color: rgb(0, 0, 0);\n"
"border-radius: 10px;"));
        label_inscription = new QLabel(frame);
        label_inscription->setObjectName(QString::fromUtf8("label_inscription"));
        label_inscription->setGeometry(QRect(150, 30, 121, 20));
        label_inscription->setStyleSheet(QString::fromUtf8("font: 700 11pt \"UnBatang\";"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 110, 66, 18));
        label->setStyleSheet(QString::fromUtf8("color: rgb(119, 118, 123);"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 190, 91, 18));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(119, 118, 123);"));
        modifier = new QPushButton(frame);
        modifier->setObjectName(QString::fromUtf8("modifier"));
        modifier->setGeometry(QRect(140, 320, 121, 26));
        modifier->setStyleSheet(QString::fromUtf8("background-color: rgb(190, 189, 189);\n"
"border-radius: 10px;"));
        Modification->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Modification);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        Modification->setMenuBar(menubar);
        statusbar = new QStatusBar(Modification);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Modification->setStatusBar(statusbar);

        retranslateUi(Modification);

        QMetaObject::connectSlotsByName(Modification);
    } // setupUi

    void retranslateUi(QMainWindow *Modification)
    {
        Modification->setWindowTitle(QCoreApplication::translate("Modification", "MainWindow", nullptr));
        label_inscription->setText(QCoreApplication::translate("Modification", "MODIFICATION", nullptr));
        label->setText(QCoreApplication::translate("Modification", "Nom", nullptr));
        label_2->setText(QCoreApplication::translate("Modification", "Mot de pass", nullptr));
        modifier->setText(QCoreApplication::translate("Modification", "Modifier", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Modification: public Ui_Modification {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFICATION_H
