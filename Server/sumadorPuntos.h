#ifndef SUMADORPUNTOS_H
#define SUMADORPUNTOS_H
#include <informacioncliente.h>
#include <matrizpaginada.h>
#include <buscadorTarjeta.h>
#include <operadormatrizpaginada.h>

class sumadorPuntos
{
public:
    sumadorPuntos();
    int sumarPuntos(int,matrizpaginada*,int,int,int);
    int sumarParTarjetasReveladas(int, matrizpaginada*,int,int);
private:
    buscadorTarjeta buscadorTarjetaSeleccionada;
    operadorMatrizPaginada operadorMatriz;
};

#endif // SUMADORPUNTOS_H
