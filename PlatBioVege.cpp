/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#include "PlatBioVege.h"

PlatBioVege::PlatBioVege(string nom, double prix, double cout, double ecotaxe, double vitamines, double proteines, double mineraux)
{

}

//PlatBioVege::PlatBioVege(string nom, double prix, double cout, double ecotaxe, double vitamines, double proteines, double mineraux), PlatBio()
//{
//	
//}

PlatBioVege:: ~PlatBioVege(){}

//TODO
void PlatBioVege::afficherPlat(ostream & os) const
{  
	os << "PLAT VEGE " << nom_ << "vitamines " << vitamines_ << " proteines " << proteines_ << " mineraux " << mineraux_ << endl;
	os << "(Apport nutritif " << calculerApportNutritif() << " )" << endl;
}

Plat * PlatBioVege::clone() const
{ 
	return new PlatBioVege(nom_, prix_, cout_, ecoTaxe_, vitamines_, proteines_, mineraux_);
}

double PlatBioVege::calculerApportNutritif() const
{
	return (vitamines_*proteines_ / mineraux_)*RAPPORT_NUTRITIF_BIO*AVANTAGE_SANS_PESTICIDE;
}
