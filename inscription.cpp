#include "inscription.h"
#include "ui_inscription.h"
#include <iostream>
#include <QString>
#include <QListWidgetItem>
#include <QLineEdit>
#include <fstream>
#include <string>
#include <vector>
#include <QHBoxLayout>
#include <QPushButton>
#include "modification.h"
#include <QShortcut>
#include <QMessageBox>

#include <QFile>


Inscription::Inscription(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Inscription),Modif(new Modification)
{
    ui->setupUi(this);
    connect(ui->inscrire,SIGNAL(clicked()),this,SLOT(inscrire()));
    lister("liste.txt");


    QShortcut *quit = new QShortcut(QKeySequence("Ctrl+Shift+X"), this);
    QShortcut *enregistre = new QShortcut(QKeySequence("Ctrl+Shift+E"), this);

    connect(quit, &QShortcut::activated, this,&Inscription::close);
    connect(ui->actionQuitter,&QAction::triggered,this,&Inscription::close);
    connect(enregistre,&QShortcut::activated,this,&Inscription::enregistrer);
    connect(ui->actionEnregistrer,&QAction::triggered,this,&Inscription::enregistrer);



}

void Inscription::lister(std::string fichier)
{
    int position;
    Personne P1;
    std::vector<Personne>::iterator i;
    std::string ligne;
    std::ifstream file(fichier.c_str());
    //Reinitialiser le vector P
    P.clear();
    if(file.is_open())
    {
        while (std::getline(file,ligne))
        {
            position=ligne.find(':');
            P1.setNom(ligne.substr(0,position));
            P1.setPassword(ligne.substr(position+1,ligne.size()-position+1));
            P.push_back(P1);
        }
    }

    ui->liste->clear();
    for(i=P.begin();i!=P.end();i++)
    {
        if(i->getNom().size()>0)
        {
            QListWidgetItem *item = new QListWidgetItem(ui->liste);
            QWidget * widget = new QWidget();
            QHBoxLayout *layout = new QHBoxLayout(widget);
            QLabel *element = new QLabel(QString::fromStdString(i->getNom()));
            QPushButton *modif= new QPushButton("Modifier");
            QPushButton *suppr= new QPushButton("Supprimer");

            //Style Sheet
            modif->setStyleSheet("background-color: rgb(190, 189, 189);border-radius:20px;");
            modif->setStyleSheet("background-color: rgb(190, 189, 189);border-radius:20px;");
            suppr->setStyleSheet("background-color: rgb(190, 189, 189);border-radius: 10px;");

            layout->addWidget(element);
            layout->addWidget(modif,0,Qt::AlignRight);
            layout->addWidget(suppr,0,Qt::AlignRight);

            widget->setLayout(layout);
            //Taille de chaque Widget
            widget->setMinimumHeight(40);

            //Ajouter une marge entre chaque element de la liste
            ui->liste->setSpacing(5);

            //les elements peuvent avoir de differente taille
            ui->liste->setUniformItemSizes(false);

            ui->liste->addItem(item);
            ui->liste->setItemWidget(item,widget);

            //------CONNECTER MOFIDIER

            connect(modif, &QPushButton::clicked, this, [=]() {
                modifier(item);
            });
            connect(suppr, &QPushButton::clicked, this, [=]() {
                desabonne(item);
            });
        }

    }
}

void Inscription::inscrire()
{
    QString name, pass,chaine;
    Personne P1=Personne();
    std::ofstream flux ("liste.txt",std::ios::app);
    QStringList liste;
    name = ui->nom->text();
    pass = ui->passwd->text();
    chaine= name+":"+pass+"\n";
    P1.setNom(name.toStdString());
    P1.setPassword(pass.toStdString());
    flux << chaine.toStdString();
    flux.close();
    ui->nom->setText("");
    ui->passwd->setText("");
    //effacher la liste
    ui->liste->clear();
    lister("liste.txt");
}

