#include "letters_set.h"


void Letra::setPuntuacion(int apariciones, int total, int num_letras) {
    double porcentaje = apariciones / total;
    puntuacion = 10 - num_letras*porcentaje;
};


ostream& operator<<(ostream& salida, const Letra& letra) {
    salida << letra.getCaracter() << '\t'<< '\t' << letra.getCantidad() << '\t'<< '\t' << '\t' << letra.getPuntuacion();
    return salida;
}

istream& operator>>(istream& entrada, Letra& letra) {
    entrada >> letra.caracter;
    entrada >> letra.cantidad;
    entrada >> letra.puntuacion;

    return entrada;
}

bool Letra::operator<(const Letra &l) const {
    return caracter < l.caracter;
}


ostream& operator<<(ostream& salida, const ConjuntoLetras& conj) {
    salida << "#Letra\tCantidad\t\tPuntos"<< endl;
    set<Letra>::iterator it = conj.letras.begin();
    while (it != conj.letras.end()) {
        salida << *it << endl;
        it++;
    }
    return salida;
}

istream& operator>>(istream& entrada, ConjuntoLetras& conj) {
    string cadena;

    getline(entrada,cadena);
    Letra letra;

    while (entrada >> letra) {
        conj.letras.insert(letra);

    }
    return entrada;
}

// Letra& ConjuntoLetras::operator[](char caracter) {
//     for (auto it = begin(); it != end(); ++it) {
//         if ((*it).getCaracter() == caracter)
//             return *(it);
//     }
//     throw std::out_of_range("Caracter no encontrado");
// }

void ConjuntoLetras::insert (const Letra &letra) {
    letras.insert(letra);
}

bool ConjuntoLetras::iterator::operator!=(const ConjuntoLetras::iterator &iter) {
    return el_iterador != iter.el_iterador;
}
bool ConjuntoLetras::iterator::operator==(const ConjuntoLetras::iterator &iter) {
    return el_iterador == iter.el_iterador;
}

const Letra& ConjuntoLetras::iterator::operator*() const{
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

Letra ConjuntoLetras::getLetra(char caracter) const{

    set<Letra>::iterator it = letras.begin();
    while (it != letras.end()) {
        if ((*it).getCaracter() == caracter);
            return (*it);
    }

    return Letra();

}





bool ConjuntoLetras::const_iterator::operator!=(const ConjuntoLetras::const_iterator &iter) {
    return el_iterador != iter.el_iterador;
}
bool ConjuntoLetras::const_iterator::operator==(const ConjuntoLetras::const_iterator &iter) {
    return el_iterador == iter.el_iterador;
}

const Letra& ConjuntoLetras::const_iterator::operator*() const{
    return *el_iterador;
}

ConjuntoLetras::const_iterator& ConjuntoLetras::const_iterator::operator++() {
    el_iterador++;
    return *this;
}


ConjuntoLetras::const_iterator ConjuntoLetras::end() const{
    return letras.end();
}

ConjuntoLetras::const_iterator ConjuntoLetras::begin() const{
    return letras.begin();
}