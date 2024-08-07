#include <iostream>
#include <string>
#include <vector> // Permet le polymorphisme

using namespace std;
// Création d'une Class (Structure d'un objet)
class Person{
    private:
        // Ses attributs (Variables)    
        string first;
        string last;

    public:
        // Ses méthodes (Fonctions)
        // Accèder à un attribut private
        void setFirstName(string first){
            this->first = first;
        }
        void setLastName(string last){
        this->last = last;
        }

        // Fonction pour afficher dans la console
        void printFullName(){
            cout << first << " " << last << endl;
        }
};

// Création d'une Class en utilisant un constructor
class PersonConstructor{
    protected:
    // Ses attributs (Variables)    
    string first;
    string last;

    public:
    // Conctructor
    PersonConstructor(string first, string last){
        this->first = first;
        this->last = last;
    }
    // Autre façon de l'écrire
    // PersonConstructor(string first, string last): first(first), last(last) {}

    // Afin de ne pas avoir besoin de passer des arguments dans un constructor
    PersonConstructor() = default;

    void printInfo() {
        cout << "First Name: " << first << endl;
        cout << "Last Name: " << last << endl;
    }
    // Autre façon d'afficher dans la console
    string getName(){
        return first + " " + last;
    }
};

// Heritage
// Ajouter public à la Class, car tous ce qui est public dans la Class hérité devient private
class Employe : public PersonConstructor{ 
    // Ajouter des attributs et méthode non-herité
    string departement;

    public:
    Employe(string firstName, string lastName, string departement)
        : PersonConstructor(firstName, lastName), departement(departement){}

    string getDepartement(){
        return departement;
    }
    void setDepartement(string departement){
        this->departement = departement;
    }
    void printInfo() {
        cout << "First Name: " << first << endl;
        cout << "Last Name: " << last << endl;
        cout << "Departement: " << departement << endl;
        // Dans le cas où on veut accèder à un attribut ou méthode privé, il faut 
        // cout << "First Name:" << first << endl;
    }

    // Si on veut override certain attribut ou méthode
    // void printInfo() override {}
    // Et il faut ajouter "virtual" avant le type de l'attribut ou méthode de la Class parent
};

int main() {
    // Instance d'un autre objet
    Person p; // (Objet) ou (Instance)

        // Appel d'un attribut
        // p.age = 26;

        // Appel d'une méthode
        p.setFirstName("Jocelin");
        p.setLastName("Thumelin");
        cout << "Instance 1" << endl;

        p.printFullName();


    // Instance d'un autre objet avec Constructor
    PersonConstructor p2("Jocelin", "Thumelin");

        // Autre façon d'afficher
        cout << p2.getName() << endl;


    // Instance d'un objet qui hérite d'une autre Class
    Employe e("Prénom_Employé", "Nom_Employé", "IT");
        cout << "Instance 2" << endl;
        e.printInfo();

    // Polyporphisme
    vector<PersonConstructor*> people;
        cout << "Instance Polymorphisme" << endl;
        people.push_back(&p2);
        people.push_back(&e);

    for (auto person : people){
        person->printInfo();
    }

    return 0;
}