#include <iostream>
using namespace std;

class Retangulo {
private:
    double largura;
    double altura;
    double profundidade;

public:
    Retangulo(double larg, double alt, double prof) {
        setLargura(larg);
        setAltura(alt);
        setProfundidade(prof);
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

    void setProfundidade(double prof) {
        if (prof > 0) {
            profundidade = prof;
        } else {
            cout << "Profundidade negativa detectada. Convertendo para valor positivo.\n";
            profundidade = prof * -1;
        }
    }

    double getLargura() const {
        return largura;
    }

    double getAltura() const {
        return altura;
    }

    double getProfundidade() const {
        return profundidade;
    }

    double calcularArea() const {
        return largura * altura;
    }

    double calcularVolume() const {
        return largura * altura * profundidade;
    }
};

int main() {
    double largura, altura, profundidade;
    
    cout << "Digite a largura do retângulo: ";
    cin >> largura;
    cout << "Digite a altura do retângulo: ";
    cin >> altura;
    cout << "Digite a profundidade do retângulo: ";
    cin >> profundidade;

    Retangulo ret(largura, altura, profundidade);

    cout << "Largura: " << ret.getLargura() << "\n";
    cout << "Altura: " << ret.getAltura() << "\n";
    cout << "Profundidade: " << ret.getProfundidade() << "\n";
    cout << "Área: " << ret.calcularArea() << "\n";
    cout << "Volume: " << ret.calcularVolume() << "\n";

    return 0;
}
