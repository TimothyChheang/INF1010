/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#include "PlatVege.h"


//TODO
PlatVege::PlatVege(string nom, double prix, double cout,
                   double vitamines, double proteines, double mineraux) : Plat(nom, prix, cout), Vege(nom, vitamines, proteines, mineraux)
{
}
PlatVege::~ PlatVege(){}

Plat* PlatVege::clone()const
{ 
	return new PlatVege(*this);
}

double PlatVege::getTaxe() const {
	return 0.07;
}

void PlatVege::setTaxe(){}


void PlatVege::afficherPlat(ostream & os) const
{   //TODO DONE :)
	Plat::afficherPlat(os);
	afficherVege(os);
	os << "(Apport nutritif  " << calculerApportNutritif() << "mg)" << endl;
}

double PlatVege::calculerApportNutritif() const
{

    //TODO
	return (vitamines_*proteines_ / mineraux_)*RAPPORT_NUTRITIF;
}
