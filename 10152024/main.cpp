#include <iostream>
#include <string>
#include <locale>

#define MAX 100

using namespace std;

class Pilha {
private:
    int topo;
    int itens[MAX];

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

    void push(int valor) {
        if (cheia()) {
            cout << "Erro: Pilha cheia, não é possível adicionar o elemento!" << std::endl;
        } else {
            topo++;
            itens[topo] = valor;
        }
    }

    int pop() {
        if (vazia()) {
            cout << "Erro: Pilha vazia, não é possível remover o elemento!" << std::endl;
            return -1;
        } else {
            int valor = itens[topo];
            topo--;
            return valor;
        }
    }

    int getTopo() {
        if (vazia()) {
            cout << "Erro: Pilha vazia!" << std::endl;
            return -1;
        } else {
            return itens[topo];
        }
    }

    int getPosicaoTopo() {
        return topo + 1;  // Retorna a posição do topo, adicionando 1 para ser 1-indexado
    }
};

int main() {
    Pilha minhaPilha;
    int quantidade, valor;
    int soma = 0;  // Variável para armazenar a soma dos valores

    cout << "Quantos valores você deseja inserir na pilha? ";
    cin >> quantidade;

    for (int i = 0; i < quantidade; i++) {
        cout << "Digite o valor " << i + 1 << ": ";
        cin >> valor;
        minhaPilha.push(valor);
    }

    cout << "\nElementos removidos da pilha em ordem (LIFO):" << std::endl;

    while (!minhaPilha.vazia()) {
        int valorRemovido = minhaPilha.pop();
        int posicaoRemovida = minhaPilha.getPosicaoTopo() + 1; // Posição antes de remover
        soma += valorRemovido;  // Soma os valores removidos

        cout << "O número " << valorRemovido << " estava na posição " << posicaoRemovida << std::endl;
    }

    // Exibe a soma final
    cout << "\nA soma dos valores removidos é: " << soma << std::endl;

    return 0;
}
