#include <fstream>
#include <set>
#include <string>
#include <vector>
#include <iostream>

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



int main (int argc , char *argv[]) {
    srand(time(NULL));
    vector<int> C = {1,2,3,4,5,6,7,8,9,10,25,50,75,100};
    vector<int> conjunto = Conjunto(C,6);


    // GENERAR NUMERO A CONSEGUIR
    int meta = 100 + rand() % 900;
    cout << meta << endl;



    return 0;
}