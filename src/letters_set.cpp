#include "letters_set.h"

ostream& operator<<(ostream& salida, const Letra& letra) {
    salida << letra.getCaracter() << '\t' << letra.getCantidad() << '\t' << letra.getPuntuacion();
    return salida;
}

istream& operator>>(istream& entrada, Letra& letra) {
    entrada >> letra.caracter;
    entrada >> letra.cantidad;
    entrada >> letra.puntuacion;

    return entrada;
}

ostream& operator<<(ostream& salida, const ConjuntoLetras& conj) {
    salida << "#Letra Cantidad Puntos";
    set<Letra>::iterator it = conj.letras.begin();
    while (it != conj.letras.end()) {
        salida << endl;
        salida << *it;
        it++;
    }
    return salida;
}

istream& operator>>(istream& entrada, ConjuntoLetras& conj) {
    string cadena;

    getline(entrada,cadena);
    Letra letra;
    while (cadena.length() > 0) {
        entrada >> letra;
        conj.letras.insert(letra);
    }
    return entrada;
}

Letra &ConjuntoLetras::operator[](char caracter) {
    ConjuntoLetras::iterator it = begin();
    Letra letra;
    while (it != end()) {
        if ((*it).getCaracter() == caracter) letra = *it;
        it++;
    }
    return letra;
}


bool ConjuntoLetras::iterator::operator!=(const ConjuntoLetras::iterator &iter) {
    return el_iterador != iter.el_iterador;
}
bool ConjuntoLetras::iterator::operator==(const ConjuntoLetras::iterator &iter) {
    return el_iterador == iter.el_iterador;
}

Letra& ConjuntoLetras::iterator::operator*() {

    return *el_iterador;
}

ConjuntoLetras::iterator& ConjuntoLetras::iterator::operator++() {
    el_iterador++;
    return *this;
}

ConjuntoLetras::iterator ConjuntoLetras::end() {
    return letras.end();
}

ConjuntoLetras::iterator ConjuntoLetras::begin() {
    return letras.begin();
}

pair<ConjuntoLetras::iterator,bool> ConjuntoLetras::insert(const Letra &letra) {
    return letras.insert(letra);
}