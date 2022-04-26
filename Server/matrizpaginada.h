/**
 * @file matrizpaginada.h
 * @version 1.0
 * @date 22/04/2022
 * @author Ludwin Ramos
 * @brief Se almacena la matriz paginada del juego
 */

#ifndef MATRIZPAGINADA_H
#define MATRIZPAGINADA_H
#include <tarjeta.h>
#include <QHash>

/**
 * @brief The matrizpaginada class Almacena la matriz paginada o las tarjetas en memoria
 */
class matrizpaginada{

public:
    matrizpaginada();

    /**
     * @brief setTarjetaCargada Inserta una tarjeta a una estructura tabla de hash el cual será la matriz paginada
     * @param keyTarjeta Identificador o llave de la tarjeta que será incorporada a la matriz paginada
     * @param nuevaTarjeta Tarjeta que será incorporada a la matriz paginada
     */
    void setTarjetaCargada(int keyTarjeta,tarjeta nuevaTarjeta);

    /**
     * @brief getTarjetasCargadas la matriz paginada para realizar operaciones sobre la misma
     * @return Retorna un puntero de la matriz paginada
     */
    QHash<int,tarjeta>* getTarjetasCargadas();

    /**
     * @brief liberarMatrizPaginada Libera la memoria ocupada por la matriz paginada
     */
    void liberarMatrizPaginada();

private:
    QHash <int,tarjeta> *tarjetasCargadas;

};

#endif // MATRIZPAGINADA_H
