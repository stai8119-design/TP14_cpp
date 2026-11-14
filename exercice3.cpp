#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;
void lireFichier(string nomFichier) {
    ifstream fichier(nomFichier);
    if (!fichier.is_open()) {
        throw runtime_error("Erreur: Impossible d'ouvrir le fichier '" + nomFichier + "' ! Il est introuvable.");
    }

    string ligne;
    cout << "Contenu du fichier " << nomFichier << "" << endl;
    while (getline(fichier, ligne)) {
        cout << ligne << endl;
    }
    fichier.close();
}

int main() {
    try {
        cout << "Tentative d'ouverture d'un fichier inexistant :" << endl;
        lireFichier("inexistant.txt");
    } 
    catch (const exception& e) {
        cout << e.what() << endl;
    }
    try {
        cout << "Tentative d'ouverture d'un fichier existant :" << endl;
        lireFichier("test.txt");
    } 
    catch (const exception& e) {
        cout << e.what() << endl;
    }
    cout << "\nFin du programme." << endl;
    return 0;
}