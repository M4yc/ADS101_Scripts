#include <iostream>
#include <string>
using namespace std;

// Classe base Pessoa
class Pessoa {
protected:
    string nome;
    int idade;
public:
    void cadastrarPessoa() {
        cout << "Digite o nome: ";
        getline(cin, nome);
        cout << "Digite a idade: ";
        cin >> idade;
        cin.ignore();
    }

    virtual void exibirDados() {
        cout << "Nome: " << nome << endl;
        cout << "Idade: " << idade << " anos" << endl;
    }
};

// Classe Aluno derivada de Pessoa
class Aluno : public Pessoa {
private:
    string curso;
    int matricula;
public:
    void cadastrarAluno() {
        cadastrarPessoa();
        cout << "Digite o curso: ";
        getline(cin, curso);
        cout << "Digite a matrícula: ";
        cin >> matricula;
        cin.ignore();
    }

    void exibirDados() override {
        Pessoa::exibirDados();
        cout << "Curso: " << curso << endl;
        cout << "Matrícula: " << matricula << endl;
    }
};

// Classe Professor derivada de Pessoa
class Professor : public Pessoa {
private:
    string disciplina;
    double salario;
public:
    void cadastrarProfessor() {
        cadastrarPessoa();
        cout << "Digite a disciplina: ";
        getline(cin, disciplina);
        cout << "Digite o salário: ";
        cin >> salario;
        cin.ignore();
    }

    void exibirDados() override {
        Pessoa::exibirDados();
        cout << "Disciplina: " << disciplina << endl;
        cout << "Salário: R$ " << salario << endl;
    }
};

// Classe Tecnico derivada de Pessoa
class Tecnico : public Pessoa {
private:
    string setor;
public:
    void cadastrarTecnico() {
        cadastrarPessoa();
        cout << "Digite o setor de trabalho: ";
        getline(cin, setor);
    }

    void exibirDados() override {
        Pessoa::exibirDados();
        cout << "Setor: " << setor << endl;
    }
};

void menu() {
    cout << "Selecione uma opção:\n";
    cout << "1. Cadastro de Aluno\n";
    cout << "2. Cadastro de Professor\n";
    cout << "3. Cadastro de Técnico Administrativo\n";
    cout << "Digite sua escolha: ";
}

int main() {
    int opcao;
    do {
        menu();
        cin >> opcao;
        cin.ignore();  // Limpa o buffer do teclado

        switch (opcao) {
            case 1: {
                Aluno aluno;
                aluno.cadastrarAluno();
                cout << "\nDados do Aluno Cadastrado:\n";
                aluno.exibirDados();
                break;
            }
            case 2: {
                Professor professor;
                professor.cadastrarProfessor();
                cout << "\nDados do Professor Cadastrado:\n";
                professor.exibirDados();
                break;
            }
            case 3: {
                Tecnico tecnico;
                tecnico.cadastrarTecnico();
                cout << "\nDados do Técnico Administrativo Cadastrado:\n";
                tecnico.exibirDados();
                break;
            }
            default:
                cout << "Opção inválida! Tente novamente.\n";
                break;
        }

        cout << "\nDeseja realizar outro cadastro? (1 - Sim / 0 - Não): ";
        cin >> opcao;
        cin.ignore();  // Limpa o buffer do teclado
    } while (opcao == 1);

    return 0;
}
