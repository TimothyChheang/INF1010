/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#include "Plat.h"

Plat::Plat(QString nom, double prix, bool isBio, bool isVege) : nom_(nom), prix_(prix), isBio_(isBio), isVege_(isVege)
{

}

// Getters 
QString Plat::getNom() const {
	return nom_;
}

double Plat::getPrix() const {
	return prix_;
}

bool Plat::isBio() const {
	return isBio_;
}

bool Plat::isVege() const {
	return isVege_;
}
