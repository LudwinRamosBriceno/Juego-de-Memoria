/**
 * @file tarjeta.h
 * @version 1.0
 * @date 22/04/2022
 * @author Ludwin Ramos
 * @brief Información referente a las tarjetas
 */

#ifndef TARJETA_H
#define TARJETA_H
#include <QImage>


/**
 * @brief The tarjeta class Almacena la información de cada tarjeta del juego
 */
class tarjeta {

public:
    tarjeta();
    void setIdentificador(int identificador);
    void setRevelada(bool revelada);
    void setTipoTarjeta(char tipoImg);
    int getIdentificador();
    char getTipoTarjeta();
    bool getRevelada();
    void setImgTarjeta();
    QImage getImgTarjeta();

private:
    int identificadorTarjeta;
    char tipoTarjeta;
    bool tarjetaRevelada;
    QImage imagenTarjeta;

};

#endif // TARJETA_H
