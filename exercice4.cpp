#include <iostream>
#include <string>
#include <exception>

using namespace std;
class MontantInvalideException : public exception {
private:
    string message;
public:
    MontantInvalideException(string msg) {
        this->message = msg;
    }
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class SoldeInsuffisantException : public exception {
private:
    string message;
public:
    SoldeInsuffisantException(string msg) {
        this->message = msg;
    }
    const char* what() const noexcept override {
        return message.c_str();
    }
};
class Compte {
private:
    int solde;

public:
    Compte(int soldeInitial) {
        if (soldeInitial < 0) {
            this->solde = 0;
        } else {
            this->solde = soldeInitial;
        }
    }
    void deposer(int montant) {
        if (montant < 0) {
            throw MontantInvalideException("Erreur : Le montant du depot ne peut pas etre negatif");
        }
        solde = solde + montant;
        cout << "Depot de " << montant << " effectue avec succes. Solde actuel : " << solde << endl;
    }
    void retirer(int montant) {
        if (montant < 0) {
            throw MontantInvalideException("Erreur : Le montant du retrait ne peut pas etre negatif");
        }
        if (montant > solde) {
            throw SoldeInsuffisantException("Erreur : Solde insuffisant pour effectuer ce retrait");
        }
        solde = solde - montant;
        cout << "Retrait de " << montant << " effectue avec succes. Solde actuel : " << solde << endl;
    }

    int getSolde() {
        return solde;
    }
};
int main() {
    Compte monCompte(4500);
    try {
        cout << "Test 1:" << endl;
        monCompte.deposer(750);  
        monCompte.retirer(360);   
        monCompte.deposer(-145);  
    } 
    catch (const MontantInvalideException& e) {
        cout << "Exception interceptee -> " << e.what() << endl;
    } 
    catch (const SoldeInsuffisantException& e) {
        cout << "Exception interceptee -> " << e.what() << endl;
    }
    try {
        cout << "Test 2:" << endl;
        monCompte.retirer(6700);
    }
    catch (const MontantInvalideException& e) {
        cout << "Exception interceptee -> " << e.what() << endl;
    } 
    catch (const SoldeInsuffisantException& e) {
        cout << "Exception interceptee -> " << e.what() << endl;
    }
    cout << "\nSolde final : " << monCompte.getSolde() << endl;
    return 0;
}