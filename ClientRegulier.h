/*
* Date : 25 fevrier 2019
* Auteur : AbdeB
*/
#ifndef CLIENT_REG
#define CLIENT_REG
#include "Client.h"
#include "Restaurant.h"
#include "def.h"
class Restaurant;

class ClientRegulier : public Client
{
 public:
	ClientRegulier();
	ClientRegulier(string_view nom, string_view prenom, int tailleGroupe, int nbPoints);// TODO
    ~ClientRegulier();
	//Accesseurs
    virtual int getNbPoints() const ;

	//Autres Methodes
	void augmenterNbPoints(int bonus);
    void afficherClient(ostream & os) const; // TODO
    double getReduction(const Restaurant & res, double montant , bool estLivraison);// TODO
//
protected:
	int nbPoints_;
};
#endif
