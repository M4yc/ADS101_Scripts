#include <iostream>
using namespace std;

int main() {
    int x = 10;  // Uma variável comum
    int* p;      // Declaração de um ponteiro para um inteiro

    p = &x;      // O ponteiro 'p' recebe o endereço de 'x'

    cout << "Valor de x: " << x << endl;                       // Imprime 10
    cout << "Endereço de x: " << &x << endl;                   // Mostra o endereço de 'x'
    cout << "Endereço armazenado em p: " << p << endl;         // Mostra o mesmo endereço (onde 'x' está armazenado)
    cout << "Valor apontado por p: " << *p << endl;            // Imprime 10 (valor de 'x' através do ponteiro)

    return 0;
}
