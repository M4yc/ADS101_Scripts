#include <iostream>
#include <locale>

#define MAX 100

using namespace std;

class Pilha {
private:
    int topo;
    char itens[MAX];  // Array para armazenar letras

public:
    Pilha() {
        topo = -1;
    }

    bool cheia() {
        return topo == MAX - 1;
    }

    bool vazia() {
        return topo == -1;
    }

    void push(char letra) {
        if (cheia()) {
            std::cout << "Erro: Pilha cheia, não é possível adicionar o elemento!" << std::endl;
        } else {
            topo++;
            itens[topo] = letra;
        }
    }

    char pop() {
        if (vazia()) {
            std::cout << "Erro: Pilha vazia, não é possível remover o elemento!" << std::endl;
            return '\0'; // Retorna um valor indicativo de erro
        } else {
            char letra = itens[topo];
            topo--;
            return letra;
        }
    }

    char getTopo() {
        if (vazia()) {
            std::cout << "Erro: Pilha vazia!" << std::endl;
            return '\0'; // Retorna um valor indicativo de erro
        } else {
            return itens[topo];
        }
    }
};

int main() {
    Pilha minhaPilha;
    int quantidade;
    char letra;

    std::cout << "Quantas letras você deseja inserir na pilha? ";
    std::cin >> quantidade;

    for (int i = 0; i < quantidade; i++) {
        std::cout << "Digite a letra " << i + 1 << ": ";
        std::cin >> letra;
        minhaPilha.push(letra);
    }

    std::cout << "\nLetras removidas da pilha em ordem (LIFO):" << std::endl;

    while (!minhaPilha.vazia()) {
        std::cout << minhaPilha.pop() << std::endl;
    }

    return 0;
}
