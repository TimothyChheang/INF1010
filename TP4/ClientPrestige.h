/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#ifndef CLIENT_PRESTIGE
#define CLIENT_PRESTIGE

#include "ClientRegulier.h"

#include "def.h"
class ClientPrestige : public ClientRegulier
{
public:
	ClientPrestige();
	ClientPrestige(string_view nom, string_view prenom, int tailleGroupe, 
		           int nbPoints, ZoneHabitation adresse);// TODO
	~ClientPrestige();
	//Accesseur 
	ZoneHabitation getAdresseCode() const;

	//Autres Fonctions
    void afficherClient(ostream & os) const;// TODO
	string getAdressCodeString() const;
    double getReduction(const Restaurant & res, double montant, bool estLivraison); //TODO

private:
	ZoneHabitation adresse_;

};

#endif

