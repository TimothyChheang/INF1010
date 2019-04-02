/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#include "ClientRegulier.h"

ClientRegulier::ClientRegulier() 
{
	nbPoints_ = 0;
}

ClientRegulier::~ClientRegulier() {
	
}

ClientRegulier::ClientRegulier(string_view nom, string_view prenom, int tailleGroupe, int nbpoints) : Client(nom, prenom, tailleGroupe), nbPoints_(nbpoints)
{ 
}


int ClientRegulier::getNbPoints() const
{
	return nbPoints_;
}


void ClientRegulier::augmenterNbPoints(int bonus)
{
	nbPoints_ += bonus;
}


void ClientRegulier::afficherClient(ostream & os) const
{
	Client::afficherClient(os);
	os << "Le client  a accumule : " << nbPoints_;
}

double ClientRegulier::getReduction(const Restaurant & res, double montant, bool estLivraison)
{
	if (nbPoints_ > SEUIL_DEBUT_REDUCTION)
		return (-montant * TAUX_REDUC_REGULIER);
	else return 0;
}
