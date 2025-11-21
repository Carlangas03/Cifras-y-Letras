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

// istream& operator>>(istream& entrada, ConjuntoLetras& conj) {
//     string cadena;
//
//     getline(entrada,cadena);
//     Letra letra;
//     while (cadena.length() > 0) {
//         entrada >> letra;
//         conj.letras.insert(letra);
//     }
//     return entrada;
// }