/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#include "ClientPrestige.h"
#include "Restaurant.h"

ClientPrestige::ClientPrestige()
{
	adresse_ = ZoneHabitation::Zone3;
}

ClientPrestige::ClientPrestige(string_view nom, string_view prenom, int tailleGroupe, int nbPoints, ZoneHabitation adresse) : ClientRegulier(nom,prenom,tailleGroupe,nbPoints), adresse_(adresse)
{
   
}

ZoneHabitation ClientPrestige::getAdresseCode() const
{
	return adresse_;
}

void ClientPrestige::afficherClient(ostream & os) const
{
	ClientRegulier::afficherClient(os);
	
}
string ClientPrestige::getAdressCodeString() const
{
	string zone;
	switch (adresse_)
	{
	case ZoneHabitation::Zone1:
		zone = "Zone 1";
		break;
	case  ZoneHabitation::Zone2:
		zone = " Zone 2";
		break;
	case  ZoneHabitation::Zone3:
		zone = "Zone 3";
		break;

	default:
		zone = "erreur zone";
		break;
	}
	return zone;
}
double ClientPrestige :: getReduction(const Restaurant & res, double montant , bool estLivraison)  // A REVOIR
{   
	
	if (nbPoints_ > SEUIL_DEBUT_REDUCTION && nbPoints_< SEUIL_LIVRAISON_GRATUITE)
		return (-montant * TAUX_REDUC_PRESTIGE + res.getFraisLivraison(getAdresseCode())); 
	else if (nbPoints_ > SEUIL_DEBUT_REDUCTION && nbPoints_ > SEUIL_LIVRAISON_GRATUITE)
		return (-montant * TAUX_REDUC_PRESTIGE);
	else return 0;
	
	
}
