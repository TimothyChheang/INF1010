/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#include "PlatBio.h"

PlatBio::PlatBio(string nom, double prix, double cout, double ecotaxe): Plat(nom, prix, cout), ecoTaxe_(ecotaxe)
{
}


PlatBio::~ PlatBio(){}

double PlatBio::getEcoTaxe() const
{
	return ecoTaxe_;
}

void PlatBio::setEcoTaxe(double ecoTaxe)
{
	ecoTaxe_ = ecoTaxe;
}

//TODO
Plat * PlatBio:: clone () const
{
	Plat::clone();
	return new Plat(ecoTaxe_);
}
double PlatBio:: getPrixDeRevient()
{ 
	//TODO
	double prixderevient = prix_ - cout_ + ecoTaxe_;
	return prixderevient;
}

void PlatBio::afficherPlat(ostream& os) const
{
    //TODO
	os << "PLAT BIO  comprend une taxe ecologique de " << ecoTaxe_ << "$" << endl;

}
