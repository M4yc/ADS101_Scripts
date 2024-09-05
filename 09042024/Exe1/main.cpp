#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Valores{
    int n1;
    int n2;
    
};

int main(){
    Valores v;

    int soma = 0;

    cout << "Digite o valor n1: ";
    cin >> v.n1;

    cout << "Digite o valor n1: ";
    cin >> v.n2;
    
    soma = v.n1 + v.n2;

    cout << "A soma de " << v.n1 << " + " << v.n2 << " = " << soma << endl;

    return 0;

}

