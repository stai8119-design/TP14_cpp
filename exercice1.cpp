#include <iostream>
#include <stdexcept>

using namespace std;
double diviser(int a, int b) {
    if (b == 0) {
        throw runtime_error("Erreur : Division par zero impossible");
    }
    return (double)a / b;
}

int main() {
    try {
        cout << "Test 1 : 10 / 2 = " << diviser(10, 2) << endl;
        cout << "Test 2 : 7 / 3 = " << diviser(7, 3) << endl;
        cout << "Test 3 : 5 / 0 = " << diviser(5, 0) << endl;
        cout << "C'est une ligne qui ne va pas s'afficher." << endl;
    } 
    catch (const exception& e) {
        cout << "Exception interceptee --> " << e.what() << endl;
    }
    cout << "Fin du programme." << endl;
    
    return 0;
}