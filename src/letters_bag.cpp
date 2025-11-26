#include "letters_bag.h"
#include <ctime>

BolsaLetras::BolsaLetras() {}

void BolsaLetras::add(Letra letra) {
    for (int i = 0; i < letra.getCantidad(); i++) {
        bolsa_letras.push_back(letra.getCaracter());
    }
}

char BolsaLetras::get() {
    int i = rand() % bolsa_letras.size()-0+1;
    list<char>::iterator it = bolsa_letras.begin();

    for (int j = 0; j < i; j++)
        it++;

    char caracter = *it;
    bolsa_letras.erase(it);

}

int BolsaLetras::size() const{
    return bolsa_letras.size();
}

string BolsaLetras::toString() const {
    string s;
    for (list<char>::iterator it = bolsa_letras.begin(); it != bolsa_letras.end(); it++)
        s += *it + "\n";

    return s;
}

ostream& operator<<(ostream& os, const BolsaLetras& b) {
    os << b.toString();
    return os;
}

istream& operator>>(istream& is, BolsaLetras& b) {
    string s;
    Letra letra;
    char caracter;
    int cantidad;
    int puntuacion;

    // Versión primera, a lo bruto
    while (getline(is, s)) {

        if (!s.empty()) {
            is >> caracter;     letra.setCaracter(caracter);
            is >> cantidad;     letra.setCantidad(cantidad);
            is >> puntuacion;   letra.setPuntuacion(puntuacion);
        }

        b.add(letra);
    }

    return is;
}
