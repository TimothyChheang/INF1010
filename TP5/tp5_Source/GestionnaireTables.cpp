/********************************************
* Titre: Travail pratique #5 - gestionnaireTables.cpp
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/


#include "GestionnaireTables.h"
#include "LectureFichierEnSections.h"


void GestionnaireTables::lireTables(const string& nomFichier)
{
	LectureFichierEnSections fichier{ nomFichier };
	fichier.allerASection("-TABLES");
	while (!fichier.estFinSection()) {
		int id, nbPlaces;
		fichier >> id >> nbPlaces;
		ajouter(new Table(id, nbPlaces));
	}
}

//Methode qui permet de retourner une table dans le conteneur IN : int , OUT : Tables*
Table* GestionnaireTables::getTable(int id) const {
	auto it = conteneur_.begin();
	for (it; it != conteneur_.end(); it++) {
		if ((*it)->getId() == id) {
			return (*it);
		}
	}
	return nullptr;
}

//Methode qui permet de retouner la table ayant assez de place pour contenir le groupe IN : int , OUT Table*
Table* GestionnaireTables::getMeilleureTable(int tailleGroupe) const {
	Table* meilleureTable = nullptr;
	auto it = conteneur_.begin();
	for (it ; (*it)->getNbPlaces() < tailleGroupe ; it++) {
		if ((*it)->getNbPlaces() >= tailleGroupe && !(*it)->estOccupee()) {
			meilleureTable = (*it);
		}
	}
	while (it != conteneur_.end()) {
		if ((*it)->getNbPlaces() >= tailleGroupe && (*it)->getNbPlaces() < meilleureTable->getNbPlaces() && !(*it)->estOccupee()) {
			meilleureTable = (*it);
			it++;
		}
	}
	return meilleureTable;
	
}

// Methode d'affichage 
void GestionnaireTables::afficherTables(ostream& os) const {
	os << "Voici les Tables: " << endl;
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		os << *(*it);
	}
}

