#ifndef DEF_H
#define DEF_H

#include "plat.h"

#include<string>
#include <QString>
#include <map>

using namespace std;
enum class TypeMenu { Matin, Midi, Soir, first_ = Matin, last_ = Soir };
const static QString MATIN = "Matin";
const static QString MIDI = "Midi";
const static QString SOIR = "Soir";

static const string entetesDesTypesDeMenu[] = { "-MATIN", "-MIDI", "-SOIR" }; // Pour le format du fichier.
const QString PRIX_STRING = "Prix: ";
const QString DOLLAR_SIGN = "$";
const QString RETIRER_PLAT = "Retirer Plat";
const QString AJOUTER_PLAT = "Ajouter Plat";
const QString COMMANDER = "Commander";
const QString VEGETARIEN = "Vegetarien";
const QString BIOLOGIQUE = "Biologique";
const QString WINDOW_TITLE = "Faire une commande";
const QString LABEL_NO_MEAL = "Erreur: Vous n'avez rien commande";
const QString LABEL_MEAL_NOT_FOUND = "Erreur: le plat n'est pas dans votre commande";
const QString LABEL_MEAL_NOT_IN_MENU = "Erreur: le plat n'est pas dans le menu";
const QString LABEL_COMMANDE_RECUE = "Commande reçue.\n Prix de votre achat: ";
const QString FICHIER_POLYFOOD = "\\polyFood.txt";

static inline TypeMenu qstringToTypeMenu(QString type){
    if(type == MATIN){
        return TypeMenu::Matin;
    } else if(type == MIDI){
        return TypeMenu::Midi;
    } else if(type == SOIR){
        return TypeMenu::Soir;
    } else {
        return TypeMenu::Matin;
    }
}

#endif
