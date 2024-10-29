#include <iostream>
#include <string>
using namespace std;

// Classe base Comprador
class Comprador {
protected:
    string nome;
    double valorCarro;

public:
    Comprador(const string& nome, double valorCarro)
        : nome(nome), valorCarro(valorCarro) {}

    virtual double calcularPreco() const {
        return valorCarro;
    }

    virtual void mostrarInfo() const {
        cout << "Nome: " << nome << endl;
        cout << "Preço final do carro: R$ " << calcularPreco() << endl;
    }
};

// Classe derivada para Pessoa Física
class PessoaFisica : public Comprador {
public:
    PessoaFisica(const string& nome, double valorCarro)
        : Comprador(nome, valorCarro) {}

    double calcularPreco() const override {
        return valorCarro;
    }
};

// Classe derivada para Produtor Rural com 15% de desconto fixo
class ProdutorRural : public Comprador {
private:
    static constexpr double desconto = 15.0;

public:
    ProdutorRural(const string& nome, double valorCarro)
        : Comprador(nome, valorCarro) {}

    double calcularPreco() const override {
        return valorCarro * (1 - desconto / 100);
    }
};

// Classe derivada para Taxista com 10% de juros fixo
class Taxista : public Comprador {
private:
    static constexpr double juros = 10.0;

public:
    Taxista(const string& nome, double valorCarro)
        : Comprador(nome, valorCarro) {}

    double calcularPreco() const override {
        return valorCarro * (1 + juros / 100);
    }
};

// Classe derivada para PCD com 20% de desconto fixo
class PCD : public Comprador {
private:
    static constexpr double desconto = 20.0;

public:
    PCD(const string& nome, double valorCarro)
        : Comprador(nome, valorCarro) {}

    double calcularPreco() const override {
        return valorCarro * (1 - desconto / 100);
    }
};

// Função para exibir o menu e retornar a escolha do usuário
int mostrarMenu() {
    int escolha;
    cout << "Escolha o tipo de comprador:" << endl;
    cout << "1. Pessoa Física" << endl;
    cout << "2. Produtor Rural" << endl;
    cout << "3. Taxista" << endl;
    cout << "4. PCD" << endl;
    cout << "Digite sua escolha: ";
    cin >> escolha;
    return escolha;
}

int main() {
    double valorCarro;
    string nome;
    int escolha = mostrarMenu();

    cout << "Digite o nome do comprador: ";
    cin.ignore(); // Limpa o buffer
    getline(cin, nome);

    cout << "Digite o valor do carro: ";
    cin >> valorCarro;

    Comprador* comprador = nullptr;

    // Criação dos objetos com valores fixos de desconto/juros
    switch (escolha) {
        case 1:
            comprador = new PessoaFisica(nome, valorCarro);
            break;
        case 2:
            comprador = new ProdutorRural(nome, valorCarro);
            break;
        case 3:
            comprador = new Taxista(nome, valorCarro);
            break;
        case 4:
            comprador = new PCD(nome, valorCarro);
            break;
        default:
            cout << "Opção inválida!" << endl;
            return 1;
    }

    cout << "\nInformações do Comprador:" << endl;
    comprador->mostrarInfo();

    delete comprador;
    return 0;
}
