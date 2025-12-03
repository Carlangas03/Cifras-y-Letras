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

int puntuacion(string palabra_usr, const Diccionario & diccionario, char modalidad) {

    int punt = 0;

    if (diccionario.Esta(mayusculas(palabra_usr))) {
        if (modalidad == 'L')
            punt = palabra_usr.size();

        else if (modalidad == 'P') {
            // sumar la puntuación de cada letra de la palabra palabra_usr
        }

        else {
            cout << "ERROR: La modalidad que se ha seleccionado no corresponde "
                 << "con ninguna de las opciones posibles.\n"
                 << "Escriba la modalidad de nuevo [P/L]: ";
            cin >> modalidad;
            punt = puntuacion(palabra_usr, diccionario, toupper(modalidad));
        }
    }

    return punt;
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    // Cargar los datos
    Diccionario diccionario;
    BolsaLetras bolsa;
    ifstream entrada_dicc (argv[1]);
    ifstream entrada_bolsa (argv[2]);
    int tamanio_bolsa = stoi(argv[3]);
    char modalidad = *argv[4];

    // Variables que se van a necesitar en el transcurso del juego
    string palabra_usr, mejor_solucion;
    set<string> perm;
    char c;

    /*************************************************************************/
    entrada_bolsa >> bolsa;
    entrada_dicc >> diccionario;

    do {
        // Generar una bolsa de n caracteres aleatorios de entre la bolsa
        string bolsita;
        for (int i = 0 ; i < tamanio_bolsa ; i++) {
            bolsita += bolsa.get();
        }

        // Parte interactiva: Solución del usuario
        cout << endl;
        cout << "Las letras son: " << bolsita << endl;
        cout << "Dime tu solucion: "; cin >> palabra_usr;

        int punt_usuario = puntuacion(palabra_usr, diccionario, toupper(modalidad));
        cout << palabra_usr << " --> Puntuacion: " << punt_usuario << endl;

        // Posibles soluciones
        sort(bolsita.begin(), bolsita.end());
        permutaciones(bolsita, perm, diccionario);


        /*********************************************************************/
        cout << endl << "Mis soluciones son: " << endl;
        for (set<string>::iterator it = perm.begin(); it != perm.end(); it++) {

            if ((*it).length() >= punt_usuario) {
                cout << *it << "\tPuntuacion: " << (*it).length() << endl;

                if ((*it).length() > mejor_solucion.length()) mejor_solucion = *it;
            }
        }
        cout << endl << "Mejor solucion: " << mejor_solucion;
        cout << endl << endl;

        // Condición para repetir el juego
        cout << "¿Seguir jugando [S/N]?: ";
        cin >> c;
    } while (c == 's' || c == 'S');

    return 0;
}