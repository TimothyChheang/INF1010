/********************************************
* Titre: Travail pratique #5 - Foncteur.h
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#pragma once

#include <algorithm>
#include "Plat.h"

using namespace std;


class FoncteurPlatMoinsCher
{ // TODO
	public:
		FoncteurPlatMoinsCher(Plat* plat);
		bool operator()(Plat* plat);




	private:

		Plat* plat_;



    
};

class FoncteurIntervalle
{
	public:
		FoncteurIntervalle(int max, int min);
		bool operator()(Plat* plat);


	private:
		int max_, min_;
};

