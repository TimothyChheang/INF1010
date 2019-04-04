#include "Foncteur.h"

FoncteurIntervalle::FoncteurIntervalle(int max, int min):max_(max), min_(min) {}

bool FoncteurIntervalle ::operator()(Plat* plat) {

	return (plat->getPrix >= min_ && plat->getPrix <= max_);
}