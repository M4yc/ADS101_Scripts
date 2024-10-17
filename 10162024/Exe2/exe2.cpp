#include <iostream>
#include <queue> 

using namespace std;

int main() {
    queue<string> fila;

    
    fila.push("A");
    fila.push("B");
    fila.push("C");

    
    cout << "Elemento no início da fila: " << fila.front() << endl;

    
    fila.pop();
    cout << "Elemento no início após remoção: " << fila.front() << endl;

    
    if (fila.empty()) {
        cout << "A fila está vazia!" << endl;
    } else {
        cout << "A fila não está vazia!" << endl;
    }

    return 0;
}
