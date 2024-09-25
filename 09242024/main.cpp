#include <iostream>
#include <string>
#include <locale>

using namespace std;

class Pessoa {
protected:
    int Id;
    string Nome;
    int CPF;
public:
    // Método para cadastrar as informações da pessoa
    void CadastrarInfo() {
        cout << "Digite o ID da pessoa: ";
        cin >> Id;
        cin.ignore();  // Limpar o buffer

        cout << "Digite o nome da pessoa: ";
        getline(cin, Nome);

        cout << "Digite o CPF da pessoa: ";
        cin >> CPF;
    }

    // Método para exibir as informações da pessoa
    virtual void ExibirInfo() const {
        cout << "\n===========================" << endl;
        cout << "Nome: " << Nome << endl;
        cout << "Id: " << Id << endl;
        cout << "CPF: " << CPF << endl;
        
    }
};

class Aluno : public Pessoa {
protected:
    string Curso;
    float Mensalidade;

public:
    // Método para cadastrar as informações do aluno
    void CadastrarInfo() {
        
        // Chama o método da classe base para preencher ID, Nome, CPF
        Pessoa::CadastrarInfo();
        cout << "===========================" << endl;
        // Cadastra dados específicos de Aluno
        cout << "Digite o curso do aluno: ";
        cin.ignore();  // Limpar o buffer
        getline(cin, Curso);

        cout << "Digite a mensalidade do aluno: ";
        cin >> Mensalidade;

        
    }

    // Método para exibir as informações do aluno
    void ExibirInfo() const override {
        
        Pessoa::ExibirInfo();  // Exibe dados de Pessoa
        cout << "===========================" << endl;
        cout << "Curso: " << Curso << endl;
        cout << "Mensalidade: R$ " << Mensalidade << endl;
    }
};

class DisciplinaAluno : public Aluno {
private:
    string NomeDisciplina;
    float nota1, nota2, nota3;

public:
    // Método para inserir notas da disciplina
    void InserirNotas() {
        cout << "===========================" << endl;
        cout << "Informe o nome da Disciplina: ";
        cin.ignore();  // Limpar o buffer
        getline(cin, NomeDisciplina);

        cout << "Informe a nota 1: ";
        cin >> nota1;

        cout << "Informe a nota 2: ";
        cin >> nota2;

        cout << "Informe a nota 3: ";
        cin >> nota3;
    }

    // Método para calcular a média das notas
    float CalcularMedia() const {
        return (nota1 + nota2 + nota3) / 3;
    }

    // Método para verificar se o aluno está aprovado ou reprovado
    string Status() const {
        return (CalcularMedia() >= 60) ? "Aprovado" : "Reprovado";
    }

    // Método para exibir as informações da disciplina
    void ExibirInfo() const override {
        Aluno::ExibirInfo();  // Chama o método da classe Aluno para exibir dados de Aluno
        cout << "Disciplina: " << NomeDisciplina << endl;
        cout << "Nota 1: " << nota1 << endl;
        cout << "Nota 2: " << nota2 << endl;
        cout << "Nota 3: " << nota3 << endl;
        cout << "Média: " << CalcularMedia() << endl;
        cout << "Status Aluno: " << Status() << endl;
        cout << "===========================" << endl;
    }
};

int main() {

    setlocale(LC_ALL, "Portuguese");

    DisciplinaAluno aluno;

    int opcao;
    do {
        cout << "\n============== Menu ==============" << endl;
        cout << "        [1] Cadastro Aluno        " << endl;
        cout << "        [2] Cadastro Professor    " << endl;
        cout << "        [3] Cadastro Tecnico      " << endl;
        cout << "        [0] Sair                  " << endl;
        cout << "==================================" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
        case 1:
            aluno.CadastrarInfo();  // Cadastrar informações do aluno
            aluno.InserirNotas();   // Inserir notas para a disciplina
            cout << "\nInformações do Aluno e da Disciplina:\n";
            aluno.ExibirInfo();  // Exibir todas as informações
            break;

        case 2:
            cout << "Funcionalidade de cadastro de professor ainda não implementada." << endl;
            break;

        case 3:
            cout << "Funcionalidade de cadastro de técnico ainda não implementada." << endl;
            break;

        case 0:
            cout << "Saindo do sistema...." << endl;
            break;

        default:
            cout << "Opcao inválida! Tente novamente." << endl;
        }
    } while (opcao != 0);

    return 0;
}
