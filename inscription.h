#ifndef INSCRIPTION_H
#define INSCRIPTION_H

#include <QMainWindow>
#include <vector>
#include "personne.h"
#include "modification.h"
#include <QListWidgetItem>

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
    void desabonne(QListWidgetItem *item);
    void modifier(QListWidgetItem *item);
    //void recherche();
    void lister(std::string fichier);
    void enregistrer();
private:
    Ui::Inscription *ui;
    std::vector<Personne> P;
    Modification *Modif;
};
#endif // INSCRIPTION_H
