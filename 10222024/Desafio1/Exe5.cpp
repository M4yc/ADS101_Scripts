#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nome;  
    int idade;    
    Node* next;   
};

void insertAtBeginning(Node** head, string nome, int idade) {
    Node* newNode = new Node();   
    newNode->nome = nome;         
    newNode->idade = idade;       
    newNode->next = *head;        
    *head = newNode;              
}

void printList(Node* node) {
    while (node != nullptr) {
        cout << "Nome: " << node->nome << ", Idade: " << node->idade << " -> ";
        node = node->next;
    }
    cout << "null" << endl;
}

int main() {
    Node* head = nullptr;  
    int n;
    
    cout << "Quantas pessoas deseja inserir? ";
    cin >> n;

    
    for (int i = 0; i < n; i++) {
        string nome;
        int idade;

        cout << "Digite o nome da pessoa " << (i + 1) << ": ";
        cin >> nome;
        cout << "Digite a idade de " << nome << ": ";
        cin >> idade;

        insertAtBeginning(&head, nome, idade);
    }

    cout << "Lista de pessoas inseridas: ";
    printList(head);

    return 0;
}
