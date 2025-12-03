#ifndef __LETTER_SET_H__
#define __LETTER_SET_H__

#include <set>
#include <sstream>
using namespace std;

/**
 * @brief TDA Letra
 *
 * Contiene información sobre un determinado carácter del juego de las
 * letras. En concreto, almacena información sobre el número de repeticiones de
 * la letra en la partida y de la puntuación que otorga al utilizarse en una
 * palabra
 */
class Letra {
private:
    char caracter;      /**< caracter de la letra */
    int cantidad;       /**< cantidad de veces que puede aparecer */
    int puntuacion;     /**< puntuación de la letra */

public:
    /**
     * @brief Constructor sin parámetros
     * @doc Establece la cantidad a 0 y la puntuación a 0
     */
    Letra () : cantidad(0), puntuacion(0) {};

    /**
     * @brief Constructor
     * @param car: caracter que representa la letra
     * @doc Establece la cantidad y la puntuación a 0
     */
    Letra (char car) : caracter(toupper(car)), cantidad(0), puntuacion(0) {};

    /**
     * @brief Constructor con parámetros
     * @param car: caracter que representa la letra
     * @param cant: cantidad de veces que aparece la letra
     * @param punt: puntuación asociada a la letra
     */
    Letra (char car, int cant, int punt) : caracter(toupper(car)) , cantidad(cant) , puntuacion(punt) {};

    /**
     * @brief Establece el caracter de la letra
     * @param c: caracter a establecer
     */
    void setCaracter(char c) { caracter = c; };

    /**
     * @brief Establece la cantidad de la letra
     * @param c: cantidad a establecer
     */
    void setCantidad(int c) { cantidad = c; };

    /**
     * @brief Establece la puntuación de la letra
     * @param p: puntuación a establecer
     */
    void setPuntuacion (int p) { puntuacion = p; };

    /**
     * @brief Establece la puntuación de la letra
     * @param apariciones: num veces que aparece una letra en un
     *                     diccionario
     * @param total: total de letras de un diccionario
     * @param num_letras: num letras diferentes de un diccionario
     * @doc La puntuación estará entre 1 y 10
     */
    void setPuntuacion (int apariciones , int total, int num_letras);

    /**
     * @brief Devuelve el caracter asociado a una letra
     * @return Caracter asociado a una letra
     */
    char getCaracter() const { return caracter; };

    /**
     * @brief Devuelve la cantidad asociada a una letra
     * @return Cantidad asociada a una letra
     */
    int getCantidad() const { return cantidad; };

    /**
     * @brief Devuelve la puntuación asociada a una letra
     * @return Puntuación asociada a una letra
     */
    int getPuntuacion() const { return puntuacion; };

    /**
     * @brief Sobrecarga del operador < para Letra
     * @param l: letra con la que se compara el objeto implícito
     * @return true si el objeto implícito es menor que l
     *         false en otro caso
     * @doc Una letra L1 es menor que L2 si :
     *          L1.caracter < L2.caracter
     */
    bool operator<(const Letra& l) const;


    /**
     * @brief Escribe en un flujo de salida una letra
     * @param salida flujo de salida
     * @param letra: el objeto que se escribe.
     * @return el flujo de salida
     */
    friend ostream& operator<<(ostream& salida, const Letra& letra);

    /**
     * @brief Lee de un flujo de entrada una letra
     * @param entrada flujo de entrada
     * @param letra: el objeto donde se realiza la lectura.
     * @return el flujo de entrada
     */
    friend istream& operator>>(istream& entrada, Letra& letra);
};



/**
 * @brief TDA ConjuntoLetras
 *
 * Este TDA representa un conjunto de letras, con la información necesaria para
 * jugar una partida al juego de las letras, es decir, el número de repeticiones
 * que tenemos de la letra y la puntuación que dicha letra otorga cuando se
 * utiliza en una palabra
 */

class ConjuntoLetras {
private:
    set<Letra> letras;  /**< conjunto de letras */
public:
    /**
     * @brief
     * @param caracter
     * @return
     */
    Letra& operator[](char caracter);

    /**
    * @brief Escribe en un flujo de salida un conjunto de letras
    * @param salida flujo de salida
    * @param letra: el objeto que se escribe.
    * @return el flujo de salida
    */
    friend ostream& operator<<(ostream& salida, const ConjuntoLetras& conj);

    /**
     * @brief Lee de un flujo de entrada un conjunto de letras
     * @param entrada flujo de entrada
     * @param letra: el objeto donde se realiza la lectura.
     * @return el flujo de entrada
     */
    friend istream& operator>>(istream& entrada, ConjuntoLetras& conj);

    /**
     * @brief Insertar una letra
     * @param letra: letra a insertar
     * @doc letra se inserta de forma ordenada
     */
    void insert (const Letra &letra);

    // /**
    //  * @brief Obtener puntuación de una cadena
    //  * @param cadena : cadena a la que queremos calcular la puntuación
    //  * @return puntuación de la cadena
    //  * @doc La puntuación se calcula según las puntuaciones de las letras del
    //  *      ConjuntoLetras
    //  */
    // int getPuntuacion (const string &cadena);

    class iterator {
    private:
        set<Letra>::iterator el_iterador;
    public:
        iterator() {}
        iterator(set<Letra>::iterator iter) : el_iterador(iter) {};
        bool operator!=(const ConjuntoLetras::iterator &iter);
        bool operator==(const ConjuntoLetras::iterator &iter);
        const Letra& operator*() const;
        iterator& operator++();
        iterator& operator=(const ConjuntoLetras::iterator &iter);
    };
    iterator begin();
    iterator end();

};


#endif
