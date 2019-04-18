/*
* Date : 25 février 2019
* Auteur : AbdeB
*/

#ifndef PLAT_H
#define PLAT_H

#include "def.h"
#include "erreurplatintrouvable.h"

#include <string>
#include <string_view>
#include <iostream>
#include <QString>

using namespace std; 

class Plat {
public:
	// constructeur
    Plat(QString nom = "inconnu", double prix = 0, bool isBio = false, bool isVege = false);

	//getters 
    QString getNom() const;
	double getPrix() const;
	bool isBio() const;
	bool isVege() const;

private:
    QString nom_;
	double prix_;
	bool isBio_;
	bool isVege_;
};

#endif // !PLAT_H
