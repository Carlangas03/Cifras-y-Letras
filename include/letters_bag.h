#ifndef __LETTERS_BAG_H__
#define __LETTERS_BAG_H__

#include <list>
#include "letters_set.h"

using namespace std;

/**
 * @brief TDA LettersBag
 *
 * Este TDA almacena un conjunto de chars utilizado en el juego de letras.
 * La estructura de datos subyacente es una lista de chars.
 */

class BolsaLetras {
private:
    list<char> bolsa_letras;

public:
    /**
     * @brief Constructor por defecto
     * @details Genera una bolsa vacía
     */
    BolsaLetras();

    /**
     * @brief Calcula la cantidad total de elementos que hay en la bolsa
     * @return Tamaño de la bolsa
     */
    int size() const;

    /**
     * @brief Añade un elemento a la bolsa
     * @param letra Letra que se va a añadir a la bolsa
     */
    void add(Letra letra);

    /**
     * @brief Extrae un elemento aleatorio de la bolsa y lo elimina de la
     * bolsa.
     * @return Elemento aleatorio
     */
    char get();

    /**
     * @brief Formatea la bolsa y la transforma en una cadena tipo std::string.
     * @return Una cadena tipo std::string la bolsa formateada, de forma
     * que por cada elemento, se imprime una línea.
     */
    string toString() const;

    /**
     * @brief Sobrecarga del operador <<. Posibilita la salida formateada
     * de la bolsa por un flujo, que por defecto es la salida estándar.
     * @param os Flujo de salida. Por defecto, os = cout.
     * @param b Bolsa.
     * @return Una referencia al flujo de salida.
     */
    friend ostream& operator<<(ostream& os, const BolsaLetras& b);

    /**
     * @brief Sobrecarga del operador >>. Permite la lectura de un objeto
     * tipo BolsaLetras desde un flujo de entrada. Se usará para leer bolsas
     * que vienen formateadas según la salida del programa 'Conjunto_letras',
     * a saber: "[letra] [cantidad] [puntuación]" por cada línea/letra.
     * @param is Flujo de entrada del que se va a leer un objeto BolsaLetras
     * @param b Bolsa en la que se van a insertar los elementos leídos.
     * @return Una referencia al flujo de entrada.
     */
    friend istream& operator>>(istream& is, BolsaLetras& b);
};

#endif