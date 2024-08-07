// Import
#include <iostream> // Permet d'utiliser la console
#include <string> // Permet d'utiliser le type "string"
#include <vector> // Permet d'utiliser "override"

using namespace std;

class Base{
    public:
    void message(){
        cout << "Base Class" << endl;
    }
};

// Lorsque une fonction est appelée à nouveau dans un enfant mais modifiée ->
// alors c'est la fonction enfant qui passe en priorité (Overriding)
class Derived: public Base{
    public:
    void message(){
        cout << "Derived Class" << endl;
        // Si on veut appeler la fonction parent dans l'enfant
        Base::message();
    }
};

int main(){

    // Class parent
    Base a;
    // Class enfant
    Derived b;
    
    a.message();
    b.message();

    return 0;
}