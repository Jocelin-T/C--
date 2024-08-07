
#include <iostream> // Permet d'afficher ET prendre des données dans la console
#include <math.h> // Permet d'utiliser l'operation "pow"
#include <string> // Permet d'utiliser le type "string"

// Permet d'utiliser plus simplement la librarie standard
//  dans le cas où le fichier/librairie ne fait pas partit des imports, 
//  il faut faire: "std::cout"
using namespace std;    // Utilisation à éviter!!
using std::cout;        // Mais plutôt comme ça afin de limiter
using std::string;      // le nombre d'utilisation de la librairie

// Prototype d'une fonction, obligatoire si après la fonction "main"
void maFonction();

int main() {
    // #################################### Console ####################################
    // "cout" (Character OUTput) permet d'afficher qqch dans la console
    // "<<" (output operateur) permet de dire que Hello World est "envoyé" dans "cout", donc d'être affiché
    // "endl" (end line) permet de faire un retour à la ligne, possible de faire "\n"
    cout << "Hello World !" << endl; 
    // Possible d'ajouter après un << une autre string à afficher dans la console
    cout << "Hello world" << endl << "Une autre ligne";

    // #################################### Variable ####################################
    // Il faut déclarer le type de variable
    // Nombre = int, float, double
    // Boolean = bool
    // Character = char
    int var_int = 10;
    float var_float = 10.12345f; // 7 chiffres max après la décimale, ne pas oublier d'ajouter un "f" après (Le compiler arrondit)
    double variableDouble = 10.987654321; // 15 chiffres max après la décimale (Le compiler arrondit)
    bool variableBool = false; // retourne 0 ou 1
    char variableChar = 'A'; // char permet d'afficher qu'un seul charactère et doit être entre ''
    string variableString = "Mon Nom";
    auto variableAuto = 10.102; // Possible d'utiliser "auto", mais à éviter pour des programmes simple

    cout << var_int << endl 
        << var_float << endl 
        << variableDouble << endl 
        << variableBool << endl 
        << variableChar << endl 
        << variableString << endl 
        << variableAuto << endl;

    // #################################### Vérifier le type de Variable ####################################
    int age = 26;
    float price = 25.10f;

    cout << typeid(age).name() << endl; // return(i)
    cout << typeid(price).name() << endl; // return(f)

    // #################################### Conversion de type de Variable ####################################
    // Si le type n'est pas donné le compiler va essayer de convertir du mieux qu'il peut:
    // float/double -> int, retire les nombres décimaux
    // int -> float/double, ajoute un ".0" à la fin
    int intToFloat = 26.5f; // (26)
    float floatToInt = 25; // (25) car le compiler n'affiche pas le ".0" dans la console

    cout << intToFloat << endl << floatToInt << endl;

    // bool -> number, si ce N'EST PAS "0", il renvoye true (donc 1)
    // number -> bool, true = 1 / false = 0
    bool boolToInt = 10; // (1)
    int intToBool = false; // (0)

    cout << boolToInt << endl << intToBool << endl;

    // Convertit l'un ou l'autre en ASCII
    char charToInt = 65; // (A) 
    int intToChar = 'A'; // (65)

    cout << charToInt << endl << intToChar << endl;

    // Pour forcer la conversion, entrer le type entre ()
    int conversionX = 5;
    int conversionY = 2;

    float conversionZ = (float) conversionX / conversionY;
    cout << conversionZ << endl;

    // #################################### Multiple type de Varaible en 1 ligne ####################################
    // Séparer les variables du même type avec une ","
    int x, y, z;
    x = 10;
    y = 15;
    z = 20;

    cout << "x: " << x << " y: " << y << " z: " << z << endl;

    // #################################### Operateur ####################################
    int operateurX = 5;
    int operateurY = 2;

    cout << operateurX + operateurY << endl; // (7)
    cout << operateurX - operateurY << endl; // (3)
    cout << operateurX * operateurY << endl; // (10)
    cout << operateurX / operateurY << endl; // (2) car c'est un Int donc pas de décimale

    // /!\ Les nombres à décimale, SONT PAS EXACTE
    // On ne peut pas utiliser modulo "%" avec des nombres à décimal
    cout << ((1.20 - 1.15) == 0.05) << endl; // (0) Alors que c'est juste mais en réalité ils ne correspondent pas
    double var1 = 1.20 - 1.15;

    // Operateur power(pow) == puissance
    cout << pow(5, 4) << endl; // (625), car 5*5*5*5

    // Operateur incrémentation (++) et décrémentation(--)
    int incrX = 10;
    int incrY = 10;

    // Si l'opérateur "++" est ajouté après la variable, alors c'est la seconde qui ce verra ajouté le (+1)
    cout << "Before: " << incrX++ << endl; // (10)
    cout << "After: " << incrX << endl; // (11)

    // Si l'opérateur "++" est ajouté avant la variable, alors c'est la première qui ce verra ajouté le (+1)
    cout << "Before: " << ++incrY << endl; // (11)
    cout << "After: " << incrY << endl; // (11)

    // Opérateur logique 
    // et = &&, ou = ||, pas = !

    // Opérateur de comparaison 
    // <, <=, >, >=, ==, !=

    // #################################### Condition ####################################
    int maVariable = 50;
    char maVariable2;

    if (maVariable >= 60) {
        maVariable2 = 'P';
    } else if (maVariable) {
        maVariable2 = 'F';
    } else {
        maVariable2 = 'W';
    }

    // Aussi possible comme ça:
    // maVariable2 = si maVariable au dessus ou égal à 60 (P) sinon (F)
    maVariable2 = (maVariable >= 60) ? 'P' : 'F';

    cout << maVariable2 << endl;

    // #################################### Switches ####################################
    int month;
    std::cout << "Enter the mouth (1-12): ";
    std::cin >> month;

    switch (month){
    case 1:
        std::cout << "January" << "\n";
        break;
    case 2:
        std::cout << "February" << "\n";    
        break;
    case 3:
        std::cout << "March" << "\n";
        break;
    case 4:
        std::cout << "April" << "\n";
        break;
    case 5:
        std::cout << "May" << "\n";
        break;
    case 6:
        std::cout << "June" << "\n";
        break;
    case 7:
        std::cout << "July" << "\n";
        break;
    case 8:
        std::cout << "August" << "\n";
        break;
    case 9:
        std::cout << "September" << "\n";
        break;
    case 10:
        std::cout << "October" << "\n";
        break;
    case 11:
        std::cout << "November" << "\n";
        break;
    case 12:
        std::cout << "December" << "\n";
        break;
    default:
        std::cout << "Entry need to be a number 1-12" << "\n";
        break;
    }

    // #################################### User Input ####################################
    string inputFullName;
    int inputAge;

    // cin (Character In) permet à l'utilisateur d'entrer des inputs
    cout << "Entrez votre prénom et nom: ";
    getline(std::cin >> std::ws, inputFullName); // "getline" permet de prendre l'input de toute la ligne, espace compris

    cout << "Entrez votre age: ";
    cin >> inputAge; // Attention au sens des ">>", toujours source vers target

    cout << endl << "Nom: " << inputFullName << ", Age: " << inputAge << endl; 

    // #################################### Fonction ####################################
    // Appeler une fonction, IL FAUT TOUJOURS qu'elle soit écrite au complet si elle ce trouve APRÈS la fonction "main()"
    // Ou la prototyper, ce qui veut dire la déclarer avant la fonction "main" et l'écrire après celle-ci (comme ici)
    maFonction();

    // #################################### String Method ####################################
    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin >> std::ws, name);

    // name.lenght() <=>int -> return a boolean
    // name.empty()         -> return a boolean

    // "append("string")" for adding concate string 
    name.append("@gmail.com");
    std::cout << name << "\n";

    // "at(i)" give the char at a certain index
    std::cout << name.at(2) << "\n";

    // "insert(i, "string")" at the index a certain string
    name.insert(7, "_");
    std::cout << name << "\n";

    // "find('char')" find the index of the 1st char
    std::cout << name.find('@') << "\n";

    // "erase(start_i, end_i)" erase the indexes and all index between
    name.erase(0, 2);
    std::cout << name << "\n";

    // ####################################  ####################################

    return 0;
}

// Déclarer une fonction, "void" si on attend aucun retour
void maFonction(){
    cout << "Fonction" << endl;
}