#include "letters_bag.h"
#include <ctime>
#include <iostream>

BolsaLetras::BolsaLetras() {}

string BolsaLetras::toString() const {
    string s;

    // for (list<char>::const_iterator it = bolsa_letras.begin(); it != bolsa_letras.end(); ++it ) {
    //     s += (*it);
    //     s += "\n";
    // }


    s += bolsa_letras[0];
    for (int i = 1; i < size(); i++) {
        s += '\n' + bolsa_letras[i] ;
    }
    return s;
}

void BolsaLetras::add(Letra letra) {
    // for (int i = 0; i < letra.getCantidad(); i++) {
    //     bolsa_letras.push_back(letra.getCaracter());
    // }

    // string& insert (size_t pos,   size_t n, char c);
    // Inserts n consecutive copies of character c.
    bolsa_letras.insert(0,letra.getCantidad(),letra.getCaracter());
}

char BolsaLetras::get() {
    int i = rand() % bolsa_letras.size();   // números entre 0 y size-1
    bolsa_letras.erase(i,1);
    return bolsa_letras[i];
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
    // Letra letra;
    char caracter;
    int cantidad;
    int puntuacion;

    // Versión primera, a lo bruto
    while (is >> caracter >> cantidad >> puntuacion) {
        Letra letra (caracter, cantidad, puntuacion);
        b.add(letra);
    }

    return is;
}


void BolsaLetras::cargarBolsa(const ConjuntoLetras &conj) {
    ConjuntoLetras::const_iterator it = conj.begin();

    while (it != conj.end()) {
        add(*it);
        ++it;
    }

}