#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pessoa{

    public:
        int Id;
        string Nome;
        int CPF;
    
    void CadastrarPessoa(){

    }
    void ExibirPessoa(){
        cout << "\n_____________________________" << endl;
        cout << "        Nome: "<< Nome <<endl;
        cout << "        Id: "<< Id <<endl;
        cout << "        CPF: "<< CPF <<endl;

    }
    
};

class Aluno: public Pessoa{
    public:
        int matricula;
        string Curso;
        float Mensalidade;
        float notas[3];
    
    float CalcMedia(){
        float soma = 0;
        for( float nota : notas)
        {
            soma += nota;
        }
        
        return soma / 3;
    }

    string VereAprov(){
        if (CalcMedia() >= 60.0)
        {
            return "Aprovado";
        }else{
            return "Reprovado";
        }
    }

    void ExibirInfo(){
        Pessoa :: ExibirPessoa();
        cout << "     Matricula: "<< matricula <<endl;
        cout << "     Media: "<< CalcMedia() <<endl;
        cout << "     Status: "<< VereAprov() <<endl;
    }

};


int main(){
    Pessoa pessoa;

    int opcao;
    do{
        cout << "============== Menu ==============" << endl;
        cout << "        [1] Cadastro Aluno        " << endl;
        cout << "        [2] Cadastro Professor    " << endl;
        cout << "        [3] Cadastro Tecnico      " << endl;
        cout << "        [0] Sair                  " << endl;
        cout << "==================================" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        switch (opcao){
        case 1:
            pessoa.ExibirPessoa();
            break;
        case 2:

            break;
        case 3:

            break;
        case 0:
            cout << "Saindo do sistema...." << endl;
            break;
        default:
            cout << "Opcao envalida! Tente novamente" << endl;
        }
    } while (opcao != 0);
    
    return 0;
}