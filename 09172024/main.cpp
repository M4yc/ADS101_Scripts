#include <iostream>
#include <string>

using namespace std;

class Calculadora{
    public:
        void Soma(float n1, float n2){
            cout << "A soma de " << n1 << " + "<< n2 << " = "<< n1 + n2 << "\n"<< endl;
        }

        void Sub(float n1, float n2){
            cout << "A subtracao de " << n1 << " - "<< n2 << " = "<< n1 - n2 << "\n" << endl;
        }

        void Mult(float n1, float n2){
            cout << "A Multiplicacao de " << n1 << " * "<< n2 << " = "<< n1 * n2 << "\n" << endl;
        }

        void Div(float n1, float n2){
            if (n2 != 0)
            {
                cout << "A divisão de " << n1 << " / "<< n2 << " = "<< n1 / n2 << "\n" << endl;
            }else{
                cout << "Não é possivel fazer divisão por zero" << "\n" << endl;
            }
        }

};

int main() {

    float n1;
    float n2;
    int escolha = 0;
    Calculadora cl;

    cout << "===== Calculadora ====="  << "\n" << endl;

    cout << "Informe o valor de n1: ";
    cin >> n1;

    cout << "\n" <<"======= Menu de escolha =======" << endl;
    cout << "       [1] Soma                " << endl;
    cout << "       [2] Subtracao           " << endl;
    cout << "       [3] Multiplicacao       " << endl;
    cout << "       [4] Divisao             " << endl;
    cout << "===============================" << "\n" << endl;
    while (1)
    {
        cout << "Informe o numero de escolha: ";
        cin >> escolha;
        if (escolha < 1 || escolha > 4)
    {
        cout << "Escolha invalida! Tente novamente." << "\n" << endl;
    }
    else{
        break;
    }
    }

    cout << "Informe o valor de n2: ";
    cin >> n2;

    if (escolha == 1)
    {
        cl.Soma(n1,n2);
    }
    else if (escolha == 2)
    {
        cl.Sub(n1, n2);
    }
    else if (escolha == 3)
    {
        cl.Mult(n1, n2);
    }
    else if (escolha == 4)
    {
        cl.Div(n1, n2);
    }
    
    return 0;
}
