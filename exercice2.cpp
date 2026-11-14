#include <iostream>
#include <string>
#include <exception>

using namespace std;
class StockInsuffisantException : public exception {
private:
    string message;
public:
    StockInsuffisantException(string msg) {
        this->message = msg;
    }
    const char* what() const noexcept override {
        return message.c_str();
    }
};
class Produit {
private:
    string nom;
    int stock;

public:
    Produit(string nom, int stock) {
        this->nom = nom;
        this->stock = stock;
    }
    void vendre(int quantite) {
        if (quantite > stock) {
            throw StockInsuffisantException("Erreur : Quantite demandee superieure au stock disponible");
        }
        stock = stock - quantite;
        cout << "Vente reussie ! Stock restant : " << stock << endl;
    }

    int getStock() {
        return stock;
    }
};
int main() {
    Produit p1("PC Portable", 5);

    try {
        cout << "Test1 : Vente valide" << endl;
        p1.vendre(2);

        cout << "\nTest2 : Vente invalide" << endl;
        p1.vendre(10);

        cout << "Cette ligne ne va pas s'afficher." << endl;
    } 
    catch (const StockInsuffisantException& e) {
        cout << "Exception interceptee --> " << e.what() << endl;
    }

    cout << "\nFin du programme." << endl;
    return 0;
}