/**
 * @file cargardescargartarjeta.h
 * @version 1.0
 * @date 22/04/2022
 * @author Ludwin Ramos
 * @brief Realiza la carga y descarga de tarjetas a disco
 */

#ifndef CARGARDESCARGARTARJETA_H
#define CARGARDESCARGARTARJETA_H
#include <matrizpaginada.h>
#include <tarjeta.h>

/**
 * @brief Estructura para leer datos del archivo binario donde se encuentra la matriz completa
 */
struct tarjetaDisco{
    int identificador;
    char tipoTarjeta;
    bool revelada;
};

/**
 * @brief carga y Descarga las tarjetas del disco
 */
class CargarDescargarTarjeta {

public:
    CargarDescargarTarjeta();

    /**
     * @brief cargarTarjeta Carga la tarjeta solicitada a la memoria o a la matriz paginada
     * @param IDtarjetaAcargar Identificador de la tarjeta seleccionada
     * @param matriz Puntero a la matriz Paginada
     */
    void cargarTarjeta(int IDtarjetaAcargar,matrizpaginada* matriz);

    /**
     * @brief descargarTarjeta Descarga y actualiza una tarjeta al azar a disco
     * @param matriz Puntero a la matriz Paginada
     * @return Retorna un iterador par asociativo de un Hash o de la matriz paginada
     */
    QHash<int,tarjeta>::iterator descargarTarjeta(matrizpaginada* matriz);

};

#endif // CARGARDESCARGARTARJETA_H
