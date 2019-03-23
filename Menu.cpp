/*
* Date : 25 février 2019
* Auteur : AbdeB
*/

#include "Menu.h"
#include "LectureFichierEnSections.h"
#include <cassert>  //? Contient "assert" qui permet de s'assurer qu'une expression est vraie, et terminer le programme avec un message d'erreur en cas contraire.
using namespace std;

// Constructeurs.

Menu::Menu() :
	type_{TypeMenu::Matin}
{
}

Menu::Menu(string fichier, TypeMenu type) :
	type_{type}
{
	lireMenu(fichier); 
}

Menu::~Menu()
{
	//TODO
	for (int i = listePlats_.size() - 1; i > -1 ; i--) {
		delete listePlats_[i];
		listePlats_.pop_back();
	}
	for (int i = listePlatsVege_.size() - 1; i > -1 ; i--) {
		delete listePlatsVege_[i];
		listePlatsVege_.pop_back();
	}
}

Plat* Menu::allouerPlat(Plat* plat) const {
    return plat->clone();
}


Menu::Menu(const Menu & menu) : type_(menu.type_), listePlats_(menu.listePlats_), listePlatsVege_(menu.listePlatsVege_)
{
}

Menu & Menu::operator=(const Menu & menu)
{
	for (int i = listePlats_.size() - 1; i > -1; i--) {
		delete listePlats_[i];
		listePlats_.pop_back();
	}
	for (int i = 0; i < menu.listePlats_.size(); i++)
		listePlats_.push_back(menu.allouerPlat(menu.listePlats_[i]));
	for (int i = listePlatsVege_.size() - 1; i > -1; i--) {
		delete listePlatsVege_[i];
		listePlatsVege_.pop_back();
	}
	for (int i = 0; i < menu.listePlatsVege_.size(); i++) {
		listePlatsVege_.push_back(dynamic_cast<owner<Vege*>>(menu.allouerPlat(dynamic_cast<Plat*>(menu.listePlatsVege_[i]))));
	}
	return *this;

}

// Getters.

vector<Plat*> Menu::getListePlats() const
{
	return listePlats_;
}

// Autres methodes.

Menu& Menu::operator+=(owner<Plat*> plat) {
	listePlats_.push_back(plat);
	if (dynamic_cast<owner<Vege*>>(plat) != nullptr) {
		listePlatsVege_.push_back(dynamic_cast<owner<Vege*>>(plat));
	}
	return *this;
}

void Menu::lireMenu(const string& nomFichier) {
	LectureFichierEnSections fichier{nomFichier};
	fichier.allerASection(entetesDesTypesDeMenu[static_cast<int>(type_)]);
	while (!fichier.estFinSection())
		*this += lirePlatDe(fichier);
}

Plat* Menu::trouverPlatMoinsCher() const
{
	assert(!listePlats_.empty() && "La liste de plats de doit pas etre vide pour trouver le plat le moins cher.");
	Plat* minimum = listePlats_[0];
	for (Plat* plat : listePlats_)
		if (*plat < *minimum)
			minimum = plat;

	return minimum;
}

Plat* Menu::trouverPlat(string_view nom) const
{
	for (Plat* plat : listePlats_)
		if (plat->getNom() == nom)
			return plat; 

	return nullptr; 
}
Plat* Menu::lirePlatDe(LectureFichierEnSections& fichier)
{
    auto lectureLigne = fichier.lecteurDeLigne();
    
    string nom, typeStr;
    TypePlat type;
    double prix, coutDeRevient;
    lectureLigne >> nom >> typeStr >> prix >> coutDeRevient;
    type = TypePlat(stoi(typeStr));
    double ecotaxe, vitamines, proteines, mineraux;
    switch (type) {
        case TypePlat::Bio :
            lectureLigne >> ecotaxe;
            return new PlatBio{ nom, prix, coutDeRevient, ecotaxe };
        case TypePlat::BioVege:
            lectureLigne >> ecotaxe >> vitamines >> proteines >> mineraux;
            return new PlatBioVege(nom, prix, coutDeRevient, ecotaxe, vitamines, proteines, mineraux);
        case TypePlat::Vege:
            lectureLigne >> vitamines >> proteines >> mineraux;
            return new PlatVege(nom, prix, coutDeRevient, vitamines, proteines, mineraux);
        default:
            return new Plat{nom, prix, coutDeRevient};
    }
    
}

// Fonctions globales.

ostream& operator<<(ostream& os, const Menu& menu){   
	for (int i = 0; i < menu.listePlats_.size(); i++) 
		menu.listePlats_[i]->afficherPlat(os);
	os << endl << "MENU ENTIEREMENT VEGETARIEN" << endl;
	for (int i = 0; i < menu.listePlatsVege_.size(); i++)
		dynamic_cast<Plat*>(menu.listePlatsVege_[i])->afficherPlat(os);
	return os;
}

