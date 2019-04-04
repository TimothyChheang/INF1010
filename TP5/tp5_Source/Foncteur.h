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
		
		bool operator()(Plat* plat1, Plat* plat2) { return plat1->getPrix() < plat2->getPrix(); }




	private:
		



    
};

class FoncteurIntervalle
{
	public:
		FoncteurIntervalle(int max, int min) : max_(max), min_(min) {}
		bool operator()(Plat* plat){ return (plat->getPrix >= min_ && plat->getPrix <= max_); }


	private:
		int max_, min_;
};

