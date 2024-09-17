#include <iostream>
#include <string>

using namespace std;

class Calculadora{
    public:
        int Soma(int n1, int n2){
            
            cout << "A soma é " << n1+n2 << endl;
        };

        int Prod(int n1, int n2){
            
            cout << "O Produto é " << n1*n2 << endl;
        };

        int Rquad(int n1){
            
            cout << "A Raiz quadrada é " << n1 * (1/2) << endl;
        };

        int Quad(int n1){
            
            cout << "O quadrado é " << n1*n1 << endl;
        };

};

int main() {

    int n1;
    int n2;
    int escolha = 0;
    Calculadora cl;
    cout << "[1] Média" << endl;
    cout << "[2] Raiz Quadrada" << endl;
    cout << "[3] Potencia" << endl;
    cout << "[4] Produto" << endl;
    while (1)
    {
        cout << "Informe a opção de escolha: ";
        cin >> escolha;
        if (escolha < 1 || escolha > 4)
    {
        cout << "Escolha invalida! Tente novamente." << endl;
    }
    else{
        break;
    }
    }
    if (escolha == 1)
    {
        
        cout << "Informe o n1: ";
        cin >> n1;

        cout << "Informe o n2: ";
        cin >> n2;

        
        cl.Soma(n1,n2);
    }
    else if (escolha == 2)
    {
        cout << "Informe o n1: ";
        cin >> n1;

        cl.Rquad(n1);

    }
    else if (escolha == 3)
    {
        cout << "Informe o n1: ";
        cin >> n1;

        cl.Quad(n1);

    }
    else if (escolha == 3)
    {
        cout << "Informe o n1: ";
        cin >> n1;

        cl.Prod(n1,n2);

    }
    return 0;
}
