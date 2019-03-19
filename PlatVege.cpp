/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#include "PlatVege.h"


//TODO
PlatVege::PlatVege(string nom, double prix, double cout,
                   double vitamines, double proteines, double mineraux)
{
    //TODO
}
PlatVege::~ PlatVege(){}

Plat* PlatVege::clone()const
{ //TODO
    
}


void PlatVege::afficherPlat(ostream & os) const
{   //TODO
	os << "PLAT VEGE " << nom_ << " vitamines" << vitamines_ << " proteines " << proteines_ << " mineraux " << mineraux_ << endl;
	os << "(Apport nutritif " << calculerApportNutritif() << " )" << endl;
}

double PlatVege::calculerApportNutritif() const
{

    //TODO
	return (vitamines_*proteines_ / mineraux_)*RAPPORT_NUTRITIF;
}
