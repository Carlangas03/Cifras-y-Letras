//
// Created by elena on 21/11/2025.
// PARA COMPILAR
// g++ -I./include ./src/dictionary.cpp ./src/letters_set.cpp ./src/cantidad_letras.cpp -o ./bin/cantidad_letras
//
// PARA EJECUTAR
// ./bin/cantidad_letras ./data/diccionario.txt ./data/letras.txt
//
#include <iostream>
#include <fstream>
#include <limits>
#include <map>
#include "letters_set.h"
#include "dictionary.h"
using namespace std;

pair<int,int> getMaxMin(map<char,int> caracteres) {

    int maximo = std::numeric_limits<int>::min();
    int minimo = std::numeric_limits<int>::max();

    for (auto it = caracteres.begin();it != caracteres.end(); ++it) {
        maximo = max(maximo, (*it).second);
        minimo = min(minimo, (*it).second);
    }

    return pair<int,int>(maximo, minimo);
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
    map<char,int> caracteres;
    //int num_caracteres = 0;

    for (Diccionario::iterator it = diccionario.begin();it != diccionario.end(); ++it)

        for (int i = 0 ; i < (*it).size(); i++)

            if ( (*it)[i] >= 65 && (*it)[i] <= 90 ||
                 ((*it)[i] >= 97 && (*it)[i] <= 122) ) { //asegurarnos que es una letra

                if (!caracteres.count((*it)[i])) caracteres[(*it)[i]] = 0;
                caracteres[(*it)[i]] += 1;
                //num_caracteres++;
            }

    for (map<char,int>::iterator it2 = caracteres.begin(); it2 != caracteres.end(); it2++) {
        Letra nueva_letra ((*it2).first, (*it2).second,0);
        nueva_letra.setPuntuacion((*it2).second, getMaxMin(caracteres));
        letras.insert(nueva_letra);
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