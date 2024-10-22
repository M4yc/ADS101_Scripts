#include <iostream>
#include <string>
using namespace std;

// Definição do nó
struct Node {
    string data;        // Dados armazenados no nó
    Node* next;      // Ponteiro para o próximo nó
};

// Função para inserir um novo nó no início da lista
void insertAtBeginning(Node** head, string newData) {
    Node* newNode = new Node();   // Aloca um novo nó
    newNode->data = newData;      // Atribui o dado
    newNode->next = *head;        // Aponta para o antigo primeiro nó
    *head = newNode;              // Atualiza o ponteiro do cabeçalho
}

// Função para exibir a lista
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "null" << endl;
}

int main() {
    Node* head = nullptr;  // Inicializa a lista vazia

    insertAtBeginning(&head, "José");
    insertAtBeginning(&head, "Maria");
    insertAtBeginning(&head, "Lucas");

    printList(head);  // Saída: 30 -> 20 -> 10 -> null

    return 0;
}
