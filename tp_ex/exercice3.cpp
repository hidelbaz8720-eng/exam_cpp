#include <iostream>
#include <string>
using namespace std;

// 1. Classe mère Vehicule avec attributs protégés (1.5 pt)
class Vehicule {
protected:
    string immatriculation;
    string marque;
    double vitesseMax;

public:
    // 2. Constructeur paramétré (1 pt)
    Vehicule(string imm, string mrq, double vMax) 
        : immatriculation(imm), marque(mrq), vitesseMax(vMax) {}

    // Destructeur virtuel (Question 6)
    virtual ~Vehicule() {}

    // Méthode virtuelle pour le polymorphisme
    virtual void afficherDetails() const {
        cout << "Immatriculation: " << immatriculation 
             << " | Marque: " << marque 
             << " | Vitesse Max: " << vitesseMax << " km/h";
    }
};

// 3. Classes dérivées Voiture et Camion avec constructeurs (2 pts)
class Voiture : public Vehicule {
private:
    int nombrePortes;
    string typeCarburant;

public:
    Voiture(string imm, string mrq, double vMax, int portes, string carburant)
        : Vehicule(imm, mrq, vMax), nombrePortes(portes), typeCarburant(carburant) {}

    // 4. Redéfinition de la méthode virtuelle (1.5 pt)
    void afficherDetails() const override {
        Vehicule::afficherDetails();
        cout << " | Portes: " << nombrePortes 
             << " | Carburant: " << typeCarburant << endl;
    }
};

class Camion : public Vehicule {
private:
    double capaciteCharge;
    int nombreEssieux;

public:
    Camion(string imm, string mrq, double vMax, double charge, int essieux)
        : Vehicule(imm, mrq, vMax), capaciteCharge(charge), nombreEssieux(essieux) {}

    // 4. Redéfinition de la méthode virtuelle (1.5 pt)
    void afficherDetails() const override {
        Vehicule::afficherDetails();
        cout << " | Capacité: " << capaciteCharge 
             << " tonnes | Essieux: " << nombreEssieux << endl;
    }
};

// 5. Fonction main avec tableau de pointeurs et polymorphisme (1.5 pt)
int main() {
    Vehicule* garage[2];
    garage[0] = new Voiture("1234-A-1", "Toyota", 180.0, 5, "Essence");
    garage[1] = new Camion("5678-B-2", "Volvo", 120.0, 15.5, 4);

    cout << "--- Détails des véhicules ---" << endl;
    for (int i = 0; i < 2; i++) {
        garage[i]->afficherDetails(); // Appel polymorphique
    }

    // Libération de la mémoire
    for (int i = 0; i < 2; i++) {
        delete garage[i];
    }

    return 0;
}