#ifndef __LETTERS_BAG_H__
#define __LETTERS_BAG_H__

#include <string>
#include "letters_set.h"

using namespace std;

/**
 * @brief TDA LettersBag
 * @details Este TDA almacena un conjunto de char utilizado en el juego de letras.
 * La estructura de datos subyacente es una string.
 */

class BolsaLetras {
private:
    /**
     * @brief Conjunto de caracteres almacenados según la cantidad
     * apariciones que determine un objeto ConjuntoLetras.
     */
    string bolsa_letras;

public:
    /**
     * @brief Constructor por defecto.
     * @details Genera una bolsa vacía.
     */
    BolsaLetras();

    /**
     * @brief Calcula la cantidad total de elementos que hay en la bolsa
     * @return Tamaño de la bolsa.
     * @note Método de consulta.
     */
    int size() const;

    /**
     * @brief Método para añadir un elemento a la bolsa
     * @param letra Letra que se va a añadir a la bolsa
     */
    void add(Letra letra);

    /**
     * @brief Método para extraer un elemento aleatorio de la bolsa.
     * @details Al obtener el elemento, lo elimina de la bolsa.
     * @return Elemento aleatorio
     */
    char get();

    /**
     * @brief Método para formatear como cadena la bolsa y obteniendo dicha cadena.
     * @return Una cadena tipo std::string la bolsa formateada, de forma
     * que por cada elemento, se imprime una línea.
     * @note Método de consulta.
     */
    string toString() const;

    /**
     * @brief Método para cargar una bolsa dado un conjunto de letras.
     * @details Genera la bolsa a partir de un conjunto de letras (TDA ConjuntoLetras).
     * @param conj : conjunto de letras a partir del cual se crea la bolsa
     */
    void cargarBolsa (const ConjuntoLetras &conj) ;

    /**
     * @brief Sobrecarga del operador <<.
     * @details Posibilita la salida formateada de la bolsa por un flujo,
     * que por defecto es la salida estándar.
     * @param os Flujo de salida. Por defecto, os = cout.
     * @param b Bolsa.
     * @return Una referencia al flujo de salida.
     */
    friend ostream& operator<<(ostream& os, const BolsaLetras& b);

    /**
     * @details Sobrecarga del operador >>.
     * @brief Permite la lectura de un objeto tipo BolsaLetras desde un flujo
     * de entrada. Se usará para leer bolsas que vienen formateadas según la
     * salida del programa 'Conjunto_letras'.
     * Es decir: "[carácter] [cantidad] [puntuación]" por cada línea/letra.
     * @param is Flujo de entrada del que se va a leer un objeto BolsaLetras
     * @param b Bolsa en la que se van a insertar los elementos leídos.
     * @return Una referencia al flujo de entrada.
     */
    friend istream& operator>>(istream& is, BolsaLetras& b);
};

#endif