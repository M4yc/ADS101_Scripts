#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Valores{
    int ini;
    int cod;
    int inc;
};

int main(){
    Valores v;

    cout << "Digite o valor de inicio: ";
    cin >> v.ini;

    cout << "Digite o valor de parada: ";
    cin >> v.cod;

    cout << "Digite o valor de incremento: ";
    cin >> v.inc;

    for (int i = v.ini; i <= v.cod; (i= i + v.inc))
    {
        cout << "Incremento = " << i << endl;
    }
    
    return 0;

}

