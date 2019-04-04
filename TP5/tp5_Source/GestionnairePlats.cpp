/********************************************
* Titre: Travail pratique #5 - gestionnairePlats.cpp
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#include "GestionnairePlats.h"
#include "LectureFichierEnSections.h"
#include "PlatBio.h"
#include "PlatVege.h"
#include "PlatBioVege.h"


GestionnairePlats::GestionnairePlats(const string& nomFichier, TypeMenu type): type_(type) {
	
	lirePlats(nomFichier,type);
}

GestionnairePlats ::~GestionnairePlats() {
	map<string, Plat*> ::const_iterator it;
	for (it = conteneur_.begin(); it != conteneur_.end(); it++) {
		delete (*it).second;
	}
}

GestionnairePlats::GestionnairePlats(GestionnairePlats* gestionnaire) {
	type_ = gestionnaire->getType();
	map<string,Plat*> :: const_iterator it;
	for (it =gestionnaire->conteneur_.begin(); it!= gestionnaire->conteneur_.end(); it++) {
		conteneur_.insert(make_pair((*it).first, allouerPlat((*it).second)));
	}
}

TypeMenu GestionnairePlats::getType() const {
	return type_;
}


Plat* GestionnairePlats::allouerPlat(Plat* plat) {
	return plat->clone();
}

Plat* GestionnairePlats::trouverPlatMoinsCher() const {

	return (min_element((*conteneur_.begin()).second, (*conteneur_.end()).second, FoncteurPlatMoinsCher()));
}

Plat* GestionnairePlats::trouverPlatPlusCher() const {
	auto p = [](Plat* plat1, Plat* plat2) {
		return (plat1->getPrix() > plat2->getPrix());
	};
	return (max_element((*conteneur_.begin()).second, (*conteneur_.end()).second, p));
}
	
Plat* GestionnairePlats::trouverPlat(const string& nom) const {
	map<string, Plat*> ::const_iterator it;
};


void GestionnairePlats::lirePlats(const string& nomFichier, TypeMenu type)
{
	LectureFichierEnSections fichier{ nomFichier };
	fichier.allerASection(entetesDesTypesDeMenu[static_cast<int>(type)]);
	while (!fichier.estFinSection())
		ajouter(lirePlatDe(fichier));
}


pair<string, Plat*> GestionnairePlats::lirePlatDe(LectureFichierEnSections& fichier)
{
	auto lectureLigne = fichier.lecteurDeLigne();
	Plat* plat;
	string nom, typeStr;
	TypePlat type;
	double prix, coutDeRevient;
	lectureLigne >> nom >> typeStr >> prix >> coutDeRevient;
	type = TypePlat(stoi(typeStr));
	double ecotaxe, vitamines, proteines, mineraux;
	switch (type) {
	case TypePlat::Bio:
		lectureLigne >> ecotaxe;
		plat = new PlatBio{ nom, prix, coutDeRevient, ecotaxe };
		break;
	case TypePlat::BioVege:
		lectureLigne >> ecotaxe >> vitamines >> proteines >> mineraux;
		plat = new PlatBioVege(nom, prix, coutDeRevient, ecotaxe, vitamines, proteines, mineraux);
		break;
	case TypePlat::Vege:
		lectureLigne >> vitamines >> proteines >> mineraux;
		plat = new PlatVege(nom, prix, coutDeRevient, vitamines, proteines, mineraux);
		break;
	default:
		plat = new Plat{ nom, prix, coutDeRevient };
	}
	return pair<string, Plat*>(plat->getNom(), plat);
}


