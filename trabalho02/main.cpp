#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

// Classe base
class Midia {
protected:
    string titulo;
    string autor;
    int ano;

public:
    Midia(const string& titulo, const string& autor, int ano)
        : titulo(titulo), autor(autor), ano(ano) {}

    virtual ~Midia() = default;

    virtual void exibirInformacoes() const = 0;
};

// Classe DVD derivada de Midia
class DVD : public Midia {
private:
    double duracao;
    string genero;

public:
    DVD(const string& titulo, const string& autor, int ano, double duracao, const string& genero)
        : Midia(titulo, autor, ano), duracao(duracao), genero(genero) {}

    void exibirInformacoes() const override {
        cout << "DVD - Titulo: " << titulo << ", Diretor: " << autor << ", Ano: " << ano
             << ", Duracao: " << duracao << " min, Genero: " << genero << endl;
    }
};

// Classe CD derivada de Midia
class CD : public Midia {
private:
    int numFaixas;
    string genero;

public:
    CD(const string& titulo, const string& autor, int ano, int numFaixas, const string& genero)
        : Midia(titulo, autor, ano), numFaixas(numFaixas), genero(genero) {}

    void exibirInformacoes() const override {
        cout << "CD - Titulo: " << titulo << ", Artista: " << autor << ", Ano: " << ano
             << ", Faixas: " << numFaixas << ", Genero: " << genero << endl;
    }
};

// Classe LP derivada de Midia
class LP : public Midia {
private:
    int numFaixas;
    string genero;

public:
    LP(const string& titulo, const string& autor, int ano, int numFaixas, const string& genero)
        : Midia(titulo, autor, ano), numFaixas(numFaixas), genero(genero) {}

    void exibirInformacoes() const override {
        cout << "LP - Titulo: " << titulo << ", Artista: " << autor << ", Ano: " << ano
             << ", Faixas: " << numFaixas << ", Genero: " << genero << endl;
    }
};

// Classe Livro derivada de Midia
class Livro : public Midia {
private:
    int numPaginas;
    string editora;

public:
    Livro(const string& titulo, const string& autor, int ano, int numPaginas, const string& editora)
        : Midia(titulo, autor, ano), numPaginas(numPaginas), editora(editora) {}

    void exibirInformacoes() const override {
        cout << "Livro - Titulo: " << titulo << ", Autor: " << autor << ", Ano: " << ano
             << ", Paginas: " << numPaginas << ", Editora: " << editora << endl;
    }
};

// Funções para cadastro
shared_ptr<Midia> cadastrarDVD() {
    string titulo, diretor, genero;
    int ano;
    double duracao;

    cout << "Digite o titulo do DVD: ";
    cin.ignore();
    getline(cin, titulo);
    cout << "Digite o diretor: ";
    getline(cin, diretor);
    cout << "Digite o ano: ";
    cin >> ano;
    cout << "Digite a duracao em minutos: ";
    cin >> duracao;
    cout << "Digite o genero: ";
    cin.ignore();
    getline(cin, genero);

    return make_shared<DVD>(titulo, diretor, ano, duracao, genero);
}

shared_ptr<Midia> cadastrarCD() {
    string titulo, artista, genero;
    int ano, numFaixas;

    cout << "Digite o titulo do CD: ";
    cin.ignore();
    getline(cin, titulo);
    cout << "Digite o artista: ";
    getline(cin, artista);
    cout << "Digite o ano: ";
    cin >> ano;
    cout << "Digite o numero de faixas: ";
    cin >> numFaixas;
    cout << "Digite o genero: ";
    cin.ignore();
    getline(cin, genero);

    return make_shared<CD>(titulo, artista, ano, numFaixas, genero);
}

shared_ptr<Midia> cadastrarLP() {
    string titulo, artista, genero;
    int ano, numFaixas;

    cout << "Digite o titulo do LP: ";
    cin.ignore();
    getline(cin, titulo);
    cout << "Digite o artista: ";
    getline(cin, artista);
    cout << "Digite o ano: ";
    cin >> ano;
    cout << "Digite o numero de faixas: ";
    cin >> numFaixas;
    cout << "Digite o genero: ";
    cin.ignore();
    getline(cin, genero);

    return make_shared<LP>(titulo, artista, ano, numFaixas, genero);
}

shared_ptr<Midia> cadastrarLivro() {
    string titulo, autor, editora;
    int ano, numPaginas;

    cout << "Digite o titulo do Livro: ";
    cin.ignore();
    getline(cin, titulo);
    cout << "Digite o autor: ";
    getline(cin, autor);
    cout << "Digite o ano: ";
    cin >> ano;
    cout << "Digite o numero de paginas: ";
    cin >> numPaginas;
    cout << "Digite a editora: ";
    cin.ignore();
    getline(cin, editora);

    return make_shared<Livro>(titulo, autor, ano, numPaginas, editora);
}

int main() {
    vector<shared_ptr<Midia>> midias;
    int opcao;

    do {
        cout << "\nSistema de Catalogacao de Midias\n";
        cout << "1. Cadastro de DVD\n";
        cout << "2. Cadastro de CD\n";
        cout << "3. Cadastro de LP\n";
        cout << "4. Cadastro de Livro\n";
        cout << "5. Exibir itens cadastrados\n";
        cout << "6. Sair do sistema\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                midias.push_back(cadastrarDVD());
                break;
            case 2:
                midias.push_back(cadastrarCD());
                break;
            case 3:
                midias.push_back(cadastrarLP());
                break;
            case 4:
                midias.push_back(cadastrarLivro());
                break;
            case 5:
                for (const auto& midia : midias) {
                    midia->exibirInformacoes();
                }
                break;
            case 6:
                cout << "Saindo do sistema...\n";
                break;
            default:
                cout << "Opcao invalida! Tente novamente.\n";
                break;
        }
    } while (opcao != 6);

    return 0;
}
