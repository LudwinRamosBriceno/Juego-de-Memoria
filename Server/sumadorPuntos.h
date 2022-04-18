#ifndef SUMADORPUNTOS_H
#define SUMADORPUNTOS_H
#include <informacioncliente.h>
#include <matrizpaginada.h>
#include <buscadorTarjeta.h>

class sumadorPuntos
{
public:
    sumadorPuntos();
    int sumarPuntos(int,matrizpaginada*,int,int);
    int sumarParTarjetasReveladas(int, matrizpaginada*,int,int);
private:
    buscadorTarjeta buscadorTarjetaSeleccionada;
};

#endif // SUMADORPUNTOS_H
