#include <iostream>
#include <string>
using namespace std;

// 1. Définition de la classe CompteBancaire avec encapsulation (1.5 pt)
class CompteBancaire {
private:
    string idCompte;      // identifiant du compte
    string nomProprietaire; // nom du propriétaire
    double solde;          // montant disponible

public:
    // 2. Constructeur paramétré (1 pt)
    CompteBancaire(string id, string nom, double soldeInitial) {
        idCompte = id;
        nomProprietaire = nom;
        solde = soldeInitial;
    }

    // 3. Méthodes (3 pts)
    // Deposer : ajoute un montant positif au solde
    void deposer(double montant) {
        if (montant > 0) {
            solde += montant;
        } else {
            cout << "Le montant à deposer doit etre positif." << endl;
        }
    }

    // Retirer : effectue un retrait si le montant est positif et le solde suffisant
    void retirer(double montant) {
        if (montant > 0 && montant <= solde) {
            solde -= montant;
        } else {
            cout << "Retrait impossible (solde insuffisant ou montant invalide)." << endl;
        }
    }

    // Afficher : affiche les informations du compte
    void afficher() const {
        cout << "ID Compte: " << idCompte 
             << " | Proprietaire: " << nomProprietaire 
             << " | Solde: " << solde << " DH" << endl;
    }
};

// 4. Programme principal (1.5 pt)
int main() {
    CompteBancaire c1("C101", "Alice", 1000.0);
    CompteBancaire c2("C102", "Bob", 500.0);

    c1.deposer(200.0);
    c2.retirer(100.0);

    cout << "--- État des comptes ---" << endl;
    c1.afficher();
    c2.afficher();

    return 0;
}