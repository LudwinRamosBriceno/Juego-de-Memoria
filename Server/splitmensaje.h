/**
 * @file resultadojuego.h
 * @version 1.0
 * @date 22/04/2022
 * @author Ludwin Ramos
 * @brief Desglosa mensajes que son recibidos
 */

#ifndef SPLITMENSAJE_H
#define SPLITMENSAJE_H
#include <QString>

/**
 * @brief The splitMensaje class Encargado de la interpretación de los mensajes recibidos
 */
class splitMensaje {

public:
    splitMensaje();

    /**
     * @brief interpretarMensaje Interpreta un mensaje delimitado por comas, de modo que se puede acceder a un dato en
     *        particular por medio de un número que indique la posición donde se encuentra el dato deseado.
     * @param indiceDato Número que indica la posición donde se encuentra el dato a buscar en el mensaje.
     * @param mensaje_a_separar Mensaje recibido que separa las instrucciones y los datos necesarios con comas
     * @return Retorna la instrucción o dato que se manda a buscar por medio un número que indica la posición
     */
    QString interpretarMensaje(int indiceDato, QString mensaje_a_separar);
};

#endif // SPLITMENSAJE_H
