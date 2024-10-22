#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Função para inserir um novo nó no início da lista duplamente encadeada
void insertAtBeginning(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = *head;
    newNode->prev = nullptr;

    if (*head != nullptr) {
        (*head)->prev = newNode;
    }

    *head = newNode;
}

// Função para imprimir a lista para frente
void printListForward(Node* node) {
    while (node != nullptr) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "null" << endl;
}

// Função para imprimir a lista para trás
void printListBackward(Node* node) {
    // Ir até o último nó
    Node* last = nullptr;
    while (node != nullptr) {
        last = node;
        node = node->next;
    }

    // Agora imprime para trás
    while (last != nullptr) {
        cout << last->data << " -> ";
        last = last->prev;
    }
    cout << "null" << endl;
}

int somar(Node* node){
    int sum = 0;
    while (node != nullptr)
    {
        sum += node->data;
        node = node->next;
    }
    return sum;
    
}

int main() {
    Node* head = nullptr;

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    cout << "Lista para frente: ";
    printListForward(head);  // Saída: 30 -> 20 -> 10 -> null

    cout << "Lista para trás: ";
    printListBackward(head); // Saída: 10 -> 20 -> 30 -> null

    int soma = somar(head);
    cout << "A soma da lista deu: "<< soma << endl;

    return 0;
}
