//
// PARA COMPILAR
// g++ ./src/cifras.cpp -o ./bin/cifras
//
// PARA EJECUTAR
// ./bin/cifras

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <thread>
#include <iomanip>

using namespace std;

/**
 * @brief Conjunto aleatorio
 * @param conj : conjunto de numeros a partir del cual generamos nuestro conjunto
 * @param num_elementos : tamaño del conjunto a conseguir
 * @return Conjunto de numeros enteros de tamaño num_elementos
 *         sacados de forma aleatoria de conj
 */
vector<int> Conjunto (const vector<int> &conj , int num_elementos) ;


/**
 * @brief Generar un numero de tres cifras
 * @return Numero entero aleatorio de tres cifras
 */
int GeneraMeta () ;

/**
 * @brief Busca las operaciones necesarias para conseguir un numero
 * @param conjunto : conjunto de numeros a partir del cual se genera la solución.
 * @param meta : numero a conseguir
 * @param sol_actual : operaciones realizadas sobre el conjunto de numeros
 * @param sol : string con los pasos a seguir para conseguir la solucion
 * @return : true si se ha conseguido la solucion
 *           false en otro caso
 */
bool Solucion (vector<int> &conjunto, int meta, string sol_actual, string &sol,
                int &aprox, string &mejor_sol);

/**
 * @brief Temporizador para permitir que el usuario pueda pensar su solución.
 * @details Imprime una línea formateada de la forma mm:ss. A cada segundo que
 * pasa, los segundos (ss) disminuyen en una unidad, y se reimprime el temporizador
 * con la instrucción os << "\r" << ... << flush;. para parar el programa un segundo
 * se usan las funciones this_thread::sleep_for(rel_time) y chrono::seconds(1).
 * @param tiempo_total Tiempo en segundos para empezar el temporizador.
 * @param os Flujo de salida en el que se imprime el temporizador. Por defecto,
 * os = cout.
 */
void Temporizador(int tiempo_total, ostream &os = cout);


/********************************************************************************************/
// PROGRAMA PRINCIPAL CIFRAS

int main (int argc , char *argv[]) {
    char seguir_jugando;
    srand(time(NULL));
    vector<int> C = {1,2,3,4,5,6,7,8,9,10,25,50,75,100};
    const int TIEMPO_DE_JUEGO = 30;

    do {
        //GENERAR EL CONJUNTO DE NUMEROS
        vector<int> conjunto = Conjunto(C,6);
        // conjunto = {10,2,2,10,25,75};
        cout << "Las cifras son : " << endl;
        for (int i = 0 ; i < conjunto.size() ; i++)
            cout << conjunto[i] << " ";

        // GENERAR NUMERO A CONSEGUIR
        int meta = GeneraMeta();
        // meta =  678;
        cout << "\nNumero a conseguir: " << meta << endl;

        Temporizador(TIEMPO_DE_JUEGO);

        // GENERAR SOLUCION
        int aprox = 1000; //lo suficientemente grande
        string solucion, mejor_solucion;
        if (Solucion(conjunto, meta,solucion,solucion,aprox,mejor_solucion)) {
            cout << "Hay solucion: " << endl;
            cout << solucion << endl;
        } else {
            cout << "No hay solucion" << endl;
            cout << "Mi aproximacion es: " << endl << mejor_solucion ;
            cout << "Diferencia de " << aprox << endl << endl;
        }

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
vector<int> Conjunto (const vector<int> &conj , int num_elementos) {
    vector<int> conjunto;
    for (int i = 0; i < num_elementos; i++) {
        int j = rand() % conj.size();   // números entre 0 y size-1
        conjunto.push_back(conj[j]);
    }
    return conjunto;
}

int GeneraMeta () {
    return 100 + rand() % 900;
}

bool Solucion ( vector<int> &conjunto, int meta, string sol_actual, string &sol, int &aprox, string &mejor_sol) {

    //Si la solución está en mi conjunto
    if (find (conjunto.begin(),conjunto.end(),meta) != conjunto.end()) {
        sol = sol_actual;
        return true;
    }
    if (conjunto.size()==1)
        return false;

    sort(conjunto.begin(),conjunto.end());

    for (int i = 0 ; i < conjunto.size() ; i++) {
        for (int j = i + 1; j < conjunto.size(); j++) {
            vector<int> restantes = conjunto;

            int numi = restantes[i];
            int numj = restantes[j];
            string operacion;

            // Eliminamos los numeros que vamos a usar
            restantes.erase(restantes.begin()+j); //primero borro el de la posicion mayor
            restantes.erase(restantes.begin()+i);


            //OPERACIONES :
            // SUMA
            restantes.push_back(numi+numj);
            operacion = sol_actual + to_string (numi) + " + " + to_string (numj) ;
            operacion += " = " + to_string(restantes.back()) + "\n";
            if (aprox > abs(restantes.back()-meta)) {
                aprox = abs(restantes.back()-meta);
                mejor_sol = operacion;
            }
            if (Solucion(restantes,meta,operacion,sol,aprox,mejor_sol)) return true;
            restantes.pop_back();

            // RESTA
            if (numj != numi) { // evitamos el numero 0 para evitar divisiones incorrectas
                restantes.push_back(numj-numi);
                operacion = sol_actual+ to_string (numj) + " - " + to_string (numi) ;
                operacion += " = " + to_string(restantes.back()) + "\n";
                if (aprox > abs(restantes.back()-meta)) {
                    aprox = abs(restantes.back()-meta);
                    mejor_sol = operacion;
                }
                if (Solucion(restantes,meta,operacion,sol,aprox,mejor_sol)) return true;
                restantes.pop_back();
            }

            //MULTIPLICACION
            restantes.push_back(numj*numi);
            operacion = sol_actual+ to_string (numj) + " * " + to_string (numi) ;
            operacion += " = " + to_string(restantes.back()) + "\n";
            if (aprox > abs(restantes.back()-meta)) {
                aprox = abs(restantes.back()-meta);
                mejor_sol = operacion;
            }
            if (Solucion(restantes,meta,operacion,sol,aprox,mejor_sol)) return true;
            restantes.pop_back();

            //DIVISION
            if (numj % numi == 0 && numi != 0) { // Comprobamos que la division es válida
                restantes.push_back(numj/numi);
                operacion = sol_actual + to_string (numj) + " / " + to_string (numi) ;
                operacion += " = " + to_string(restantes.back()) + "\n";
                if (aprox > abs(restantes.back()-meta)) {
                    aprox = abs(restantes.back()-meta);
                    mejor_sol = operacion;
                }
                if (Solucion(restantes,meta,operacion,sol,aprox,mejor_sol)) return true;
                restantes.pop_back();
            }

        } // for (int j ...
    } // for (int i ...

    //si no se ha encontrado la solucion
    return false;
}

void Temporizador (int tiempo_total, ostream & os) {
    for (int i = tiempo_total; i >= 0; i--) {
        int minutos = i / 60;
        int segundos = i % 60;
        os << "\r" << "Tiempo restante: "
           << setw(2) << setfill('0') << minutos << ":"
           << setw(2) << setfill('0') << segundos << flush;
        this_thread::sleep_for(chrono::seconds(1));
    }
    os << endl << endl;
}