/*
* Date : 3 avril 2019
* Auteur : Pierre-Olivier Côté
*/
#include "Menu.h"


Menu::Menu(QString nomFichier)
{
	lireFichier(nomFichier);
}

Menu::~Menu() {
	supprimerPlatsDuMenu(menuMatin_);
	supprimerPlatsDuMenu(menuMidi_);
	supprimerPlatsDuMenu(menuSoir_);
}

void Menu::supprimerPlatsDuMenu(map<QString, Plat*> menu) {
	for (auto it = menu.begin(); it != menu.end(); it++)
		delete it->second;
}

map<QString, Plat*> Menu::getMenu(TypeMenu typeMenu) const
{
	switch (typeMenu)
	{
    case TypeMenu::Matin: return menuMatin_;
    case TypeMenu::Midi: return menuMidi_;
    case TypeMenu::Soir: return menuSoir_;
	default: 
        return menuMatin_;
	}
}

void Menu::ajouterPlat(TypeMenu typeMenu, Plat* plat) {
    pair<QString, Plat*> platPair = pair<QString, Plat*>(plat->getNom(), plat);

	switch (typeMenu)
	{
    case TypeMenu::Matin:
        menuMatin_.insert(platPair);
        break;
    case TypeMenu::Midi:
        menuMidi_.insert(platPair);
        break;
    case TypeMenu::Soir:
        menuSoir_.insert(platPair);
        break;
	}
}

void Menu::lireFichier(QString nomFichier)
{
    lirePlats(nomFichier, TypeMenu::Matin, menuMatin_);
    lirePlats(nomFichier, TypeMenu::Midi, menuMidi_);
    lirePlats(nomFichier, TypeMenu::Soir, menuSoir_);
}


void Menu::lirePlats(QString nomFichier, TypeMenu typeMenu, map<QString, Plat*>& menu)
{
    QFile file(nomFichier);
        if (!file.open(QIODevice::ReadOnly)) {
            throw ErreurFichierIntrouvable("Erreur: le fichier duquel on lit le menu est introuvable. Specifier un chemin absolu et bien \"escape\" les backslash du path.");
        }
        else {
            QString type;
            switch (typeMenu) {
            case TypeMenu::Matin :
                type = "-MATIN\r\n";
                break;
            case TypeMenu::Midi :
                type = "-MIDI\r\n";
                break;
            case TypeMenu::Soir :
                type = "-SOIR\r\n";
                break;
            }
            QString ligne;

            QString nom;

            QString prixString;
            double prix;

            QString isBioString;
            int isBio;

            QString isVegeString;
            int isVege;


            // lecture
            while (!file.atEnd()) {
                ligne = file.readLine();
                //trouver le bon type de menu (section)
                if (ligne == type){
                    //commencer a lire -- s'arrete si fin du fichier ou encore si on arrive a une nouvelle section du menu
                    ligne = file.readLine();
                    int curseur = 0;
                    while (ligne[0] != '-' && !file.atEnd()) {
                        //trouver le nom
                        for (int i = 0; i < int(ligne.size()); i++) {
                            if (ligne[i] == ' ') {
                                curseur = i;
                                break;
                            }
                            nom += ligne[i];
                        }
                        //trouver le prix

                        for (int i = curseur + 1; i < int(ligne.size()); i++) {
                            if (ligne[i] == ' ') {
                                curseur = i;
                                break;
                            }
                            prixString += ligne[i];

                        }
                        //passer le prixString en double --- indice dans l'enonce
                        prix = prixString.toDouble();

                        for (int i = curseur + 1; i < int(ligne.size()); i++) {
                            if (ligne[i] == ' '){
                                curseur = i;
                                break;
                            }
                            isBioString += ligne[i];
                        }

                        isBio =  bool(isBioString.toShort());

                        for (int i = curseur + 1; i < int(ligne.size()); i++) {
                            if (ligne[i] == ' '){
                                curseur = i;
                                break;
                            }
                            isVegeString += ligne[i];
                        }

                        isVege =bool(isVegeString.toShort());

                        Plat* plat = new Plat(nom, prix, isBio, isVege);
                        menu.insert(pair<QString, Plat*>(plat->getNom(), plat));
                        nom = "";
                        prixString = "";
                        isVegeString = "";
                        isBioString = "";

                        ligne = file.readLine();
                    }
                }
            }

            file.close();
        }
}

Plat* Menu::getPlat(QString nomPlat) const {
    auto it = menuMatin_.find(nomPlat);
    if(it != menuMatin_.end()){
        return it->second;
    }
    it = menuMidi_.find(nomPlat);
    if(it != menuMidi_.end()){
        return it->second;
    }
    it = menuSoir_.find(nomPlat);
    if(it != menuSoir_.end()){
        return it->second;
    }
    throw ErreurPlatIntrouvable(LABEL_MEAL_NOT_IN_MENU);
}

