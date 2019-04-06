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
{
	public:
		FoncteurPlatMoinsCher(){}
		bool operator()(pair<string, Plat*> Pair1, pair<string, Plat*> Pair2) { return Pair1.second->getPrix() < Pair2.second->getPrix(); }
	private:
};

class FoncteurIntervalle
{
	public:
		FoncteurIntervalle(int max, int min) : max_(max), min_(min) {}
		bool operator()(pair<string, Plat*> Pair){ return (Pair.second->getPrix() >= min_ && Pair.second->getPrix() <= max_); }

	private:
		int max_, min_;
};

