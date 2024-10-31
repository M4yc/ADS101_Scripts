#include <iostream>
#include <string>

using namespace std;

class ContaBancaria {
protected:
    string nomeCliente;
    double saldo;


public:
    ContaBancaria(const string& nome, double saldoInicial)
        : nomeCliente(nome), saldo(saldoInicial) {}

    virtual void exibirDetalhes() const {
        cout << "Cliente: " << nomeCliente << "\nSaldo: " << saldo << endl;
    }

    virtual void aplicarCorrecao() = 0;

    virtual ~ContaBancaria() {}
};

class ContaCorrente : public ContaBancaria {
public:
    ContaCorrente(const string& nome, double saldoInicial)
        : ContaBancaria(nome, saldoInicial) {}

    void aplicarCorrecao() override {
        cout << "Conta corrente não possui correção.\n";
    }

    void exibirDetalhes() const override {
        cout << "Tipo de conta: Conta Corrente\n";
        ContaBancaria::exibirDetalhes();
    }
};

class ContaPoupanca : public ContaBancaria {
private:
    double taxaCorrecao;

public:
    ContaPoupanca(const string& nome, double saldoInicial, double taxa)
        : ContaBancaria(nome, saldoInicial), taxaCorrecao(taxa) {}

    void aplicarCorrecao() override {
        saldo += saldo * (taxaCorrecao / 100);
    }

    void exibirDetalhes() const override {
        cout << "Tipo de conta: Conta Poupança\n";
        ContaBancaria::exibirDetalhes();
        cout << "Taxa de correção: " << taxaCorrecao << "%\n";
    }
};

int main() {
    int escolha;
    string nome;
    double saldoInicial;
    double taxaCorrecao = 3.0; // Correção fixa para Conta Poupança

    cout << "Escolha o tipo de conta:\n";
    cout << "1. Conta Corrente\n";
    cout << "2. Conta Poupança\n";
    cout << "Escolha: ";
    cin >> escolha;

    cout << "Digite o nome do cliente: ";
    cin.ignore();
    getline(cin, nome);

    cout << "Digite o saldo inicial: ";
    cin >> saldoInicial;

    ContaBancaria* conta = nullptr;

    if (escolha == 1) {
        conta = new ContaCorrente(nome, saldoInicial);
    } else if (escolha == 2) {
        conta = new ContaPoupanca(nome, saldoInicial, taxaCorrecao);
    } else {
        cout << "Opção inválida!\n";
        return 1;
    }

    conta->exibirDetalhes();
    conta->aplicarCorrecao();
    cout << "\nApós correção:\n";
    conta->exibirDetalhes();

    delete conta;

    return 0;
}
