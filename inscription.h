#ifndef INSCRIPTION_H
#define INSCRIPTION_H

#include <QMainWindow>
#include <vector>
#include "personne.h"
#include "modification.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Inscription;
}
QT_END_NAMESPACE

class Inscription : public QMainWindow
{
    Q_OBJECT

public:
    Inscription(QWidget *parent = nullptr);
    ~Inscription();
public slots:
    void inscrire();
    //void desabonne();
    void modifier();
    //void recherche();
    void lister(std::string fichier);
private:
    Ui::Inscription *ui;
    std::vector<Personne> P;
    Modification *Modif;
};
#endif // INSCRIPTION_H
