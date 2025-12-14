#ifndef __LETTERS_BAG_H__
#define __LETTERS_BAG_H__

#include <string>
#include "letters_set.h"

using namespace std;


// -------------------------- Clase BolsaLetras -------------------------------
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
     * @brief Constructor con un parámetro.
     * @details Genera una bolsa de letras de un conjunto de letras (TDA
     * ConjuntoLetras) ya existente.
     * Añade cada caracter tantas veces como indica el campo Cantidad en cada
     * letra (TDA Letra) del conjunto.
     *
     * @code
     *
     * ConjuntoLetras conjunto;
     * ifstream entrada("letras.txt") // <-- Fichero de salida del programa cantidad_letras
     *
     * if (!entrada) {
     *    cout << "Error al abrir el fichero de entrada" << endl;
     *    return 1;
     * }
     *
     * BoslaLetras(conjunto);
     *
     * @endcode
    **/
    BolsaLetras(const ConjuntoLetras & conjunto);

    /**
     * @brief Calcula la cantidad total de elementos que hay en la bolsa
     * @return Tamaño de la bolsa.
     * @note Método de consulta.
     */
    int size() const;

    /**
     * @brief Método para añadir un elemento a la bolsa.
     * @details Este es el método que se encarga de introducir en la bolsa
     * los caracteres tantas veces como indique el campo `cantidad` de la
     * @p letra (TDA Letra).
     * @param letra Letra que se va a añadir a la bolsa
     *
     * @code
     *
     * ifstream entrada("letras.txt") // <-- Fichero de salida del programa cantidad_letras
     *
     * if (!entrada) {
     *    cout << "Error al abrir el fichero de entrada" << endl;
     *    return 1;
     * }
     *
     * ConjuntoLetras conjunot ("letras.txt");
     * Letra letra('a', 3, 10);
     * BolsaLetras bolsa(conjunto);
     *
     * bolsa.add(letra);
     * cout << bolsa << endl; // <-- "aaa"
     *
     * @endcode
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
     * @details Genera la bolsa a partir de un conjunto de letras (TDA ConjuntoLetras),
     * de forma que en la bolsa se incluyen los caracteres correspondientes a las letras
     * tantas veces como indica su campo `cantidad`.
     * @param conj Conjunto de letras a partir del cual se crea la bolsa
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