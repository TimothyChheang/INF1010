#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Commande.h"
#include "Filtre.h"
#include "Menu.h"
#include "def.h"
#include "erreurplatintrouvable.h"
#include "erreurcommandevide.h"

#include <QMainWindow>
#include <QAction>
#include <QComboBox>
#include <QListWidget>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QFrame>
#include <QPushButton>
#include <QLabel>
#include <QObject>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Commande* commande, Filtre* filtre, Menu* menu,QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void mettreAJourPlatsFiltres();
    void mettreAJourPlatsCommande();
    void mettreAJourPrix();

private slots:
    void clicOptionBio();
    void clicOptionVege();
    void choixTypeMenu(QString typeMenu);
    void insererPlatsChoisisDansCommande();
    void retirerPlatsChoisisDeCommande();
    void commander();

private:
    void setUI();

    void creerWidgets();
    void creerWidgetTypeMenu();
    void creerWidgetConditionsAlimentaires();
    void creerWidgetPlatsFiltres();
    void creerWidgetCommande();
    void creerWidgetBoutonsAjouterRetirer();
    void creerWidgetPrix();
    void creerWidgetCommander();

    void designLayout();

    void connecterSignauxAuxSlots();
    void message(QString erreur);

    int calculerPrixCommande();

    Commande* commande_;
    Filtre* filtre_;
    Menu* menu_;

    Ui::MainWindow *ui;
    QComboBox* widgetTypeMenu_;
    QCheckBox* widgetPlatsVeges_;
    QCheckBox* widgetPlatsBios_;
    QListWidget* widgetPlatsFiltres_;
    QListWidget* widgetCommande_;
    QPushButton* widgetAjouterPlat_;
    QPushButton* widgetRetirerPlat_;
    QLabel* widgetPrix_;
    QPushButton* widgetCommander_;
};

#endif // MAINWINDOW_H
