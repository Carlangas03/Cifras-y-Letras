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
    * @brief Construye un diccionario vacío.
    **/
    Diccionario();

    /**
     * @brief Devuelve el número de palabras en el diccionario
    **/
    int size() const ;

    /**
    * @brief Obtiene todas las palabras en el diccionario de un longitud dada
    * @param longitud la longitud de las palabras de salida
    * @return un vector con las palabras de longitud especifica en el parametro de entrada
    **/
    vector<string> PalabrasLongitud(int longitud);

    /**
    * @brief Indica si una palabra está en el diccionario o no.
    * @param palabra la palabra que se quiere buscar
    * @return true si la palabra está en el diccionario. False en caso contrario
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
    * @brief Escribe en un flujo de salida un diccionario.
    * @param os flujo de salida.
    * @param D el objeto diccionario que se escribe.
    * @return el flujo de salida.
    **/
    friend ostream & operator<<(ostream & os, const Diccionario &D);

    //------------------------- Clase Iterator --------------------------------
    /**
     * @brief Clase iteradora para el TDA Diccionario.
     * @details Se basa en un set<string>::iterator.
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
 * @note Método que modifica.
 * @return La palabra en mayúsculas.
 */
string mayusculas(string &palabra);
#endif
