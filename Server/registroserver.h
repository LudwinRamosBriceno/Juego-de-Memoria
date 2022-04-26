/**
 * @file registroserver.h
 * @version 1.0
 * @date 22/04/2022
 * @author Ludwin Ramos
 * @brief Cuadro de información correspondiente a parametros del servidor
 */

#ifndef REGISTROSERVER_H
#define REGISTROSERVER_H
#include <matrizpaginada.h>
#include <informacioncliente.h>

/**
 * @brief The registroServer class Gestiona el cuadro en consola que muestra la información de los parametros del servidor
 */
class registroServer {

public:
    registroServer();

    /**
     * @brief actualizarTabla Actualiza la tabla con los parametros del servidor en la consola
     * @param matriz Puntero de la matriz paginada
     * @param cliente Puntero de la instancia que almacena la información de los jugadores
     */
    void actualizarTabla(matrizpaginada* matriz, informacioncliente* cliente);
    void estadoFinal();

private:
    bool limpiarTabla;
    void getUsoMemoria(double&, double&);
};

#endif // REGISTROSERVER_H
