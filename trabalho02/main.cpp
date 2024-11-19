#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

// Classe base para itens de mídia
class Item {
protected:
    string titulo;

public:
    virtual ~Item() {} // Destrutor virtual para permitir polimorfismo
    virtual void cadastrar() = 0; // Método virtual puro para cadastro
    virtual void exibir() const = 0; // Método virtual puro para exibição
};

// Classe para DVD (herda de Item)
class DVD : public Item {
private:
    int ano;

public:
    void cadastrar() override {
        cout << "Cadastro de DVD\n";
        cout << "Digite o título: ";
        cin.ignore();
        getline(cin, titulo);
        cout << "Digite o ano: ";
        cin >> ano;
    }

    void exibir() const override {
        cout << "DVD: " << titulo << " (" << ano << ")\n";
    }
};

// Classe para CD (herda de Item)
class CD : public Item {
private:
    string artista;

public:
    void cadastrar() override {
        cout << "Cadastro de CD\n";
        cout << "Digite o título: ";
        cin.ignore();
        getline(cin, titulo);
        cout << "Digite o artista: ";
        getline(cin, artista);
    }

    void exibir() const override {
        cout << "CD: " << titulo << " - " << artista << "\n";
    }
};

// Classe para LP (herda de Item)
class LP : public Item {
private:
    string genero;

public:
    void cadastrar() override {
        cout << "Cadastro de LP\n";
        cout << "Digite o título: ";
        cin.ignore();
        getline(cin, titulo);
        cout << "Digite o gênero: ";
        getline(cin, genero);
    }

    void exibir() const override {
        cout << "LP: " << titulo << " (" << genero << ")\n";
    }
};

// Classe para Livro (herda de Item)
class Livro : public Item {
private:
    string autor;

public:
    void cadastrar() override {
        cout << "Cadastro de Livro\n";
        cout << "Digite o título: ";
        cin.ignore();
        getline(cin, titulo);
        cout << "Digite o autor: ";
        getline(cin, autor);
    }

    void exibir() const override {
        cout << "Livro: " << titulo << " - " << autor << "\n";
    }
};

// Classe para o sistema de cadastro (gerencia os itens)
class SistemaCadastro {
private:
    vector<unique_ptr<Item>> itens; // Armazena itens de mídia

public:
    void menu() {
        int opcao;
        do {
            cout << "========== Menu =============\n";
            cout << "[1] Cadastro de DVD\n";
            cout << "[2] Cadastro de CD\n";
            cout << "[3] Cadastro de LP\n";
            cout << "[4] Cadastro de Livro\n";
            cout << "[5] Exibição dos itens cadastrados\n";
            cout << "[6] Sair do sistema\n";
            cout << "=========================\n";
            cout << "Escolha uma opção: ";
            cin >> opcao;

            switch (opcao) {
                case 1:
                    adicionarItem(make_unique<DVD>());
                    break;
                case 2:
                    adicionarItem(make_unique<CD>());
                    break;
                case 3:
                    adicionarItem(make_unique<LP>());
                    break;
                case 4:
                    adicionarItem(make_unique<Livro>());
                    break;
                case 5:
                    exibirItens();
                    break;
                case 6:
                    cout << "Saindo do sistema...\n";
                    break;
                default:
                    cout << "Opção inválida. Tente novamente.\n";
                    break;
            }
        } while (opcao != 6);
    }

    // Método para adicionar um item ao sistema
    void adicionarItem(unique_ptr<Item> item) {
        item->cadastrar();
        itens.push_back(move(item)); // Armazena o item na lista
    }

    // Método para exibir todos os itens cadastrados
    void exibirItens() const {
        cout << "\nItens cadastrados:\n";
        for (const auto& item : itens) {
            item->exibir();
        }
        cout << endl;
    }
};

// Função principal
int main() {
    SistemaCadastro sistema;
    sistema.menu();
    return 0;
}
