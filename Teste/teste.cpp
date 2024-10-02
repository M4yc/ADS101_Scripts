#include <iostream>
#include <string>
using namespace std;

class Pessoa {
protected:
    string nome;
    int id;
    int cpf;

public:
    void cadastrarpessoa(){
        cout << "Digite um nome: ";
        getline(cin, nome);
        cout << "Digite um ID: ";
        cin >> id;
        cout << "Digite o CPF: ";
        cin >> cpf;
    }

        virtual void exibirdados(){
            cout << "nome: " << nome << endl; 
            cout << "id: " << id << endl;
            cout << "cpf: " << cpf << endl;
        } 
        
};

class Aluno : public Pessoa {
    private: 
        string curso;
        float mensalidade;
        string nomedisciplina;
        float nota1, nota2, nota3;
        
    public:
        void cadastraraluno (){
            cadastrarpessoa ();
            cout << "digite o curso:";
            getline (cin, curso);
            cout << "digite a mensalidade:";
            cin >> mensalidade;
            
        }
        
        void inserirnotas (){
            cout << "digite o nome da disciplina: ";
            getline (cin, disciplina);
            cout << "digite a nota 1:" ;
            cin >> nota1;
            cout << "digite a nota 2:" ;
            cin >> nota2;
            cout << "digite a nota 3:" ;
            cin >> nota3;
            
        }
        
        void media () const {
            return ( nota1 + nota2 + nota3 )/3;
        }
        void status () const {
            return (media() >= 60)? "aprovado": "reprovado";
        }
        
        void exibirdados (){
            Pessoa::exibirdados();
            cout << " curso " << curso << endl; 
            cout << "mensalidade" << mensalidade << endl;
            cout << "disciplina" << disciplina << endl;
            cout << "nota1 " << nota1 << endl; 
            cout << "nota2 " << nota2 << endl;
            cout << "nota3 " << nota3 << endl;
            cout << "media " << media() << endl;
            cout << "status " << status() << endl;
        } 
};
   
class Professor : public Pessoa {
    
    private: 
        string curso;
        string nomedisciplina01;
        int cargahorariadisciplina01;       
        string nomedisciplina02;
        int cargahorariadisciplina02;
        string nomedisciplina03;
        int cargahorariadisciplina03;
        
    public:
        void cadastrarprofessor (){
            cadastrarpessoa ();
            cout << "digite o curso:";
            getline (cin, curso);
            
        }
        
        void inserircargahoraria (){
            cout << "digite o nome da 1ª disciplina: ";
            getline (cin, nomedisciplina01);
            cout << "digite a carga horaria da 1ª disciplina:" ;
            cin >> cargahorariadisciplina01;
            cout << "digite o nome da 1ª disciplina:" ;
            cin >> nomedisciplina02;
            cout << "digite a carga horaria da 2ª disciplina:" ;
            cin >> cargahorariadisciplina02;
            cout << "digite o nome da 1ª disciplina:" ;
            cin >> nomedisciplina03;
            cout << "digite a carga horaria da 3ª disciplina:" ;
            cin >> cargahorariadisciplina03;
        }
        
        void soma () const {
            return ( cargahorariadisciplina01 + cargahorariadisciplina02 + cargahorariadisciplina03 );
        }
         
        void exibirdados (){
            Pessoa::exibirdados();
            cout << " curso " << curso << endl; 
            cout << "nomedisciplina01" << nomedisciplina01 << endl;
            cout << "cargahorariadisciplina01" << cargahorariadisciplina01 << endl;
            cout << "nomedisciplina02" << nomedisciplina02 << endl;
            cout << "cargahorariadisciplina02" << cargahorariadisciplina02 << endl;
            cout << "nomedisciplina03 " << nomedisciplina03<< endl; 
            cout << "cargahorariadisciplina03" << cargahorariadisciplina03 << endl;
        }
};    

class Tecnico : public Pessoa {
    
    private: 
        string setor;
        string periodo;
        
       
    public:
        void cadastrartecnico (){
            cadastrarpessoa ();
            cout << "digite o setor:";
            getline (cin, setor);
            string << "digite o periodo: ";
            cin >> periodo;
            
        }

         void exibirdados (){
            Pessoa::exibirdados();
            cout << " setor " << setor << endl; 
            cout << "periodo" << periodo << endl;
        }

};