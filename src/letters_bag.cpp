#include "letters_bag.h"
#include <ctime>
#include <iostream>


// -------------------------- Clase BolsaLetras -------------------------------
BolsaLetras::BolsaLetras() {}

int BolsaLetras::size() const{
    return bolsa_letras.size();
}

void BolsaLetras::add(Letra letra) {
    bolsa_letras.insert(0,letra.getCantidad(),letra.getCaracter());
}

char BolsaLetras::get() {
    int i = rand() % bolsa_letras.size();   // números entre 0 y size-1
    bolsa_letras.erase(i,1);
    return bolsa_letras[i];
}

string BolsaLetras::toString() const {

    string s;
    s += bolsa_letras[0];
    for (int i = 1; i < size(); i++)
        s += '\n' + bolsa_letras[i] ;

    return s;
}

void BolsaLetras::cargarBolsa(const ConjuntoLetras &conj) {
    ConjuntoLetras::const_iterator it = conj.begin();

    while (it != conj.end()) {
        add(*it);
        ++it;
    }
}

ostream& operator<<(ostream& os, const BolsaLetras& b) {
    os << b.toString();
    return os;
}

istream& operator>>(istream& is, BolsaLetras& b) {
    string s;
    getline (is, s);
    // Letra letra;
    char caracter;
    int cantidad;
    int puntuacion;

    while (is >> caracter >> cantidad >> puntuacion) {
        Letra letra (caracter, cantidad, puntuacion);
        b.add(letra);
    }

    return is;
};