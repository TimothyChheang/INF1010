#include "Foncteur.h"

FoncteurPlatMoinsCher::FoncteurPlatMoinsCher(Plat* plat){
	plat_ = new Plat(*plat);
}

bool FoncteurPlatMoinsCher::operator()(Plat* plat) {
	return (plat->getPrix > this->plat_->getPrix);
}