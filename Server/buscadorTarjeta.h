/**
 * @file buscadorTarjeta.h
 * @version 1.0
 * @date 22/04/2022
 * @author Ludwin Ramos
 * @brief Se buscan las tarjetas en disco o en la matriz paginada
 */

#ifndef BUSCADORTARJETA_H
#define BUSCADORTARJETA_H
#include <QImage>
#include <matrizpaginada.h>
#include <tarjeta.h>

/**
 * @brief Encargada de la lógica de paginación
 */
class buscadorTarjeta {

public:
    buscadorTarjeta();
    /**
     * @brief buscarImgTarjeta Busca la imagen correspodiente a la tarjeta seleccionada
     * @param keyTarjetaAcargar Identificador de la tarjeta seleccionada
     * @param matriz Puntero a la matriz Paginada
     * @return retorna la imagen de la tarjeta seleccionada por el jugador
     */
    QImage buscarImgTarjeta(int keyTarjetaAcargar, matrizpaginada* matriz);

    /**
     * @brief buscarTarjeta Busca la tarjeta solicitada en la matriz paginada o en disco
     * @return retorna la tarjeta solicitada
     */
    tarjeta buscarTarjeta(int, matrizpaginada*);

    /**
     * @brief getVerificadorPuntosAdicionales Verifica la obtención de puntos adicionales
     * @return retorna el puntaje extra en caso de que el jugador seleccionado dos tarjetas en la matriz paginada
     */
    int getVerificadorPuntosAdicionales();
private:
    int tarjetasEnMemoria;
};

#endif // BUSCADORTARJETA_H
