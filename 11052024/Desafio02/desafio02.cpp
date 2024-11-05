#include <iostream>
using namespace std;

class Retangulo {
private:
    double largura;
    double altura;

public:
    Retangulo(double larg, double alt) {
        setLargura(larg);
        setAltura(alt);
    }

    void setLargura(double larg) {
        if (larg > 0) {
            largura = larg;
        } else {
            cout << "Largura negativa detectada. Convertendo para valor positivo.\n";
            largura = larg * -1;
        }
    }

    void setAltura(double alt) {
        if (alt > 0) {
            altura = alt;
        } else {
            cout << "Altura negativa detectada. Convertendo para valor positivo.\n";
            altura = alt * -1;
        }
    }

    double getLargura() const {
        return largura;
    }

    double getAltura() const {
        return altura;
    }

    double calcularArea() const {
        return largura * altura;
    }
};

int main() {
    double largura, altura;
    
    cout << "Digite a largura do retângulo: ";
    cin >> largura;
    cout << "Digite a altura do retângulo: ";
    cin >> altura;

    Retangulo ret(largura, altura);

    cout << "Largura: " << ret.getLargura() << "\n";
    cout << "Altura: " << ret.getAltura() << "\n";
    cout << "Área: " << ret.calcularArea() << "\n";

    return 0;
}
