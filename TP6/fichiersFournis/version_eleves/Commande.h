/*
* Date : 3 avril 2019
* Auteur : Pierre-Olivier Côté
*/
#ifndef COMMANDE
#define COMMANDE

#include "Plat.h"
#include "erreurplatintrouvable.h"
#include "erreurcommandevide.h"
#include "def.h"

#include <map>
#include <string>
#include <QStringList>
#include <QObject>

using namespace std;

class Commande: public QObject {
        Q_OBJECT
public:
    Commande();
    QStringList getCommande();
    void ajouterPlat(QString nomPlat);
    void retirerPlat(QString nomPlat);
    void viderCommande();

signals:
    void commandeModifie();

private:
    QStringList commande_;
};
#endif
