#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Documento {
    string nome;
    int paginas;

    Documento(string n, int p) : nome(n), paginas(p) {}
};

int main() {
    queue<Documento> filaImpressao;

    filaImpressao.push(Documento("Relatório Financeiro", 10));
    filaImpressao.push(Documento("Contrato de Trabalho", 5));
    filaImpressao.push(Documento("Apresentação de Vendas", 15));

    while (!filaImpressao.empty()) {
        Documento docAtual = filaImpressao.front();
        cout << "Imprimindo: " << docAtual.nome << " (" << docAtual.paginas << " páginas)" << endl;
        filaImpressao.pop();
    }

    return 0;
}
