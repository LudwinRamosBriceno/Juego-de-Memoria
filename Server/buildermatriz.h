/**
 * @file buildermatriz.h
 * @version 1.0
 * @date 22/04/2022
 * @author Ludwin Ramos
 * @brief Se crea la matriz paginada del juego
 */

#ifndef BUILDERMATRIZ_H
#define BUILDERMATRIZ_H
#include <tarjeta.h>
#include <matrizpaginada.h>

/**
 * @brief Encargada de la construcción de la matriz paginada
 */
class builderMatriz {

public:
    builderMatriz();

    /**
     * @brief construirMatriz Crea la matriz paginada al iniciar el juego
     * @return Retorna un puntero a la matriz paginada
     */
    matrizpaginada* construirMatriz();

    /**
     * @brief verificarCantidadTipos Verifica que la cantidad de tarjetas de los distintos tipos sean iguales
     * @param Tipo de tarjeta al azar que se debe verificar
     * @return tipoTarjeta Regresa el tipo de tarjeta que le corresponde a una tarjeta
     */
    char verificarCantidadTipos(char tipoTarjeta);

private:
    int cantidadTarjetasTipoA = 0;
    int cantidadTarjetasTipoB =0;
    int cantidadTarjetasTipoC = 0;

};

#endif // BUILDERMATRIZ_H
