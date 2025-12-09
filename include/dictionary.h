#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include <string>
#include <vector>
#include <set>

using namespace std;

/**
 * @brief TDA Dictionary
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
    * @brief Diccionario()
    * @details Construye un diccionario vacío.
    **/
    Diccionario();

    /**
     * @brief int size() const
     * @details Devuelve el número de palabras en el diccionario
    **/
    int size() const ;

    /**
    * @brief vector<string> PalabrasLongitud(int longitud)
    * @details Obtiene todas las palabras en el diccionario de un longitud dada
    * @param longitud la longitud de las palabras de salida
    * @return un vector con las palabras de longitud especifica en el parametro de entrada
    **/
    vector<string> PalabrasLongitud(int longitud);

    /**
    * @brief bool Esta(const string & palabra) const.
    * @details Indica si una palabra está en el diccionario o no.
    * @param palabra la palabra que se quiere buscar
    * @return true si la palabra está en el diccionario. False en caso contrario
    **/
    bool Esta(const string & palabra) const;

    /**
    * @brief friend istream & operator>> (istream & is,Diccionario & D).
    * @details Lee de un flujo de entrada un diccionario.
    * @param is flujo de entrada.
    * @param D el objeto donde se realiza la lectura.
    * @return el flujo de entrada.
    **/
    friend istream & operator>>(istream & is,Diccionario &D);

    /**
    * @brief friend ostream & operator<< (ostream & os, const Diccionario & D).
    * @details Escribe en un flujo de salida un diccionario.
    * @param os flujo de salida.
    * @param D el objeto diccionario que se escribe.
    * @return el flujo de salida.
    **/
    friend ostream & operator<<(ostream & os, const Diccionario &D);


    /**
     * @brief Clase iteradora para el TDA Diccionario.
     * @details Se basa en un set<string>::iterator.
    **/
    class iterator{

    private:
        /**
         * @brief set<string>::iterator it
         * @details iterador de la clase set<string>::iterator como base para el iterador del
         * TDA Diccionario.
        **/
        set<string>::iterator it;

    public:
        /**
         * @brief iterator().
         * @details Constructor por defecto.
         */
        iterator ();

        /**
         * @brief const string & operator* () const.
         * @return  Devuelve el elemento del diccionario al que apunta el iterador.
         * @note Método de consulta.
         */
        const string & operator*() const;

        /**
         * @brief iterator & operator++ ().
         * @details Calcula la posición siguiente del diccionario. Como es de imaginar, es la dirección
         * de la siguiente palabra del diccionario.
         * @return Puntero a la siguiente posición según la indicación anterior.
         */
        iterator & operator ++();

        /**
         * @brief bool operator== (const iterator &i).
         * @details Calcula si la palabra del diccionario a la que apunta el iterador implícito
         * es igual a la que apunta el parámetro \par i.
         * @param i
         * @return true si ambas son iguales; false en caso contrario.
         */
        bool operator ==(const iterator &i);

        /**
         * @brief bool operator !=(const iterator &i).
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
     * @brief const iterator begin() const.
     * @details Calcula la primera posición (dirección de la palabra
     * correspondiente) del diccionario.
     * @return Un puntero a la primera palabra del diccionario.
     */
    const iterator begin() const;

    /**
     * @brief const iterator end() const.
     * @details Calcula la última posición (dirección de la palabra
     * correspondiente) del diccionario.
     * @return Un puntero a la última palabra del diccionario.
     */
    const iterator end() const;
};

/**
 * @brief string mayusculas (string & palabra)
 * @details Pasa a mayúsculas todos los caracteres de la palabra que se
 * pasa por parámetro.
 * @param palabra Palabra que se va a pasar a mayúsculas.
 * @note Método que modifica.
 * @return La palabra en mayúsculas.
 */
string mayusculas(string &palabra);
#endif
