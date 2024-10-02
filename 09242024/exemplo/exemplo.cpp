#include <iostream>
#include <string>
using namespace std;

// Classe base Pessoa
class Pessoa {
protected:
    string nome;
    int id;
    int cpf;
public:
    void cadastrarPessoa() {
        cout << "Digite o nome: ";
        getline(cin, nome);
        cout << "Digite o Id: ";
        cin >> id;
        cout << "Digite o CPF: ";
        cin >> cpf;
        cin.ignore();
    }

    virtual void exibirDados() {
        cout << "\n===========================" << endl;
        cout << "Nome: " << nome << endl;
        cout << "Id: " << id << endl;
        cout << "CPF: " << cpf << endl;
        
    }
};

// Classe Aluno derivada de Pessoa
class Aluno : public Pessoa {
private:
    string curso;
    float mensalidade;
    string nomeDisciplina;
    float nota1, nota2, nota3;
public:
    void cadastrarAluno() {
        cadastrarPessoa();
        cout << "Digite o curso do aluno: ";
        cin.ignore();  // Limpar o buffer
        getline(cin, curso);

        cout << "Digite a mensalidade do aluno: ";
        cin >> mensalidade;
    }

    void inserirNotas() {
        cout << "===========================" << endl;
        cout << "Informe o nome da Disciplina: ";
        cin.ignore();  // Limpar o buffer
        getline(cin, nomeDisciplina);

        cout << "Informe a nota 1: ";
        cin >> nota1;

        cout << "Informe a nota 2: ";
        cin >> nota2;

        cout << "Informe a nota 3: ";
        cin >> nota3;
    }

    // Método para calcular a média das notas
    float calcularMedia() const {
        return (nota1 + nota2 + nota3) / 3;
    }

    // Método para verificar se o aluno está aprovado ou reprovado
    string status() const {
        return (calcularMedia() >= 60) ? "Aprovado" : "Reprovado";
    }

    void exibirDados() override {
        Pessoa::exibirDados();
        cout << "===========================" << endl;
        cout << "Curso: " << curso << endl;
        cout << "Mensalidade: R$ " << mensalidade << endl;
        cout << "Disciplina: " << nomeDisciplina << endl;
        cout << "Nota 1: " << nota1 << endl;
        cout << "Nota 2: " << nota2 << endl;
        cout << "Nota 3: " << nota3 << endl;
        cout << "Média: " << calcularMedia() << endl;
        cout << "Status Aluno: " << status() << endl;
        cout << "===========================" << endl;
    }
};

// Classe Professor derivada de Pessoa
class Professor : public Pessoa {
private:
    string curso;
    string nomeDisciplina1, nomeDisciplina2, nomeDisciplina3;
    int cargaHora1, cargaHora2, cargaHora3;
public:
    void cadastrarProfessor() {
        cadastrarPessoa();
        cout << "===========================" << endl;
        // Cadastra dados específicos de Aluno
        cout << "Digite o curso do Professor: ";
        cin.ignore();  // Limpar o buffer
        getline(cin, curso);
    }

    void InserirCarga() {
        cout << "===========================" << endl;
        cout << "Informe o nome da Disciplina 1: ";
        cin.ignore();  // Limpar o buffer
        getline(cin, nomeDisciplina1);

        cout << "Informe a carga horaria da disciplina 1: ";
        cin >> cargaHora1;

        cout << "Informe o nome da Disciplina 2: ";
        cin.ignore();  // Limpar o buffer
        getline(cin, nomeDisciplina2);

        cout << "Informe a carga horaria da disciplina 2: ";
        cin >> cargaHora2;

        cout << "Informe o nome da Disciplina 3: ";
        cin.ignore();  // Limpar o buffer
        getline(cin, nomeDisciplina3);

        cout << "Informe a carga horaria da disciplina 3: ";
        cin >> cargaHora3;
    }

    // Método para calcular a média das notas
    float SomaCarga() const {
        return (cargaHora1 + cargaHora2 + cargaHora3);
    }

    void exibirDados() override {
        Pessoa::exibirDados();
        cout << "===========================" << endl;
        cout << "Curso: " << curso << endl;
        cout << "Disciplina: " << nomeDisciplina1 << endl;
        cout << "Carga horaria: " << cargaHora1 << endl;
        cout << "Disciplina: " << nomeDisciplina2 << endl;
        cout << "Carga horaria: " << cargaHora2 << endl;
        cout << "Disciplina: " << nomeDisciplina3 << endl;
        cout << "Carga horaria: " << cargaHora3 << endl;
        cout << "Total de Horas: " << SomaCarga() << endl;
        cout << "===========================" << endl;
    }
};

// Classe Tecnico derivada de Pessoa
class Tecnico : public Pessoa {
private:
    string setor;
    string periodo;
public:
    void cadastrarTecnico() {
        cadastrarPessoa();
        cout << "===========================" << endl;
        // Cadastra dados específicos de Aluno
        cout << "Digite o setor do Administrativo: ";
        cin.ignore();  // Limpar o buffer
        getline(cin, setor);

        cout << "Digite o periodo que trabalha: ";
        cin.ignore();  // Limpar o buffer
        getline(cin, periodo);
    }


    void exibirDados() override {
        Pessoa::exibirDados();
        cout << "Setor do ADM: "<< setor <<endl; 
        cout << "Periodo de trabalho do ADM: "<< periodo <<endl;
        cout << "===========================" << endl;
    }
};

void menu() {
        cout << "\n============== Menu ==============" << endl;
        cout << "        [1] Cadastro Aluno        " << endl;
        cout << "        [2] Cadastro Professor    " << endl;
        cout << "        [3] Cadastro Tecnico      " << endl;
        cout << "        [0] Sair                  " << endl;
        cout << "==================================" << endl;
        cout << "Escolha uma opcao: ";
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
                aluno.inserirNotas();
                cout << "\nDados do Aluno Cadastrado:\n";
                aluno.exibirDados();
                break;
            }
            case 2: {
                Professor professor;
                professor.cadastrarProfessor();
                professor.InserirCarga();
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
                continue;
                break;
        }

        cout << "\nDeseja realizar outro cadastro? (1 - Sim / 0 - Não): ";
        cin >> opcao;
        cin.ignore();  // Limpa o buffer do teclado
    } while (opcao != 0);
    
    return 0;
}