void Inscription::modifier(QListWidgetItem *item)
{
    int position_actuelle;
    std::string ligne ;

    position_actuelle=ui->liste->row(item);

    QWidget *fenetre = new QWidget;
    QFrame * frame = new QFrame(fenetre);
    frame->setFrameShape(QFrame::Box);
    frame->setStyleSheet("background-color: rgb(191, 248, 80);border-radius: 40px;");
    frame->resize(400,350);

    QLabel *titre=new QLabel("MODIFICATION",frame);
    titre->move(160,10);
    titre->setStyleSheet("font: 700 11pt \"UnBatang\";");

    QLabel *nom_label = new QLabel("Nom",frame);
    nom_label->move(30,60);
    nom_label->setStyleSheet("color: rgb(119, 118, 123);");

    QLineEdit *nom=new QLineEdit(frame);
    nom->resize(340,40);
    nom->move(30,90);
    nom->setStyleSheet("background-color: rgb(246, 245, 244);border-color: rgb(0, 0, 0);border-radius: 10px;");

    QLabel *passwd_label = new QLabel("Mot de pass",frame);
    passwd_label->move(30,140);
    passwd_label->setStyleSheet("color: rgb(119, 118, 123);");

    QLineEdit *passwd=new QLineEdit(frame);
    passwd->resize(340,40);
    passwd->move(30,170);
    passwd->setStyleSheet("background-color: rgb(246, 245, 244);border-color: rgb(0, 0, 0);border-radius: 10px;");

    QPushButton *annuler = new QPushButton("Annuler",frame);
    annuler->move(70,250);
    annuler->resize(100,30);
    annuler->setStyleSheet("background-color: rgb(190, 189, 189);border-radius: 10px;");

    connect(annuler,&QPushButton::clicked,this,[=](){
        fenetre->close();
    });

    QPushButton *modifier = new QPushButton("Modifier",frame);
    modifier->move(230,250);
    modifier->resize(100,30);
    modifier->setStyleSheet("background-color: rgb(190, 189, 189);border-radius: 10px;");

    connect(modifier,&QPushButton::clicked,this,[=](){
        int i;
        std::string ligne;
        std::vector <std::string> lignes;
        std::vector <std::string>::iterator it;
        QString name,pass;
        name=nom->text();
        pass=passwd->text();
        std::ifstream file("liste.txt");
        while (std::getline(file, ligne)) {

            lignes.push_back(ligne);
        }
        file.close();

        std::ofstream fic ("liste.txt");
        fic << "";
        fic.close();
        std::cout << "POs : " << position_actuelle << std::endl;
        std::cout << "Line : " << lignes[4]<<std::endl;
        i=0;
        std::ofstream f("liste.txt",std::ios::app);
        if(f.is_open())
        {
            for(it=lignes.begin();it!=lignes.end();it++)
            {
                if(i==position_actuelle)
                {
                    *it = name.toStdString() + ":" + pass.toStdString()+"\n";
                    f<<*it;
                    i++;
                    continue;
                }
                *it = *it + "\n";
                f<<*it;
                i++;
            }
            f.close();
        }
        fenetre->close();
        lister("liste.txt");
        QMessageBox::information(this,"Message","Modification enregistrer");
    });

    fenetre->resize(400,350);
    fenetre->show();

}

void Inscription::desabonne(QListWidgetItem *item)
{
    std::cout << "des\n";
    int position_supprime,i;
    std::vector <std::string> lignes;
    std::vector <std::string>::iterator it;
    std::string ligne;
    position_supprime=ui->liste->row(item);
    std::ifstream file("liste.txt");
    std::cout << "POS : " << position_supprime << std::endl;

    while (std::getline(file, ligne)) {

        lignes.push_back(ligne);
    }

    file.close();

    std::ofstream fic ("liste.txt");
    fic << "";
    fic.close();

    i=0;
    std::ofstream f("liste.txt",std::ios::app);
    if(f.is_open())
    {
        for(it=lignes.begin();it!=lignes.end();it++)
        {
            if(i==position_supprime)
            {
                i++;
                continue;
            }
            *it = *it + "\n";
            f<<*it;
            i++;
        }
        f.close();
    }



    lister("liste.txt");
}


void Inscription::enregistrer()
{
    QWidget *fenetre = new QWidget;
    QLabel *nom_fichier= new QLabel("Nom du fichier : ",fenetre);
    nom_fichier->move(30,30);

    QLineEdit *champ = new QLineEdit(fenetre);
    champ->resize(250,30);
    champ->move(30,60);

    QPushButton *annuler = new QPushButton("Annuler",fenetre);
    annuler->move(30,100);

    QPushButton *ok = new QPushButton("OK",fenetre);
    ok->move(150,100);

    QObject::connect(ok,&QPushButton::clicked,this,[=](){

        QString fichier;
        fichier = champ->text();
        QFile file(fichier);
        if(file.exists())
        {
            QFile::remove(fichier);
        }
        QFile::copy("liste.txt",fichier);
        fenetre->close();
        if(file.size()>0)
        {
            QMessageBox::information(this,"Message","Liste enregistré dans le fichier");
        }
    });

    QObject::connect(annuler,&QPushButton::clicked,this,[=](){
        fenetre->close();
    });



    fenetre->resize(300,200);
    fenetre->show();
}

Inscription::~Inscription()
{
    delete ui;
}
