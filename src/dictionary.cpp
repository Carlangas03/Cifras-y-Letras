#include "dictionary.h"
#include <fstream>

Diccionario::Diccionario() {}

int Diccionario::size() const { return datos.size(); }

bool Diccionario::Esta(const string &palabra) {
    if (datos.count(palabra) == 0)
        return false;
    else
        return true;
}

vector<string> Diccionario::PalabrasLongitud(int longitud) {
    vector <string> palabras;
    for (Diccionario::iterator it = begin(); it != end(); ++it)
        if ((*it).length() == longitud)
            palabras.push_back(*it);

    return palabras;
}

ostream & operator<<(ostream & os, const Diccionario &D) {
    for (Diccionario::iterator it = D.begin(); it != D.end(); ++it)
        os << *it << endl;

    return os;
}

istream & operator>>(istream & is,Diccionario &D) {
    string palabra;
    while (getline(is, palabra))
        D.datos.insert(palabra);

    return is;
};

Diccionario::iterator::iterator() {}

const string & Diccionario::iterator::operator*() const {
    return *it;
}

Diccionario::iterator & Diccionario::iterator::operator ++() {
    ++it;
    return *this;
}

bool Diccionario::iterator::operator ==(const iterator &i) {
    return (i.it == it);
}

bool Diccionario::iterator::operator !=(const iterator &i) {
    return (i.it != it);
};

const Diccionario::iterator Diccionario::begin() const {
    iterator i;
    i.it = datos.begin();
    return i;
}

const Diccionario::iterator Diccionario::end() const {
    iterator i;
    i.it = datos.end();
    return i;
}

