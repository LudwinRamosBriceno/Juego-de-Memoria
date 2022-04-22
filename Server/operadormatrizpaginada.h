/**
 * @file operadormatrizpaginada.h
 * @version 1.0
 * @date 22/04/2022
 * @author Ludwin Ramos
 * @brief Gestion de las operaciones sobre la matriz paginada
 */

#ifndef OPERADORMATRIZPAGINADA_H
#define OPERADORMATRIZPAGINADA_H
#include <matrizpaginada.h>
#include <informacioncliente.h>
#include <buscadorTarjeta.h>

/**
 * @brief The operadorMatrizPaginada class Realiza las operaciones necesarias sobre la matriz paginada
 */
class operadorMatrizPaginada {

public:
    operadorMatrizPaginada();

    /**
     * @brief reducirMatriz Disminuye la cantidad de tarjetas almacenadas o cargadas en la matriz paginada
     * @param infoCliente Puntero de la instancia que almacena la información de los jugadores
     * @param matrizPaginada Puntero de la matriz paginada
     * @param keyTarjeta1 Identificador o llave de la primer tarjeta seleccionada
     * @param keyTarjeta2 Identificador o llave de la segunda tarjeta seleccionada
     */
    void reducirMatriz(informacioncliente*infoCliente,matrizpaginada* matrizPaginada, int keyTarjeta1, int keyTarjeta2);

    /**
     * @brief shuffleMatriz Realiza una elección aleatoria de las tarjetas que estarán en memoria o en la matriz paginada
     * @param matriz Puntero de la matriz paginada
     */
    void shuffleMatriz(matrizpaginada* matriz);
private:
     buscadorTarjeta buscadorTarjetaSeleccionada;
};

#endif // OPERADORMATRIZPAGINADA_H
