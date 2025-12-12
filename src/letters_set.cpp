#include "letters_set.h"

// --------------------------- Clase Letra ------------------------------------
// Letra () : cantidad(0), puntuacion(0) {};
// Letra (char car) : caracter(toupper(car)), cantidad(0), puntuacion(0) {};
// Letra (char car, int cant, int punt) : caracter(toupper(car)) , cantidad(cant) , puntuacion(punt) {};
// void setCaracter(char c) { caracter = c; };
// void setCantidad(int c) { cantidad = c; };
// void setPuntuacion (int p) { puntuacion = p; };

void Letra::setPuntuacion(int apariciones, pair<int,int> max_min) {
    const int MAXIMA_PUNTUACION = 10;

    double intervalo = (max_min.first - max_min.second) / MAXIMA_PUNTUACION;
    puntuacion = MAXIMA_PUNTUACION - (apariciones / intervalo) + 1;

    if (puntuacion==0) puntuacion = 1;
}

// char getCaracter() {return caracter; };
// int getCantidad() const { return cantidad; };
// int getPuntuacion() const { return puntuacion; };

bool Letra::operator<(const Letra &l) const {
    return caracter < l.caracter;
}

ostream& operator<<(ostream& salida, const Letra& letra) {
    salida << letra.getCaracter() << '\t' << letra.getCantidad() <<'\t'<<  '\t' << letra.getPuntuacion();
    return salida;
}

istream& operator>>(istream& entrada, Letra& letra) {
    entrada >> letra.caracter;
    entrada >> letra.cantidad;
    entrada >> letra.puntuacion;

    return entrada;
};


// ------------------------ Clase ConjuntoLetras ------------------------------
Letra ConjuntoLetras::getLetra(char caracter) const{

    bool continua = true;
    set<Letra>::iterator it = letras.begin();

    while (it != letras.end() && continua) {
        if ((*it).getCaracter() == caracter)
            continua = false;

        else
            it++;
    }
    return (*it);


}

ostream& operator<<(ostream& salida, const ConjuntoLetras& conj) {
    salida << "#Letra\tCantidad\tPuntos"<< endl;
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


// -------------------------- Clase Iterator ----------------------------------
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


// ----------------------- Clase Const_Iterator --------------------------------
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