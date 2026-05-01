#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>

class Personne
{
private:
    std::string nom;
    std::string password;
public:
    Personne();
    void setNom(std::string name);
    std::string getNom();
    void setPassword(std::string mdp);
    std::string getPassword();
    bool operator == (Personne P);
    Personne operator = (Personne& P);
    ~Personne();
};

#endif // PERSONNE_H
