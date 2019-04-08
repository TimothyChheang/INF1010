/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#pragma once

#include <algorithm>
#include "Foncteur.h"


using namespace  std;

//              T   = pair<string, Plat*> ou Table*; 
//              C   = map<string, Plat*> ou set<Table*>; 
template<typename T, typename C>
class GestionnaireGenerique
{
	public:

	//Methode qui nous permet de prendre le conteneur  OUT : C
	C getConteneur() const{ return conteneur_; }


	// Methode qui permet d'ajouter un element de pair<string,Plat*> ou Table* dans le conteneur_ IN : T
	void ajouter(T t) { conteneur_.insert(t); }

	// Methode qui permet de prendre la taille de notre conteneur OUT :int
	int getNombreElements() const { return conteneur_.size(); }

	protected:
	C conteneur_;
};

