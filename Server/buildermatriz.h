#ifndef BUILDERMATRIZ_H
#define BUILDERMATRIZ_H
#include <tarjeta.h>
#include <matrizpaginada.h>


class builderMatriz {

public:
    builderMatriz();
    matrizpaginada* construirMatriz();
    char verificarCantidadTipos(char tipoTarjeta);

private:
    int cantidadTarjetasTipoA = 0;
    int cantidadTarjetasTipoB =0;
    int cantidadTarjetasTipoC = 0;

};

#endif // BUILDERMATRIZ_H
