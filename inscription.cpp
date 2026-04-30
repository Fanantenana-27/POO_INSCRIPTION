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
//#include "fonction.h"

Inscription::Inscription(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Inscription),Modif(new Modification)
{
    ui->setupUi(this);
    connect(ui->inscrire,SIGNAL(clicked()),this,SLOT(inscrire()));
    lister("liste.txt");

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

    std::cout << "Pos actuelle : " << position_actuelle << "Item : " << item->text().toStdString() << std::endl;
    Modif->set_position(position_actuelle);
    Modif->show();
    std::cout << "FIN DE MODIFICATION" << std::endl;
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




Inscription::~Inscription()
{
    delete ui;
}
