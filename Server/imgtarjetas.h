/**
 * @file imgtarjetas.h
 * @version 1.0
 * @date 22/04/2022
 * @author Ludwin Ramos
 * @brief Se gestionan las rutas de almacenamiento de las imágenes de las distintas tarjetas
 */

#ifndef IMGTARJETAS_H
#define IMGTARJETAS_H
#include <QString>

/**
 * @brief The imgtarjetas class Contiene las rutas de las imágenes de las tarjetas que serán utilizadas
 */
class imgtarjetas {

public:
    imgtarjetas();

    /**
     * @brief getImgTarjeta Se obtiene la imagen correspondiente a la tarjeta seleccionada
     * @param tipoTarjeta Tipo de la tarjeta a la cual se le busca su imagen
     * @return Retorna la ruta de almacenamiento¨ de la imagen de la tarjeta seleccionada
     */
    QString getImgTarjeta(char tipoTarjeta);

private:
    QString imgtarjetaA;
    QString imgtarjetaB;
    QString imgtarjetaC;
};

#endif // IMGTARJETAS_H
