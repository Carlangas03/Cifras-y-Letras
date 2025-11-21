// //
// // Created by elena on 21/11/2025.
// //
// #include <iostream>
// #include <fstream>
// #include <map>
// #include "letters_set.h"
// #include "dictionary.h"
// using namespace std;
//
// int main (int argc, char* argv[]) {
//     if (argc != 4) {
//         cout << "ERROR: Argumentos incorrectos" ;
//         return 1;
//     }
//
//
//     ifstream dicc (argv[1]);
//     if (!dicc.is_open()) {
//         cout << "ERROR: No se ha podido abrir el diccionario.";
//         return 1;
//     }
//     ifstream let (argv[2]);
//     if (!let.is_open()) {
//         cout << "ERROR: No se ha podido abrir el archivo letras.";
//         return 1;
//     }
//
//     Diccionario diccionario ;
//     ConjuntoLetras letras;
//     dicc >> diccionario;
//     let >> letras;
//     map<char,int> caracteres;
//     Diccionario::iterator it = diccionario.begin();
//     int num_caracteres = 0;
//
//     while (it != diccionario.end()) {
//         for (int i = 0 ; i < (*it).size(); i++) {
//             caracteres[(*it)[i]] += 1;
//             num_caracteres++;
//         }
//         it++;
//     }
//
//
//     return 0;
// }
//
