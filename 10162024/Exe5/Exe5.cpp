#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Pessoa {
private:
    string nome;
    int quantidadeIngressos;

public:
    
    Pessoa(string n, int q) : nome(n), quantidadeIngressos(q) {}

    
    string getNome() const {
        return nome;
    }

    int getQuantidadeIngressos() const {
        return quantidadeIngressos;
    }
};

class FilaIngressos {
private:
    queue<Pessoa> fila; 

public:
    
    void adicionarPessoa(const Pessoa& pessoa) {
        fila.push(pessoa);
    }

    
    void processarFila() {
        while (!fila.empty()) {
            Pessoa clienteAtual = fila.front(); 
            cout << clienteAtual.getNome() << " comprou "
                 << clienteAtual.getQuantidadeIngressos() << " ingresso(s)."
                 << endl;
            fila.pop(); 
        }
    }

    bool filaVazia() const {
        return fila.empty();
    }
};

int main() {
    FilaIngressos filaDeIngressos;
    int numPessoas;

    
    cout << "Informe o número de pessoas na fila: ";
    cin >> numPessoas;
    cin.ignore(); 

    
    for (int i = 0; i < numPessoas; i++) {
        string nome;
        int quantidade;

        
        cout << "Informe o nome da pessoa " << i + 1 << ": ";
        getline(cin, nome);

        cout << "Informe a quantidade de ingressos para " << nome << ": ";
        cin >> quantidade;
        cin.ignore(); 

        
        filaDeIngressos.adicionarPessoa(Pessoa(nome, quantidade));
    }

    cout << "\nProcessando a fila de ingressos:\n";
    filaDeIngressos.processarFila();

    return 0;
}
