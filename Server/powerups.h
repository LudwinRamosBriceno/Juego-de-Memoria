/**
 * @file powerups.h
 * @version 1.0
 * @date 22/04/2022
 * @author Ludwin Ramos
 * @brief Gestion de los potenciadores o ventajas que se obtienen en el juego
 */

#ifndef POWERUPS_H
#define POWERUPS_H
#include <informacioncliente.h>

/**
 * @brief The powerUps class Controla los power ups que pueden obtener los jugadores
 */
class powerUps {

public:
    powerUps();

    /**
     * @brief definirPowerUp Define el power up que le corresponde al jugador de acuerdo a su acumulado de puntos
     * @param jugador Identificador del jugador que tiene su turno en ese momento
     * @param infoCliente Puntero de la instancia que almacena la información de los jugadores
     * @return Retorna un resultado correspondiente al power up utilizado
     */
    int definirPowerUp(int jugador, informacioncliente* infoCliente);
};

#endif // POWERUPS_H
