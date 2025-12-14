#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include <string>
#include <vector>
#include <set>

using namespace std;


// ------------------------------- Clase Diccionario --------------------------
/**
 * @brief TDA Diccionario
 * @details Almacena las palabras de un fichero de texto y permite iterar sobre ellas
 *
**/
class Diccionario{
private:
    /**
     * @brief Estructura lineal base para el diccionario. Consiste en un set de string, ya que se
     * trata de palabras, y no tiene sentido repetirlas.
    **/
    set<string> datos;

public:
    /**
    * @brief Constructor sin parámetros.
    * @details Construye un diccionario vacío.
    **/
    Diccionario();

    /**
     * @brief Constructor con un parámetro.
     * @param fichero_diccionario Nombre del fichero que se va a tomar como diccionario.
     * @pre El fichero debe tener el formato adecuado, es decir, una palabra por línea.
     * @note Este constructor se basa en el operador >>.
    **/
    Diccionario(string fichero_diccionario);

    /**
     * @brief Devuelve el número de palabras en el diccionario
    **/
    int size() const ;

    /**
    * @brief Obtiene todas las palabras en el diccionario de un longitud dada.
    * @param Longitud la longitud de las palabras de salida.
    * @return Un vector con las palabras de longitud especifica en el parametro de entrada.
    * @code
    * Diccionario d("fichero_diccionario.txt");
    * vector<string> v;
    *
    * v = d.PalabrasLongitud(5);
    * cout << v << endl; // Muestra las palabras de longitud = 5 pertenecientes al diccionario
    *                    // cargado desde el fichero "fichero_diccionario.txt"
    *
    * @endcode
    **/
    vector<string> PalabrasLongitud(int longitud);

    /**
    * @brief Indica si una palabra está en el diccionario o no.
    * @param palabra la palabra que se quiere buscar
    * @return true si la palabra está en el diccionario. False en caso contrario
    * @code
    * Diccionario d("fichero_diccionario.txt");
    * string palabra ("Hola");
    *
    * if (d.Esta(palabra)
    *   cout << "La palabra " << palabra << " pertenece al diccionario." << endl;
    *
    * else
    *   cout << "La palabra " << palabra << " no pertenece al diccionario." << endl;
    *
    * @endcode
    **/
    bool Esta(const string & palabra) const;

    /**
    * @brief Lee de un flujo de entrada un diccionario.
    * @param is flujo de entrada.
    * @param D el objeto donde se realiza la lectura.
    * @return el flujo de entrada.
    **/
    friend istream & operator>>(istream & is,Diccionario &D);

    /**
    * @brief Escribe en un flujo de salida el diccionario correspondiente
    * al objeto implícito.
    * @param os flujo de salida.
    * @param D el objeto diccionario que se escribe.
    * @return el flujo de salida.
    **/
    friend ostream & operator<<(ostream & os, const Diccionario &D);

    //------------------------- Clase Iterator --------------------------------
    /**
     * @brief Clase iteradora para el TDA Diccionario.
     * @details Se basa en un set<string>::iterator. Permitirá recorrer diccionarios
     * de la forma que si indica a continuación:
     * @code
     * Diccionario d;
     * ifstream entrada("fichero_diccionario.txt");
     *
     * if (!entrada) {
     *    cout << "Error al abrir el fichero";
     *    return 1;
     * }
     *
     * for (Diccionario::iterator it = d.begin(); it != d.end(); it++) {
     *    // código de iteración
     * }
     *
     * @endcode
    **/
    class iterator{
    private:
        /**
         * @brief iterador de la clase set<string>::iterator como base para el iterador del
         * TDA Diccionario.
        **/
        set<string>::iterator it;

    public:
        /**
         * @brief Constructor por defecto.
         */
        iterator ();

        /**
         * @brief Sobrecarga del operador *.
         * @return  Devuelve el elemento del diccionario al que apunta el iterador.
         * @note Método de consulta.
         */
        const string & operator*() const;

        /**
         * @brief Sobrecarga del operador ++.
         * @details Calcula la posición siguiente del diccionario. Como es de imaginar, es la dirección
         * de la siguiente palabra del diccionario.
         * @return Puntero a la siguiente posición según la indicación anterior.
         */
        iterator & operator ++();

        /**
         * * @brief Sobrecarga del operador ==.
         * @details Calcula si la palabra del diccionario a la que apunta el iterador implícito
         * es igual a la que apunta el parámetro \par i.
         * @param i
         * @return true si ambas son iguales; false en caso contrario.
         */
        bool operator ==(const iterator &i);

        /**
         * @brief Sobrecarga del operador !=.
         * @details Calcula si las palabras a las que apuntan el iterador implícito y el iterador
         * del parámetro @par i son diferentes.
         * @param i
         * @return true si las palabras son diferentes; false si son iguales.
         */
        bool operator !=(const iterator &i);

        /**
         * @brief friend class Diccionario
         * @details La clase Diccionario se declara como amiga de la iteradora para
         * poder acceder a los miembros privados del diccionario, que en este caso es
         * todo el set de palabras.
         */
        friend class Diccionario;
    };

    /**
     * @brief Calcula la primera posición (dirección de la palabra
     * correspondiente) del diccionario.
     * @return Un puntero a la primera palabra del diccionario.
     */
    const iterator begin() const;

    /**
     * @brief Calcula la última posición (dirección de la palabra
     * correspondiente) del diccionario.
     * @return Un puntero a la última palabra del diccionario.
     */
    const iterator end() const;
};


// ----------------------------- Funciones externas ---------------------------
/**
 * @brief Función externa a la clase.
 * @details Pasa a mayúsculas todos los caracteres de la palabra que se
 * pasa por parámetro.
 * @param palabra Palabra que se va a pasar a mayúsculas.
 * @return La palabra en mayúsculas.
 *
 * @code
 *
 * string palabra ("palabra1"), palabra2 ("pALabRA2");
 *
 * cout << palabra1 << endl; // => "palabra1"
 * cout << palabra2 << endl; // => "pALabRA2"
 *
 * palabra1 = mayusculas(palabra1); cout << palabra1;  // => "PALABRA1"
 * palabra2 = mayusculas(palabra2); cout << palabra2;  // => "PALABRA2"
 *
 * @endcode
 */
string mayusculas(const string &palabra);
#endif
