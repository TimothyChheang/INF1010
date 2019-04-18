#include "mainwindow.h"
#include "Menu.h"
#include "Filtre.h"
#include "Commande.h"
#include <QString>
#include <QApplication>
#include "erreurfichierintrouvable.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString chemin = "C:\\Users\\Symon\\Documents\\INF1010\\TP6\\fichiersFournis" ; // INSERER CHEMIN ABSOLU VERS polyFood.txt
    try {
        Menu menu = Menu(chemin+FICHIER_POLYFOOD);
        Filtre filtre(&menu);
        Commande commande;
        MainWindow mainGui(&commande, &filtre, &menu);


        //TODO
        //Connecter les mises a jour de la vue en fonction du modele (plats filtres + plats commande + prix)
        QObject::connect(&filtre, &Filtre::choixFiltrageModifie, &mainGui, &MainWindow::mettreAJourPlatsFiltres);
        QObject::connect(&commande, &Commande::commandeModifie, &mainGui, &MainWindow::mettreAJourPlatsCommande);
        QObject::connect(&commande, &Commande::commandeModifie, &mainGui, &MainWindow::mettreAJourPrix);

        mainGui.show();
        return a.exec();

    } catch (ErreurFichierIntrouvable erreur) {
        QMessageBox mbox;
        mbox.setText(erreur.what());
        mbox.show();
        return a.exec();
    }

}
