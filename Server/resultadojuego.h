/**
 * @file resultadojuego.h
 * @version 1.0
 * @date 22/04/2022
 * @author Ludwin Ramos
 * @brief Gestiona el estado actual del juego
 */

#ifndef RESULTADOJUEGO_H
#define RESULTADOJUEGO_H
#include <informacioncliente.h>

/**
 * @brief The resultadoJuego class Gestiona los turnos de los jugadores y el estado del juego
 */
class resultadoJuego {

public:
    resultadoJuego();

    /**
     * @brief definirResultadoJuego Define los turnos y el estado del juego (si acabó o no)
     * @param turnoJugador Turno del jugador actual
     * @param infoCliente Puntero de la instancia que almacena la información de los jugadores
     * @param tipoTarjeta1Presionada Tipo de tarjeta de la primera tarjeta presionada
     * @param tipoTarjeta2Presionada Tipo de tarjeta de la segunda tarjeta presionada
     * @return Retorna un mensaje que contiene el siguiente turno del jugador y el estado del juego
     */
    QString definirResultadoJuego(int turnoJugador,informacioncliente* infoCliente, char tipoTarjeta1Presionada, char tipoTarjeta2Presionada);

    /**
     * @brief definirResultadoFinalJuego Define el resultado final al acabar el juego
     * @param infoCliente Puntero de la instancia que almacena la información de los jugadores
     * @return Retorna un mensaje que contiene instrucciones e información del estado final del juego
     */
    QString definirResultadoFinalJuego(informacioncliente* infoCliente);
};

#endif // RESULTADOJUEGO_H
