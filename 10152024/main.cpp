#include <iostream>
#include <string>

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

    int getProximoValor() {
        if (topo > 0) {
            return itens[topo - 1];
        }
        return 0;  // Retorna 0 se não houver mais valores
    }
};

int main() {
    Pilha minhaPilha;
    int quantidade, valor, somaTotal = 0, somaValorAtualMaisProximo = 0;

    cout << "Quantos valores você deseja inserir na pilha? ";
    cin >> quantidade;

    for (int i = 0; i < quantidade; i++) {
        cout << "Digite o valor " << i + 1 << ": ";
        cin >> valor;
        minhaPilha.push(valor);
    }

    cout << "\nElementos removidos da pilha e somados ao próximo valor (LIFO):" << std::endl;

    while (!minhaPilha.vazia()) {
        int valorAtual = minhaPilha.pop();
        int valorProximo = minhaPilha.getProximoValor();  // Obtém o próximo valor sem removê-lo

        somaTotal += valorAtual;  // Soma de todos os valores removidos
        somaValorAtualMaisProximo = valorAtual + valorProximo;  // Soma do valor atual com o próximo

        cout << "O número " << valorAtual << " somado ao próximo (" << valorProximo << ") é: " << somaValorAtualMaisProximo << std::endl;
    }

    // Exibe a soma total de todos os valores removidos
    cout << "\nA soma total de todos os valores removidos é: " << somaTotal << endl;

    return 0;
}
