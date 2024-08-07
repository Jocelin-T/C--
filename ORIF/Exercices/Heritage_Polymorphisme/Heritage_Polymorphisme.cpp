// Import
#include <iostream> // Permet d'utiliser la console
#include <string> // Permet d'utiliser le type "string"
#include <math.h> // Permet d'utiliser "pow" (puissance)
#include <vector> // Permet d'utiliser "override"


using namespace std;

////////////////////////// Classe Parent //////////////////////////
class Shape{
    public:
    double base;
    double side;
    double height;
    double radius;

    double resultatPerimetre;
    double resultatAire;

    virtual double calculePerimetre(){
        resultatPerimetre = (base + side) * 2;
        return resultatPerimetre; 
    }
    virtual double calculeAire(){
        resultatAire = base * side;
        return resultatAire;
    }

    // Demande à l'utilisateur les mesures nécessaires au calcule de la forme
    void numberChooseByUserBase(){
        cout << "Combien mesure la base: ";
        cin >> base;
        cout << "----------------------------------------------------------" << endl;
    }
    void numberChooseByUserSide(){
        cout << "Combien mesure le côté: ";
        cin >> side;
        cout << "----------------------------------------------------------" << endl;
    }
    void numberChooseByUserHeight(){
        cout << "Combien mesure la hauteur: ";
        cin >> height;
        cout << "----------------------------------------------------------" << endl;
    }
    void numberChooseByUserRadius(){
        cout << "Combien mesure le rayon: ";
        cin >> radius;
        cout << "----------------------------------------------------------" << endl;
    }
        

    void afficherResultat(string shape){
        cout << "----------------------------------------------------------" << endl;
        cout << "Résultat périmètre du " << shape << ": " << calculePerimetre() << endl;
        cout << " " << endl;
        cout << "Résultat de la surface du " << shape << ": " << calculeAire() << endl;
    }

};

// Classe enfant
////////////////////////// Rectangle //////////////////////////
class Rectangle : public Shape{
    public:
    void shapeMath(){
        numberChooseByUserBase();
        numberChooseByUserSide();
        afficherResultat("rectangle");
    }
};

////////////////////////// Triangle //////////////////////////
class Triangle : public Shape{
    public:
    double calculePerimetre() override{
        resultatPerimetre = base + (side * 2);
        return resultatPerimetre;
    }
    double calculeAire() override{
        resultatAire = (base * height) / 2;
        return resultatAire;
    }

    void shapeMath(){
        numberChooseByUserBase();
        numberChooseByUserSide();
        numberChooseByUserHeight();
        afficherResultat("triangle");
    }
};

////////////////////////// Cercle //////////////////////////
class Circle : public Shape{
    public:
    double calculePerimetre() override{
        resultatPerimetre = 2 * 3.14 * radius;
        return resultatPerimetre; 
    }
    double calculeAire() override{
        resultatAire = 3.14 * pow(radius, 2);
        return resultatAire;
    }

    void shapeMath(){
        numberChooseByUserRadius();
        afficherResultat("cercle");
    }
};

// Fonction qui demande quelle forme l'utilisateur veut calculer
void userShapeChoice() {
    int choiceUser;

    cout << "Entrez (1) pour un rectangle" << endl;
    cout << "Entrez (2) pour un triangle" << endl;
    cout << "Entrez (3) pour un cercle" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "Quelle forme voulez vous calculer: ";

    cin >> choiceUser;
    cout << "Clear!\033c"; // Console Clear

    // Switch qui crée l'instance de la forme choisie
    switch(choiceUser){
        case 1:{
            Rectangle rectangle;
            rectangle.shapeMath();
            break;
        }
        case 2:{
            Triangle triangle;
            triangle.shapeMath();
            break;
        }
        case 3:{
            Circle circle;
            circle.shapeMath();
            break;
        }
        default:{
            cout << "----------------------------------------------------------" << endl;
            cout << "ERROR: La valeur choisie (" << choiceUser << ") ne fait pas parti des possibilitées" << endl;
            cout << "----------------------------------------------------------" << endl;
            userShapeChoice();
            break;
        }
    }
}


////////////////////////// Fonction Main //////////////////////////
int main() {
    bool relance = true;

    while(relance){
        char reponseRelance = ' ';
        cout << "Clear!\033c"; // clear Console

        userShapeChoice();

        // Boucle de relance
        cout << "___________________________________________________________" << endl;
        cout << "Entrez (n) si vous ne voulez stopper le programme: ";
        cin >> reponseRelance;
        if(reponseRelance == 'n' or reponseRelance == 'N'){
            relance = false;
        }
    }
    cout << "Clear!\033c"; // clear Console
    return 0;
}