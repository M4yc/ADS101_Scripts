#include <iostream>
#include <string>

using namespace std;

class Carro {
public:
    
    string cor;
    string modelo;
    int ano;

    
    void acelerar() {
        cout << "O carro está acelerando!" << endl;
    }
};

int main() {
    
    Carro meuCarro;
    meuCarro.cor = "Vermelho";
    meuCarro.modelo = "Honda";
    meuCarro.ano = 2022;

    
    meuCarro.acelerar();

    return 0;
}
