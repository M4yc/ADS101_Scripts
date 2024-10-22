#include <iostream>
#include <string>
using namespace std;

// Estrutura que representa um nó (paciente) na lista ligada
struct Paciente {
    string nome;
    int idade;
    Paciente* proximo;
};

// Função para adicionar um paciente no final da fila
void adicionarPaciente(Paciente** frente, Paciente** fim, string nome, int idade) {
    Paciente* novoPaciente = new Paciente();
    novoPaciente->nome = nome;
    novoPaciente->idade = idade;
    novoPaciente->proximo = nullptr;

    // Se a fila está vazia, o novo paciente será o primeiro da fila
    if (*fim == nullptr) {
        *frente = novoPaciente;
        *fim = novoPaciente;
    } else {
        (*fim)->proximo = novoPaciente;
        *fim = novoPaciente;
    }

    cout << "Paciente " << nome << " adicionado à fila." << endl;
}

// Função para atender o primeiro paciente da fila (remover do início)
void atenderPaciente(Paciente** frente) {
    if (*frente == nullptr) {
        cout << "A fila está vazia. Ninguém para atender." << endl;
        return;
    }

    Paciente* pacienteAtendido = *frente;
    cout << "Atendendo paciente: " << pacienteAtendido->nome << ", Idade: " 
         << pacienteAtendido->idade << endl;

    *frente = pacienteAtendido->proximo;
    delete pacienteAtendido; // Libera a memória do paciente atendido
}

// Função para exibir a fila de pacientes
void exibirFila(Paciente* frente) {
    if (frente == nullptr) {
        cout << "A fila está vazia." << endl;
        return;
    }

    cout << "Fila de Pacientes: " << endl;
    while (frente != nullptr) {
        cout << "Paciente: " << frente->nome << ", Idade: " << frente->idade << endl;
        frente = frente->proximo;
    }
}

int main() {
    Paciente* frente = nullptr; // Ponteiro para o primeiro paciente (início da fila)
    Paciente* fim = nullptr;    // Ponteiro para o último paciente (fim da fila)

    // Adicionando pacientes à fila
    adicionarPaciente(&frente, &fim, "Ana", 30);
    adicionarPaciente(&frente, &fim, "João", 45);
    adicionarPaciente(&frente, &fim, "Carlos", 50);
    cout << endl;

    // Exibindo a fila de pacientes
    exibirFila(frente);
    cout << endl;

    // Atendendo pacientes
    atenderPaciente(&frente);
    atenderPaciente(&frente);
    cout << endl;

    // Exibindo a fila novamente após alguns atendimentos
    exibirFila(frente);

    return 0;
}

