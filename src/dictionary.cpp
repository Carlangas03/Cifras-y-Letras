#include "dictionary.h"
#include <fstream>

Diccionario::Diccionario() {}

int Diccionario::size() const { return datos.size(); }

bool Diccionario::Esta(string palabra) {
    if (datos.count(palabra) == 0)
        return false;
    else
        return true;
}

vector<string> Diccionario::PalabrasLongitud(int longitud) {
    vector <string> palabras;

    for (set<string>::iterator it = datos.begin(); it != datos.end(); ++it)
        if (it->length() == longitud)
            palabras.push_back(*it);

    return palabras;
}

ostream & operator<<(ostream & os, const Diccionario &D) {
    for (set<string>::iterator it = D.datos.begin(); it != D.datos.end(); ++it)
        os << *it << endl;

    return os;
}

istream & operator>>(istream & is,Diccionario &D) {
    string palabra;
    while (getline(is, palabra))
        D.datos.insert(palabra);

    return is;
}

Diccionario::iterator() {

}

Diccionario::iterator Diccionario::iterator & operator ++();
bool operator ==(const iterator &i);
bool operator !=(const iterator &i);

Diccionario::iterator begin() {

}

Diccionario::iterator end() {

}





{
};

