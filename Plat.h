/*
* Date : 25 février 2019
* Auteur : AbdeB
*/

#ifndef PLAT_H
#define PLAT_H

#include "LectureFichierEnSections.h"
#include <string>
#include <string_view>
#include <iostream>
#include "def.h"
using std::string, std::string_view, std::ostream;  //? On ne devrait normalement pas faire de "using" global dans un .h, mais c'est accepte en INF1010.

class Plat {
public:
	// constructeur
	Plat(string_view nom = "inconnu", double prix = 0, double cout = 0);
         ~Plat();
	//getters 
	virtual string getNom() const;
	virtual double getPrix() const;
	virtual double getCout() const;

	//setters 
	void setNom(string nom);
	void setPrix(double prix);

	//methodes en plus
        double getPrixRevient();
        Plat *  clone () const; // TODO DONE :)
	bool operator < (const Plat& plat) const;
        void afficherPlat(ostream& os) const; // TODO DONE :)


protected:
	string nom_;
	double prix_;
	double cout_;
};

#endif // !PLAT_H
