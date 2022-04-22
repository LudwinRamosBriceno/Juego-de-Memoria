/**
 * @file actualizardatosjugadores.h
 * @version 1.0
 * @date 22/04/2022
 * @author Ludwin Ramos
 * @brief Se actualizan los datos de los jugadores
 */
#ifndef ACTUALIZARDATOSJUGADORES_H
#define ACTUALIZARDATOSJUGADORES_H
#include <matrizpaginada.h>
#include <informacioncliente.h>

/**
 * @brief Encargada de actualizar los parámetros de los jugadores con respecto al juego
 */
class ActualizarDatosJugadores {

public:
    ActualizarDatosJugadores();

    /**
     * @brief actualizarDatos Actualiza los puntos y los pares de tarjetas reveladas de cada jugador
     * @param jugador Identificador del jugador que posee el turno actual
     * @param tarjetasEnMemoria Número de tarjetas en memoria que revela el jugador particular en un turno
     * @param matriz Puntero a la matriz Paginada
     * @param infoCliente Puntero a la información almacenada de los jugadores
     * @param tarjeta1 Identificador de la tarjeta 1 presionada por el usuario
     * @param tarjeta2 Identificador de la tarjeta 2 presionada por el usuario
     */
    void actualizarDatos(int jugador,int tarjetasEnMemoria, matrizpaginada *matriz, informacioncliente *infoCliente, int tarjeta1, int tarjeta2);

    /**
     * @brief verificarCambioPuntos
     * @param jugador Identificador del jugador que posee el turno actual
     * @param puntosActual Puntos que posee el jugador actualmente
     * @param puntosActualizados Puntos que posee el jugador al obtener puntos
     * @param infoCliente Puntero a la información almacenada de los jugadores
     * @return Retorna el puntaje extra que debe obtener el jugador
     */
    int verificarCambioPuntos(int jugador,int puntosActual,int puntosActualizados,informacioncliente* infoCliente);
};

#endif // ACTUALIZARDATOSJUGADORES_H
