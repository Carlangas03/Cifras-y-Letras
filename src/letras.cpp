//
// PARA COMPILAR:
//  g++ -I ./include ./src/dictionary.cpp ./src/letters_bag.cpp ./src/letras.cpp ./src/letters_set.cpp -o letras
//
// PARA EJECUTAR
// ./bin/letras ./data/diccionario.txt ./data/letras.txt [L|P] n

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


/**
 * @brief Calcular la puntuacion
 * @param palabra : palabra a la que se le calcula la puntuación
 * @param diccionario : diccionario en el que debe estar la palabra para ser puntuada
 * @param conjunto : conjunto de letras que contiene la puntuacion de cada caracter
 * @return Puntuacion de una palabra
 */
int puntuacion(string palabra, const Diccionario & diccionario,
               const ConjuntoLetras &conjunto);

/**
 * @brief Calcular palabras a partir de un conjunto de letras
 * @param cadena : letras a partir de las cuales se calculan las permutaciones
 * @param perm : permutaciones ya calculadas
 * @param diccionario : diccionario en el cual las posibles permutaciones deben aparecer
 */
void permutaciones (string cadena, set<string> &perm, const Diccionario &diccionario);

/**
 * @brief Muestra ayuda para el uso del programa
 * @param salida : flujo de salida en el que se muestra la ayuda
 */
void showHelp(ostream &salida);



/*******************************************************************************/
// PROGRAMA PRINCIPAL

int main(int argc, char *argv[]) {
    srand(time(NULL));

    // Compruebo que el numero de argumentos es correcto
    if (argc != 5) {
        showHelp(cout);
        return 1;
    }

    // Comprobamos los argumentos
    ifstream entrada_dicc;
    entrada_dicc.open(argv[1]);
    if (!entrada_dicc)
        throw ios_base::failure(string("Error abriendo el archivo ") + string(argv[1]));

    ifstream entrada_conj;
    entrada_conj.open(argv[2]);
    if (!entrada_conj)
        throw ios_base::failure(string("Error abriendo el archivo ") + string(argv[2]));

    int tamanio_bolsa = stoi(argv[3]);

    char modalidad = toupper(*argv[4]);
    while (modalidad != 'L' && modalidad != 'P') {
        cout << "ERROR: La modalidad que se ha seleccionado no corresponde "
                 << "con ninguna de las opciones posibles.\n"
                 << "Escriba la modalidad de nuevo [P/L]: ";
            cin >> modalidad;
            modalidad = toupper(modalidad);
    }


    Diccionario diccionario;
    ConjuntoLetras conjunto;
    entrada_dicc >> diccionario;
    entrada_dicc.close();
    entrada_conj >> conjunto;
    entrada_conj.close();

    //Variables que se usan a lo largo del programa
    BolsaLetras bolsa;
    char seguir_jugando;

    /*************************************************************************/

    do {
        string palabra_usr, mejor_solucion;
        int punt_usuario, mejor_punt;

        //Entrada de la bolsa, dentro del bucle para garantizar que en todas las iteraciones
        //tenemos todos los caracteres disponibles
        bolsa.cargarBolsa(conjunto);

        // Generar una bolsa de n caracteres aleatorios de entre la bolsa
        string bolsita;
        for (int i = 0 ; i < tamanio_bolsa ; i++)
            bolsita += bolsa.get();


        // SOLUCIÓN DEL USUARIO
        cout << endl;
        cout << "Las letras son: " << bolsita << endl;

        //GENERAR LAS POSIBLES SOLUCIONES
        set<string> perm;
        sort(bolsita.begin(),bolsita.end());
        permutaciones(bolsita, perm, diccionario);


        cout << "Dime tu solucion: ";
        getline(cin, palabra_usr);
        mayusculas(palabra_usr);


        //COMPROBACIÓN DE QUE LA SOLUCIÓN DEL USUARIO ES VÁLIDA
        while (!diccionario.Esta(palabra_usr) || perm.count(palabra_usr) == 0) {
            cout << "Su palabra no es valida." << endl;
            cout << "Intentelo de nuevo." << endl;
            cout << "Dime tu solucion: ";
            getline(cin, palabra_usr);
            mayusculas(palabra_usr);
        }

        // calcular puntuacion del usuario
        if (modalidad == 'L') punt_usuario = palabra_usr.length();
        else punt_usuario = puntuacion (palabra_usr,diccionario,conjunto);
        cout << palabra_usr << " --> Puntuacion: " << punt_usuario << endl;

        mejor_solucion = palabra_usr;
        mejor_punt = punt_usuario;
        // POSIBLES SOLUCIONES (mejores que la del usuario)
        cout << endl << "Mis soluciones son: " << endl;

        for (set<string>::iterator it = perm.begin(); it != perm.end(); it++) {

            int punt ;

            if (modalidad == 'L') punt = (*it).length();
            else punt = puntuacion(*it,diccionario,conjunto);

            if (punt > punt_usuario) {
                cout << *it << "\tPuntuacion: " << punt << endl;
                if (punt > mejor_punt ) {
                    mejor_punt = punt;
                    mejor_solucion = *it;
                }
            }
        }

        cout << endl << "Mejor solucion: " << mejor_solucion;
        cout << endl << "Puntuacion: " << mejor_punt;
        cout << endl << endl;

        // CONDICIÓN PARA SEGUIR EL JUEGO
        cout << "¿Seguir jugando [S/N]?: ";
        cin >> seguir_jugando;
        cin.ignore();
        seguir_jugando = toupper(seguir_jugando);
        while (seguir_jugando != 'S' && seguir_jugando != 'N') {
            cout << "Caracter no valido. Escriba de nuevo [S/N]: ";
            cin >> seguir_jugando;
            cin.ignore();
            seguir_jugando = toupper(seguir_jugando);
        }
    } while (seguir_jugando == 'S');

    return 0;
}



// FUNCIONES

int puntuacion(string palabra, const Diccionario & diccionario,
               const ConjuntoLetras &conjunto) {

    int punt = 0;
    mayusculas(palabra);

    if (diccionario.Esta(palabra))

        for (int i = 0 ; i < palabra.length() ; i++ ) {
            Letra letra = conjunto.getLetra(palabra.at(i));
            punt += letra.getPuntuacion();
        }
    return punt;
}


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