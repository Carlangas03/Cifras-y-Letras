#include "letters_bag.h"
#include <ctime>
#include <iostream>

BolsaLetras::BolsaLetras() {}

string BolsaLetras::toString() const {
    string s;
    for (list<char>::const_iterator it = bolsa_letras.begin(); it != bolsa_letras.end(); ++it ) {
        s += (*it);
        s += "\n";
    }
    return s;
}

void BolsaLetras::add(Letra letra) {
    for (int i = 0; i < letra.getCantidad(); i++) {
        bolsa_letras.push_back(letra.getCaracter());
    }
}

char BolsaLetras::get() {
    int i = rand() % bolsa_letras.size();   // números entre 0 y size-1
    list<char>::iterator it = bolsa_letras.begin();

    for (int k = 0; k < i; k++)
        it++;

    char caracter = *it;
    bolsa_letras.erase(it);

    return caracter;
}

int BolsaLetras::size() const{
    return bolsa_letras.size();
}

ostream& operator<<(ostream& os, const BolsaLetras& b) {
    os << b.toString();
    return os;
}

istream& operator>>(istream& is, BolsaLetras& b) {
    string s;
    getline (is, s);
    Letra letra;
    char caracter;
    int cantidad;
    int puntuacion;

    // Versión primera, a lo bruto
    while (is >> caracter >> cantidad >> puntuacion) {
        letra.setCaracter(caracter);
        letra.setCantidad(cantidad);
        letra.setPuntuacion(puntuacion);
        b.add(letra);
    }



    return is;
}
