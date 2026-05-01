#include "personne.h"
#include <string>

Personne::Personne(){}



void Personne::setNom(std::string name)
{
    nom=name;
}

std::string Personne::getNom()
{
    return(nom);
}

void Personne::setPassword(std::string mdp)
{
    password=mdp;
}

std::string Personne::getPassword()
{
    return(password);
}
bool Personne::operator == (Personne  P)
{
    return(nom==P.nom && password==P.password);
}

Personne Personne::operator =(Personne& P)
{
    if(&P != this)
    {
        nom=P.nom;
        password=P.password;
    }
    return(*this);
}

Personne::~Personne(){}
