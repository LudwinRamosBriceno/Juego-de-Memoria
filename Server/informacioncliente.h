/**
 * @file informacioncliente.h
 * @version 1.0
 * @date 22/04/2022
 * @author Ludwin Ramos
 * @brief Se gestionan los parametros de juego de cada jugador
 */

#ifndef INFORMACIONCLIENTE_H
#define INFORMACIONCLIENTE_H
#include <QString>

// Se obtiene y se actualizan los parametros de juego de cada jugador
class informacioncliente {

public:
    informacioncliente();
    void setNombreJugador1(QString nombre);
    void setNombreJugador2(QString nombre);
    QString getNombreJugador1();
    QString getNombreJugador2();
    void setPuntajeJugador1(int puntaje);
    void setPuntajeJugador2(int puntaje);
    int getPuntajeJugador1();
    int getPuntajeJugador2();
    void setparTarjetasReveladasJugador1(int cantidadParTarjetasReveladas);
    void setparTarjetasReveladasJugador2(int cantidadParTarjetasReveladas);
    int getparTarjetasReveladasJugador1();
    int getparTarjetasReveladasJugador2();

    // Según el jugador que se le brinde este actualiza el acumulado de puntos de power Ups
    void setPuntosPowerUp(int jugador,bool sumapuntos);

    /* Según el jugador que se le brinde este regresa un resultado correspondiente al power Up, dependiendo del acumulado
     * de puntos de power Ups que poseea el jugador
     */
    int getPuntosPowerUp(int jugador);

private:
    int puntajeJugador1;
    int puntajeJugador2;
    QString nombreJugador1;
    QString nombreJugador2;
    int parTarjetasReveladasJugador1;
    int parTarjetasReveladasJugador2;
    int acumuladoJugador1;
    int acumuladoJugador2;
};

#endif // INFORMACIONCLIENTE_H
