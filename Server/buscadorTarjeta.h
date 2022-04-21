#ifndef BUSCADORTARJETA_H
#define BUSCADORTARJETA_H
#include <QImage>
#include <matrizpaginada.h>
#include <tarjeta.h>


class buscadorTarjeta {

public:
    buscadorTarjeta();
    QImage buscarImgTarjeta(int,matrizpaginada*);
    tarjeta buscarTarjeta(int, matrizpaginada*);
    int getVerificadorPuntosAdicionales();
private:
    int tarjetasEnMemoria;
};

#endif // BUSCADORTARJETA_H
