#include "dictionary.h"
#include <fstream>

// ------------------------------- Clase Diccionario --------------------------
Diccionario::Diccionario() {}

Diccionario::Diccionario(string fichero_diccionario) {
    fichero_diccionario >> this;
}

int Diccionario::size() const { return datos.size(); }

vector<string> Diccionario::PalabrasLongitud(int longitud) {
    vector <string> palabras;
    for (Diccionario::iterator it = begin(); it != end(); ++it)
        if ((*it).length() == longitud)
            palabras.push_back(*it);

    return palabras;
}

bool Diccionario::Esta(const string &palabra) const {
    if (datos.count(palabra) == 0)
        return false;
    else
        return true;
}

istream & operator>>(istream & is,Diccionario &D) {
    string palabra;
    while (getline(is, palabra))
        D.datos.insert(mayusculas(palabra));
    return is;
};

ostream & operator<<(ostream & os, const Diccionario &D) {
    for (Diccionario::iterator it = D.begin(); it != D.end(); ++it)
        os << *it << endl;

    return os;
}


//--------------------------- Clase Iterator ----------------------------------
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


// ----------------------------- Funciones externas ---------------------------
string mayusculas(const string &palabra) {
    for (int i = 0 ; i < palabra.length(); i++)
        palabra[i] = toupper(palabra[i]);
    return palabra;
}
