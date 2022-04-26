/**
 * @file crearArchivoBin.h
 * @version 1.0
 * @date 22/04/2022
 * @author Ludwin Ramos
 * @brief Crea un archivo binario donde se almacenará la matriz completa en disco
 */

#ifndef CREARARCHIVOBIN_H
#define CREARARCHIVOBIN_H
#include <QString>
#include <tarjeta.h>

/**
 * @brief Estructura para escribir conjuntos de datos consistentes en un archivo binario
 */
struct tarjetaAAlmacenar{
    int identificador;
    char tipoTarjeta;
    bool revelada;
};

/**
 * @brief Crear un archivo binario con la matriz completa del juego
 */
class crearArchivoBin {

public:
    crearArchivoBin();

    /**
     * @brief almacenarTarjetas Almacena las tarjetas una por una en un archivo binario
     * @param nuevaTarjeta Tarjeta que será almacenada en el archivo binario
     */
    void almacenarTarjetas(tarjeta nuevaTarjeta);
};

#endif // CREARARCHIVOBIN_H
