//
// Created by elena on 21/11/2025.
//
#include <iostream>
#include <fstream>
#include <map>
#include "letters_set.h"
#include "dictionary.h"
using namespace std;

int CalcularPuntuacion(double apariciones, double total, int num_letras) {
    double porcentaje = apariciones / total;
    return 10 - num_letras*porcentaje;
}

int main (int argc, char* argv[]) {
    if (argc != 3) {
        cout << "ERROR: Argumentos incorrectos" ;
        return 1;
    }


    ifstream dicc (argv[1]);
    if (!dicc.is_open()) {
        cout << "ERROR: No se ha podido abrir el diccionario.";
        return 1;
    }

    // ifstream let (argv[2]);
    // if (!let.is_open()) {
    //     cout << "ERROR: No se ha podido abrir el archivo letras.";
    //     return 1;
    // }

    Diccionario diccionario ;
    ConjuntoLetras letras;
    dicc >> diccionario;
    // let >> letras;
    map<char,int> caracteres;
    Diccionario::iterator it = diccionario.begin();
    int num_caracteres = 0;

    while (it != diccionario.end()) {
        for (int i = 0 ; i < (*it).size(); i++) {
            if (!caracteres.count((*it)[i])) caracteres[(*it)[i]] = 0;
            caracteres[(*it)[i]] += 1;
            num_caracteres++;
        }
        ++it;
    }

    map<char,int>::iterator it2 = caracteres.begin();
    cout << num_caracteres << endl;
    while (it2 != caracteres.end()) {
        Letra nueva_letra ((*it2).first, (*it2).second,CalcularPuntuacion((*it2).second, num_caracteres, caracteres.size()));
        letras.insert(nueva_letra);
        it2++;
    }


    ofstream salida (argv[2]);
    if (!salida.is_open()) {
        cout << "ERROR: No se ha podido abrir el archivo de salida.";
        return 1;
    }

    // Obtener un fichero salida.txt con las tres columnas (letra, cantidad, puntuacion)
    salida << letras;

    return 0;
}

