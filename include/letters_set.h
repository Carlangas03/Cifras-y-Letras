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
    void setCaracter(char c) { caracter = c; };
    void setCantidad(int c) { cantidad = c; };
    void setPuntuacion (int p) { puntuacion = p; };

    char getCaracter() const { return caracter; };
    int getCantidad() const { return cantidad; };
    int getPuntuacion() const { return puntuacion; };

    friend ostream& operator<<(ostream& salida, const Letra& letra);
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
    set<Letra> letras;
public:
    friend ostream& operator<<(ostream& salida, const ConjuntoLetras& conj);
    friend istream& operator>>(istream& entrada, ConjuntoLetras& conj);
};


#endif
