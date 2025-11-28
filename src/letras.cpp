//
// Created by elena on 28/11/2025.
//
#include "dictionary.h"
#include <fstream>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>

#include "letters_bag.h"
#include <ctime>
using namespace std;

void permutaciones (string cadena, set<string> &perm, const Diccionario &diccionario) {

    if (cadena.length() == 0) {return ;}

    do {
        if (diccionario.Esta(cadena)) perm.insert(cadena);
    } while (next_permutation(cadena.begin(),cadena.end()));


    for (auto i = 0; i < cadena.size(); i++) {
        string cadena_aux = cadena;
        cadena_aux.erase(i, 1);
        permutaciones(cadena_aux, perm, diccionario);
    }

}

int main() {
    srand(time(NULL));
    Diccionario diccionario;

    BolsaLetras bolsa;
    ifstream entrada ("./data/letras.txt");
    ifstream entrada2 ("./data/diccionario.txt");

    entrada2 >> diccionario;

    entrada >> bolsa;
    string bolsita;

    for (int i = 0 ; i< 8 ; i++) {
        bolsita += bolsa.get();
    }
    cout << bolsita;
    sort(bolsita.begin(), bolsita.end());


    set<string> perm;
    //Posibles soluciones
    permutaciones(bolsita, perm, diccionario);

    set<string>::iterator it = perm.begin();
    for (it ; it != perm.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}