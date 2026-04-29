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
            std::cout << "Fin\n";
            connect(modif,SIGNAL(clicked()),this,SLOT(modifier()));

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

// void Inscription::modifier()
// {
//     std::cout << "ok\n";
//     int position_actuelle,i;
//     Personne new_Personne;
//     Modification M;
//     std::string chaine;
//     std::fstream file("liste.txt",std::ios::app);
//     std::vector<Personne>::iterator it;
//     position_actuelle=ui->liste->currentRow();
//     Modif->set_oldPersonne(P[position_actuelle]);
//     Modif->show();
//     new_Personne=Modif->get_newPersonne();
//     P[position_actuelle]=new_Personne;

//     //Reinitialiser le vector P
//     if(file.is_open())
//     {
//         for (it=P.begin();it!=P.end();i++)
//         {
//             chaine=it->getNom() + ":" + it->getPassword() + "\n";
//             file << chaine;
//         }
//     }
//     lister("liste.txt");
// }

void Inscription::modifier()
{
    std::cout << "SLOT\n";
    Modif->show();
}


// void Inscription::desabonne()
// {
//     std::string ancien,chaine;
//     Personne *P1=new Personne();
//     Personne P_ancien=Personne();
//     std::cout << "Ancien nom : " ;
//     std::getline(std::cin,chaine);
//     P_ancien.setNom(ancien);
//     std::cout << "Nouvel nom : " ;
//     std::getline(std::cin,chaine);
//     P1->setNom(chaine);
//     std::cout << "Ancien mot de pass : ";
//     std::getline(std::cin,chaine);
//     P_ancien.setPassword(ancien);
//     std::cout << "Nouvel mot de pass : ";
//     std::getline(std::cin,chaine);
//     P1->setPassword(chaine);
//     for (std::vector<Personne>::iterator i=P.begin();i!=P.end();i++)
//     {
//         if(i->getNom()==P_ancien.getNom() && i->getPassword()==P_ancien.getPassword())
//         {
//             i->setNom(P1->getNom());
//             i->setPassword(P1->getPassword());
//         }
//     }
//     std::vector <Personne>::iterator trouve = std::find_if(P.begin(),P.end(),[P_ancien](Personne X){return X==P_ancien;});
//     *trouve = *P1;
// }

// void Inscription::lister()
// {
//     std::cout << "LISTE DES INSCRITS" << std::endl;
//     for (std::vector <Personne>::iterator i=P.begin() ; i!=P.end() ; i++ )
//     {
//         std::cout << i->getNom() << std::endl;
//     }
// }


Inscription::~Inscription()
{
    delete ui;
}
