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

int puntuacion(string palabra, const Diccionario & diccionario, ConjuntoLetras conjunto, char modalidad) {

    int punt = 0;

    if (diccionario.Esta(mayusculas(palabra))) {
        if (modalidad == 'L')
            punt = palabra.size();

        else if (modalidad == 'P') {
            //for (string::iterator it = palabra.begin(); it != palabra.end(); it++ ) {
            //    punt += conjunto[*it].getCantidad();
            //}
        }

        else {
            cout << "ERROR: La modalidad que se ha seleccionado no corresponde "
                 << "con ninguna de las opciones posibles.\n"
                 << "Escriba la modalidad de nuevo [P/L]: ";
            cin >> modalidad;
            punt = puntuacion(palabra, diccionario, conjunto, toupper(modalidad));
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
    ConjuntoLetras conjunto;
    string palabra_usr, mejor_solucion;
    set<string> perm;
    char c;

    /*************************************************************************/
    entrada_bolsa >> bolsa;         // string del campo 'char' (tantas veces
                                    // como indica el campo 'int cantidad')
    entrada_dicc >> diccionario;    // set<string> (palabras válidas)

    entrada_bolsa.close(); entrada_dicc.close();

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

        int punt_usuario = puntuacion(palabra_usr, diccionario, conjunto, toupper(modalidad));
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
        c = toupper(c);
        while (c != 'S' && c != 'N') {
            cout << "Caracteres no validos. Escriba de nuevo [S/N]: ";
            cin >> c;
            c = toupper(c);
        }

    } while (c == 'S');

    return 0;
}