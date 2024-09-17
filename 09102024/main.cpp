#include <iostream>
#include <string>

using namespace std;


class Animal {
public:
    string nome;

    
    Animal(string n) : nome(n) {}

    
    void dormir() {
        cout << nome << " está dormindo." << endl;
    }
};


class Cachorro : public Animal {
public:
    string raca;
    int idade;  

    
    Cachorro(string n, string r, int i) : Animal(n), raca(r), idade(i) {}

    
    void latir() {
        cout << nome << " está latindo!" << endl;
    }

    
    void dormir() {
        cout << nome << " um cachorro da raça " << raca << " está dormindo." << endl;
    }

    
    void mostrarIdade() {
        cout << nome << " tem " << idade << " anos." << endl;
    }
};

int main() {
    
    Animal animal("Animal Genérico");
    animal.dormir(); 

    
    Cachorro cachorro("Bolt", "Pastor Alemão", 3);  
    cachorro.dormir(); 
    cachorro.latir(); 
    cachorro.mostrarIdade(); 

    return 0;
}
