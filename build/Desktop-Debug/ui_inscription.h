/********************************************************************************
** Form generated from reading UI file 'inscription.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSCRIPTION_H
#define UI_INSCRIPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Inscription
{
public:
    QAction *actionQuitter;
    QAction *actionEnregistrer;
    QWidget *centralwidget;
    QFrame *frame_3;
    QFrame *frame;
    QLineEdit *nom;
    QLineEdit *passwd;
    QLabel *label_inscription;
    QLabel *label;
    QLabel *label_2;
    QPushButton *inscrire;
    QFrame *frame_2;
    QLabel *label_inscription_2;
    QListWidget *liste;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Inscription)
    {
        if (Inscription->objectName().isEmpty())
            Inscription->setObjectName(QString::fromUtf8("Inscription"));
        Inscription->resize(1040, 600);
        actionQuitter = new QAction(Inscription);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionEnregistrer = new QAction(Inscription);
        actionEnregistrer->setObjectName(QString::fromUtf8("actionEnregistrer"));
        centralwidget = new QWidget(Inscription);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(10, 10, 1019, 559));
        frame_3->setStyleSheet(QString::fromUtf8("background-color: rgb(246, 245, 244);"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        frame = new QFrame(frame_3);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 100, 401, 441));
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
        label_inscription->setGeometry(QRect(150, 30, 101, 20));
        label_inscription->setStyleSheet(QString::fromUtf8("font: 700 11pt \"UnBatang\";"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 110, 66, 18));
        label->setStyleSheet(QString::fromUtf8("color: rgb(119, 118, 123);"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 190, 91, 18));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(119, 118, 123);"));
        inscrire = new QPushButton(frame);
        inscrire->setObjectName(QString::fromUtf8("inscrire"));
        inscrire->setGeometry(QRect(140, 320, 121, 26));
        inscrire->setStyleSheet(QString::fromUtf8("background-color: rgb(190, 189, 189);\n"
"border-radius: 10px;"));
        frame_2 = new QFrame(frame_3);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(420, 100, 521, 441));
        frame_2->setStyleSheet(QString::fromUtf8("border-radius: 40px;\n"
"background-color: rgb(222, 221, 218);\n"
"border-color: rgb(0, 0, 0);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_inscription_2 = new QLabel(frame_2);
        label_inscription_2->setObjectName(QString::fromUtf8("label_inscription_2"));
        label_inscription_2->setGeometry(QRect(180, 30, 151, 20));
        label_inscription_2->setStyleSheet(QString::fromUtf8("font: 700 11pt \"UnBatang\";"));
        liste = new QListWidget(frame_2);
        liste->setObjectName(QString::fromUtf8("liste"));
        liste->setGeometry(QRect(20, 80, 481, 341));
        liste->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(0, 0, 0);\n"
"border-radius:10px"));
        Inscription->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Inscription);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1040, 23));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        Inscription->setMenuBar(menubar);
        statusbar = new QStatusBar(Inscription);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Inscription->setStatusBar(statusbar);

        menubar->addAction(menuFichier->menuAction());
        menuFichier->addAction(actionQuitter);
        menuFichier->addAction(actionEnregistrer);

        retranslateUi(Inscription);

        QMetaObject::connectSlotsByName(Inscription);
    } // setupUi

    void retranslateUi(QMainWindow *Inscription)
    {
        Inscription->setWindowTitle(QCoreApplication::translate("Inscription", "Inscription", nullptr));
        actionQuitter->setText(QCoreApplication::translate("Inscription", "Quitter                                                                                      Ctrl+Shift+X", nullptr));
        actionEnregistrer->setText(QCoreApplication::translate("Inscription", "Enregistrer  dans un fichier la liste                                  Ctrl+Shift+E", nullptr));
        label_inscription->setText(QCoreApplication::translate("Inscription", "INSCRIPTION", nullptr));
        label->setText(QCoreApplication::translate("Inscription", "Nom", nullptr));
        label_2->setText(QCoreApplication::translate("Inscription", "Mot de pass", nullptr));
        inscrire->setText(QCoreApplication::translate("Inscription", "S'inscrire", nullptr));
        label_inscription_2->setText(QCoreApplication::translate("Inscription", "LISTE DES INSCRITS", nullptr));
        menuFichier->setTitle(QCoreApplication::translate("Inscription", "Fichier", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Inscription: public Ui_Inscription {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSCRIPTION_H
