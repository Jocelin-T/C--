#include <iostream> // Permet d'afficher ET prendre des données dans la console
#include <string> // Permet d'utiliser le type "string"


// #################################### Namespace ####################################
// The same variable name can be create multiple time, as long as she is in a different namespace

// using namespace std;    // Utilisation à éviter!! Elle permet d'utiliser toute la librairie std
// using std::cout;        // Mais plutôt comme ça afin de limiter
// using std::string;      // le nombre d'utilisation de la librairie std

namespace first{
    int x = 1;
}
namespace second{
    int x = 2;
}

int main(){

    int x = 0;
    std::cout << x << "\n"; // If there is no precision the var is the local one who gonna be used
    std::cout << first::x << "\n"; // Else, the namespace need to be before the variable
    using namespace second; // or this line can be declare for using this namespace, 
    std::cout << x << "\n"; //but wont work here because "x" is declared localy

    return 0;
}