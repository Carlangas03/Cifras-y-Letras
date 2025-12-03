//
// PARA COMPILAR:
//  g++ -I ./include ./src/dictionary.cpp ./src/letters_bag.cpp ./src/letras.cpp ./src/letters_set.cpp -o letras
//
#include "dictionary.h"
#include <fstream>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include "letters_set.h"
#include "letters_bag.h"
#include <ctime>
using namespace std;

void Mayuscula (string &cadena) {
    for (int i = 0; i < cadena.size(); i++) {
        cadena[i] = toupper(cadena[i]);
    }
}

int puntuacion(string palabra, const Diccionario & diccionario, const ConjuntoLetras &conjunto, char &modalidad) {

    int punt = 0;

    if (diccionario.Esta(mayusculas(palabra))) {
        if (modalidad == 'L')
            punt = palabra.size();

        else if (modalidad == 'P') {
            for (int i = 0 ; i < palabra.length(); i++ ) {
                Letra letra = conjunto.getLetra(palabra.at(i));
                punt += letra.getPuntuacion();
            }
        }

        else {
            cout << "ERROR: La modalidad que se ha seleccionado no corresponde "
                 << "con ninguna de las opciones posibles.\n"
                 << "Escriba la modalidad de nuevo [P/L]: ";
            cin >> modalidad;
            modalidad = toupper(modalidad);
            punt = puntuacion(palabra, diccionario, conjunto, modalidad);
        }
    }

    return punt;
}


void permutaciones (string cadena, set<string> &perm, const Diccionario &diccionario ,
                    const ConjuntoLetras & conj, int punt_min, char modalidad) {

    if (cadena.length() == 0) {return ;}

    do {
        if (diccionario.Esta(cadena) &&
            puntuacion (cadena,diccionario,conj,modalidad) >= punt_min) perm.insert(cadena);
    } while (next_permutation(cadena.begin(),cadena.end()));


    for (auto i = 0; i < cadena.size(); i++) {
        string cadena_aux = cadena;
        cadena_aux.erase(i, 1);
        permutaciones(cadena_aux, perm, diccionario, conj, punt_min, modalidad);
    }

}


/**
 * Muestra ayuda para el uso del programa
 * @param salida : flujo de salida en el que se muestra la ayuda
 */
void showHelp(ostream &salida) {
    salida << "ERROR en los parametros de letras." << endl;
    salida << "Ejecutar con los siguientes parametros: " << endl;
    salida << '\t' << "./bin/letras [diccionario.txt] [letras.txt] ";
    salida << "[num. letras] [modalidad]" <<endl;
    salida << endl;
    salida << "Parametros:" << endl;
    salida << '\t' << "[diccionario.txt] : fichero con el diccionario" << endl;
    salida << '\t' << "[letras.txt] : fichero con las letras" << endl;
    salida << '\t' << "[num. letras] : numero de letras que se deben generar" ;
    salida << " de forma aleatoria" << endl;
    salida << '\t' << "[modalidad] : modalidad de juego" << endl;
    salida << "\t\t\t\t" << "Longitud: si el parametro es L, se buscara la palabra mas larga" << endl;
    salida << "\t\t\t\t" << "Puntuacion: si el parametro es P, se buscara la palabra con mas puntuacion" << endl;
}

int main(int argc, char *argv[]) {

    if (argc != 5) {
        showHelp(cout);
        return 1;
    }

    srand(time(NULL));

    // Cargar los datos
    Diccionario diccionario;
    BolsaLetras bolsa;


    //ifstream entrada_dicc (argv[1]);
    ifstream entrada_dicc;
    entrada_dicc.open(argv[1]);
    if (!entrada_dicc)
        throw ios_base::failure(string("Error abriendo el archivo ") + string(argv[1]));

    // ifstream entrada_bolsa (argv[2]);
    // ifstream entrada_bolsa (argv[2]);
    // if (!entrada_bolsa)
    //     throw ios_base::failure(string("Error abriendo el archivo ") + string(argv[2]));


    int tamanio_bolsa = stoi(argv[3]);
    char modalidad = *argv[4];

    // Variables que se van a necesitar en el transcurso del juego
    ConjuntoLetras conjunto;
    ifstream entrada_conj (argv[2]);
    if (!entrada_conj)
        throw ios_base::failure(string("Error abriendo el archivo ") + string(argv[2]));

    entrada_conj >> conjunto;

    //set<string> perm;   -->tiene que ir dentro para no ir acumulando permutaciones
    char c;

    /*************************************************************************/

    entrada_dicc >> diccionario;    // set<string> (palabras válidas)

    entrada_dicc.close();

    do {
        string palabra_usr, mejor_solucion;

        // //Entrada de la bolsa (dentro del bucle para garantizar que en todas las
        // //iteraciones tenemos todos los caracteres disponibles)
        // entrada_bolsa >> bolsa;         // string del campo 'char' (tantas veces
        //                                 // como indica el campo 'int cantidad')
        // entrada_bolsa.close();
        bolsa.cargarBolsa(conjunto);
        cout << bolsa;

        // Generar una bolsa de n caracteres aleatorios de entre la bolsa
        string bolsita;
        for (int i = 0 ; i < tamanio_bolsa ; i++) {
            bolsita += bolsa.get();
        }

        // Parte interactiva: Solución del usuario
        cout << endl;
        cout << "Las letras son: " << bolsita << endl;
        cout << "Dime tu solucion: ";
        getline(cin, palabra_usr);
        Mayuscula(palabra_usr);
        // cin >> palabra_usr;

        while (!diccionario.Esta(palabra_usr)) {
            cout << "Su palabra no esta en el diccionario." << endl;
            cout << "Intentelo de nuevo." << endl;
            cout << "Dime tu solucion: ";
            getline(cin, palabra_usr);
            Mayuscula(palabra_usr);
        }

        modalidad=toupper(modalidad);
        int punt_usuario = puntuacion(palabra_usr, diccionario, conjunto, modalidad);
        cout << palabra_usr << " --> Puntuacion: " << punt_usuario << endl;

        set<string> perm;
        // Posibles soluciones
        sort(bolsita.begin(), bolsita.end());

        permutaciones(bolsita, perm, diccionario, conjunto,punt_usuario, modalidad);


        /*********************************************************************/
        cout << endl << "Mis soluciones son: " << endl;
        for (set<string>::iterator it = perm.begin(); it != perm.end(); it++) {


            //HAY QUE CAMBIAR PARA MOSTRAR LA PUNTUACION DE
            cout << *it << "\tPuntuacion: " << (*it).length() << endl;

            //HAY QUE CAMBIAR ESTO
            //
            // if ((*it).length() >= punt_usuario) {
            //
            //     if ((*it).length() > mejor_solucion.length()) mejor_solucion = *it;
            // }
        }
        cout << endl << "Mejor solucion: " << mejor_solucion;
        cout << endl << endl;

        // Condición para repetir el juego
        cout << "¿Seguir jugando [S/N]?: ";
        cin >> c;
        cin.ignore();
        c = toupper(c);
        while (c != 'S' && c != 'N') {
            cout << "Caracter no valido. Escriba de nuevo [S/N]: ";
            cin >> c;
            cin.ignore();
            c = toupper(c);
        }

    } while (c == 'S');

    return 0;
}