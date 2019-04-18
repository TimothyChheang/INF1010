/*
* Date : 3 avril 2019
* Auteur : Pierre-Olivier Côté
*/
#include "Filtre.h"


Filtre::Filtre(Menu* Menu):menu_(Menu), typeMenu_(TypeMenu::Matin), isVegeOption_(false), isBioOption_(false)
{

}

QStringList Filtre::getNomPlatsFiltres()
{
    map<QString, Plat*> menu = menu_->getMenu(typeMenu_);
	filtrerPlats(menu);

    QStringList nomPlats;
    for(auto it = menu.begin(); it != menu.end(); it++){
        nomPlats += QString(it->first);
    }
    return nomPlats;
}

void Filtre::filtrerPlats(map<QString, Plat*>& plats) {
	//IMPLEMENTER
	for (auto it = plats.begin(); it != plats.end();) {
        if ((isVegeOption_ && !it->second->isVege()) || (isBioOption_ && !it->second->isBio()) )
			it = plats.erase(it);
		else
			it++;
	};
}


void Filtre::clicOptionVege() {
	isVegeOption_ = !isVegeOption_;
    emit choixFiltrageModifie();
}
void Filtre::clicOptionBio() {
	isBioOption_ = !isBioOption_;
    emit choixFiltrageModifie();
}
void Filtre::choixTypeMenu(TypeMenu typeMenu) {
	typeMenu_ = typeMenu;
    emit choixFiltrageModifie();
}
