#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Pessoa {
    string nome;
    int quantidadeIngressos;

    Pessoa(string n, int q) : nome(n), quantidadeIngressos(q) {}
};

int main() {
    queue<Pessoa> filaIngressos;

    filaIngressos.push(Pessoa("Ana", 2));
    filaIngressos.push(Pessoa("Carlos", 3));
    filaIngressos.push(Pessoa("Beatriz", 1));

    while (!filaIngressos.empty()) {
        Pessoa clienteAtual = filaIngressos.front();
        cout << clienteAtual.nome << " comprou "
             << clienteAtual.quantidadeIngressos << " ingresso(s)." << endl;
        filaIngressos.pop();
    }

    return 0;
}
