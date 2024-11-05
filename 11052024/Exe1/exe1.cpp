#include <iostream>
using namespace std;

class Retangulo {
private:
    double largura;
    double altura;

public:
    // Construtor que inicializa largura e altura
    Retangulo(double larg, double alt) {
        setLargura(larg);
        setAltura(alt);
    }

    // Método para definir a largura, com verificação
    void setLargura(double larg) {
        if (larg > 0) {
            largura = larg;
        } else {
            cout << "Largura inválida. Deve ser positiva.\n";
            largura = 1.0; // valor padrão
        }
    }

    // Método para definir a altura, com verificação
    void setAltura(double alt) {
        if (alt > 0) {
            altura = alt;
        } else {
            cout << "Altura inválida. Deve ser positiva.\n";
            altura = 1.0; // valor padrão
        }
    }

    // Métodos para obter largura e altura
    double getLargura() const {
        return largura;
    }

    double getAltura() const {
        return altura;
    }

    // Método para calcular a área do retângulo
    double calcularArea() const {
        return largura * altura;
    }
};

int main() {
    Retangulo ret(5.0, 3.0); // cria um retângulo com largura 5 e altura 3

    cout << "Largura: " << ret.getLargura() << "\n";
    cout << "Altura: " << ret.getAltura() << "\n";
    cout << "Área: " << ret.calcularArea() << "\n";

    ret.setLargura(-4.0); // tenta definir uma largura negativa
    cout << "Largura após ajuste: " << ret.getLargura() << "\n";
    cout << "Área após ajuste: " << ret.calcularArea() << "\n";

    return 0;
}
