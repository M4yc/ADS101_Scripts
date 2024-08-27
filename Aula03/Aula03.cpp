#include <iostream>
#include <vector>
#include <string>

// Códigos de cores
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Preto */
#define RED     "\033[31m"      /* Vermelho */
#define GREEN   "\033[32m"      /* Verde */
#define YELLOW  "\033[33m"      /* Amarelo */
#define BLUE    "\033[34m"      /* Azul */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Ciano */
#define WHITE   "\033[37m"      /* Branco */

using namespace std;

class Pessoa{
    private:
        /* data */
    public:
        int Id; 
        string Nome;
        int Idade;
};

class Pecas{
    public:
        int Id; 
        string Nome;
        string Modelos;
};

int main(){
    Pessoa pessoa;
    Pessoa amigo;
    Pecas pecas;

    pessoa.Id = 1;
    pessoa.Nome = "Jóse";
    pessoa.Idade = 20;
    amigo.Nome = "Luiz";


    cout << RED << "Nome: " << amigo.Nome << RESET << endl;
    cout << RED << "Id: " << pessoa.Id << RESET << endl;
    cout << BLUE << "Nome: " << pessoa.Nome << RESET << endl;
    cout << GREEN << "Idade: " << pessoa.Idade << RESET << endl;

    return 0;

}