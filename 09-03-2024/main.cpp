#include <iostream>
#include <vector>
#include <string>

using namespace std;

int soma(int a, int b);

float media(int a, int b, int c);

int sqrt(int a);

int quad(int a);

int prod(int a, int b);

int main(){
    int n1 = 0;
    int n2 = 0;
    int n3 = 0;

    cout << "Informe o n1: ";
    cin >> n1;

    cout << "Informe o n2: ";
    cin >> n2;

    cout << "A soma de " << n1 << " + " << n2 << "= ";
    cout << soma(n1,n2) << "\n";

    cout << "A media de " << n1 << " " << n2 << " " << n3 << "= ";
    cout << media(n1,n2,n3) << "\n";

    cout << "A raiz quadrada de " << n1 << "= ";
    cout << sqrt(n1) << "\n";

    cout << "O quadrado de " << n1 << "= ";
    cout << quad(n1) << "\n";

    cout << "O produto de " << n1 << " * " << n2 << "= ";
    cout << prod(n1,n2) << "\n";

    return 0;

}

int soma(int a, int b){

    return a + b;
}

float media(int a, int b, int c){

    return (a + b + c) / 3;
}

int sqrt(int a){

    return a * (1/2);
}

int quad(int a){

    return a * a;
}

int prod(int a, int b){

    return a * b;
}