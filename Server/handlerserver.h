/**
 * @file handlerserver.h
 * @version 1.0
 * @date 22/04/2022
 * @author Ludwin Ramos
 * @brief Se gestiona la logica relacionada con el servidor
 */

#ifndef HANDLERSERVER_H
#define HANDLERSERVER_H
#include <matrizpaginada.h>
#include <informacioncliente.h>
#include <QTcpSocket>
#include <buscadorTarjeta.h>
#include <operadormatrizpaginada.h>
#include <resultadojuego.h>
#include <registroserver.h>
#include <iostream>

using namespace std;

/**
 * @brief Gestiona todas las entradas o mensajes que recibe el servidor
 */
class handlerServer {

public:
    handlerServer();

    /**
     * @brief iniciarJuego Inicializa todo lo necesario para comenzar el juego
     * @param nombreJugador1 Nombre del jugador 1
     * @param nombreJugador2 Nombre del Jugador 2
     * @return retorna un mensaje con instrucciones y datos necesarios
     */
    QString iniciarJuego(QString nombreJugador1, QString nombreJugador2);

    /**
     * @brief logicHandler Gestiona las jugadas de los jugadores
     * @param mensajeCliente Mensaje del cliente que contiene instrucciones
     * @return Retorna un mensaje con instrucciones a ejecutar por el cliente
     */
    QString logicHandler(QString mensajeCliente);

    /**
     * @brief getResultadoJuego Se obtiene el resultado parcial o final del juego
     * @return Se retorna un mensaje con instrucciones y datos a enviar.
     */
    QString getResultadoJuego();

    /**
     * @brief finalizarJuego Realiza operaciones de liberación de memoria que ocupaba la lógica del servidor
     * @return Retorna un mensaje final para terminar el juego
     */
    QString finalizarJuego();

private:
    QString convetirBase64(QImage);

private:
    matrizpaginada *matrizPaginada;
    informacioncliente *cliente;
    int tarjeta1Presionada;
    int tarjeta2Presionada;
    int turnoJugador;
    buscadorTarjeta buscadorTarjetaSeleccionada;
    operadorMatrizPaginada operadorMatriz;
    resultadoJuego verificadorEstadoJuego;
    registroServer* tablaParametros;
};

#endif // HANDLERSERVER_H
