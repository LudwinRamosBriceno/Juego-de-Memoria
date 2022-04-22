/**
 * @file sumadorPuntos.h
 * @version 1.0
 * @date 22/04/2022
 * @author Ludwin Ramos
 * @brief Sumador de puntos de los jugadores
 */

#ifndef SUMADORPUNTOS_H
#define SUMADORPUNTOS_H
#include <informacioncliente.h>
#include <matrizpaginada.h>
#include <buscadorTarjeta.h>
#include <operadormatrizpaginada.h>

/**
 * @brief The sumadorPuntos class Suma los puntos y los pares de tarjetas que revelan los jugadores
 */
class sumadorPuntos {
public:
    sumadorPuntos();

    /**
     * @brief sumarPuntos Aumenta los puntos de los jugadores al acertar un par de tarjetas
     * @param puntajeActualJugador Puntaje que posee actualmente el jugador antes de actualizarlo
     * @param matriz Puntero de la matriz paginada
     * @param tarjeta1 Identificador de la primer tarjeta presionada
     * @param tarjeta2 Identificador de la segunda tarjeta presionada
     * @param tarjetasEnMemoria Número de tarjetas en memoria que revela el jugador particular en un turno
     * @return Retorna el puntaje actualizado correspondiente al jugador
     */
    int sumarPuntos(int puntajeActualJugador, matrizpaginada *matriz, int tarjeta1, int tarjeta2,int tarjetasEnMemoria);

    /**
     * @brief sumarParTarjetasReveladas Aumenta los pares de tarjetas reveladas de los jugadores al acertar un par de tarjetas
     * @param parTarjetasReveladasActualJugador Pares de tarjetas reveladas que posee actualmente el jugador antes de actualizarlas
     * @param matriz Puntero de la matriz paginada
     * @param tarjeta1 Identificador de la primer tarjeta presionada
     * @param tarjeta2 Identificador de la segunda tarjeta presionada
     * @return Retorna el Par de tarjetas revelados actualizado correspondiente al jugador
     */
    int sumarParTarjetasReveladas(int parTarjetasReveladasActualJugador, matrizpaginada *matriz, int tarjeta1, int tarjeta2);

private:
    buscadorTarjeta buscadorTarjetaSeleccionada;
    operadorMatrizPaginada operadorMatriz;
};

#endif // SUMADORPUNTOS_H
