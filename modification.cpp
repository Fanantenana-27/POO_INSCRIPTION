#include "modification.h"
#include "ui_modification.h"
#include <fstream>

Modification::Modification(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Modification)
{
    ui->setupUi(this);

    connect(ui->modifier,SIGNAL(clicked()),this,SLOT(modifier()));
}

void Modification::set_newPersonne(Personne *P)
{
    newPersonne->setNom(P->getNom());
    newPersonne->setPassword(P->getPassword());
}

Personne& Modification::get_newPersonne()
{
    return(*newPersonne);
}

void Modification::set_oldPersonne(Personne& P)
{
    oldPersonne->setNom(P.getNom());
    oldPersonne->setPassword(P.getPassword());
}

Personne& Modification::get_oldPersonne()
{
    return(*oldPersonne);
}

void Modification::modifier()
{
    QString name , pass,chaine;
    //ui->nom->setText(QString::fromStdString(oldPersonne->getNom()));
    //ui->passwd->setText(QString::fromStdString(oldPersonne->getPassword()));
    name=ui->nom->text();
    pass=ui->passwd->text();
    std::string ligne;
    std::ofstream flux ("tmp.txt");
    chaine= name + ":" + pass + "\n";
    if(flux.is_open())
    {
        flux << chaine.toStdString();
    }
    flux.close();
    // newPersonne->setNom(name.toStdString());
    // newPersonne->setPassword(pass.toStdString());
    std::ifstream f("tmp.txt");
    if(f.is_open())
    {
        std::getline(f,ligne);
    }
    std::cout << "Ligne : " <<  ligne  << std::endl;
    this->close();
}

Modification::~Modification()
{
    delete ui;
}
