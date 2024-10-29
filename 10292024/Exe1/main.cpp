#include <iostream>
using namespace std;

class Animal {
public:
    // Método virtual para ativar o polimorfismo
    virtual void fazerSom() {
        cout << "Animal faz um som genérico." << endl;
    }
};

class Cachorro : public Animal {
public:
    // Override para sobrescrever o método da classe base
    void fazerSom() override {
        cout << "Cachorro faz: Au Au!" << endl;
    }
};

class Gato : public Animal {
public:
    void fazerSom() override {
        cout << "Gato faz: Miau!" << endl;
    }
};

class Vaca : public Animal {
public:
    void fazerSom() override {
        cout << "Vaca faz: Muuuuuu" << endl;
    }
};

class Cavalo : public Animal {
public:
    void fazerSom() override {
        cout << "Cavalo faz: não" << endl;
    }
};

int main() {
    Animal* animal1 = new Cachorro();
    Animal* animal2 = new Gato();
    Animal* animal3 = new Vaca();
    Animal* animal4 = new Cavalo();


    animal1->fazerSom(); // Saída: "Cachorro faz: Au Au!"
    animal2->fazerSom(); // Saída: "Gato faz: Miau!"
    animal3->fazerSom(); // Saída: "Gato faz: Miau!"
    animal4->fazerSom(); // Saída: "Gato faz: Miau!"

    delete animal1;
    delete animal2;
    delete animal3;
    delete animal4;
    return 0;
}
