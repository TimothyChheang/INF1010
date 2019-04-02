#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <string_view>
#include <iostream>
#include "Table.h"
//#include "Restaurant.h"
#include "def.h"
using std::string, std::string_view, std::ostream;  //? On ne devrait normalement pas faire de "using" global dans un .h, mais c'est accepte en INF1010.

class Restaurant;
class Table;
class Client
{
public:
	Client();
	Client(string_view nom, string_view prenom, int tailleGroupe);
	~Client() ;
	//getters
	virtual int getTailleGroupe() const;
	virtual string getNom() const;
	virtual string getPrenom() const;
    virtual Table * getTable()const;
    // setters
    void setTable(Table * ta);
	//affichage
    virtual int getNbPoints() const = 0;
    virtual void afficherClient(ostream & os) const = 0; // TODO
    virtual double getReduction(const Restaurant & res, double montant, bool estLivraison) = 0 ;

protected:
	string nom_;
	string prenom_;
	int tailleGroupe_;
    Table * tableOccupee_;
};
#endif

