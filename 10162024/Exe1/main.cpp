#include <iostream>
#include <queue> 

using namespace std;

int main() {
    queue<int> fila;

    
    fila.push(10);
    fila.push(20);
    fila.push(30);

    
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
