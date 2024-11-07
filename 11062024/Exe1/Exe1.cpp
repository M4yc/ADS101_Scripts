#include <iostream>
#include <string>
using namespace std;

class ContaBancaria {
private:
    string nomeCliente;
    double saldo;

public:
    ContaBancaria(const string& nome, double saldoInicial)
        : nomeCliente(nome), saldo(saldoInicial) {}

    void depositar(double valor) {
        if (valor > 0) {
            saldo += valor;
            cout << "Depósito de " << valor << " realizado com sucesso!\n";
        } else {
            cout << "Valor de depósito inválido.\n";
        }
    }

    void sacar(double valor) {
        if (valor > 0 && valor <= saldo) {
            saldo -= valor;
            cout << "Saque de " << valor << " realizado com sucesso!\n";
        } else {
            cout << "Saldo insuficiente ou valor inválido para saque.\n";
        }
    }

    double getSaldo() const {
        return saldo;
    }

    string getNomeCliente() const {
        return nomeCliente;
    }

    string getClassificacao() const {
        if (saldo > 50000) {
            return "Ouro";
        } else if (saldo > 20000) {
            return "Prata";
        } else if (saldo > 1000) {
            return "Bronze";
        } else {
            return "Pobre";
        }
    }
};

int main() {
    string nome;
    double saldoInicial;

    cout << "Digite o nome do cliente: ";
    getline(cin, nome);

    cout << "Digite o saldo inicial: ";
    cin >> saldoInicial;

    ContaBancaria conta(nome, saldoInicial);

    int opcao;
    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Consultar saldo\n";
        cout << "2. Depositar\n";
        cout << "3. Sacar\n";
        cout << "4. Consultar classificação da conta\n";
        cout << "5. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Saldo atual: " << conta.getSaldo() << "\n";
                break;
            case 2: {
                double valorDeposito;
                cout << "Digite o valor para depósito: ";
                cin >> valorDeposito;
                conta.depositar(valorDeposito);
                break;
            }
            case 3: {
                double valorSaque;
                cout << "Digite o valor para saque: ";
                cin >> valorSaque;
                conta.sacar(valorSaque);
                break;
            }
            case 4:
                cout << "Classificação da conta: " << conta.getClassificacao() << "\n";
                break;
            case 5:
                cout << "Saindo do programa. Obrigado por usar nosso banco!\n";
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
                break;
        }
    } while (opcao != 5);

    return 0;
}
