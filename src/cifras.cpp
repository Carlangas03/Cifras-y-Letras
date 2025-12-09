#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

/**
 * @brief Conjunto aleatorio
 * @param conj : conjunto de numeros a partir del cual generamos nuestro conjunto
 * @param num_elementos : tamaño del conjunto a conseguir
 * @return Conjunto de numeros enteros de tamaño num_elementos
 *         sacados de forma aleatoria de conj
 */
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


bool Solucion ( vector<int> &conjunto, int meta, string sol_actual, string &sol) {

    // Primero ordenamos los numeros (evitamos restas negativas o divisiones indeseadas)
    sort(conjunto.begin(),conjunto.end());

    //Si la solución está en mi conjunto
    if (find (conjunto.begin(),conjunto.end(),meta) != conjunto.end()) {
        sol = sol_actual;
        return true;
    }

    for (int i = 0 ; i < conjunto.size(); i++) {
        for (int j = i+1; j < conjunto.size(); j++) {

            vector<int> restantes = conjunto;

            int numi = restantes[i];
            int numj = restantes[j];
            string operacion;

            // Eliminamos los numeros que vamos a usar
            restantes.erase(restantes.begin()+j);
            restantes.erase(restantes.begin()+i);

            //OPERACIONES :
            // SUMA
            restantes.push_back(numi+numj);
            operacion = sol_actual + to_string (numi) + " + " + to_string (numj) + " = " + to_string(restantes.back()) + "\n";
            if (Solucion(restantes,meta,operacion,sol)) return true;
            restantes.pop_back();

            // RESTA
            if (numj != numi) { // evitamos el numero 0 para evitar divisiones incorrectas
                restantes.push_back(numj-numi);
                operacion = sol_actual+ to_string (numj) + " - " + to_string (numi) + " = " + to_string(restantes.back()) + "\n";
                if (Solucion(restantes,meta,operacion,sol)) return true;
                restantes.pop_back();
            }


            //MULTIPLICACION
            restantes.push_back(numj*numi);
            operacion = sol_actual+ to_string (numj) + " * " + to_string (numi) + " = " + to_string(restantes.back()) + "\n";
            if (Solucion(restantes,meta,operacion,sol)) return true;
            restantes.pop_back();

            //DIVISION
            if (numj % numi == 0) {
                restantes.push_back(numj/numi);
                operacion = sol_actual + to_string (numj) + " / " + to_string (numi) + " = " + to_string(restantes.back()) + "\n";
                if (Solucion(restantes,meta,operacion,sol)) return true;
                restantes.pop_back();
            }

        } // for (int j ...
    } // for (int i ...

    //si no se ha encontrado la solucion
    return false;
}



int main (int argc , char *argv[]) {
    srand(time(NULL));
    vector<int> C = {1,2,3,4,5,6,7,8,9,10,25,50,75,100};

    //GENERAR EL CONJUNTO DE NUMEROS
    vector<int> conjunto = Conjunto(C,6);
    cout << "Las cifras son : " << endl;
    for (int i = 0; i < conjunto.size(); i++)
        cout << conjunto[i] << " ";


    // GENERAR NUMERO A CONSEGUIR
    int meta = GeneraMeta();
    cout << "\nNumero a conseguir: " << meta << endl;


    // GENERAR SOLUCION
    string solucion;
    if (Solucion(conjunto, meta,solucion, solucion)) {
        cout << "Hay solucion: " << endl;
        cout << solucion << endl;
    } else {
        cout << "No hay solucion" << endl;
    }
    return 0;
}