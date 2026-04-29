#ifndef MODIFICATION_H
#define MODIFICATION_H

#include <QMainWindow>
#include <personne.h>

namespace Ui {
class Modification;
}

class Modification : public QMainWindow
{
    Q_OBJECT

public:
    explicit Modification(QWidget *parent = nullptr);
    void set_newPersonne(Personne *P);
    Personne& get_newPersonne();
    void set_oldPersonne(Personne& P);
    Personne& get_oldPersonne();
    ~Modification();
    
private slots:
    void modifier();
    
private:
    Personne *newPersonne;
    Personne *oldPersonne;
    Ui::Modification *ui;
};

#endif // MODIFICATION_H
