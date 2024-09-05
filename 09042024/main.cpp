#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Pessoa{
    string nome;
    int idade;
    
};

int main(){
    Pessoa p;
    cout << "Digite o nome: ";
    std::getline(std::cin,p.nome);

    cout << "Digite a idade: ";
    cin >> p.idade;

    cout << "Nome: " << p.nome << ", idade: " << p.idade << endl;

    return 0;

}

